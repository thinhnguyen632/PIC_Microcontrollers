#include <tv_kit_vdk_18f6722_all.c>
unsigned int8 t0, t0_tam, g_han;
unsigned int8 g_han_lcd[2], t0_lcd[2];
unsigned int i;

#include <18f6722.h>

void b411_hienthi_4led7doan()
{
   giaima_bin_2so_vitri_vn(t0,0,cx_vn);
   giaima_bin_2so_vitri_vn(g_han,6,cx_vn);
   xuat_8led_7doan();
}

void b508_hienthi_lcd()
{
   g_han_lcd[1] = (g_han%10)+0x30;
   g_han_lcd[0] = (g_han/10)+0x30;
   lcd_goto_xy(0,0);
   for (i=0;i<2;i++)
   {
      lcd_data(g_han_lcd[i]);
   }
   t0_lcd[1] = (t0%10)+0x30;
   t0_lcd[0] = (t0/10)+0x30;
   lcd_goto_xy(1,0);
   for (i=0;i<2;i++)
   {
      lcd_data(t0_lcd[i]);
   }
}

void b411_dem_sp_t0()
{
   t0 = get_timer0();
   if(t0_tam!=t0)
   {
      t0_tam = t0;
      b411_hienthi_4led7doan();
      b508_hienthi_lcd();
      if (t0>=g_han)
      {
         set_timer0(0);
         buzzer_on_off(300);
      }
   }
}

void kt_bt()
{
   if(phim_run_c2(150)==co_nhan)
   {
      setup_timer_0(t0_ext_l_to_h|t0_div_1);
      set_timer0(0); t0_tam = 1; g_han=50;
      xuat_32led_don_4byte(0,0,0xff,0xff);
   }
   if(phim_stop_c2(150)==co_nhan)
   {
      setup_timer_0(t0_off|t0_div_1);
      set_timer0(0); t0_tam = 1; g_han=50;
      t0=0;
      xuat_32led_don_4byte(0,0,0,0);
   }
}

void main()
{
   set_up_port();
   
   lcd_setup();
   
   setup_timer_0(t0_off|t0_div_1);
   set_timer0(0); t0_tam = 1; g_han=50;
   t0=0;
   b411_hienthi_4led7doan();
   while(true)
   {
      kt_bt();
      b411_dem_sp_t0();
   }
}
