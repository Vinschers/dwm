//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	/* {"",		"weather",			3600,			7}, */
	{"",		"hardware",			60,			6},
	{"",		"network",			1,			5},
	{"",		"disk",				30,			4},
	/* {"",		"wifi",				1,			3}, */
	{"",		"battery",			60,			2},
	{"",		"datetime",			1,			1},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
