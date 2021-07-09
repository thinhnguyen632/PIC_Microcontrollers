#include <tv_kit_vdk_18f6722_all.c>
unsigned int8 XX[2]={"00"};
unsigned int8 YY[2]={"00"};
unsigned int8 mp,i;
unsigned int8 dem,temp1=0,temp0=0,dem_yy=0;
unsigned int1 tt_led,tt_dem=0;

signed int8 bdn;

#int_timer3
void timer3_ct_con_ngat()
{
   bdn++;
   set_timer3(3036);
}
void h415_dem_giay_timer3()
{
   if (bdn>=10)
   {
      bdn = bdn - 10;
      if (dem_yy<dem)   
      {
         dem_yy++;
         YY[1]=(dem_yy%10)+0x30;
         YY[0]=(dem_yy/10)+0x30;
         lcd_goto_xy(2,16);
         for (i=0; i<2; i++) lcd_data(YY[i]);
      }
      else
      {
         dem_yy=dem;
         YY[1]=(dem_yy%10)+0x30;
         YY[0]=(dem_yy/10)+0x30;
         lcd_goto_xy(2,16);
         for (i=0; i<2; i++) lcd_data(YY[i]);
         xuat_32led_don_1dw(0xffffffff);
         tt_led=1;
         lcd_goto_xy(0,16);
         lcd_data("ON ");
         buzzer_on_off(5000);
         lcd_goto_xy(0,16);
         lcd_data("OFF");
         dem_yy=0;
         bdn=0;
      }
      
   }
}

void cai_dat_XX()
{
   if(tt_dem==0)
   {
      if (mp<10)
      {
         temp0=temp1;
         temp1=mp;
         XX[0] = XX[1];
         XX[1] = (mp+0x30);
         dem = temp0*10 + temp1;
         if (dem < 60)
         {
            lcd_goto_xy(1,16);
            for (i=0; i<2; i++) lcd_data(XX[i]);
         }
         else 
         {
            lcd_goto_xy(1,16);
            lcd_data("59");
            dem=59;
         }
      }
   }
}

void kt_dem()
{
   if (tt_dem==1)
   {
      h415_dem_giay_timer3();
   }
   if (tt_dem==0)
   {
      YY[1]=(dem_yy%10)+0x30;
      YY[0]=(dem_yy/10)+0x30;
      lcd_goto_xy(2,16);
      for (i=0; i<2; i++) lcd_data(YY[i]);
   }
}

void cai_dat_YY()
{
   if (mp==12)
   {
      if (tt_led==1)
      {
         xuat_32led_don_1dw(0);
         tt_led=0;
      }
   }
   if (mp==10)
   {
      if(tt_led==1)
      {
         xuat_32led_don_1dw(0);
         tt_led=0;
      }
      tt_dem=1;
      dem_yy=0;
      bdn=0;
   }
   if (mp==11)
   {
      tt_dem=~tt_dem;
      bdn=0;
   }
   if (mp==14)
   {
      tt_dem=0;
      dem_yy=0;
      dem=0;
      bdn=0;
      YY[1]=0+0x30;
      YY[0]=0+0x30;
      lcd_goto_xy(2,16);
      for (i=0; i<2; i++) lcd_data(YY[i]);
      XX[0] = (dem/10)+0x30;
      XX[1] = (dem%10)+0x30;
      lcd_goto_xy(1,16);
      for (i=0; i<2; i++) lcd_data(XX[i]);
   }
}

void main()
{
   set_up_port();
   
   enable_interrupts(global);
   enable_interrupts(int_timer3);
   setup_timer_3(t3_internal|t3_div_by_8);
   set_timer3(3036);
   bdn=0; dem_yy=0;
   
   lcd_setup();
   lcd_goto_xy(0,0);
   lcd_data("Dieu Khien Buz:     ");//ZZZ
   lcd_goto_xy(1,0);
   lcd_data("Thoi gian cai:  00  ");//XX
   lcd_goto_xy(2,0);
   lcd_data("Thoi gian dem:  00  ");//YY
   xuat_32led_don_1dw(0);
   tt_led=0;
   tt_dem=0;
   while(true)
   {
      mp = key_tip229_cdoi_c2(10);
      if(mp!=0xff)
      {
         cai_dat_XX();
         cai_dat_YY();
         delay_ms(200);
      } 
      kt_dem();
   }
}
