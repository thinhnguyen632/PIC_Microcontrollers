#include <tv_kit_vdk_18f6722_all.c>

unsigned int1 tt_lcd;

unsigned char hang1[]={"Dong ho:            "};
unsigned char hang2[]={"  :  :              "};
unsigned char hang3[]={"18146222            "};
unsigned char hang4[]={"NGUYEN TIEN THINH   "};
unsigned char hang1_bt3[]={"San pham:           "};
unsigned char hang3_bt3[]={"Thoi gian:    :  :  "};
unsigned char trong[]={"                    "};

unsigned int i;
unsigned int gio_lcd[2],phut_lcd[2],giay_lcd[2];
unsigned int sp_lcd[2];


unsigned int8 t0, t0_tam, g_han;

signed int8 bdn,giay=0,phut=0,gio=0;
#int_timer3
void timer3_ct_con_ngat()
{
   bdn++;
   set_timer3(3036);
}

void gpg_khoi_tao_ngat_timer3()
{
   enable_interrupts(global);
   enable_interrupts(int_timer3);
   setup_timer_3(t3_internal|t3_div_by_8);
   set_timer3(3036);
   bdn=0; giay=0; phut=0;
}

void ht_mssv_ho_va_ten_lcd()
{
   lcd_puts(0,0,hang1);
   lcd_puts(1,0,hang2);
   lcd_puts(2,0,hang3);
   lcd_puts(3,0,hang4);
}

void gpg_hien_thi_lcd()
{
   ht_mssv_ho_va_ten_lcd();
   gio_lcd[1]=(gio%10)+0x30;
   gio_lcd[0]=(gio/10)+0x30;
   
   phut_lcd[1]=(phut%10)+0x30;
   phut_lcd[0]=(phut/10)+0x30;
   
   giay_lcd[1]=(giay%10)+0x30;
   giay_lcd[0]=(giay/10)+0x30;
   
   lcd_goto_xy(1,0);
   for (i=0; i<2; i++) lcd_data(gio_lcd[i]);
   lcd_goto_xy(1,3);
   for (i=0; i<2; i++) lcd_data(phut_lcd[i]);
   lcd_goto_xy(1,6);
   for (i=0; i<2; i++) lcd_data(giay_lcd[i]);
}

void gpg_hien_thi_lcd_bt3()
{
   lcd_puts(1,0,trong);
   lcd_puts(3,0,trong);
   lcd_puts(0,0,hang1_bt3);
   lcd_puts(2,0,hang3_bt3);
   
   gio_lcd[1]=(gio%10)+0x30;
   gio_lcd[0]=(gio/10)+0x30;
   
   phut_lcd[1]=(phut%10)+0x30;
   phut_lcd[0]=(phut/10)+0x30;
   
   giay_lcd[1]=(giay%10)+0x30;
   giay_lcd[0]=(giay/10)+0x30;
   
   sp_lcd[1] = (t0%10)+0x30;
   sp_lcd[0] = (t0/10)+0x30;
   
   lcd_goto_xy(0,18);
   for (i=0;i<2;i++) lcd_data(sp_lcd[i]);
   
   lcd_goto_xy(2,12);
   for (i=0; i<2; i++) lcd_data(gio_lcd[i]);
   lcd_goto_xy(2,15);
   for (i=0; i<2; i++) lcd_data(phut_lcd[i]);
   lcd_goto_xy(2,18);
   for (i=0; i<2; i++) lcd_data(giay_lcd[i]);
  
}

void gpg_tang_theo_bdn()
{
   if (giay<59) giay++;
   else
   {
      giay=0;
      if(phut<59) phut++;
      else
      {
         phut=0;
         if(gio<24) gio++;
         else gio=0;
      }
   }
}

void gpg_phim_3bt()
{
   if(phim_bt0_c1(c_ktnp,150)==co_nhan)
   {
      if (gio<23)
      {
         gio++;
      }
      else
      {
         gio=0;
      }
   }
   
   if(phim_bt1_c1(c_ktnp,150)==co_nhan)
   {
      if (phut<59)
      {
         phut++;
      }
      else
      {
         phut=0;
      }
   }
   
   if(phim_bt2_c1(c_ktnp,150)==co_nhan)
   {
      if (giay<59)
      {
         giay++;
      }
      else
      {
         giay=0;
      }
   }
}


void gpg_3bt()
{
   if (bdn>=10)
   {
      bdn = bdn - 10;
      gpg_tang_theo_bdn();
      gpg_hien_thi_lcd();
   }
   else
   {
      gpg_phim_3bt();
   }
}

void gpg_bt3()
{
   if (bdn>=10)
   {
      bdn = bdn - 10;
      gpg_tang_theo_bdn();
      gpg_hien_thi_lcd_bt3();
      xuat_32led_don_1dw(0);
   }
   else
   {
      gpg_phim_3bt();
   }
}

void hienthi_2led7doan()
{
   giaima_bin_2so_vitri_vn(t0,0,kx_vn);;
   xuat_8led_7doan();
}

void dem_sp_t0()
{
   t0 = get_timer0();
   if(t0_tam!=t0)
   {
      t0_tam = t0;
      hienthi_2led7doan();
      if (t0>=g_han)
      {  
         set_timer0(0);
         for (i=0;i<5;i++)
         {
            t0=1;
            hienthi_2led7doan();
            xuat_32led_don_1dw(0xffffffff);
            delay_ms(100);
            xuat_32led_don_1dw(0);
            delay_ms(100);
         }
      }
   }
}

void dem_sp_t0_bt3()
{
   t0 = get_timer0();
   if(t0_tam!=t0)
   {
      t0_tam = t0;
      if (t0>=g_han)
      {  
         set_timer0(0);
         for (i=0;i<5;i++)
         {
            t0=1;
            xuat_32led_don_1dw(0xffffffff);
            delay_ms(100);
            xuat_32led_don_1dw(0);
            delay_ms(100);
         }
      }
   }
}

void phim_nhan_bt3()
{
   if(phim_bt3_c1(c_ktnp,150)==co_nhan)
   {
      tt_lcd=~tt_lcd;
   }
}


void kt_tt_lcd()
{
   if (tt_lcd==0)
   {
      hienthi_2led7doan();
      gpg_3bt();
      dem_sp_t0();
   }
   else
   {
      led_7d[0]=0xff; led_7d[1]=0xff;
      xuat_8led_7doan();
      gpg_bt3();
      dem_sp_t0_bt3();
   }
}

void main()
{
   set_up_port();
   lcd_setup();
   
   ht_mssv_ho_va_ten_lcd();
   gpg_khoi_tao_ngat_timer3();
   
   setup_timer_0(t0_ext_l_to_h|t0_div_1);
   set_timer0(0); t0_tam = 1; g_han=16;
   
   tt_lcd=0;
   
   while(true)
   {
      phim_nhan_bt3();
      kt_tt_lcd();
   }
}
