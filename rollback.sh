#!/bin/sh

[ -f xinitrc.old ] && cp xinitrc.old ~/.xinitrc || echo "Nothing to rollback to"
