#include <3ds.h>
#include <stdio.h>
#include "libsu.h"

int main(int argc, char **argv) {
    gfxInitDefault();
	sdmcInit();
    consoleInit(GFX_TOP, NULL);
	
	printf("Arm11 exploit demo, get access to am:u service\n\n");
    if(suInit() == 0)
	{
		Result res = amInit();
		printf("am:u init : %08X\n", res);
	}
	
    printf("Press START to exit.\n");

    while(aptMainLoop()) {
        hidScanInput();
        if(hidKeysDown() & KEY_START) {
            break;
        }

        gfxFlushBuffers();
        gfxSwapBuffers();
        gspWaitForVBlank();
    }

    gfxExit();
	sdmcExit();
	amExit();
    return 0;
}
