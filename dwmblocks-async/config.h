#define CMDLENGTH 500
#define DELIMITER " "
#define ICON_LENGTH 60
#define CLICKABLE_BLOCKS 1

#define DIV(bg, fg) "^t^^v^^c"bg"^^t^^b"bg"^^v^^c"fg"^ "

const Block blocks[] = {
	BLOCK("^v^"DIV("#4C566A", "#D8DEE9"),		"sb-weather",			60,			12),
	BLOCK(     DIV("#2E3440", "#7DCFFF"),		"sb-network",			1,			11),
	BLOCK(     DIV("#4C566A", "#E0AF68"),		"sb-packages",			7200,			10),
	BLOCK(	   DIV("#2E3440", "#9ECE6A"),		"sb-disk",			30,			9),
	BLOCK(	   DIV("#4C566A", "#BB9AF7"),		"sb-memory",			10,			8),
	BLOCK(	   DIV("#2E3440", "#E06C75"),		"sb-cpu",			2,			7),
	BLOCK(	   DIV("#4C566A", "#E0AF68"),		"sb-keyboard",			0,			4),
	BLOCK(	   DIV("#2E3440", "#EEEEEE"),		"sb-volume",			0,			3),
	BLOCK(	   DIV("#4C566A", "#9ECE6A"),		"sb-date",			3600,			2),
	BLOCK(     DIV("#2E3440", "#7DCFFF"),		"sb-time",	    		1, 			1),
};
