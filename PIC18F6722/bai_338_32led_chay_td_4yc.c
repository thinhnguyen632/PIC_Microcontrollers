#include <tv_kit_vdk_18f6722_all.c>
#include <chuong3_32led_if_no_delay.c>
void main()
{
   set_up_port();
   while(true)
   {
      b338_32led_4yc_tu_dong_if();
      delay_ms(20);
   }
}
