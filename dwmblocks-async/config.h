#define CMDLENGTH 7500
#define DELIMITER " "
#define ICON_LENGTH 60
#define CLICKABLE_BLOCKS 1

#define DIV(bg, fg) "^t^^v^^c"bg"^^t^^b"bg"^^v^^c"fg"^ "

const Block blocks[] = {
	BLOCK("^v^"DIV("#2E3440", "#FFE34D"),		"sb-price",			60,			13),
	BLOCK(     DIV("#4C566A", "#D8DEE9"),		"sb-weather",			60,			12),
	BLOCK(     DIV("#2E3440", "#84FFE6"),		"sb-network",			1,			11),
	BLOCK(     DIV("#4C566A", "#FF9484"),		"sb-packages",			7200,			10),
	BLOCK(	   DIV("#2E3440", "#BCFF84"),		"sb-disk",			30,			9),
	BLOCK(	   DIV("#4C566A", "#CB9EFF"),		"sb-memory",			10,			8),
	BLOCK(	   DIV("#2E3440", "#84B2FF"),		"sb-cpu",			2,			7),
	BLOCK(	   DIV("#4C566A", "#FFC784"),		"sb-keyboard",			0,			4),
	BLOCK(	   DIV("#2E3440", "#FF84A8"),		"sb-volume",			0,			3),
	BLOCK(	   DIV("#4C566A", "#89FF84"),		"sb-date",			3600,			2),
	BLOCK(     DIV("#2E3440", "#84E5FF"),		"sb-time",	    		1, 			1),
};
