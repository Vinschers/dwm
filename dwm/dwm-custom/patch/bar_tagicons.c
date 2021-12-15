#include <ctype.h>

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

char *
getoccupiedicon(Monitor *m, int tag)
{
	Client *c;
	unsigned int i = 0;
	const char *class;
	char *icon = NULL, *tagsuperscript = gettagsuperscript(tag), lowerclass[200], currentclass[200];
	XClassHint ch = { NULL, NULL };

	for (c = m->clients; c && !(c->tags & 1 << tag); c = c->next);

	if (!c)
		return NULL;

	/* rule matching */
	XGetClassHint(dpy, c->win, &ch);
	class    = ch.res_class ? ch.res_class : broken;
	tolowerstr(lowerclass, class);

	icon = geticon(m, tag, IconsOccupied);

	for (i = 0; i < LENGTH(occupiedicons); ++i) {
		tolowerstr(currentclass, occupiedicons[i][0]);

		if (strstr(lowerclass, currentclass)) {
			icon = occupiedicons[i][1];
			appendtagsuperscript(icon, tagsuperscript);
			break;
		}
	}

	if (ch.res_class)
		XFree(ch.res_class);
	if (ch.res_name)
		XFree(ch.res_name);

	return icon;
}

char *
tagicon(Monitor *m, int tag)
{
	char *icon = getoccupiedicon(m, tag);

	if (!icon) {
		icon = geticon(m, tag, IconsDefault);

		if (TEXTW(icon) <= lrpad && m->tagset[m->seltags] & 1 << tag)
			icon = geticon(m, tag, IconsVacant);
	}

	return icon;
}

/*
char *
tagicon(Monitor *m, int tag)
{
	char *icon = getoccupiedicon(m, tag);
	int tagindex = tag + NUMTAGS * m->index;

	if (!icon) {
		if (tagindex >= LENGTH(tagicons[DEFAULT_TAGS]))
			tagindex = tagindex % LENGTH(tagicons[DEFAULT_TAGS]);
		if (m->alttag)
			icon = tagicons[ALTERNATIVE_TAGS][tagindex];
		icon = tagicons[DEFAULT_TAGS][tagindex];
	}

	return icon;
}
*/
