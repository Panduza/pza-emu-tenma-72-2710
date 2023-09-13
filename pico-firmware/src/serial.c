/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pico/stdlib.h"


typedef struct{
	char version[32];
	uint8_t state;
	float current;
	float voltage;
}Tenma_t;
	
#define STATE_ON "@"
#define STATE_OFF "!@"

int main() {

	Tenma_t tenma={.version="TENMA 72-2710 V6.8 SN:03265065", .state=0, .current=0.f, .voltage=0.f};
	char serial_input[10], *current_substring, *voltage_substring;
	
	stdio_init_all();

	while (true) {
		scanf("%s",serial_input);
        	if (!strcmp(serial_input,"*IDN?"))
        	{
        		printf("%s\n", tenma.version);
        	} 
        	else if (!strcmp(serial_input,"STATUS?"))
        	{
        		if (0 == tenma.state)
        			printf("%s\n", STATE_OFF);
        		else
        			printf("%s\n", STATE_ON);
        	}
        	else if (!strcmp(serial_input,"OUT0"))
        	{
			tenma.state = 0;
        	}
        	else if (!strcmp(serial_input,"OUT1"))
        	{
			tenma.state = 1;
        	}
        	else if (!strcmp(serial_input,"ISET1?"))
        	{
			printf("%f\n", tenma.current);
        	}
        	else if (!strcmp(serial_input,"VSET1?"))
        	{
			printf("%f\n", tenma.voltage);
        	}
        	else if (strstr(serial_input,"ISET1") != NULL)
        	{
        		current_substring = serial_input + 6;
			tenma.current = atof(current_substring) ;
        	}
        	else if (strstr(serial_input,"VSET1") != NULL)
        	{
        		voltage_substring = serial_input + 6;
			tenma.voltage = atof(voltage_substring) ;
        	}
    	}
	return 0;
}
