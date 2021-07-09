#include <tv_kit_vdk_18f6722_all.c> 
void b315_32led_1dsp_mp(usi16 dl) 
{
   usi8 i, j; usi32 x, dp;
   x = 0xffffffff;
   dp = 0x80000000;
   for (i = 0; i < 32; i++)
   {
   xuat_32led_don_1dw(x);
   delay_ms(dl);
   for (j = i; j < 32; j++)
   {
      if (i==0) {x=x>>1; xuat_32led_don_1dw(x); delay_ms(dl);}
      if (i>0) 
      {
         x=(x>>1) + dp;
         xuat_32led_don_1dw(x);
         delay_ms(dl);
      }
      x = x>>1;
      dp = dp>>1;
      delay_ms(dl);
   }
   
   }
}

void main()
{ 
   set_up_port();
   while(true)
   { 
      b315_32led_1dsp_mp(40);
   } 
}
