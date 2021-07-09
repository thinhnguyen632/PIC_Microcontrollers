signed int8 bdn,giay,phut,gio;
signed int8 gt_mod,tg_chinh;
#int_timer3
void timer3_ct_con_ngat()
{
   bdn++;
   set_timer3(3036);
}

void h418_gpg_khoi_tao_ngat_timer3()
{
   enable_interrupts(global);
   enable_interrupts(int_timer3);
   setup_timer_3(t3_internal|t3_div_by_8);
   set_timer3(3036);
   bdn=0; giay=0; phut=0;
}

void h418_gpg_hien_thi_binh_thuong()
{
   giaima_bin_2so_vitri_vn(giay,0,kx_vn);
   giaima_bin_2so_vitri_vn(phut,3,kx_vn);
   giaima_bin_2so_vitri_vn(gio,6,kx_vn);
   xuat_8led_7doan();
}

void h418_gpg_hien_thi_chop_tat()
{
   if(bdn==0)
      h418_gpg_hien_thi_binh_thuong();
   if(bdn==5)
   {
      if((gt_mod==1)&&(input(bt0))&&(input(bt1)))
      {
         led_7d[7]=0xff; led_7d[6]=0xff;
      }
      if((gt_mod==2)&&(input(bt0))&&(input(bt1)))
      {
         led_7d[4]=0xff; led_7d[3]=0xff;
      }
      if((gt_mod==3)&&(input(bt0))&&(input(bt0)))
      {
         led_7d[1]=0xff; led_7d[0]=0xff;
      }
      xuat_8led_7doan();
   }
}

void h418_gpg_tang_theo_bdn()
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

void h418_gpg_phim_mod(usi16 dl_mod)
{
   if(phim_mode_c2(dl_mod)==co_nhan)
   {
      if(gt_mod>=3) gt_mod=0;
      else
      {
         gt_mod++; tg_chinh=0;
      }
      h418_gpg_hien_thi_binh_thuong();
   }
}

void h418_gpg_chinh_tang()
{
   switch (gt_mod)
   {
      case 1:  if (gio==23)   gio=0;
               else           gio++;
               break;
      case 2:  if (phut==59)  phut=0;
               else           phut++;
               break;
      case 3:  if (giay==59)  giay=0;
               else           giay++;
               break;
      default: break;
   }
}

void h418_gpg_chinh_giam()
{
   switch (gt_mod)
   {
      case 1:  if (gio==0)    gio=23;
               else           gio--;
               break;
      case 2:  if (phut==0)   phut==59;
               else           phut--;
               break;
      case 3:  if (giay==0)   giay=59;
               else           giay--;
               break;
      default: break;
   }
}

void h418_gpg_phim_up(usi8 dl_ud)
{ 
   if(phim_up_c2(dl_ud)==co_nhan)
   { 
      h418_gpg_chinh_tang(); 
      h418_gpg_hien_thi_binh_thuong(); 
      tg_chinh = 0; 
   } 
}

void h418_gpg_phim_dw(usi8 dl_ud) 
{
   if(phim_dw_c2(dl_ud)==co_nhan) 
   { 
      h418_gpg_chinh_giam(); 
      h418_gpg_hien_thi_binh_thuong();
      tg_chinh = 0;
   } 
}

void b418_gpg_3bt(usi16 dl_mod, usi8 dl_ud)
{
   if (bdn>=10)
   {
      bdn  = bdn - 10;
      h418_gpg_tang_theo_bdn();
      h418_gpg_hien_thi_chop_tat();
      if((tg_chinh>20)&&(gt_mod !=0))  gt_mod=0;
      else  tg_chinh++;
   }
   else
   {
      h418_gpg_phim_mod(dl_mod);
      h418_gpg_phim_up(dl_ud);
      h418_gpg_phim_dw(dl_ud);
      h418_gpg_hien_thi_chop_tat();
   }
}
