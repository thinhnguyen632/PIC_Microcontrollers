#include <tv_kit_vdk_18f6722_all.c>
usi8 giay_tam;
unsigned int8 tt_ht;

void h518_gpg_hien_thi_binh_thuong()
{
   giaima_bcd_2so_vitri_vn(giay_ds,0,kx_vn);
   giaima_bcd_2so_vitri_vn(phut_ds,3,kx_vn);
   giaima_bcd_2so_vitri_vn(gio_ds,6,kx_vn);
   xuat_8led_7doan();
}

void ntn_hien_thi_binh_thuong()
{
   giaima_bcd_2so_vitri_vn(time_r[4],6,kx_vn);//ngay
   giaima_bcd_2so_vitri_vn(time_r[5],3,kx_vn);//thang
   giaima_bcd_2so_vitri_vn(time_r[6],0,kx_vn);//nam
   xuat_8led_7doan();
}

void thu_hien_thi_binh_thuong()
{
   led_7d[3]=0xff; 
   led_7d[4]=0xff;
   led_7d[6]=0xff; 
   led_7d[7]=0xff;
   giaima_bcd_2so_vitri_vn(time_r[3],0,kx_vn);//thu
   xuat_8led_7doan();
}


void kt_bt3()
{
   if(phim_bt3_c1(c_ktnp,150)==co_nhan)
   {
      if (tt_ht<2)   tt_ht++;
      else           tt_ht=0;
   }
}

void kt_tt_ht()
{
   if (tt_ht==0)  h518_gpg_hien_thi_binh_thuong();
   if (tt_ht==1)  ntn_hien_thi_binh_thuong();
   if (tt_ht==2)  thu_hien_thi_binh_thuong();
}

void main()
{
   set_up_port();
   ds1307_kiem_tra_ma();
   tt_ht=0;
   while(true)
   {
      ds1307_doc_time(8);
      kt_bt3();
      if(giay_tam!=giay_ds)
      {
         giay_tam=giay_ds;
         kt_tt_ht();
      }
   }
}
