#include <tv_kit_vdk_18f6722_all.c>
unsigned int8 t0, t0_tam, g_han;
unsigned int8 g_han_lcd[2], t0_lcd[2];

void b411_hienthi_4led7doan()
{
   giaima_bin_2so_vitri_vn(t0,0,cx_vn);
   giaima_bin_2so_vitri_vn(g_han,6,cx_vn);
   xuat_8led_7doan();
}

void hienthi_lcd_so_to()
{
   g_han_lcd[1] = (g_han%10);
   g_han_lcd[0] = (g_han/10);
   lcd_hien_thi_so_to(g_han_lcd[0],1,0);
   lcd_hien_thi_so_to(g_han_lcd[1],1,3);

   t0_lcd[1] = (t0%10);
   t0_lcd[0] = (t0/10);
   lcd_hien_thi_so_to(t0_lcd[0],1,14);
   lcd_hien_thi_so_to(t0_lcd[1],1,17);
}

void b411_dem_sp_t0()
{
   t0 = get_timer0();
   if(t0_tam!=t0)
   {
      t0_tam = t0;
      b411_hienthi_4led7doan();
      hienthi_lcd_so_to();
      if (t0>=g_han)
      {
         set_timer0(0);
         buzzer_on_off(300);
      }
   }
}

void main()
{
   set_up_port();
   
   setup_timer_0(t0_ext_l_to_h|t0_div_1);
   set_timer0(0); t0_tam = 1; g_han=50;
   
   lcd_setup();
   
   lcd_khoi_tao_cgram_so_to();
   
   while(true)
   {
      b411_dem_sp_t0();
   }
}
