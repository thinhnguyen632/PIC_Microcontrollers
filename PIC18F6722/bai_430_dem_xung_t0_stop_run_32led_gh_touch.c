#include <tv_kit_vdk_18f6722_all.c>
unsigned int8 t0, t0_tam,g_han,mp8;

void b412_hienthi_4led7doan()
{
   giaima_bin_2so_vitri_vn(t0,0,kx_vn);
   giaima_bin_2so_vitri_vn(g_han,6,kx_vn);
   xuat_8led_7doan();
}

void h428_hien_thi_gh()
{
   led_7d[7] = ma7doan[bcd_8led[7]];
   led_7d[6] = ma7doan[bcd_8led[6]];
   giaima_bin_2so_vitri_vn(g_han,6,kx_vn);
   xuat_8led_7doan();
}


void dieu_chinh()
{
   mp8 = key_tip229_cdoi_c2(10);
   if((mp8>0) && (mp8<10))
   {
      bcd_8led[7] = bcd_8led[6];
      bcd_8led[6] = mp8;
      delay_ms(200);
      h428_hien_thi_gh();
   }
}




void nut_nhan()
{
   mp8 = key_tip229_cdoi_c2(10);
   if(mp8==13)
   {
      setup_timer_0(t0_ext_l_to_h|t0_div_1);
      xuat_32led_don_2word(0,0xffff); 
   }
   if(mp8==10)
   {
      xuat_32led_don_2word(0,0);
      setup_timer_0(T0_OFF);
   }
}

void b412_dem_sp_t0()
{
   t0 = get_timer0();
   if(t0_tam!=t0)
   {
      t0_tam = t0;
      b412_hienthi_4led7doan();
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
   setup_timer_0(t0_off);
   set_timer0(0); t0_tam = 1; g_han=50;
   xuat_32led_don_2word(0,0);
   while(true)
   {
      dieu_chinh();
      nut_nhan();
      b412_dem_sp_t0();
   }
}
