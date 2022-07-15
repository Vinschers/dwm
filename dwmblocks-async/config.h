#define CMDLENGTH 1000
#define DELIMITER " "
#define ICON_LENGTH 60
#define CLICKABLE_BLOCKS 1

const char *bgcolors[] = {"#224664", "#132738"};
const char *fgcolors[] = {"#BE9DFF", "#3AC1FF"};

const Block blocks[] = {
	{"sb-network",			1,			8},
    {"sb-price",		    60,			7},
    {"sb-weather",			60,			6},
    {"sb-keyboard",		    0,			5},
    {"sb-volume",		    0,			4},
    {"sb-hardware",		    2,			3},
    {"sb-battery",			30,			2},
    {"sb-datetime",	        1, 			1},
};
