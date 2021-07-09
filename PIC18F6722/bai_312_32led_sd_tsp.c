#include <tv_kit_vdk_18f6722_all.c> 
void b312_32led_sd_tsp(usi16 dl) 
{
   usi8 i, j; usi32 x, xd, don;
   xd = 0;
   for (j = 0; j < 32; j++)
   {
      don = 0x80000000;
      for (i = j; i < 32; i++)
      {
         x = don + xd;
         xuat_32led_don_1dw(x);
         delay_ms(dl);
         don = (don >> 1);
      }
      xd = x;
   }
}

void main()
{ 
   set_up_port();
   while(true)
   { 
      b312_32led_sd_tsp(40);
   } 
}
