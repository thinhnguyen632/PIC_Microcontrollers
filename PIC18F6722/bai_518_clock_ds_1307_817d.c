#include <tv_kit_vdk_18f6722_all.c>
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
   while(true)
   {
      ds1307_doc_time(8);
      if(giay_tam!=giay_ds)
      {
         giay_tam=giay_ds;
         h518_gpg_hien_thi_binh_thuong();
      }
      delay_ms(500);
   }
}
