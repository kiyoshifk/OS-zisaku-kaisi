#include "gonbe.h"
#include "function.h"


//struct BOOTINFO { /* 0x0ff0-0x0fff */
//	char cyls; /* �u�[�g�Z�N�^�͂ǂ��܂Ńf�B�X�N��ǂ񂾂̂� */
//	char leds; /* �u�[�g���̃L�[�{�[�h��LED�̏�� */
//	char vmode; /* �r�f�I���[�h  ���r�b�g�J���[�� */
//	char reserve;
//	short scrnx, scrny; /* ��ʉ𑜓x */
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
	binfo = (struct BOOTINFO *)ADR_BOOTINFO;	// ���̍s�͕K���c���Ă���
	dispinit();
}
