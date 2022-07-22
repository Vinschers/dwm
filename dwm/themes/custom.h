#define BAR_BG "#132738"
#define BAR_FG "#fcfdfe"
#define NORMAL_BORDER "#282737"
#define SELECTED_BORDER "#61afef"
#define UNSELECTED_WINDOW "#132738"
#define ACTIVE_GROUP "#132738"
#define SELECTED_WINDOW "#212171"

static char c000000[]                    = "#000000"; // placeholder value

static char normfgcolor[]                = BAR_FG;
static char normbgcolor[]                = BAR_BG;
static char normbordercolor[]            = NORMAL_BORDER;
static char normfloatcolor[]             = NORMAL_BORDER;

static char selfgcolor[]                 = BAR_FG;              /* dmenu selected fg */
static char selbgcolor[]                 = "#5555ff";           /* dmenu selected bg */
static char selbordercolor[]             = SELECTED_BORDER;
static char selfloatcolor[]              = SELECTED_BORDER;

static char titlenormfgcolor[]           = BAR_FG;
static char titlenormbgcolor[]           = BAR_BG;
static char titlenormbordercolor[]       = NORMAL_BORDER;
static char titlenormfloatcolor[]        = NORMAL_BORDER;

static char titleselfgcolor[]            = BAR_FG;
static char titleselbgcolor[]            = BAR_BG;
static char titleselbordercolor[]        = SELECTED_BORDER;
static char titleselfloatcolor[]         = SELECTED_BORDER;

static char tagsnormfgcolor[]            = "#d1d1ff";
static char tagsnormbgcolor[]            = BAR_BG;
static char tagsnormbordercolor[]        = NORMAL_BORDER;
static char tagsnormfloatcolor[]         = NORMAL_BORDER;

static char tagsselfgcolor[]             = "#effcfe";
static char tagsselbgcolor[]             = "#1460d2";
static char tagsselbordercolor[]         = SELECTED_BORDER;
static char tagsselfloatcolor[]          = SELECTED_BORDER;

static char urgfgcolor[]                 = "#000000";
static char urgbgcolor[]                 = "#f7575d";
static char urgbordercolor[]             = "#f7575d";
static char urgfloatcolor[]              = "#f7575d";


static char hidnormfgcolor[]             = "#1460d2";
static char hidselfgcolor[]              = "#227799";
static char hidnormbgcolor[]             = BAR_BG;
static char hidselbgcolor[]              = BAR_BG;
static char normTTBbgcolor[]             = UNSELECTED_WINDOW;
static char normLTRbgcolor[]             = UNSELECTED_WINDOW;
static char normMONObgcolor[]            = UNSELECTED_WINDOW;
static char normGRIDbgcolor[]            = UNSELECTED_WINDOW;
static char normGRD1bgcolor[]            = UNSELECTED_WINDOW;
static char normGRD2bgcolor[]            = UNSELECTED_WINDOW;
static char normGRDMbgcolor[]            = UNSELECTED_WINDOW;
static char normHGRDbgcolor[]            = UNSELECTED_WINDOW;
static char normDWDLbgcolor[]            = UNSELECTED_WINDOW;
static char normSPRLbgcolor[]            = UNSELECTED_WINDOW;
static char normfloatbgcolor[]           = UNSELECTED_WINDOW;
static char actTTBbgcolor[]              = ACTIVE_GROUP;
static char actLTRbgcolor[]              = ACTIVE_GROUP;
static char actMONObgcolor[]             = ACTIVE_GROUP;
static char actGRIDbgcolor[]             = ACTIVE_GROUP;
static char actGRD1bgcolor[]             = ACTIVE_GROUP;
static char actGRD2bgcolor[]             = ACTIVE_GROUP;
static char actGRDMbgcolor[]             = ACTIVE_GROUP;
static char actHGRDbgcolor[]             = ACTIVE_GROUP;
static char actDWDLbgcolor[]             = ACTIVE_GROUP;
static char actSPRLbgcolor[]             = ACTIVE_GROUP;
static char actfloatbgcolor[]            = ACTIVE_GROUP;
static char selTTBbgcolor[]              = SELECTED_WINDOW;
static char selLTRbgcolor[]              = SELECTED_WINDOW;
static char selMONObgcolor[]             = SELECTED_WINDOW;
static char selGRIDbgcolor[]             = SELECTED_WINDOW;
static char selGRD1bgcolor[]             = SELECTED_WINDOW;
static char selGRD2bgcolor[]             = SELECTED_WINDOW;
static char selGRDMbgcolor[]             = SELECTED_WINDOW;
static char selHGRDbgcolor[]             = SELECTED_WINDOW;
static char selDWDLbgcolor[]             = SELECTED_WINDOW;
static char selSPRLbgcolor[]             = SELECTED_WINDOW;
static char selfloatbgcolor[]            = SELECTED_WINDOW;

