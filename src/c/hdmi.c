#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hdmi.h"

int syntax_error(){
	fprintf(stderr, "%s\n", HELP);
	return 1;
}

int main(int argc, char** argv){
	char cmd[MAX] = {'\0'};
	char res[SMALL_MAX] = {'\0'};
	char direction[SMALL_MAX] = {'\0'};

	if(argc == 1){
		snprintf(cmd, MAX, "'%s %s %s %s %s %s %s'", PROGRAM, OUTPUT, SECONDARY_ADAPTER, MODE, LOW_RES, TOP, MAIN_ADAPTER);
		puts(cmd);
		return 0;
	} else if(argc == 2 && !strcmp(argv[1], "list")){
		return system(LIST_CMD);
	} else if(argc != 3){
		return syntax_error();
	} else {
		if(!strcmp(argv[1], "left")) strncpy(direction, LEFT, SMALL_MAX-1);
		else if(!strcmp(argv[1], "right")) strncpy(direction, RIGHT, SMALL_MAX-1);
		else if(!strcmp(argv[1], "top")) strncpy(direction, TOP, SMALL_MAX-1);
		else if(!strcmp(argv[1], "same")) strncpy(direction, SAME, SMALL_MAX-1);
		else return syntax_error();
		
		if(!strcmp(argv[2], "low")) strncpy(res, LOW_RES, SMALL_MAX-1);
		else if(!strcmp(argv[2], "high") || !strcmp(argv[1], "hi")) strncpy(res, HIGH_RES, SMALL_MAX-1);
		else if(strlen(argv[2]) <= SMALL_MAX-1) strncpy(res, argv[2], SMALL_MAX-1);
		else return syntax_error();

		snprintf(cmd, MAX, "%s %s %s %s %s %s %s", PROGRAM, OUTPUT, SECONDARY_ADAPTER, MODE, res, direction, MAIN_ADAPTER);
		return system(cmd);
	}
}

