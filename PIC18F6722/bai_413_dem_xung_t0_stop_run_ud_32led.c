#include <tv_kit_vdk_18f6722_all.c>
#include <bai_411_t0_tv.c>

unsigned int8 tt_dem=0;
unsigned int1 tt_ct=0;

void b411_dem_sp_t0_demxuong()
{
   t0 = g_han - get_timer0();
   if(t0_tam!=t0)
   {
      t0_tam = t0;
      b411_hienthi_4led7doan();
      if (t0<=0)
      {
         set_timer0(0);
         buzzer_on_off(300);
      }
   }
}

void kt_bt_ud()
{
   if(tt_ct==1)
   {
      if(phim_ud_c2(150)==co_nhan)
      {
         if(tt_dem<3)
         {
            tt_dem++;
         }
         else tt_dem=0;
      }
   }
}

void kt_bt()
{
   if(phim_run_c2(150)==co_nhan)
   {
      setup_timer_0(t0_ext_l_to_h|t0_div_1);
      set_timer0(0); t0_tam = 1; g_han=50;
      t0=0;
      xuat_32led_don_4byte(0,0,0xff,0xff);
      tt_ct=1;
      tt_dem=0;
   }
   
   if(phim_stop_c2(150)==co_nhan)
   {
      setup_timer_0(t0_off|t0_div_1);
      set_timer0(0); t0_tam = 1; g_han=50;
      t0=0;
      xuat_32led_don_4byte(0,0,0,0);
      tt_ct=0;
      tt_dem=0;
   }
}

void kt_tt_dem()
{
   if(tt_ct==1)
   {
      if(tt_dem==1)
      {
         b411_dem_sp_t0();
         xuat_32led_don_4byte(0xff,0,0xff,0xff);
      }
      if(tt_dem==2)
      {
         b411_dem_sp_t0_demxuong();
         xuat_32led_don_4byte(0,0xff,0xff,0xff);
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
      kt_bt();
      kt_bt_ud();
      kt_tt_dem();
   }
}

//setup_timer_0(t0_ext_l_to_h|t0_div_1);
//set_timer0(0); t0_tam = 1; g_han=50;
