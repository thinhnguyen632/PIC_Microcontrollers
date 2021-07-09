#include <tv_kit_vdk_18f6722_all.c>
unsigned int16 y;

void phim_up()
{
   delay_ms(20);
   {
      if(!input(up))
      {
         y=(y<<1)+1;
         xuat_32led_don_2word(0,y);
         while(!input(up));
      }
   }
}

void phim_dw()
{
   delay_ms(20);
   {
      if(!input(dw))
      {
         y=(y>>1);
         xuat_32led_don_2word(0,y);
         while(!input(dw));
      }
   }
}

void phim_clr()
{
   delay_ms(20);
   {
      if(!input(clr))
      {
         xuat_32led_don_2word(0,0);
         y=0;
         while(!input(clr));
      }
   }
}

void main()
{
   set_up_port();
   y=0x0000;
   while(true)
   {
      phim_up();
      phim_dw();
      phim_clr();
   }
}
