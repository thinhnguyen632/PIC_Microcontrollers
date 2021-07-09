#include <tv_kit_vdk_18f6722_all.c> 
void b311_32led_sd_pst(usi16 dl) 
{
   usi8 i, j; usi32 x, xd, don;
   xd = 0;
   for (j = 0; j < 32; j++)
   {
      don = 1;//0000 0000 0000 0000 0000 0000 0000 0001
      for (i = j; i < 32; i++)
      {
         x = don + xd;//0000 0000 0000 0000 0000 0000 0000 0000 + 0000 0000 0000 0000 0000 0000 0000 0001
         xuat_32led_don_1dw(x);
         delay_ms(dl);
         don = (don << 1);// 0000 0000 0000 0000 0000 0000 0000 0010
      }
      xd = x;
   }
}

void main()
{ 
   set_up_port();
   while(true)
   { 
      b311_32led_sd_pst(40);
   } 
}
