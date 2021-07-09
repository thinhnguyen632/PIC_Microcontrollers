#include <tv_kit_vdk_18f6722_all.c>
void main()
{
   set_up_port();
   while(true)
   {
      while(input(on));
      xuat_32led_don_4byte(0,0,0,0xff);
      while(input(off));
      xuat_32led_don_4byte(0,0,0,0);
   }
}
//cach viet dung lenh if
//void main()
//{
//   set_up_port();
//   xuat_32led_don_4byte(0,0,0,0);
//   while(true)
//   {
//      if(!input(on))
//      xuat_32led_don_4byte(0,0,0,0xff);
//      else if(!input(off))
//      xuat_32led_don_4byte(0,0,0,0);
//   }
//}
