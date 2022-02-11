#define CMDLENGTH 1000
#define DELIMITER " "
#define ICON_LENGTH 60
#define CLICKABLE_BLOCKS 1

#define DIV(bg) "^t^^v^^c"bg"^^t^^b"bg"^^v^ "

const Block blocks[] = {
	BLOCK("^v^"DIV("#4C566A"),		"sb-network",			1,			8),
	BLOCK(     DIV("#2E3440"),		"sb-price",			60,			7),
	BLOCK(     DIV("#4C566A"),		"sb-weather",			60,			6),
	BLOCK(	   DIV("#2E3440"),		"sb-keyboard",			0,			5),
	BLOCK(	   DIV("#4C566A"),		"sb-volume",			0,			4),
	BLOCK(	   DIV("#2E3440"),		"sb-hardware",			2,			3),
	BLOCK(	   DIV("#4C566A"),		"sb-battery",			30,			2),
	BLOCK(     DIV("#2E3440"),		"sb-datetime",	    		1, 			1),
};
