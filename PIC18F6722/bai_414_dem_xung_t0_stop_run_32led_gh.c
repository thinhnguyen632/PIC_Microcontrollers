#include <tv_kit_vdk_18f6722_all.c>
#include <bai_411_t0_tv.c>

void kt_bt()
{
   if(phim_run_c2(150)==co_nhan)
   {
      setup_timer_0(t0_ext_l_to_h|t0_div_1);
      set_timer0(0); t0_tam = 1; g_han=g_han;
      xuat_32led_don_4byte(0,0,0xff,0xff);
   }
   if(phim_stop_c2(150)==co_nhan)
   {
      setup_timer_0(t0_off|t0_div_1);
      set_timer0(0); t0_tam = 1; g_han=50;
      t0=0;
      xuat_32led_don_4byte(0,0,0,0);
   }
   delay_ms(200);
}

void b406_up_dw_g_han()
{
   if(phim_bt2_c2(150)==co_nhan)
   {
      if(g_han<99)
      {
         g_han++;
         b411_hienthi_4led7doan();
      }
      else 
      {
         g_han=0;
         b411_hienthi_4led7doan();
      }
   }
   if(phim_bt3_c2(150)==co_nhan)
   {
      if(g_han>0)
      {
         g_han--;
         b411_hienthi_4led7doan();
      }
      else 
      {
         g_han=99;
         b411_hienthi_4led7doan();
      }
   }
}

void main()
{
   set_up_port();
   setup_timer_0(t0_off|t0_div_1);
   set_timer0(0); t0_tam = 1; g_han=50;
   t0=0;
   b411_hienthi_4led7doan();
   while(true)
   {
      b406_up_dw_g_han();
      kt_bt();
      b411_dem_sp_t0();
   }
}
