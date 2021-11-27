#!/bin/sh

compile () {
	cd "$1"
	
	for f in *.def.h; do 
	    cp -- "$f" "${f%.def.h}.h"
	done

	make clean install
	make clean
	! [ -z "$2" ] && rm "$2"

	cd ..
}

compile "dwm" "config.h"

compile "dmenu" "config.h"

compile "st" "config.h"

# compile "dwmblocks" "blocks.h"
# compile "slstatus"

cp xinitrc ~/.xinitrc
