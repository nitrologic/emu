#!/bin/sh
# Mac only ram drive called /build
NUMSECTORS=512000
ramdev=`hdid -nomount ram://$NUMSECTORS`

if [ ! -d $build/guard ]; then
newfs_hfs $ramdev
sudo mount -t hfs $ramdev /build
diskutil rename /build build
# do not remove
mkdir /build/guard
fi