unsigned int8 t0, t0_tam, g_han;
void b411_hienthi_4led7doan()
{
   giaima_bin_2so_vitri_vn(t0,0,cx_vn);
   giaima_bin_2so_vitri_vn(g_han,6,cx_vn);
   xuat_8led_7doan();
}

void b411_dem_sp_t0()
{
   t0 = get_timer0();
   if(t0_tam!=t0)
   {
      t0_tam = t0;
      b411_hienthi_4led7doan();
      if (t0>=g_han)
      {
         set_timer0(0);
         buzzer_on_off(300);
      }
   }
}
