#include <tv_kit_vdk_18f6722_all.c>
unsigned int16 y;
unsigned int1 tt_clr;

void phim_up()
{
   delay_ms(20);
   {
      if(!input(up))
      {
         if (tt_clr==0)
         {
            y=(y<<1)+1;
            xuat_32led_don_2word(0,y);
         }
         else if (tt_clr==1)
         {
            y=(y>>1)+0x8000;
            xuat_32led_don_2word(0,y);
         }
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
         if(tt_clr==0)
         {
            y=(y>>1);
            xuat_32led_don_2word(0,y);
         }
         else if(tt_clr==1)
         {
            y=(y<<1);
            xuat_32led_don_2word(0,y);
         }
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
         tt_clr=~tt_clr;
      }
      while(!input(clr));
   }
}

void main()
{
   set_up_port();
   y=0x0000;
   tt_clr=0;
   while(true)
   {
      phim_up();
      phim_dw();
      phim_clr();
   }
}
