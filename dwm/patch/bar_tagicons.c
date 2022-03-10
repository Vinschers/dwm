#include <ctype.h>
#include <string.h>

char *
geticon(Monitor *m, int tag, int iconset)
{
	int i;
	int tagindex = tag + NUMTAGS * m->num;
	for (i = 0; i < LENGTH(tagicons[iconset]) && tagicons[iconset][i] != NULL; ++i);
	if (i == 0)
		tagindex = 0;
	else if (tagindex >= i)
		tagindex = tagindex % i;

	return tagicons[iconset][tagindex];
}

void
tolowerstr(char *dest, const char *src)
{
	unsigned char *p = NULL;

	for (p = (unsigned char *)src; *p; ++p)
		*(dest++) = tolower(*p);
	*dest = 0;
}

char *
gettagsuperscript(int tag)
{
	switch (tag) {
		case 0:
			return "¹";
		case 1:
			return "²";
		case 2:
			return "³";
		case 3:
			return "⁴";
		case 4:
			return "⁵";
		case 5:
			return "⁶";
		case 6:
			return "⁷";
		case 7:
			return "⁸";
		case 8:
			return "⁹";
	}

	return 0;
}

void
appendtagsuperscript(char *icon, char *tag)
{
	char *aftertag = icon;
	unsigned char firstbyte = (unsigned char) *icon;

	if (*(icon) == 0 || firstbyte >> 7 == 0)
		aftertag += 1;
	else if (firstbyte >> 5 == 6)
		aftertag += 2;
	else if (firstbyte >> 4 == 14)
		aftertag += 3;
	else if (firstbyte >> 3 == 30)
		aftertag += 4;

	for (; *tag; ++aftertag)
		*aftertag = *(tag++);

	*aftertag = 0;
}

unsigned char
hex_to_dec(const char *hex)
{
    unsigned char ret = 0;

    if (hex[0] >= 'a')
        ret += hex[0] - 'a' + 10;
    else
        ret += hex[0] - '0';
    ret <<= 4;

    if (hex[1] >= 'a')
        ret += hex[1] - 'a' + 10;
    else
        ret += hex[1] - '0';

    return ret;
}

void
change_scheme(char *color, Clr *scheme)
{
    char lowercolor[10];
    unsigned short red, green, blue;

    tolowerstr(lowercolor, color + 1); // Remove #

    red = hex_to_dec(lowercolor);
    green = hex_to_dec(lowercolor + 2);
    blue = hex_to_dec(lowercolor + 4);

    scheme->color.red = red << 8;
    scheme->color.green = green << 8;
    scheme->color.blue = blue << 8;
}

unsigned char
containsstr(char *str1, char *str2)
{
    char *ptr;

    for (ptr = str1; *ptr; ++ptr) {
        if (*ptr == ' ' || ptr == str1)
            if (strncmp(str2, ptr, strlen(str2)) == 0)
                return 1;
    }

    return 0;
}

char *
getoccupiedicon(Monitor *m, int tag, char *img_icon)
{
	Client *c = NULL;
    unsigned short i = 0;
	char *icon = NULL, *tagsuperscript = gettagsuperscript(tag), lowername[200], currentname[200];
    unsigned char hasicon = 0;

    for (c = m->clients; c && !(c->tags & 1 << tag); c = c->next) {}
	if (!c)
		return NULL;

	tolowerstr(lowername, c->name);

	icon = geticon(m, tag, IconsOccupied);
    change_scheme(colors[SchemeTagsNorm][0], scheme[SchemeTagsNorm]);

	for (i = 0; i < LENGTH(occupiedicons); ++i) {
		tolowerstr(currentname, occupiedicons[i][0]);

		if (containsstr(lowername, currentname)) {
            hasicon = 1;
			icon = occupiedicons[i][1];
			appendtagsuperscript(icon, tagsuperscript);

            if (strlen(occupiedicons[i][2]))
                change_scheme(occupiedicons[i][2], scheme[SchemeTagsNorm]);

			break;
		}
	}

    if (!hasicon && c->icon) {
        *img_icon = 1;
        return gettagsuperscript(tag);
    }

	return icon;
}

char *
tagicon(Monitor *m, int tag, char *img_icon)
{
    *img_icon = 0;
	char *icon = getoccupiedicon(m, tag, img_icon);

	if (!icon) {
		icon = geticon(m, tag, IconsDefault);

		if (TEXTW(icon) <= lrpad && m->tagset[m->seltags] & 1 << tag)
			icon = geticon(m, tag, IconsVacant);
	}

	return icon;
}
