#define BAR_OFFSET 2

int
width_tags(Bar *bar, BarArg *a)
{
    Client *c;
	Monitor *m = bar->mon;
	int w, i, tw;
    char img_icon;

	for (w = 0, i = 0; i < NUMTAGS; i++) {
		tw = TEXTW(tagicon(bar->mon, i, &img_icon));
        if (img_icon) {
    	    for (c = m->clients; c && !(c->tags & 1 << i); c = c->next) {}
            tw += c->icw;
        }
		if (tw > lrpad)
			w += tw;
	}
	return w + BAR_OFFSET;
}

int
draw_tags(Bar *bar, BarArg *a)
{
	int invert;
	int w, x = a->x;
	unsigned int i, occ = 0, urg = 0;
	char *icon, img_icon;
	Client *c;
	Monitor *m = bar->mon;

	for (c = m->clients; c; c = c->next) {
		occ |= c->tags;
		if (c->isurgent)
			urg |= c->tags;
	}
	for (i = 0; i < NUMTAGS; i++) {

    	for (c = m->clients; c && !(c->tags & 1 << i); c = c->next) {}

		icon = tagicon(bar->mon, i, &img_icon);
		invert = 0;
		w = TEXTW(icon);

        if (img_icon)
            w += c->icw;
            
		if (w <= lrpad)
			continue;
		drw_setscheme(drw, scheme[
			m->tagset[m->seltags] & 1 << i
			? SchemeTagsSel
			: urg & 1 << i
			? SchemeUrg
			: SchemeTagsNorm
		]);
		drw_text(drw, x, a->y, w, a->h, lrpad / 2, "", invert, False);

        if (img_icon) {
		    drw_text(drw, x + BAR_OFFSET + c->icw, a->y, TEXTW(icon), a->h, lrpad / 2, icon, invert, False);
		    drw_pic(drw, x + BAR_OFFSET + lrpad / 2, a->y + (a->h - c->ich)/2, c->icw, c->ich, c->icon);
        }
        else {
		    drw_text(drw, x + BAR_OFFSET, a->y, w, a->h, lrpad / 2, icon, invert, False);
		    drw_text(drw, x + w, a->y, w, a->h, lrpad / 2, "", invert, False);
        }

		drawindicator(m, NULL, occ, x, a->y, w, a->h, i, -1, invert, tagindicatortype);
		if (ulineall || m->tagset[m->seltags] & 1 << i)
			drw_rect(drw, x + ulinepad + BAR_OFFSET, bh - ulinestroke - ulinevoffset, w - (ulinepad * 2), ulinestroke, 1, 0);

		x += w;
	}

	return 1;
}

int
click_tags(Bar *bar, Arg *arg, BarArg *a)
{
    Client *c;
	Monitor *m = bar->mon;
	int i = 0, x = lrpad / 2;
	char icon[30], img_icon;

	do {
		strcpy(icon, tagicon(bar->mon, i, &img_icon));
		if (icon[0] == 0)
            continue;
		x += TEXTW(icon);
        if (img_icon) {
    	    for (c = m->clients; c && !(c->tags & 1 << i); c = c->next) {}
            x += c->icw;
        }
	} while (a->x >= x && ++i < NUMTAGS);
	if (i < NUMTAGS) {
		arg->ui = 1 << i;
	}
	return ClkTagBar;
}

