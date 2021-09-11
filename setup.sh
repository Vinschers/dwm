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

sudo pacman -S --needed picom nitrogen

cd ../
cp ~/.xinitrc xinitrc.old
cp xinitrc ~/.xinitrc
