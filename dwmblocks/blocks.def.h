//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"",		"weather",			3600,			6},
	{"",		"cpu_temp",			60,			5},
	{"",		"disk",				30,			4},
	{"",		"ram",				5,			3},
	{"",		"network",			1,			2},
	{"",		"datetime",			1,			1},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
