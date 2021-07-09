#include <tv_kit_vdk_18f6722_all.c>

unsigned int8 t0, t0_tam, g_han;
unsigned int8 g_han_lcd[2], t0_lcd[2];
unsigned int i;
unsigned int chuky;
unsigned int rong[]={"                    "};

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
   lcd_goto_xy(1,0);
   for (i=0;i<2;i++)
   {
      lcd_data(g_han_lcd[i]);
   }
   t0_lcd[1] = (t0%10)+0x30;
   t0_lcd[0] = (t0/10)+0x30;
   lcd_goto_xy(1,18);
   for (i=0;i<2;i++)
   {
      lcd_data(t0_lcd[i]);
   }
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

void hienthi_lcd_chnho_dvto()
{
   g_han_lcd[0] = (g_han/10)+0x30;
   lcd_goto_xy(1,0); lcd_data(g_han_lcd[0]);
   g_han_lcd[1] = (g_han%10);
   lcd_hien_thi_so_to(g_han_lcd[1],1,1);
   
   t0_lcd[0] = (t0/10)+0x30;
   lcd_goto_xy(1,16); lcd_data(t0_lcd[0]);
   t0_lcd[1] = (t0%10);
   lcd_hien_thi_so_to(t0_lcd[1],1,17);
}

void hienthi_lcd_chto_dvnho()
{
   g_han_lcd[0] = (g_han/10);
   lcd_hien_thi_so_to(g_han_lcd[0],1,0);
   g_han_lcd[1] = (g_han%10)+0x30;
   lcd_goto_xy(1,3); lcd_data(g_han_lcd[1]);
   
   t0_lcd[0] = (t0/10);
   lcd_hien_thi_so_to(t0_lcd[0],1,16);
   t0_lcd[1] = (t0%10)+0x30;
   lcd_goto_xy(1,19); lcd_data(t0_lcd[1]); 
}

void reset_lcd()
{
   lcd_puts(0,0,rong);
   lcd_puts(1,0,rong);
   lcd_puts(2,0,rong);
   lcd_puts(3,0,rong);
}

void kt_chuky()
{
   
   if(chuky==0)
   {
      reset_lcd();
      b508_hienthi_lcd();
   }
   if(chuky==1)  
   {
      reset_lcd();
      hienthi_lcd_so_to();
   }
   if(chuky==2)
   {
      reset_lcd();
      hienthi_lcd_chnho_dvto();
   }
   if(chuky==3)
   {
      reset_lcd();
      hienthi_lcd_chto_dvnho();
   }
}

void b411_dem_sp_t0()
{
   t0 = get_timer0();
   if(t0_tam!=t0)
   {
      t0_tam = t0;
      b411_hienthi_4led7doan();
      kt_chuky();
      if (t0>=g_han)
      {
         set_timer0(0);
         buzzer_on_off(300);
         if(chuky<3) chuky++;
         else        chuky=0;
      }
   }
}

void main()
{
   set_up_port();
   setup_timer_0(t0_ext_l_to_h|t0_div_1);
   set_timer0(0); t0_tam = 1; g_han=15;
   
   lcd_setup();
   
   lcd_khoi_tao_cgram_so_to();
   
   chuky=0;
   
   while(true)
   {
      b411_dem_sp_t0();
   }
}
