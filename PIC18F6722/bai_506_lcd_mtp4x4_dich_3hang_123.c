#include <tv_kit_vdk_18f6722_all.c>
unsigned int8 hang1[20],hang2[20],hang3[20],temp1,temp2;
unsigned int8 mp,i,dem=0;

void xoa_hang_1()
{
   for(i=0; i<20; i++)  hang1[i]=" ";
}
void xoa_hang_2()
{
   for(i=0; i<20; i++)  hang2[i]=" ";
}
void xoa_hang_3()
{
   for(i=0; i<20; i++)  hang3[i]=" ";
}

void lcd_dich_ht_mp()
{
   for(i=0; i<19; i++)  hang1[i]=hang1[i+1];
   mp = mp%16;
   if(mp<10)   hang1[19]=(mp+0x30);
   else        hang1[19]=(mp+0x37);
   lcd_goto_xy(1,0);
   for (i=0; i<20; i++) lcd_data(hang1[i]);
   
   for(i=0; i<19; i++)  hang2[i]=hang2[i+1];
   if(dem<20)
   {
      hang2[19]=" ";
   }
   else
   {
      hang2[19]=temp1;
   }
   lcd_goto_xy(2,0);
   for (i=0; i<20; i++) lcd_data(hang2[i]);
   
   for(i=0; i<19; i++)  hang3[i]=hang3[i+1];
   if(dem<20)
   {
      hang3[19]=" ";
   }
   else
   {
      hang3[19]=temp2;
   }
   lcd_goto_xy(3,0);
   for (i=0; i<20; i++) lcd_data(hang3[i]);
}

void main()
{
   set_up_port();
   lcd_setup();
   lcd_goto_xy(0,0);
   lcd_data("hay nhan phim bat ky");
   xoa_hang_1();
   xoa_hang_2();
   xoa_hang_3();
   while(true)
   {
      mp = key_tip229_cdoi_c2(10);
      if(mp!=0xff)
      {
         lcd_dich_ht_mp();
         delay_ms(200);
         dem++;
         temp1=hang1[0];
         temp2=hang2[0];
      }
   }
}
