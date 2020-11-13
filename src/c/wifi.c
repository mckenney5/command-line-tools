#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wifi.h"

/* Handles wifi connections */

int add_new(){
/* Adds a new connection */
	puts("TODO");
	return 1;
}

void scan(){
/* Scans for SSIDs */
	system(SCAN_SCRIPT);
}

void disable(){

}

void connect(){

}

void init(){
/* Default, connects to the access point */
	system(ENABLE_ADAPTER_SCRIPT);
	system(CONNECT_SCRIPT);
	system(ONLINE_SCRIPT);
}

int main(int argc, char** argv){
	if(argc == 1)
		init();
	else if(!strcmp("add", argv[1]))
		return add_new();
	else if(!strcmp("scan", argv[1]))
		scan();
	else
		puts("usage w (optional) add/scan");
	return 0;
}

