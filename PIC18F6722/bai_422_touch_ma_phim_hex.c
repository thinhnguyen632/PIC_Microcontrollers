#include <tv_kit_vdk_18f6722_all.c>
unsigned int8 mp8;
const unsigned char ma7doan_hex[7]={0x88,0x83,0xc6,0xa1,0x86,0x8e,0xc0};


void b421_ttp229_doc_16phim() 
{ 
   mp8 = key_tip229_cdoi_c2(10); 
   if((mp8>0)&&(mp8<10)) 
   { 
      giaima_bin_2so_vitri_vn(mp8,0,kx_vn);
      xuat_8led_7doan();
   }
   if((mp8>9)&&(mp8<17))//10 11 12 13 14 15 16
   {
      led_7d[0]=ma7doan_hex[mp8-10];
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
