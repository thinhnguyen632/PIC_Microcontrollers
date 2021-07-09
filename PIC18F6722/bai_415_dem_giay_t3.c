#include <tv_kit_vdk_18f6722_all.c>
signed int8 bdn, giay;

#int_timer3
void timer3_ct_con_ngat()
{
   bdn++;
   set_timer3(3036);
}

void h415_dem_giay_timer3()
{
   if (bdn>=10)
   {
      bdn = bdn - 10;
      if (giay<59)   giay++;
      else           giay=0;
      giaima_bin_2so_vitri_vn(giay,0,kx_vn);
      xuat_8led_7doan();
   }
}

void main()
{
   set_up_port();
   enable_interrupts(global);
   enable_interrupts(int_timer3);
   setup_timer_3(t3_internal|t3_div_by_8);
   set_timer3(3036);
   bdn=0; giay=0;
   while(true)
   {
      h415_dem_giay_timer3();
   }
}
