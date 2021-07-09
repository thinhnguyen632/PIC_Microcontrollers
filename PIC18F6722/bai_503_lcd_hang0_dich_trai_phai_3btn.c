#include <tv_kit_vdk_18f6722_all.c>

unsigned int8 tt_lcd=0;
unsigned char hang0[]={"  HANG    THU    0  "};
unsigned char hang1[]={"  HANG    THU    1  "};
unsigned char hang2[]={"  HANG    THU    2  "};
unsigned char hang3[]={"  HANG    THU    3  "};
unsigned char temp;
unsigned int8 i;

void hienthi_4hang()
{
   lcd_puts(0,0,hang0);
   lcd_puts(1,0,hang1);
   lcd_puts(2,0,hang2);
   lcd_puts(3,0,hang3);
}

void kt_bt()
{
   if(phim_bt0_c2(0)==co_nhan)
   {
      tt_lcd=1; // hang thu 0 dich trai cuon tron
   }
   
   if(phim_bt1_c2(0)==co_nhan)
   {
      tt_lcd=3; // dung
   }
   
   if(phim_bt2_c2(0)==co_nhan)
   {
      tt_lcd=2; // hang thu 0 dich phai cuon tron
   }
}

void kt_tt_lcd()
{
   if(tt_lcd==1)
   {
      temp=hang0[0];
      for (i=0; i<19; i++)
      {
         hang0[i]=hang0[i+1];
      }
      hang0[19]=temp; 
      hienthi_4hang();
      delay_ms(1000);
   }
   if(tt_lcd==2)
   {
      temp=hang0[19];
      for (i=19; i>0; i--)
      {
         hang0[i]=hang0[i-1];
      }
      hang0[0]=temp; 
      hienthi_4hang();
      delay_ms(1000);
   }
   if(tt_lcd==3)
   {
      hienthi_4hang();
   }
}

void main()
{
   set_up_port();
   lcd_setup();
   hienthi_4hang();
   
   while(true)
   {
      kt_bt();
      kt_tt_lcd();
   }
}
