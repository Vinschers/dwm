#!/bin/sh

cd dwm
cp config.def.h config.h
make clean install

cd ../dmenu
cp config.def.h config.h
make clean install

cd ../st
cp config.def.h config.h
make clean install

cd ../dwmblocks
make clean install

cd ../
cp ~/.xinitrc xinitrc.old
cp xinitrc ~/.xinitrc
