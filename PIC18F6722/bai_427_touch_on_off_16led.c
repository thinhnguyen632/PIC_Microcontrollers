#include <tv_kit_vdk_18f6722_all.c>
unsigned int8 mp8;
unsigned char led_don_0[8]={0,0,0,0,0,0,0,0};
unsigned char led_don_1[8]={0,0,0,0,0,0,0,0};
unsigned int8 x0, x1;

void doc_led_don() 
{
   x0 = led_don_0[0]<<7 | led_don_0[1]<<6 | led_don_0[2]<<5 | led_don_0[3]<<4 | led_don_0[4]<<3 | led_don_0[5]<<2 | led_don_0[6]<<1 | led_don_0[7]<<0;
   x1 = led_don_1[0]<<7 | led_don_1[1]<<6 | led_don_1[2]<<5 | led_don_1[3]<<4 | led_don_1[4]<<3 | led_don_1[5]<<2 | led_don_1[6]<<1 | led_don_1[7]<<0;
}

void doc_mp()
{
   mp8 = key_tip229_cdoi_c2(10);
   if ((mp8>0)&&(mp8<9))// 1 2 3 4 5 6 7 8
   {
      if (led_don_0[8-mp8]==0)
      {
         led_don_0[8-mp8]=1;
      }
      else
      {
         led_don_0[8-mp8]=0;
      }
      doc_led_don();
      xuat_32led_don_4byte(0,0,x1,x0);
      delay_ms(200);
   }
   if ((mp8>8)&&(mp8<17))//9 10 11 12 13 14 15 16
   {
      if (led_don_1[16-mp8]==0)
      {
         led_don_1[16-mp8]=1;
      }
      else
      {
         led_don_1[16-mp8]=0;
      }
      doc_led_don();
      xuat_32led_don_4byte(0,0,x1,x0);
      delay_ms(200);
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
