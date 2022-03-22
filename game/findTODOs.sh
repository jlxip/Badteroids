#!/bin/sh -e
dirname="$(pwd | rev | cut -d'/' -f1 | rev)"

find src/ -type f -regex '.*\(cpp\|hpp\)$' -exec grep -Hn TODO {} \;
