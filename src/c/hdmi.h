#ifndef _USING_HDMI_H
#define _USING_HDMI_H

/* Config file */

// this is what your main screen is called, see man xrandr
#define MAIN_ADAPTER "LVDS-1"

// this is what adapter you are trying to control
#define SECONDARY_ADAPTER "HDMI-1"

// low resolution - for older TVs
#define LOW_RES "1024x768"

// high resolution - for everything else
#define HIGH_RES "1920x1080"

// screen directions
#define LEFT "--left-of"
#define RIGHT "--right-of"
#define TOP "--top-of"
#define SAME "--same-as"

// program to invoke (default xrandr)
#define PROGRAM "xrandr"

// other flags
#define MODE "--mode"
#define OUTPUT "--output"

// max command size
#define MAX 1024

// smallest arg size, should be the size of the largest input +1
#define SMALL_MAX 12

// help text
#define HELP "usage: hdmi <direction/list> <resolution>\n(left/right/top/same) (low/high/<custom>)"

// list command (lists possible resolutions)
#define LIST_CMD PROGRAM " | grep -Eo '[0-9]{1,4}x[0-9]{1,4}' | sort -u -n"

#endif
