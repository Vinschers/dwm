void
holdbar(const Arg *arg)
{
    Monitor *m;
	Bar *bar;
    
    for (m = mons; m; m = m->next) {
	    if (m->showbar)
		    continue;
	    m->showbar = 2;
	    updatebarpos(m);
	    for (bar = m->bar; bar; bar = bar->next)
		    XMoveResizeWindow(dpy, bar->win, bar->bx, bar->by, bar->bw, bar->bh);
        arrange(m);
    }
}

void
keyrelease(XEvent *e)
{
	Bar *bar;
    Monitor *m;

	if (XEventsQueued(dpy, QueuedAfterReading)) {
		XEvent ne;
		XPeekEvent(dpy, &ne);

		if (ne.type == KeyPress && ne.xkey.time == e->xkey.time &&
				ne.xkey.keycode == e->xkey.keycode) {
			XNextEvent(dpy, &ne);
			return;
		}
	}

    if (systray)
		XMoveWindow(dpy, systray->win, -32000, -32000);

    for (m = mons; m; m = m->next) {
	    if (e->xkey.keycode == XKeysymToKeycode(dpy, HOLDKEY) && m->showbar == 2) {
		    m->showbar = 0;
		    updatebarpos(m);
		    for (bar = m->bar; bar; bar = bar->next)
			    XMoveResizeWindow(dpy, bar->win, bar->bx, bar->by, bar->bw, bar->bh);
		    arrange(m);
        }
	}
}

