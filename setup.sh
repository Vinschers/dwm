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

compile "dmenu" "config.h"
compile "st" "config.h"
compile "dwmblocks" "blocks.h"

\cp dwm/patches.h dwm-flexipatch/patches.h
./flexipatch-finalizer.sh -d dwm-flexipatch/ -o dwm-final/ -r
\cp -r dwm/* dwm-final/
cd dwm-final
make clean install
