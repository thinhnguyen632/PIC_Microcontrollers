#include <tv_kit_vdk_18f6722_all.c>
signed int8 g_han;
void b406_hienthi_4led7doan()
{
   giaima_bin_2so_vitri_vn(g_han,6,1);
   xuat_8led_7doan();
}

void b406_up_dw_g_han()
{
   if(phim_up_c2(150)==co_nhan)
   {
      if(g_han<99)
      {
         g_han++;
         b406_hienthi_4led7doan();
      }
      else 
      {
         g_han=0;
         b406_hienthi_4led7doan();
      }
   }
   if(phim_dw_c2(150)==co_nhan)
   {
      if(g_han>0)
      {
         g_han--;
         b406_hienthi_4led7doan();
      }
      else 
      {
         g_han=99;
         b406_hienthi_4led7doan();
      }
   }
}

void main()
{
   set_up_port();
   g_han = 50;
   b406_hienthi_4led7doan();
   while(true)
   {
      b406_up_dw_g_han();
   }
}
