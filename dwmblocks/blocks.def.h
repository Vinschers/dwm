//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"",		"weather",			3600,			5},
	{"",		"hardware",			60,			4},
	{"",		"network",			1,			3},
	{"",		"disk",				30,			2},
	{"",		"datetime",			1,			1},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
