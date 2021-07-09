#include <tv_kit_vdk_18f6722_all.c>

usi8 ttl, tt_ct;
usi32 x;
void h327_reset_tang_tcttd_if()
{
   ttl=0; x=0;
}
void h327_32led_std_tsp_if()
{
   if(ttl<32)
   {
      x=(x>>1)+0x80000000;
      xuat_32led_don_1dw(x);
      ttl++;
   }
   else if(ttl<64)
   {
      x=(x>>1);
      xuat_32led_don_1dw(x);
      ttl++;
   }
   else h327_reset_tang_tcttd_if();
}

void h327_32led_std_pst_if()
{
   if(ttl<32)
   {
      x=(x<<1)+1;
      xuat_32led_don_1dw(x);
      ttl++;
   }
   else if(ttl<64)
   {
      x=(x<<1);
      xuat_32led_don_1dw(x);
      ttl++;
   }
   else h327_reset_tang_tcttd_if();
}

void b327_32led_std_pst_tsp_tat_3bt_if()
{
   if(phim_bt0_c1(c_ktnp,0)==co_nhan)
   {
      if(tt_ct<2)
      {
         tt_ct++;
         h327_reset_tang_tcttd_if();
      }
   }
   if(phim_bt1_c1(c_ktnp,0)==co_nhan)
   {
      if(tt_ct>0)
      {
         tt_ct--;
         h327_reset_tang_tcttd_if();
      }
   }
}

void main()
{
   set_up_port();
   tt_ct=0;
   h327_reset_tang_tcttd_if();
   while(true)
   {
      b327_32led_std_pst_tsp_tat_3bt_if();
      if(tt_ct==0) xuat_32led_don_1dw(0);
      if(tt_ct==1) h327_32led_std_pst_if();
      if(tt_ct==2) h327_32led_std_tsp_if();
      delay_ms(200);
   }
}
