#include <tv_kit_vdk_18f6722_all.c>
signed int8 g_han, donvi, chuc;
void b406_hienthi_4led7doan()
{
   g_han = chuc + donvi;
   giaima_bin_2so_vitri_vn(g_han,6,1);
   xuat_8led_7doan();
}

void b406_up_dw_g_han()
{
   if(phim_bt0_c2(150)==co_nhan)
   {
      if(chuc<90)
      {
         chuc = chuc + 10;
         b406_hienthi_4led7doan();
      }
      else
      {
         chuc = 0;
         b406_hienthi_4led7doan();
      }
      
   }
   if(phim_bt2_c2(150)==co_nhan)
   {
      if(donvi<9)
      {
         donvi++;
         b406_hienthi_4led7doan();
      }
      else
      {
         donvi=0;
         chuc = chuc + 10;
         b406_hienthi_4led7doan();
      }
   }
}

void main()
{
   set_up_port();
   chuc = 50;
   donvi = 0;
   g_han = chuc + donvi;
   b406_hienthi_4led7doan();
   while(true)
   {
      b406_up_dw_g_han();
   }
}
