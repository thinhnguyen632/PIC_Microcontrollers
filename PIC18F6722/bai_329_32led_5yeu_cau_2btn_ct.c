#include <tv_kit_vdk_18f6722_all.c>

usi8 ttl, tt_ct;
usi32 x;
usi16 LT,LP;

void h327_reset_tang_tcttd_if()
{
   ttl=0; x=0; LT=0; LP=0;
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

void std_pst_16led()
{
   if(ttl<16)
   {
      LP=(LP<<1)+1;
      LT=(LT<<1)+1;
      xuat_32led_don_2word(LT,LP);
      ttl++;
   }
   else if(ttl<32)
   {
      LP=(LP<<1);
      LT=(LT<<1);
      xuat_32led_don_2word(LT,LP);
      ttl++;
   }
   else h327_reset_tang_tcttd_if();
}

void std_tsp_16led_delay(usi8 dl)
{
   if(ttl<16)
   {
      LT=(LT>>1)+0x8000;
      LP=(LP>>1)+0X8000;
      xuat_32led_don_2word(LT,LP);
      delay_ms(dl);
      ttl++;
   }
   else if(ttl<32)
   {
      LT=(LT>>1);
      LP=(LP>>1);
      xuat_32led_don_2word(LT,LP);
      delay_ms(dl);
      ttl++;
   }
   else h327_reset_tang_tcttd_if();
}

void b328_32led_std_pst_tsp_tat_3bt_if()
{
   if(phim_bt0_c2(2)==co_nhan)
   {
      if(tt_ct<4)
      {
         tt_ct++;
         h327_reset_tang_tcttd_if();
      }
   }
   if(phim_bt1_c2(2)==co_nhan)
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
      b328_32led_std_pst_tsp_tat_3bt_if();
      if(tt_ct==0) xuat_32led_don_1dw(0);
      if(tt_ct==1) h327_32led_std_pst_if();
      if(tt_ct==2) h327_32led_std_tsp_if();
      if(tt_ct==3) std_pst_16led();
      if(tt_ct==4) std_tsp_16led_delay(30);
      delay_ms(200);
   }
}
