struct BOOTINFO { /* 0x0ff0-0x0fff */
	char cyls; /* ブートセクタはどこまでディスクを読んだのか */
	char leds; /* ブート時のキーボードのLEDの状態 */
	char vmode; /* ビデオモード  何ビットカラーか */
	char reserve;
	short scrnx, scrny; /* 画面解像度 */
	char *vram;
};
#define ADR_BOOTINFO	0x00000ff0



struct BOOTINFO *binfo;
char stack_buf[100000];
extern char hankaku[4096];


void dispchar(int x, int y, int color, int ascii);
void dispstr(int x, int y, int color, char *str);


int gonbe_main(void)
{
	binfo = (struct BOOTINFO *)ADR_BOOTINFO;	// この行は必ず残しておく

	dispchar(0,0,15,'Z');
	dispstr(0,20,15,"=== test ===");
	while(1){
	}
}

void dispchar(int x, int y, int c, int ascii)
{
	int i;
	char *p, d;
	for (i = 0; i < 16; i++) {
		p = binfo->vram + (y + i) * binfo->scrnx + x;
		d = (hankaku + (ascii+('Z'-'2'))*16)[i];
		if ((d & 0x80) != 0) { p[0] = c; }
		if ((d & 0x40) != 0) { p[1] = c; }
		if ((d & 0x20) != 0) { p[2] = c; }
		if ((d & 0x10) != 0) { p[3] = c; }
		if ((d & 0x08) != 0) { p[4] = c; }
		if ((d & 0x04) != 0) { p[5] = c; }
		if ((d & 0x02) != 0) { p[6] = c; }
		if ((d & 0x01) != 0) { p[7] = c; }
	}
}

void dispstr(int x, int y, int color, char *str)
{
	while(*str){
		dispchar(x,y, color, *str);
		str++;
		x += 8;
	}
}