static char *colors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
	[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
	[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
	[SchemeFlexActTTB]   = { titleselfgcolor,  actTTBbgcolor,    actTTBbgcolor,        c000000 },
	[SchemeFlexActLTR]   = { titleselfgcolor,  actLTRbgcolor,    actLTRbgcolor,        c000000 },
	[SchemeFlexActMONO]  = { titleselfgcolor,  actMONObgcolor,   actMONObgcolor,       c000000 },
	[SchemeFlexActGRID]  = { titleselfgcolor,  actGRIDbgcolor,   actGRIDbgcolor,       c000000 },
	[SchemeFlexActGRD1]  = { titleselfgcolor,  actGRD1bgcolor,   actGRD1bgcolor,       c000000 },
	[SchemeFlexActGRD2]  = { titleselfgcolor,  actGRD2bgcolor,   actGRD2bgcolor,       c000000 },
	[SchemeFlexActGRDM]  = { titleselfgcolor,  actGRDMbgcolor,   actGRDMbgcolor,       c000000 },
	[SchemeFlexActHGRD]  = { titleselfgcolor,  actHGRDbgcolor,   actHGRDbgcolor,       c000000 },
	[SchemeFlexActDWDL]  = { titleselfgcolor,  actDWDLbgcolor,   actDWDLbgcolor,       c000000 },
	[SchemeFlexActSPRL]  = { titleselfgcolor,  actSPRLbgcolor,   actSPRLbgcolor,       c000000 },
	[SchemeFlexActFloat] = { titleselfgcolor,  actfloatbgcolor,  actfloatbgcolor,      c000000 },
	[SchemeFlexInaTTB]   = { titlenormfgcolor, normTTBbgcolor,   normTTBbgcolor,       c000000 },
	[SchemeFlexInaLTR]   = { titlenormfgcolor, normLTRbgcolor,   normLTRbgcolor,       c000000 },
	[SchemeFlexInaMONO]  = { titlenormfgcolor, normMONObgcolor,  normMONObgcolor,      c000000 },
	[SchemeFlexInaGRID]  = { titlenormfgcolor, normGRIDbgcolor,  normGRIDbgcolor,      c000000 },
	[SchemeFlexInaGRD1]  = { titlenormfgcolor, normGRD1bgcolor,  normGRD1bgcolor,      c000000 },
	[SchemeFlexInaGRD2]  = { titlenormfgcolor, normGRD2bgcolor,  normGRD2bgcolor,      c000000 },
	[SchemeFlexInaGRDM]  = { titlenormfgcolor, normGRDMbgcolor,  normGRDMbgcolor,      c000000 },
	[SchemeFlexInaHGRD]  = { titlenormfgcolor, normHGRDbgcolor,  normHGRDbgcolor,      c000000 },
	[SchemeFlexInaDWDL]  = { titlenormfgcolor, normDWDLbgcolor,  normDWDLbgcolor,      c000000 },
	[SchemeFlexInaSPRL]  = { titlenormfgcolor, normSPRLbgcolor,  normSPRLbgcolor,      c000000 },
	[SchemeFlexInaFloat] = { titlenormfgcolor, normfloatbgcolor, normfloatbgcolor,     c000000 },
	[SchemeFlexSelTTB]   = { titleselfgcolor,  selTTBbgcolor,    selbordercolor,        c000000 },
	[SchemeFlexSelLTR]   = { titleselfgcolor,  selLTRbgcolor,    selbordercolor,        c000000 },
	[SchemeFlexSelMONO]  = { titleselfgcolor,  selMONObgcolor,   selbordercolor,       c000000 },
	[SchemeFlexSelGRID]  = { titleselfgcolor,  selGRIDbgcolor,   selbordercolor,       c000000 },
	[SchemeFlexSelGRD1]  = { titleselfgcolor,  selGRD1bgcolor,   selbordercolor,       c000000 },
	[SchemeFlexSelGRD2]  = { titleselfgcolor,  selGRD2bgcolor,   selbordercolor,       c000000 },
	[SchemeFlexSelGRDM]  = { titleselfgcolor,  selGRDMbgcolor,   selbordercolor,       c000000 },
	[SchemeFlexSelHGRD]  = { titleselfgcolor,  selHGRDbgcolor,   selbordercolor,       c000000 },
	[SchemeFlexSelDWDL]  = { titleselfgcolor,  selDWDLbgcolor,   selbordercolor,       c000000 },
	[SchemeFlexSelSPRL]  = { titleselfgcolor,  selSPRLbgcolor,   selbordercolor,       c000000 },
	[SchemeFlexSelFloat] = { titleselfgcolor,  selfloatbgcolor,  selbordercolor,      c000000 },
};
