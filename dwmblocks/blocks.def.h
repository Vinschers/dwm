//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	/* {"",		"weather",			3600,			8}, */
	{"",		"hardware",			60,			7},
	{"",		"network",			1,			6},
	{"",		"disk",				30,			5},
	/* {"",		"wifi",				1,			4}, */
	{"",		"battery",			60,			3},
	{"",		"volume",			0,			2},
	{"",		"datetime",			1,			1},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
