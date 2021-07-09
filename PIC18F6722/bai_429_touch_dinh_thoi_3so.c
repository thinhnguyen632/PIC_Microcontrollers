#include <tv_kit_vdk_18f6722_all.c> 
usi8 mp8,giay,giay_cai,bdn;
int1 tt_ena_dis=0, tt_on_off=0;

#int_timer3
void timer3_ct_con_ngat() 
{ 
   bdn++; 
   set_timer3(3036);
}

void timer3_xung_noi_on(int1 tt) 
{ 
   setup_timer_3(t3_internal|t3_div_by_8); 
   if(tt==true) set_timer3(3036); 
}

void timer3_xung_noi_off(int1 tt) 
{ 
   setup_timer_3(t3_disabled); 
   if(tt==true) set_timer3(3036);
}



void h428_dem_giay_dinh_thoi_timer3() 
{ 
   if(tt_on_off==tt_on)
   {
      if (bdn>=10)
      { 
         bdn = 0; 
         giay++; 
      } 
      if((giay==giay_cai)&&(tt_on_off==tt_on))
      { 
         sang_32led();
         tt_on_off = tt_off; 
         tt_ena_dis = disable; 
         timer3_xung_noi_off(no_reset);
         buzzer_on_off(200);
      }
   } 
}

void h429_hien_thi_dinh_thoi_giay_3so() 
{ 
   led_7d[2] = ma7doan[bcd_8led[2]];
   led_7d[1] = ma7doan[bcd_8led[1]]; 
   led_7d[0] = ma7doan[bcd_8led[0]]; 
   giaima_bin_3so_vitri_vn(giay,5,kx_vn); 
   xuat_8led_7doan(); 
} 

void h429_cai_giay_dinh_thoi_3so() 
{ 
   mp8 = key_tip229_cdoi_c2(10);
   if((mp8>0)&&(mp8<17))
   { 
      mp8 = mp8%16;
      if((mp8<10)&&(tt_ena_dis!=enable)) 
      { 
         bcd_8led[2] = bcd_8led[1];
         bcd_8led[1] = bcd_8led[0]; 
         bcd_8led[0] = mp8;
         delay_ms(200);
      } 
      else if(mp8==10) 
      { 
         tt_on_off = tt_on; 
         tt_ena_dis = enable; 
         giay_cai=bcd_8led[2]*100 +bcd_8led[1]*10 +bcd_8led[0];
         if(giay_cai<5) 
         { 
            giay_cai = 5; 
            bcd_8led[2]=0; bcd_8led[1]=0; bcd_8led[0]=5;
         } 
         giay=0; 
         tat_32led();
         timer3_xung_noi_on(co_reset); 
      } 
      else if(mp8==11) tat_32led();
      else if(mp8==12)
      {
         tt_on_off = tt_off;
         tt_ena_dis = disable; 
         timer3_xung_noi_off(no_reset);
         giay=0;
      } 
   } 
}

void b429_dinh_thoi_giay_3so() 
{ 
   h429_cai_giay_dinh_thoi_3so(); 
   h428_dem_giay_dinh_thoi_timer3();
   h429_hien_thi_dinh_thoi_giay_3so(); 
}

void main()
{ 
   set_up_port();
   enable_interrupts(global);
   enable_interrupts(int_timer3); 
   bdn=0; giay=0;
   while(true)
   { 
   b429_dinh_thoi_giay_3so(); 
   } 
}

