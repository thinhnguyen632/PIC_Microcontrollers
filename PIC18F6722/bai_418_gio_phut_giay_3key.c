#include <tv_kit_vdk_18f6722_all.c>
#include <bai_418_gio_phut_giay_3key_tv.c>

void main()
{
   set_up_port();
   h418_gpg_khoi_tao_ngat_timer3();
   while(true)
   {
      b418_gpg_3bt(400,250);
   }
}
