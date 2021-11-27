/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 4;        /* border pixel of windows */
static const unsigned int gappx     = 5;        /* gap pixel between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int systraypinning = 2;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;        /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
#define ICONSIZE 16 /* icon size */
#define ICONSPACING 5 /* space between icon and title */
static const char *fonts[]          = { "monospace:size=11", "fontawesome:size=12", "fontawesomebrands:size=12", "JoyPixels:pixelsize=15", "Noto Color Emoji:pixelsize=15" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#2E3440"; /* Status bar bg */
static const char col_gray2[]       = "#3B4252"; /* Unselected border */
static const char col_gray3[]       = "#ECEFF4"; /* Status bar fg */
static const char col_gray4[]       = "#eeeeee"; /* Tags fg */
static const char col_cyan[]        = "#8F00FF";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* staticstatus */
static const int statmonval = 1;

/* tagging: refer to https://github.com/bakkeby/patches/wiki/tagicons */
static const char *tags[NUMTAGS] = { NULL };  /* left for compatibility reasons, i.e. code that checks LENGTH(tags) */
static char *tagicons[][NUMTAGS*2] = {
	[IconsDefault]               = { "" },
	[IconsVacant]                = { "1", "2", "3", "4", "5", "6", "7", "8", "9" },
	[IconsOccupiedDefault]       = { "", "", "", "", "", "<6>", "<7>", "", "" },
	[IconsOccupiedDualMonitor]   = { "", "", "", "<3>", "", "<5>", "<7>", "<8>", "", "", "", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "" },
};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask

#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#define STATUSBAR "dwmblocks"

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      			spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, 			spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      			togglebar,      {0} },
	{ MODKEY,                       XK_j,      			focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      			focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      			incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      			incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      			setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      			setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, 			zoom,           {0} },
	{ MODKEY,                       XK_Tab,    			view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      			killclient,     {0} },
	{ MODKEY,                       XK_t,      			setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      			setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      			setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  			setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  			togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_f,      			togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      			view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      			tag,            {.ui = ~0 } },
	{ ALTKEY,                       XK_j,  				focusmon,       {.i = -1 } },
	{ ALTKEY,                       XK_k, 				focusmon,       {.i = +1 } },
	{ ALTKEY|ShiftMask,             XK_j,	  			tagmon,         {.i = -1 } },
	{ ALTKEY|ShiftMask,             XK_k, 				tagmon,         {.i = +1 } },
//	{ MODKEY|ShiftMask,             XK_a,      		        seticonset,     {.i = 0 } },
//	{ MODKEY|ShiftMask,             XK_b,      			seticonset,     {.i = 0 } },
	{ ShiftMask,             	XK_Print,  			spawn,          SHCMD("flameshot gui") },
	{ MODKEY|ShiftMask,             XK_e,      			spawn,          SHCMD("dmenuselector emojis") },
	{ MODKEY|ShiftMask,             XK_m,      			spawn,          SHCMD("dmenuselector math") },
	{ MODKEY|ShiftMask,             XK_p,      			spawn,          SHCMD("simple-scan") },
	{ MODKEY|ShiftMask,             XK_b,      			spawn,          SHCMD("xdg-open https://searx.be") },
	{ MODKEY|ShiftMask,             XK_l,      			spawn,          SHCMD("latex2img") },
	{ MODKEY|ShiftMask,             XK_equal,  			spawn,          SHCMD("pamixer -i 1 && pkill -RTMIN+2 dwmblocks") },
	{ MODKEY|ShiftMask,             XK_minus,  			spawn,          SHCMD("pamixer -d 1 && pkill -RTMIN+2 dwmblocks") },
	TAGKEYS(                        XK_1,                      			0)
	TAGKEYS(                        XK_2,                      			1)
	TAGKEYS(                        XK_3,                      			2)
	TAGKEYS(                        XK_4,                      			3)
	TAGKEYS(                        XK_5,                      			4)
	TAGKEYS(                        XK_6,                      			5)
	TAGKEYS(                        XK_7,                      			6)
	TAGKEYS(                        XK_8,                      			7)
	TAGKEYS(                        XK_9,                      			8)
	{ MODKEY|ShiftMask,             XK_q,      			quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
//	{ ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
//	{ ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
//	{ ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkTagBar,            0,              Button4,        cycleiconset,   {.i = +1 } },
	{ ClkTagBar,            0,              Button5,        cycleiconset,   {.i = -1 } },
};
