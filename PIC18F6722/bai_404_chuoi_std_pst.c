#include <tv_kit_vdk_18f6722_all.c>

const unsigned char ma7doan_cocacola[30]={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
0xc6,0x88,0x8e,0x86,0xbf,0xc6,0xc0,0xc6,0x88,0xbf,0xc6,0xc0,0xc7,0x88,
0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
//dp gfedcba
//1100 0111 -> L 0xc7
//0xc6,0x88,0x8e,0x86
//C,A,F,E
//0xc6,0xc0,0xc6,0x88,0xc6,0xc0,0xc7,0x88
//C,O,C,A,C,O,L,A
//-
//dp/gfedcba
//10111111 -> 0xbf


void led7doan_hien_thi_cocacola()
{
   for (int i=0; i<22; i++)
   {
      led_7d[7]=ma7doan_cocacola[i];
      led_7d[6]=ma7doan_cocacola[i+1];
      led_7d[5]=ma7doan_cocacola[i+2];
      led_7d[4]=ma7doan_cocacola[i+3];
      led_7d[3]=ma7doan_cocacola[i+4];
      led_7d[2]=ma7doan_cocacola[i+5];
      led_7d[1]=ma7doan_cocacola[i+6];
      led_7d[0]=ma7doan_cocacola[i+7];
      xuat_8led_7doan();
      delay_ms(500);
   }
}


void main()
{
   set_up_port();
   while(true)
   {
      led7doan_hien_thi_cocacola();
   }
}
