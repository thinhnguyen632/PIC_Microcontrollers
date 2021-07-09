#include <tv_kit_vdk_18f6722_all.c>
unsigned int8 mp8;

void b421_ttp229_doc_16phim() 
{ 
   mp8 = key_tip229_cdoi_c2(10); 
   if((mp8>0)&&(mp8<17)) 
   { 
      xuat_32led_don_4byte(0,0,0,mp8);
      giaima_bin_2so_vitri_vn(mp8,0,kx_vn);
      xuat_8led_7doan();
   } 
}

void main()
{
   set_up_port();
   while(true)
   {
      b421_ttp229_doc_16phim();
   }
}
