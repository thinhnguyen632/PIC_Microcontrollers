#include <tv_kit_vdk_18f6722_all.c>
unsigned int8 mp8;

void h423_dtsp_8led_7doan()// 7 6 5 4 3 2 1 0 //  
{
   for(int i=0; i<7; i++)
      led_7d[i] = led_7d[i+1];
}

void b423_doc_16phim_single_dtsp_8led()
{
   mp8 = key_tip229_cdoi_c2(10);
   if ((mp8>0)&&(mp8<17))
   {
      h423_dtsp_8led_7doan();
      led_7d[7] = ma7doan[mp8%16];
      xuat_8led_7doan();
      delay_ms(500);
   }
}

void main()
{
   set_up_port();
   while(true)
   {
      b423_doc_16phim_single_dtsp_8led();
   }
}
