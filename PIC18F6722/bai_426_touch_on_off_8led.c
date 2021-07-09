#include <tv_kit_vdk_18f6722_all.c>
unsigned int8 mp8;
unsigned char led_don[8]={0,0,0,0,0,0,0,0};
unsigned int8 x;

void doc_led_don() 
{
   x = led_don[0]<<7 | led_don[1]<<6 | led_don[2]<<5 | led_don[3]<<4 | led_don[4]<<3 | led_don[5]<<2 | led_don[6]<<1 | led_don[7]<<0;
}

void doc_mp()
{
   mp8 = key_tip229_cdoi_c2(10);
   if ((mp8>0)&&(mp8<9))
   {
      led_don[8-mp8]=1;
      doc_led_don();
      xuat_32led_don_4byte(0,0,0,x);
   }
   if ((mp8>8)&&(mp8<17))//9 10 11 12 13 14 15 16
   {
      led_don[16-mp8]=0;
      doc_led_don();
      xuat_32led_don_4byte(0,0,0,x);
   }
}

void main()
{
   set_up_port();
   while(true)
   {
      doc_mp();
   }
}
