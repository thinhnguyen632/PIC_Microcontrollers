#include <tv_kit_vdk_18f6722_all.c>
void b501_lcd_hien_thi_chuoi()
{
   unsigned char hang0[]={"BO THUC HANH VDK MCU"};
   unsigned char hang1[]={"PIC 16F8722/ARDUINO "};
   unsigned char hang2[]={"NGUYEN DINH PHU SPKT"};
   unsigned char hang3[]={"LIEN HE:  0903982443"};
   unsigned int8 i;
   lcd_goto_xy(0, 0);
   for (i=0; i<20; i++) lcd_data(hang0[i]);
   lcd_goto_xy(1, 0);
   for (i=0; i<20; i++) lcd_data(hang1[i]);
   
   lcd_puts(2,0,hang2);
   lcd_puts(3,0,hang3);
}

void main()
{
   set_up_port();
   lcd_setup();
   while(true)
   {
      b501_lcd_hien_thi_chuoi();
      while(true);
   }
}
