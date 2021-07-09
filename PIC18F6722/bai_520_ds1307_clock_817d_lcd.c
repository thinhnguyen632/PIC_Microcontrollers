#include <tv_kit_vdk_18f6722_all.c>
#include <bai_520_ds1307_clock_817d_lcd_tv.c>
usi8 giay_tam;

void h518_gpg_hien_thi_binh_thuong()
{
   giaima_bcd_2so_vitri_vn(giay_ds,0,kx_vn);
   giaima_bcd_2so_vitri_vn(phut_ds,3,kx_vn);
   giaima_bcd_2so_vitri_vn(gio_ds,6,kx_vn);
   xuat_8led_7doan();
}

void main()
{
   set_up_port();
   ds1307_kiem_tra_ma();
   
   lcd_setup();
   lcd_khoi_tao_cgram_so_to();
   lcd_goto_xy(0,0);
   ds1307_hthi_text_lcd();
   ds1307_hthi_thu_lcd();
   ds1307_hthi_giay_lcd_soto();
   ds1307_hthi_phut_lcd_soto();
   ds1307_hthi_gio_lcd_soto();
   ds1307_hthi_ntn_lcd();
   
   while(true)
   {
      ds1307_doc_time(8);
      if(giay_tam!=giay_ds)
      {
         giay_tam=giay_ds;
         h518_gpg_hien_thi_binh_thuong();
         ds1307_hthi_lcd_soto();
      }
      delay_ms(500);
   }
}
