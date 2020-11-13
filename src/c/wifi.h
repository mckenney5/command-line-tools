#ifndef _USING_W_H
#define _USING_W_H

#define ADAPTER "wlp1s0"

#define ENABLE_ADAPTER_SCRIPT "ip link set " ADAPTER " up"

#define SCAN_SCRIPT "iw " ADAPTER " scan | grep \"SSID: \" | sort -u"

#define CONNECT_SCRIPT "wpa_supplicant -B -Dwext -i" ADAPTER " -c/etc/wpa_supplicant.conf && dhclient " ADAPTER

#define ONLINE_SCRIPT "if [ -z $(for i in `ip r`; do echo $i; done |grep -A 1 src | tail -n1) ] then echo FAIL. else echo Online"

#endif
