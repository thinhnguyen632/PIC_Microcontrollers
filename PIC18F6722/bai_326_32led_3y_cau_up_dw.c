#include <tv_kit_vdk_18f6722_all.c>
usi8 tt_ct;
void b308_32led_std_pst(usi16 dl)
{
   usi8 i; usi32 x;
   x = 0;
   for(i=0;i<32;i++)
   {
      x = (x << 1)+1;
      xuat_32led_don_1dw(x);
      delay_ms(dl);
   }
   for(i=0;i<32;i++)
   {
      x = (x << 1);
      xuat_32led_don_1dw(x);
      delay_ms(dl);
   }
}

void b309_32led_std_tsp(usi16 dl)
{
   usi8 i; usi32 x;
   x = 0;
   for(i=0;i<32;i++)
   {
      x = (x>>1) + 0x80000000;
      xuat_32led_don_1dw(x);
      delay_ms(dl);
   }
   for(i=0;i<32;i++)
   {
      x = (x>>1);
      xuat_32led_don_1dw(x);
      delay_ms(dl);
   }
}

void b326_32led_std_pst_tsp_tat_3bt()
{
   if(phim_bt0_c1(c_ktnp,0)==co_nhan)
   {
      if(tt_ct<2) tt_ct++;
   }
   if(phim_bt1_c1(c_ktnp,0)==co_nhan)
   {
      if(tt_ct>0) tt_ct--;
   }
   if(tt_ct==0) xuat_32led_don_1dw(0);
   if(tt_ct==1) b308_32led_std_pst(200);
   if(tt_ct==2) b309_32led_std_tsp(200);
}

void main()
{
   set_up_port();
   tt_ct=0;
   while(true)
   {
      b326_32led_std_pst_tsp_tat_3bt();
   }
}
