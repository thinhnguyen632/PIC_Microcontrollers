#include <tv_kit_vdk_18f6722_all.c>
#include <chuong3_32led_if_no_delay.c>
void main()
{
   set_up_port();
   while(true)
   {
      b339_32led_tong_hop_tu_dong_if();
   }
}
