//Modify this file to change what commands output to your statusbar, and recompile using the make command.

#define DIV(bg, fg) "^t^^v^^c"bg"^ ^t^^b"bg"^^v^^c"fg"^ "

static const Block blocks[] = {
			/*Icon*/			/*Command*/		/*Update Interval*/	/*Update Signal*/
	/* {"",						"weather",			3600,			10}, */
	{"^v^"DIV("#2E3440", "#E0AF68"),		"packages",			7200,			9},
	{     DIV("#4C566A", "#7DCFFF"),		"network",			1,			8},
	{     DIV("#2E3440", "#9ECE6A"),		"disk",				30,			7},
	{     DIV("#4C566A", "#BB9AF7"),		"hardware",			60,			6},
	/* { "",					"wifi",				1,			5}, */
	/* {  DIV("#000000", "#EEEEEE"),		"battery",			60,			4}, */
	{     DIV("#2E3440", "#7AA2F7"),		"volume",			0,			3},
	{     DIV("#4C566A", "#E5E9F0"),		"sdate",			3600,			2},
	{     DIV("#2E3440", "#E5E9F0"),		"stime",			1,			1},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = "";
static unsigned int delimLen = 5;
