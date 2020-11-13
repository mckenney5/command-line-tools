#!/bin/bash
if [ -z "$1" ]
then	
	# list the command instead
	echo "'xrandr --output HDMI-1 --mode 1024x768 --left-of LVDS-1'"
elif [ $1 = "tiny-tv" ]
then
	xrandr --output HDMI-1 --mode 1024x768 --right-of LVDS-1
elif [ $1 = "big-tv" ]
then
	xrandr --output HDMI-1 --mode 1920x1080 --right-of LVDS-1
else
	echo "usage: tiny-tv / big-tv / <none>"
	echo "none spits out the xrandr command, try ./hdmi.sh >> cmd.txt"
fi

