#include <tv_kit_vdk_18f6722_all.c>

unsigned int8 t0, t0_tam, g_han;

unsigned char hoten[]={"NGUYEN TIEN THINH   "};
unsigned char mssv[]={"18146222            "};
unsigned char trong[]={"                    "};
unsigned char sosp[]={"So San Pham         "};

usi8 giay_tam;

unsigned int1 tt_lcd=0;

unsigned int8 t0_lcd[2];
unsigned int i;


void hien_thi_led7doan()
{
   giaima_bin_2so_vitri_vn(g_han,0,kx_vn);
   giaima_bin_2so_vitri_vn(t0,6,kx_vn);
   xuat_8led_7doan();
}

void dem_sp_t0()
{
   t0 = get_timer0();
   if(t0_tam!=t0)
   {
      t0_tam = t0;
      hien_thi_led7doan();
      if (t0>g_han)
      {
         set_timer0(1);
         t0=1;
         hien_thi_led7doan();
      }
   }
}

void kt_bt0_bt1()
{
   if(phim_bt0_c1(k_ktnp,100)==co_nhan)
   {
      if(g_han<99)   g_han++;
      else           g_han=0;
   }
   if(phim_bt1_c1(k_ktnp,100)==co_nhan)
   {
      if(g_han>0)    g_han--;
      else           g_han=99;
   }
   if (tt_lcd==0) hien_thi_led7doan();
}




void ds1307_hthi_giay_lcd_soto()
{
   lcd_hien_thi_so_to(giay_ds/16,2,14);
   lcd_hien_thi_so_to(giay_ds%16,2,17);
}

void ds1307_hthi_phut_lcd_soto()
{
   lcd_hien_thi_so_to(phut_ds/16,2,7);
   lcd_hien_thi_so_to(phut_ds%16,2,10);
}

void ds1307_hthi_gio_lcd_soto()
{
   lcd_hien_thi_so_to(gio_ds/16,2,0);
   lcd_hien_thi_so_to(gio_ds%16,2,3);
}

void ds1307_hthi_lcd_soto()
{
   ds1307_hthi_giay_lcd_soto();
   if(giay_ds==0)
   {
      ds1307_hthi_phut_lcd_soto();
      if(phut_ds==0)
      {
         ds1307_hthi_gio_lcd_soto();
      }
   }
}

void ht_mssv_ho_va_ten_lcd()
{
   lcd_puts(0,0,hoten);
   lcd_puts(1,0,mssv);
}

void hien_thi_gpg_soto()
{
   ds1307_doc_time(8);
   if(giay_tam!=giay_ds)
   {
      giay_tam=giay_ds;
      ds1307_hthi_lcd_soto();
   }
   delay_ms(500);
}

void xoa_lcd()
{
   lcd_puts(0,0,trong);
   lcd_puts(1,0,trong);
   lcd_puts(2,0,trong);
   lcd_puts(3,0,trong);
}

void xoa_led7doan()
{
   led_7d[0]=0xff;
   led_7d[1]=0xff;
   led_7d[2]=0xff;
   led_7d[3]=0xff;
   led_7d[4]=0xff;
   led_7d[5]=0xff;
   led_7d[6]=0xff;
   led_7d[7]=0xff;
   xuat_8led_7doan();
}

void demsp_hienthi_lcd()
{
   lcd_puts(0,0,sosp);
   t0_lcd[1] = (t0%10)+0x30;
   t0_lcd[0] = (t0/10)+0x30;
   lcd_goto_xy(1,0);
   for (i=0;i<2;i++)
   {
      lcd_data(t0_lcd[i]);
   }
}

void dem_sp_lcd()
{
   t0 = get_timer0();
   if(t0_tam!=t0)
   {
      t0_tam = t0;
      demsp_hienthi_lcd();
      if (t0>g_han)
      {
         set_timer0(1);
         t0=1;
         demsp_hienthi_lcd();
      }
   }
}

void gpg_hien_thi_l7d()
{
   giaima_bcd_2so_vitri_vn(giay_ds,0,kx_vn);
   led_7d[2]=0xbf;
   giaima_bcd_2so_vitri_vn(phut_ds,3,kx_vn);
   led_7d[5]=0xbf;
   giaima_bcd_2so_vitri_vn(gio_ds,6,kx_vn);
   xuat_8led_7doan();
}

void gpg_l7d()
{
   ds1307_doc_time(8);
   if(giay_tam!=giay_ds)
   {
      giay_tam=giay_ds;
      gpg_hien_thi_l7d();
   }
   delay_ms(500);
}

void kt_bt2()
{
   if(phim_bt2_c1(c_ktnp,100)==co_nhan)
   {
      tt_lcd=~tt_lcd;
      xoa_lcd();
      xoa_led7doan();
   }
}

void kt_tt_lcd()
{
   if(tt_lcd==0)
   {
      ht_mssv_ho_va_ten_lcd();
      ds1307_hthi_giay_lcd_soto();
      ds1307_hthi_phut_lcd_soto();
      ds1307_hthi_gio_lcd_soto();
      kt_bt0_bt1();
      dem_sp_t0();
      hien_thi_gpg_soto();
   }
   else
   {
      kt_bt0_bt1();
      demsp_hienthi_lcd();
      dem_sp_lcd();
      lcd_puts(3,0,hoten);
      gpg_l7d();
   }
}



void main()
{
   set_up_port();
   
   setup_timer_0(t0_ext_l_to_h|t0_div_1);
   set_timer0(0); t0_tam = 1; g_han=15;
   
   lcd_setup();
   ht_mssv_ho_va_ten_lcd();
   lcd_khoi_tao_cgram_so_to();
   ds1307_kiem_tra_ma();
   
   ds1307_hthi_giay_lcd_soto();
   ds1307_hthi_phut_lcd_soto();
   ds1307_hthi_gio_lcd_soto();
   
   while(true)
   {
      kt_tt_lcd();
      kt_bt2();
   }
}
