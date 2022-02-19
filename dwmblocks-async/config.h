#define CMDLENGTH 1000
#define DELIMITER " "
#define ICON_LENGTH 60
#define CLICKABLE_BLOCKS 1

#define BG_1 "#132738"
#define BG_2 "#224664"

#define DIV(bg) "^t^^v^^c"bg"^^t^^b"bg"^^v^ "

const Block blocks[] = {
	BLOCK("^v^"DIV(BG_2),		"sb-network",			1,			8),
	BLOCK(     DIV(BG_1),		"sb-price",			    60,			7),
	BLOCK(     DIV(BG_2),		"sb-weather",			60,			6),
	BLOCK(	   DIV(BG_1),		"sb-keyboard",			0,			5),
	BLOCK(	   DIV(BG_2),		"sb-volume",			0,			4),
	BLOCK(	   DIV(BG_1),		"sb-hardware",			2,			3),
	BLOCK(	   DIV(BG_2),		"sb-battery",			30,			2),
	BLOCK(     DIV(BG_1),		"sb-datetime",	        1, 			1),
};
