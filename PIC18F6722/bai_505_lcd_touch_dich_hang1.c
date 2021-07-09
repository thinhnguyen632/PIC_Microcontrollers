#include <tv_kit_vdk_18f6722_all.c>
unsigned int8 hang1[20];
unsigned int8 mp,i;

void xoa_hang_1()
{
   for(i=0; i<20; i++)  hang1[i]=" ";
}

void lcd_dich_ht_mp()
{
   for(i=0; i<19; i++)  hang1[i]=hang1[i+1];
   mp = mp%16;
   if(mp<10)   hang1[19]=(mp+0x30);
   else        hang1[19]=(mp+0x37);
   lcd_goto_xy(1,0);
   for (i=0; i<20; i++) lcd_data(hang1[i]);
}

void main()
{
   set_up_port();
   lcd_setup();
   lcd_goto_xy(0,0);
   lcd_data("hay nhan phim bat ky");
   xoa_hang_1();
   while(true)
   {
      mp = key_tip229_cdoi_c2(10);
      if(mp!=0xff)
      {
         lcd_dich_ht_mp();
         delay_ms(200);
      }
   }
}
