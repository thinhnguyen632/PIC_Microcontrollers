#include <tv_kit_vdk_18f6722_all.c>
#include <bai_411_t0_tv.c>

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
