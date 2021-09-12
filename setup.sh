#!/bin/sh

cd dwm
cp config.def.h config.h
make clean install
rm config.h
[ -f patches.h ] && rm patches.h

cd ../dmenu
cp config.def.h config.h
make clean install
rm config.h

cd ../st
cp config.def.h config.h
make clean install
rm config.h

cd ../dwmblocks
cp blocks.def.h blocks.h
make clean install
rm blocks.h

cd ../
cp ~/.xinitrc xinitrc.old
cp xinitrc ~/.xinitrc
