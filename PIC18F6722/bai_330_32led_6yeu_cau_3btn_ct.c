#include <tv_kit_vdk_18f6722_all.c>

usi8 ttl, tt_dir;
usi32 x;
usi16 LT,LP;

void h327_reset_tang_tcttd_if()
{
   ttl=0; x=0; LT=0; LP=0;
}

void chon_ct()
{
   //yeu cau 2
   if (tt_dir==0)
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
   //yeu cau 3
   if (tt_dir==1)
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
   //yeu cau 4
   if (tt_dir==2)
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
   //yeu cau 5
   if (tt_dir==3)
   {
      if(ttl<16)
      {
         LT=(LT>>1)+0x8000;
         LP=(LP>>1)+0X8000;
         xuat_32led_don_2word(LT,LP);
         delay_ms(30);
         ttl++;
      }
      else if(ttl<32)
      {
         LT=(LT>>1);
         LP=(LP>>1);
         xuat_32led_don_2word(LT,LP);
         delay_ms(30);
         ttl++;
      }
   else h327_reset_tang_tcttd_if();
   }
}

void kt_bt()
{
   if(phim_bt0_c2(2)==co_nhan)
   {
      if(tt_dir<3)
      {
         tt_dir++;
         h327_reset_tang_tcttd_if();
      }
   }
   if(phim_bt1_c2(2)==co_nhan)
   {
      if(tt_dir>0)
      {
         tt_dir--;
         h327_reset_tang_tcttd_if();
      }
   }
}

void main()
{
   set_up_port();
   tt_dir=0;
   h327_reset_tang_tcttd_if();
   while(true)
   {
      kt_bt();
      chon_ct();
      delay_ms(200);
   }
}
