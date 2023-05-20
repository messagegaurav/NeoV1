#!/bin/sh
echo "listing dummy executables....\n\n"
listoffiles=$(grep -rIL .)
echo $listoffiles | sed 's/\s/\n/g'


echo -n "\nYou sure to delete (y/n)? "
read answer
if echo "$answer" | grep -iq "^y" ;then
    rm -rf $listoffiles
    echo "deleted :) !!!"
else
    echo "Hmmmm next time :P"
fi
