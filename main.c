#include <LPC17xx.h>
#include <stdlib.h>
#include "stdio.h"
#include "stdarg.h"
#include "type.h"
#include "GLCD.h"
#include "GLCD_Scroll.h"
#include "half_fit.h"

void displayf(const char *format, ...) {
	char str[100];
	va_list args;
	va_start(args, format);
	vsprintf(str, format, args);
	va_end(args);
	//print_string(str);
}

int main2( void ) {
	
	void* blocks[10];
	
	SystemInit();
	
	printf("Started\n");
	
	half_init();
	
	printf("Init'd\n");
	
	blocks[0] = half_alloc(6112);
	
	printf("Block 0: 0x%08x\n", (int) blocks[0]);
	
	blocks[1] = half_alloc(3300);
	
	printf("Block 1: 0x%08x\n", (int) blocks[1]);
	
	blocks[2] = half_alloc(8572);
	
	printf("Block 2: 0x%08x\n", (int) blocks[2]);
	
	half_free(blocks[0]);
	
	half_free(blocks[2]);
	
	blocks[3] = half_alloc(2540);
	
	printf("Block 3: 0x%08x\n", (int) blocks[3]);
	
	half_alloc(15990);
	
	half_free(blocks[0]);
	
	while ( 1 );
}
