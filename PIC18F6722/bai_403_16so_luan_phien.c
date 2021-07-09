#include <tv_kit_vdk_18f6722_all.c>
void b401_hien_thi_8so_817d()
{
   led_7d[7]=ma7doan[7];
   led_7d[6]=ma7doan[6];
   led_7d[5]=ma7doan[5];
   led_7d[4]=ma7doan[4];
   led_7d[3]=ma7doan[3];
   led_7d[2]=ma7doan[2];
   led_7d[1]=ma7doan[1];
   led_7d[0]=ma7doan[0];
   
   xuat_8led_7doan();
}

void led7doan_hien_thi_8_den_F()
{
   for (int i=0; i<8; i++)
   {
      led_7d[i]=ma7doan[i+8];
   }
   xuat_8led_7doan();
}

void main()
{
   set_up_port();
   while(true)
   {
      b401_hien_thi_8so_817d();
      delay_ms(1000);
      led7doan_hien_thi_8_den_F();
      delay_ms(1000);
   }
}
