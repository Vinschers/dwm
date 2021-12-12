#define CMDLENGTH 500
#define DELIMITER " "
#define ICON_LENGTH 60
#define CLICKABLE_BLOCKS 1

#define DIV(bg, fg) "^t^^v^^c"bg"^^t^^b"bg"^^v^^c"fg"^ "

const Block blocks[] = {
	BLOCK("^v^"DIV("#4C566A", "#7DCFFF"),		"network",			1,			11),
	BLOCK(     DIV("#2E3440", "#E0AF68"),		"packages",			7200,			10),
	BLOCK(	   DIV("#2E3440", "#9ECE6A"),		"disk",				30,			9),
	BLOCK(	   DIV("#4C566A", "#BB9AF7"),		"memory",			10,			8),
	BLOCK(	   DIV("#2E3440", "#E06C75"),		"cpu",				2,			7),
	BLOCK(	   DIV("#4C566A", "#E0AF68"),		"keyboard",			0,			4),
	BLOCK(	   DIV("#2E3440", "#EEEEEE"),		"volume",			0,			3),
	BLOCK(	   DIV("#4C566A", "#9ECE6A"),		"sdate",			3600,			2),
	BLOCK(     DIV("#2E3440", "#7DCFFF"),		"stime",	    		1, 			1),
};
