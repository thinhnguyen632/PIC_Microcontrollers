#include <tv_kit_vdk_18f6722_all.c> 
void b316_32led_1dst_mp(usi16 dl) 
{
   usi8 i, j; usi32 x, dt;
   x = 0xffffffff;
   dt = 1;
   for (i = 0; i < 32; i++)
   {
   xuat_32led_don_1dw(x);
   delay_ms(dl);
   for (j = i; j < 32; j++)
   {
      if (i==0) {x=x<<1; xuat_32led_don_1dw(x); delay_ms(dl);}
      if (i>0) 
      {
         x=(x<<1) + dt;
         xuat_32led_don_1dw(x);
         delay_ms(dl);
      }
      x = x<<1;
      dt = dt<<1;
      delay_ms(dl);
   }
   
   }
}

void main()
{ 
   set_up_port();
   while(true)
   { 
      b316_32led_1dst_mp(40);
   } 
}
