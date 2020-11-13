#!/bin/bash
# starts wifi
echo "Turnind adapter on"
sudo ip link set wlp1s0 up
echo "Showing networks"
sudo iw wlp1s0 scan | grep SSID:
echo "Attempting to connect to known networks"
sudo wpa_supplicant -B -Dwext -iwlp1s0 -c/etc/wpa_supplicant.conf
echo "Attempting IP address request"
sudo dhclient wlp1s0
echo "Done."

