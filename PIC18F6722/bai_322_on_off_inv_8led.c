#include <tv_kit_vdk_18f6722_all.c>
unsigned int8 y;
void main()
{
   set_up_port();
   y=0;
   xuat_32led_don_4byte(0,0,0,0);
   while(true)
   {
      while(input(on));
      y=0x0f;
      xuat_32led_don_4byte(0,0,0,y);
      do
      {
         if (!input(inv))
         {
            y=~y;
            xuat_32led_don_4byte(0,0,0,y);
         }
      }while(input(off));
      xuat_32led_don_4byte(0,0,0,0);
   }
}
