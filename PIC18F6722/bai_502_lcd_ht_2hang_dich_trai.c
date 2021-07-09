#include <tv_kit_vdk_18f6722_all.c>
void main()
{
   set_up_port();
   lcd_setup();
   lcd_goto_xy(0,0);
   lcd_data("khoa dien - dien tu ");
   lcd_goto_xy(1,0);
   lcd_data("bm dientucong nghiep");
   delay_ms(1000);
   while(true)
   {
      lcd_command(lcd_shift_left);
      delay_ms(1000);
   }
}
