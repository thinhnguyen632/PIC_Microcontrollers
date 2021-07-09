#include <tv_kit_vdk_18f6722_all.c> 
void b306_32led_std_tnv(usi16 dl) 
{ 
   usi8 i; usi16 LT,LP;
   LT = 0; LP = 0;
   for (i=0;i<16;i++)
   {
      LT = (LT>>1) + 0X8000;
      LP = (LP<<1) + 1;
      xuat_32led_don_2word(LT,LP);
      delay_ms(dl);
   }
   for (i=0;i<16;i++)
   {
      LT = (LT>>1);
      LP = (LP<<1);
      xuat_32led_don_2word(LT,LP);
      delay_ms(dl);
   }
}

void main()
{ 
   set_up_port();
   while(true)
   { 
      b306_32led_std_tnv(40);
   } 
}
