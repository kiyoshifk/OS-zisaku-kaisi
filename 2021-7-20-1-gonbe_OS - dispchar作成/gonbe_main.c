#include "gonbe.h"
#include "function.h"


//struct BOOTINFO { /* 0x0ff0-0x0fff */
//	char cyls; /* ブートセクタはどこまでディスクを読んだのか */
//	char leds; /* ブート時のキーボードのLEDの状態 */
//	char vmode; /* ビデオモード  何ビットカラーか */
//	char reserve;
//	short scrnx, scrny; /* 画面解像度 */
//	char *vram;
//};
//#define ADR_BOOTINFO	0x00000ff0



struct BOOTINFO *binfo;
char stack_buf[100000];
extern char hankaku[4096];

char title[]="=== test ===";
char a=1;

void init();

int gonbe_main(void)
{
	init();
	
	text_color = 15;
	dispchar(100,20,'A');
	text_color = 3;
	dispstr(0,30,title);
	while(1){
	}
}

void init()
{
	binfo = (struct BOOTINFO *)ADR_BOOTINFO;	// この行は必ず残しておく
	dispinit();
}
