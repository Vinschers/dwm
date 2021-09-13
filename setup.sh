#!/bin/sh

cd dwm-flexipatch
cp config.def.h config.h
make clean install
make clean
rm config.h
rm patches.h

cd ..
./flexipatch-finalizer.sh -r -d ./dwm-flexipatch -o ./dwm
cd dwm
cp config.def.h config.h
make clean install
make clean
rm config.h

cd ../dmenu
cp config.def.h config.h
make clean install
make clean
rm config.h

cd ../st
cp config.def.h config.h
make clean install
make clean
rm config.h

cd ../dwmblocks
cp blocks.def.h blocks.h
make clean install
make clean
rm blocks.h

cd ../
cp ~/.xinitrc xinitrc.old
cp xinitrc ~/.xinitrc
