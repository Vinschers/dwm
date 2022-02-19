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

cd st
make install
make clean
cd ..

cd dwmblocks-async
make install
make clean
cd ..

cd dwm
make install
make clean
cd ..
