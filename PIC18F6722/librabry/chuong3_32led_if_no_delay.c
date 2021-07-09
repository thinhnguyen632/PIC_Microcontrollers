//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                      
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                                      
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//cac chuong trinh dieu khien 32 led cac kieu, dung lenh if
//cac bai nay co su dung lai cac ham cua cac bai da viet
//truoc do, nen chi dung cho cac bai tong hop
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx       
//!void h333_32led_tnv_ttr_pst_tsp(usi16 dl,usi8 dir); 
void h332_32led_std_pst_tsp_tat_3bt_if(usi8 tt);                    
                                                
//!void h332_32led_std_tsp_if(usi16 dl);            
//!void h332_32led_std_pst_if(usi16 dl);               
//!void h337_32led_std_ttrtnv_psttsp_if(usi16 dl,usi8 dir);

//!void h338_32led_sd_pst_if(usi16 dl);    
//!void h338_32led_sd_tsp_if(usi16 dl);                        
//!void h339_32led_sd_tnvttr_psttsp_if(usi16 dl,usi8 dir);

//!void h340_32led_ds_dp_md_if(usi16 dl);
//!void h340_32led_ds_dt_md_if(usi16 dl);       
//!void h341_32led_ds_dvdrdpdt_md_if(usi16 dl,int1 dir);  
//!                                        
//!void h342_32led_kds_dt_if(usi16 dl, usi8 sb);
//!void h343_32led_kds_dp_if(usi16 dl, usi8 sb); 
//!void h344_32led_kds_dvdrdtdp_if(usi16 dl, usi8 k, usi8 dir);
//!
//!void h333_32led_std_tnv_if(usi16 dl);
//!void h333_32led_std_ttr_if(usi16 dl); 
void h334_32led_4yc(usi8 tt);
void h332x_reset_tang_tcttd_if();             
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
//ham dieu khien 32 led std theo thu tu   
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//!void h331_32led_std_pst_tsp_tat_3bt(usi8 tt)      
//!{                                                                                                         
//!   if(tt==1) b308_32led_std_pst(200);
//!   if(tt==2) b309_32led_std_tsp(200);                                                          
//!}                                                               
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//minh hoa cho dap ung cham cua for va nha phim      
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    
//!void b331_32led_std_pst_tsp_tat_3bt()                       
//!{                                                                   
//!   if(phim_bt0_c1(c_ktnp,0)==co_nhan) tt_ct = 1;                   
//!   if(phim_bt1_c1(c_ktnp,0)==co_nhan) tt_ct = 2;                  
//!   if(phim_bt2_c1(c_ktnp,0)==co_nhan) 
//!      {
//!         tt_ct = 0;
//!         xuat_32led_don_1dw(0);
//!      }                                                      
//!   h331_32led_std_pst_tsp_tat_3bt(tt_ct);                                                       
//!}    

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx              
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                      
//ham lua chon ham  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//!void h332_32led_std_pst_tsp_tat_3bt_if(usi8 tt)      
//!{                                                                                                         
//!   if(tt==1) h332_32led_std_pst_if(200);                                       
//!   if(tt==2) h332_32led_std_tsp_if(200);                                                          
//!}   
                       
unsigned int32  x=0; 
unsigned int16  LP=0, LT=0;              
unsigned int8   tt_ct=0, tt_ct_td=0;        
unsigned int8  dg32=32, dt32=0;             
unsigned int32 x32=0, y32_pst=1, z32=0,   y32_tsp=0x80000000;    
unsigned int8  dg16=32, dt16=0;     
unsigned int16 y16_pst=1, z16_pst=0,   y16_tsp=0x8000, z16_tsp=0; 

unsigned int32 v32_pst=0xfffffffe,v32_tsp=0x7fffffff;
unsigned int32 u32_pst=0x80000000,u32_tsp=1;   
unsigned int8  cnt1=1, cnt2=1; 

unsigned int32 v16_pst=0xfffe,v16_tsp=0x7fff;
unsigned int32 u16_pst=0x8000,u16_tsp=1; 
unsigned int8 ttl;
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//ham reset cac bien dung cho cac bai dung lenh if                          
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
void h332_reset_tang_tcttd_if()    
{ 
   ttl=0;   x=0;  tt_ct_td++;                                                    
   dg32=32; dt32=0;                             
   x32=0; z32=0;                                   
   y32_pst=1;                        
   y32_tsp=0x80000000,      
   
   dg16=16; dt16=0;
   y16_pst=1;        z16_pst=0;                        
   y16_tsp=0x8000;   z16_tsp=0; 
   
   v32_pst=0xfffffffe;    
   v32_tsp=0x7fffffff;
   cnt1=1; cnt2=1;
   u32_tsp=0x80000000;   u32_pst=1;
   v16_pst=0xfffe;      v16_tsp=0x7fff;
   u16_pst=0x0001;      u16_tsp=0x8000;    
} 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                           
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//dk 32 led sang tat dan trai sang phai dung lenh if                
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
void h332_32led_std_tsp_if()    
{                                                       
   if(ttl<32)                                    
   {                                         
      x=(x>>1)+0x80000000;                     
      xuat_32led_don_1dw(x);
      ttl++;         
   }                  
   else  if(ttl<64)
   {  
      x=(x>>1);
      xuat_32led_don_1dw(x);
      ttl++;                  
    }                                                    
    else  h332_reset_tang_tcttd_if();   
}                

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//dk 32 led sang tat dan phai sang trai dung lenh if                 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
void h332_32led_std_pst_if()         
{                                             
   if(ttl<32)              
   {            
      x=(x<<1)+1;
      xuat_32led_don_1dw(x);
      ttl++;
   }
   else  if(ttl<64)                                           
   {                                                                     
      x=(x<<1);
      xuat_32led_don_1dw(x);
      ttl++; 
    } 
    else  h332_reset_tang_tcttd_if();  
} 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//dk 32 led sang tat dan ttr          
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
void h333_32led_std_ttr_if()     
{                                        
  if(ttl<16)                                          
   {                                 
      LT = (LT<<1)+1;LP = (LP>>1)+0x8000; 
      xuat_32led_don_2word(LT,LP); 
      ttl++;
   }                          
   else  if(ttl<32)                                           
   {                                                                          
      LT = (LT<<1);     LP = (LP>>1);
      xuat_32led_don_2word(LT,LP);
      ttl++;
   }
   else  h332_reset_tang_tcttd_if();  
}     
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//dk 32 led sang tat dan tnv          
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
void h333_32led_std_tnv_if()     
{                                        
  if(ttl<16)                                          
   {                                 
      LT = (LT<<1)+1;LP = (LP>>1)+0x8000; 
      xuat_32led_don_2word(LP,LT);     
      ttl++;
   }                          
   else  if(ttl<32)                                           
   {                                                                          
      LT = (LT<<1);     LP = (LP>>1);
      xuat_32led_don_2word(LP,LT);
      ttl++;                           
   }
   else  h332_reset_tang_tcttd_if();  
}                                                       
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                              
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//tong hop 4 yeu tu dong cau bai 338   
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
void h338_32led_4yc(usi8 tt)            
{                                                                                                         
   if(tt==0) h332_32led_std_pst_if();                                       
   if(tt==1) h332_32led_std_tsp_if(); 
   if(tt==2) h333_32led_std_tnv_if();         
   if(tt==3) h333_32led_std_ttr_if();                              
}                   
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    
void b338_32led_4yc_tu_dong_if()      
{                                                                                                                   
   if(tt_ct_td>3)  tt_ct_td=0;
   h338_32led_4yc(tt_ct_td);              
}                 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//dk 32 led chon chieu xuat data ttr/tnv/pst/tsp song song
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
void h337_32led_tnv_ttr_pst_tsp(usi8 dir)     
{                                        
  if(dir==0) xuat_32led_don_2word(LT,LP);
  if(dir==1) xuat_32led_don_2word(LP,LT);
  if(dir==2) xuat_32led_don_2word(LP,LP);
  if(dir==3) xuat_32led_don_2word(LT,LT);  
}      
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//dk 32 led std ttr/tnv/pst/tsp song song                     
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
void h337_32led_std_ttrtnv_psttsp_if(usi8 dir)     
{                                        
  if(ttl<16)                                          
   {                                 
      LT = (LT<<1)+1;LP = (LP>>1)+0x8000; 
      h337_32led_tnv_ttr_pst_tsp(dir);
      ttl++;
   }                          
   else  if(ttl<32)                                           
   {                                                                          
      LT = (LT<<1);     LP = (LP>>1);
      h337_32led_tnv_ttr_pst_tsp(dir);
      ttl++;
   }
   else  h332_reset_tang_tcttd_if();                                                                   
}                                                          
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//dk 32 led sang don pst dung lenh if    
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx     
void h338_32led_sd_pst_if()           
{                                             
   if(dg32>0)          
   {                   
      if(dg32>dt32)                                              
      {       
         z32 = x32|y32_pst;
         xuat_32led_don_1dw(z32);      
         y32_pst = y32_pst<<1;             
         dt32++; 
      }
      if(dg32==dt32)  
      {
         dg32--;
         dt32=0;                
         x32=z32;
         y32_pst = 1;  
      }            
   }                         
   else  h332_reset_tang_tcttd_if();
}                                                              
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//dk 32 led sang don tsp dung lenh if    
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
void h338_32led_sd_tsp_if()           
{       
   if(dg32>0)          
   {                   
      if(dg32>dt32)          
      {
         z32 = x32|y32_tsp;
         xuat_32led_don_1dw(z32);                              
         y32_tsp = y32_tsp>>1;             
         dt32++;  
      }
     if(dg32==dt32)  
      {
         dg32--;
         dt32=0;                
         x32=z32;
         y32_tsp = 0x80000000;  
      }            
   }
   else  h332_reset_tang_tcttd_if();
}   
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//dk 32 led sang don: tnv/ttr/pst/tsp song song     
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
void h339_32led_sd_tnvttr_psttsp_if(usi8 dir)  
{                                                               
   if(dg16>0)                                       
   {                            
      if(dg16>dt16)      
      { 
         LP = z16_pst|y16_pst;
         LT = z16_tsp|y16_tsp;
         h337_32led_tnv_ttr_pst_tsp(dir);                     
         y16_pst = y16_pst<<1;         
         y16_tsp = y16_tsp>>1; 
         dt16++;  
      }
      if(dg16==dt16) 
      {
         dg16--;
         dt16=0;                                            
         z16_pst=LP;  z16_tsp=LT;         
         y16_pst = 1; y16_tsp = 0X8000;
      }
   }                                             
   else  h332_reset_tang_tcttd_if();
} 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//ham lua chon cac yeu cau dieu khien 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
void h339_32led_tong_hop(usi8 tt)      
{                                                                                                         
   if(tt==0)   h332_32led_std_pst_if();                                       
   if(tt==1)   h332_32led_std_tsp_if(); 
   if(tt==2)   h337_32led_std_ttrtnv_psttsp_if(0);         
   if(tt==3)   h337_32led_std_ttrtnv_psttsp_if(1);
   if(tt==4)   h337_32led_std_ttrtnv_psttsp_if(2);
   if(tt==5)   h337_32led_std_ttrtnv_psttsp_if(3); 

   if(tt==6)  h338_32led_sd_pst_if();                              
   if(tt==7)  h338_32led_sd_tsp_if(); 
   if(tt==8)  h339_32led_sd_tnvttr_psttsp_if(0);            
   if(tt==9)  h339_32led_sd_tnvttr_psttsp_if(1);       
   if(tt==10)  h339_32led_sd_tnvttr_psttsp_if(2);            
   if(tt==11)  h339_32led_sd_tnvttr_psttsp_if(3);     
            
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//dk 32 led diem sang dich phai mat dan dung lenh if    
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
void h340_32led_ds_dp_md_if()   
{                                                             
   if(cnt1<33)    
   {                      
      if(cnt2>0)              
      {                                                 
         y32_pst = y32_pst>>1;                  
         z32 = v32_pst|y32_pst;                    
         xuat_32led_don_1dw(z32);     
         cnt2--;                             
      }                 
      else                                             
      {                                       
         cnt1++;        
         cnt2 = cnt1;             
         u32_pst = u32_pst<<1;     
         y32_pst = u32_pst;          
         v32_pst = v32_pst<<1;  
      }                                                                          
   }
   else  h332_reset_tang_tcttd_if();  
}                                                            
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//dk 32 led diem sang dich trai mat dan dung lenh if    
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
void h340_32led_ds_dt_md_if()   
{       
   if(cnt1<33)    
   {
      if(cnt2>0)              
      {                                                 
         y32_tsp = y32_tsp<<1;                  
         z32 = v32_tsp|y32_tsp;                    
         xuat_32led_don_1dw(z32);    
         cnt2--;                             
      }                 
      else                                             
      {
         cnt1++;        
         cnt2 = cnt1;             
         u32_tsp = u32_tsp>>1;
         y32_tsp = u32_tsp;
         v32_tsp = v32_tsp>>1;   
      }
   }
   else  h332_reset_tang_tcttd_if();  
}                                                                            
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx       
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//dk 32 led diem sang dich vao/ra/phai/trai mat dan dung lenh if    
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
void h341_32led_ds_dvdrdpdt_md_if(int1 dir)   
{                                                             
   if(cnt1<17)                                             
   {                                                      
      if(cnt2>0)                         
      {                                                          
         y16_pst = y16_pst>>1;    //phai 
         y16_tsp = y16_tsp<<1;    //trai
             
         LT = v16_tsp|y16_tsp;        
         LP = v16_pst|y16_pst;                  
         h337_32led_tnv_ttr_pst_tsp(dir);  
         
         cnt2--;                                           
      }                 
      else                                             
      {                                       
         cnt1++;        
         cnt2 = cnt1;             
         u16_pst = u16_pst<<1;     
         y16_pst = u16_pst;
         v16_pst = v16_pst<<1; 
         
         u16_tsp = u16_tsp>>1;     
         y16_tsp = u16_tsp;      
         v16_tsp = v16_tsp>>1;          
      }                            
   }
   else  h332_reset_tang_tcttd_if();  
}   
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//dk 32 led: k diem sang di chuyen pst                       
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void h342_xu_ly_kds_dt_if(usi8 k)  
{          
   if((k!=0)&&(k<17))                     
   {
      if(ttl<k)              
      {                                                                 
         if(ttl==0)       x=0x1;          
         else if(ttl==1)  x=0x3;                      
         else if(ttl==2)  x=0x7; 
         else if(ttl==3)  x=0xf;
         else if(ttl==4)  x=0x1f;       
         else if(ttl==5)  x=0x3f; 
         else if(ttl==6)  x=0x7f; 
         else if(ttl==7)  x=0xff;    
         else if(ttl==8)  x=0x1ff;          
         else if(ttl==9)  x=0x3ff;                      
         else if(ttl==10) x=0x7ff; 
         else if(ttl==11) x=0xfff;
         else if(ttl==12) x=0x1fff;       
         else if(ttl==13) x=0x3fff;         
         else if(ttl==14) x=0x7fff; 
         else if(ttl==15) x=0xffff;
      }
   } 
   else  ttl=32+k;//end
 }                                  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void h342_32led_kds_dt_if(usi8 k)             
{                                                        
   if(ttl<32+k)                             
   {                    
      h342_xu_ly_kds_dt_if(k);                 
      xuat_32led_don_1dw(x);
      x=(x<<1);
      ttl++;
   }                                                  
    else  h332_reset_tang_tcttd_if();  
}  

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx           
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//dk 32 led: k diem sang di chuyen tsp                       
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void h343_xu_ly_kds_dp_if(usi8 k)  
{                                                                                 
   if((k!=0)&&(k<17))
   {
      if(ttl<k)
      {                               
         if(ttl==0)       x=0x80000000;        
         else if(ttl==1)  x=0xc0000000;                      
         else if(ttl==2)  x=0xe0000000;   
         else if(ttl==3)  x=0xf0000000;
         else if(ttl==4)  x=0xf8000000;       
         else if(ttl==5)  x=0xfc000000; 
         else if(ttl==6)  x=0xfe000000; 
         else if(ttl==7)  x=0xff000000;
         else if(ttl==8)  x=0xff800000;       
         else if(ttl==9)  x=0xffc00000;                     
         else if(ttl==10) x=0xffe00000;   
         else if(ttl==11) x=0xfff00000;
         else if(ttl==12) x=0xfff80000;      
         else if(ttl==13) x=0xfffc0000; 
         else if(ttl==14) x=0xfffe0000; 
         else if(ttl==15) x=0xffff0000;          
      }       
   }
   else  ttl=32+k;//end
 }      
                              
void h343_32led_kds_dp_if(usi8 k)    
{                            
   if(ttl<32+k)                             
   {                        
      h343_xu_ly_kds_dp_if(k);                 
      xuat_32led_don_1dw(x);
      x=(x>>1);                                         
      ttl++;
   }                                                  
    else  h332_reset_tang_tcttd_if();  
}     
        
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                         
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//dk 32 led: k diem sang di chuyen vao/ra/trai/phai                       
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void h344_xu_ly_kds_dvdrdtdp_if(usi8 k)  
{          
   if((k!=0)&&(k<9))
   {                                                                     
      if(ttl<k)
      {                                                                    
         if(ttl==0)       {LT=0x8000; LP=0x0001;}
         else if(ttl==1)  {LT=0xc000; LP=0x0003;}                      
         else if(ttl==2)  {LT=0xe000; LP=0x0007;}                      
         else if(ttl==3)  {LT=0xf000; LP=0x000f;}
         else if(ttl==4)  {LT=0xf800; LP=0x001f;}       
         else if(ttl==5)  {LT=0xfc00; LP=0x003f;} 
         else if(ttl==6)  {LT=0xfe00; LP=0x007f;}   
         else if(ttl==7)  {LT=0xff00; LP=0x00ff;}
      }     
   }
   else  ttl=16+k;//end
 }                                   
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                              
void h344_32led_kds_dvdrdtdp_if(usi8 k, usi8 dir)             
{                                                        
   if(ttl<16+k)                             
   {                            
      h344_xu_ly_kds_dvdrdtdp_if(k);                 
      h337_32led_tnv_ttr_pst_tsp(dir);      
      LT=LT>>1; LP=LP<<1;                      
      ttl++;            
   }                                                  
    else  h332_reset_tang_tcttd_if();  
}  

     

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//ham lua chon cac yeu cau dieu khien 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
void h352_32led_tong_hop(usi8 tt)                               
{                                                                                                         
   if(tt==0)   h332_32led_std_pst_if();                                       
   if(tt==1)   h332_32led_std_tsp_if(); 
   if(tt==2)   h337_32led_std_ttrtnv_psttsp_if(0);         
   if(tt==3)   h337_32led_std_ttrtnv_psttsp_if(1);
   if(tt==4)   h337_32led_std_ttrtnv_psttsp_if(2);
   if(tt==5)   h337_32led_std_ttrtnv_psttsp_if(3); 

   if(tt==6)   h338_32led_sd_pst_if();                              
   if(tt==7)   h338_32led_sd_tsp_if(); 
   if(tt==8)   h339_32led_sd_tnvttr_psttsp_if(0);            
   if(tt==9)   h339_32led_sd_tnvttr_psttsp_if(1);       
   if(tt==10)  h339_32led_sd_tnvttr_psttsp_if(2);            
   if(tt==11)  h339_32led_sd_tnvttr_psttsp_if(3);   
                                                   
   if(tt==12)  h340_32led_ds_dp_md_if();
   if(tt==13)  h340_32led_ds_dt_md_if();              
   if(tt==14)  h341_32led_ds_dvdrdpdt_md_if(0);
   if(tt==15)  h341_32led_ds_dvdrdpdt_md_if(1);  
   if(tt==16)  h341_32led_ds_dvdrdpdt_md_if(2);
   if(tt==17)  h341_32led_ds_dvdrdpdt_md_if(3);                                        
 
   if(tt==18)  h342_32led_kds_dt_if(1);
   if(tt==19)  h342_32led_kds_dt_if(2);                      
   if(tt==20)  h342_32led_kds_dt_if(3);
   if(tt==21)  h342_32led_kds_dt_if(4);      
   if(tt==22)  h342_32led_kds_dt_if(5);
   if(tt==23)  h342_32led_kds_dt_if(6);
   if(tt==24)  h342_32led_kds_dt_if(7);   
   if(tt==25)  h342_32led_kds_dt_if(8);  

   if(tt==26)  h342_32led_kds_dt_if(9);
   if(tt==27)  h342_32led_kds_dt_if(10);                      
   if(tt==28)  h342_32led_kds_dt_if(11);
   if(tt==29)  h342_32led_kds_dt_if(12);      
   if(tt==30)  h342_32led_kds_dt_if(13);
   if(tt==31)  h342_32led_kds_dt_if(14);
   if(tt==32)  h342_32led_kds_dt_if(15);   
   if(tt==33)  h342_32led_kds_dt_if(16);                              
                                                         
   if(tt==34)  h343_32led_kds_dp_if(1);                       
   if(tt==35)  h343_32led_kds_dp_if(2);
   if(tt==36)  h343_32led_kds_dp_if(3);
   if(tt==37)  h343_32led_kds_dp_if(4);  
   if(tt==38)  h343_32led_kds_dp_if(5);           
   if(tt==39)  h343_32led_kds_dp_if(6);
   if(tt==40)  h343_32led_kds_dp_if(7);         
   if(tt==41)  h343_32led_kds_dp_if(8);
                                     
   if(tt==42)  h343_32led_kds_dp_if(9);
   if(tt==43)  h343_32led_kds_dp_if(10);      
   if(tt==44)  h343_32led_kds_dp_if(11);
   if(tt==45)  h343_32led_kds_dp_if(12);  
   if(tt==46)  h343_32led_kds_dp_if(13);           
   if(tt==47)  h343_32led_kds_dp_if(14);
   if(tt==48)  h343_32led_kds_dp_if(15);
   if(tt==49)  h343_32led_kds_dp_if(16);  
                               
   if(tt==50)  h344_32led_kds_dvdrdtdp_if(1,0);
   if(tt==51)  h344_32led_kds_dvdrdtdp_if(2,0);                
   if(tt==52)  h344_32led_kds_dvdrdtdp_if(3,0);
   if(tt==53)  h344_32led_kds_dvdrdtdp_if(4,0);  
   if(tt==54)  h344_32led_kds_dvdrdtdp_if(5,0);           
   if(tt==55)  h344_32led_kds_dvdrdtdp_if(6,0);
   if(tt==56)  h344_32led_kds_dvdrdtdp_if(7,0);
   if(tt==57)  h344_32led_kds_dvdrdtdp_if(8,0);    

   if(tt==58)  h344_32led_kds_dvdrdtdp_if(1,1);
   if(tt==59)  h344_32led_kds_dvdrdtdp_if(2,1);                
   if(tt==60)  h344_32led_kds_dvdrdtdp_if(3,1);
   if(tt==61)  h344_32led_kds_dvdrdtdp_if(4,1);  
   if(tt==62)  h344_32led_kds_dvdrdtdp_if(5,1);           
   if(tt==63)  h344_32led_kds_dvdrdtdp_if(6,1);
   if(tt==64)  h344_32led_kds_dvdrdtdp_if(7,1);
   if(tt==65)  h344_32led_kds_dvdrdtdp_if(8,1);   
   if(tt==66)  h344_32led_kds_dvdrdtdp_if(1,2);
   if(tt==67)  h344_32led_kds_dvdrdtdp_if(2,2);                
   if(tt==68)  h344_32led_kds_dvdrdtdp_if(3,2);
   if(tt==69)  h344_32led_kds_dvdrdtdp_if(4,2);  
   if(tt==70)  h344_32led_kds_dvdrdtdp_if(5,2);           
   if(tt==71)  h344_32led_kds_dvdrdtdp_if(6,2);
   if(tt==72)  h344_32led_kds_dvdrdtdp_if(7,2);
   if(tt==73)  h344_32led_kds_dvdrdtdp_if(8,2); 
                                             
   if(tt==74)  h344_32led_kds_dvdrdtdp_if(1,3);
   if(tt==75)  h344_32led_kds_dvdrdtdp_if(2,3);                
   if(tt==76)  h344_32led_kds_dvdrdtdp_if(3,3);
   if(tt==77)  h344_32led_kds_dvdrdtdp_if(4,3);  
   if(tt==78)  h344_32led_kds_dvdrdtdp_if(5,3);           
   if(tt==79)  h344_32led_kds_dvdrdtdp_if(6,3);
   if(tt==80)  h344_32led_kds_dvdrdtdp_if(7,3);
   if(tt==81)  h344_32led_kds_dvdrdtdp_if(8,3);                                   
   //wdl[2] = (ma7doan[tt/10]*256)+ma7doan[tt%10];           
         //xuat_8led_7doan_8so();                                                            
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    
void b339_32led_tong_hop_tu_dong_if()      
{                                                                                                                   
   if(tt_ct_td>81)  tt_ct_td=0;    
   h352_32led_tong_hop(tt_ct_td);              
}     

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//minh hoa cho dap ung nhanh dung if va nha phim              
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
void b339_32led_tong_hop_3bt_if()      
{                                                                    
   if((phim_bt0_c2(20)==co_nhan)&&(tt_ct<11))  
   {                                                       
      tt_ct++;                                     
      h332_reset_tang_tcttd_if();                                       
   }                                                         
   if((phim_bt1_c2(20)==co_nhan)&&(tt_ct>0))    
   {                                                   
      tt_ct--;                             
      h332_reset_tang_tcttd_if();                            
   }                                                 
   h339_32led_tong_hop(tt_ct);                                                       
}                                                           
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//minh hoa cho dap ung anh dung nhanh nhat                     
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
void b333_32led_std_pst_tsp_tat_3bt_if_c2()                
{                                                                    
   if((phim_bt0_c2(1)==co_nhan)&&(tt_ct != 1))        
   {                                              
      tt_ct = 1;                                     
      h332_reset_tang_tcttd_if();                                 
   }                                                         
   if((phim_bt1_c2(1)==co_nhan)&&(tt_ct != 2))      
   {                                                   
      tt_ct = 2;                
      h332_reset_tang_tcttd_if();                                        
   }                          
   if(phim_bt2_c2(1)==co_nhan) 
   {
      tt_ct = 0;  xuat_32led_don_1dw(0);
      h332_reset_tang_tcttd_if();
   }                                                             
   h332_32led_std_pst_tsp_tat_3bt_if(tt_ct);                                                       
}     
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//test thu 1 phim bt0 - khong ok                             
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
void b333_32led_std_pst_tsp_tat_3bt_if_2()      
{                                                                    
   if(phim_bt0_c2(10)==co_nhan)     
   {   
      if(tt_ct==0)                 
      {                                     
         tt_ct = 1;                                                      
         h332_reset_tang_tcttd_if();                                           
      }
      else if(tt_ct==1)        
      {                                                               
         tt_ct = 2;                                     
         h332_reset_tang_tcttd_if();
      }                                   
      else if(tt_ct==2)  
      {                                     
         tt_ct = 0;                                     
         xuat_32led_don_1dw(0);  
      }
   }                
   h332_32led_std_pst_tsp_tat_3bt_if(tt_ct);                                                       
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx           
//dung thu 1 bt0 - ok khong dua vao giao trinh                                 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx     
void b332_32led_std_pst_tsp_tat_3bt_if_2()      
{                                                                    
   if(phim_bt0_c1(c_ktnp,0)==co_nhan)     
   {   
      if(tt_ct==0)
      {                                     
         tt_ct = 1;                                     
         h332_reset_tang_tcttd_if();
      }
      else if(tt_ct==1)
      {                                     
         tt_ct = 2;                                     
         h332_reset_tang_tcttd_if();
      }
      else if(tt_ct==2)
      {                                     
         tt_ct = 0;                                     
         h332_reset_tang_tcttd_if(); 
         xuat_32led_don_1dw(0);
      }
   }                
   h332_32led_std_pst_tsp_tat_3bt_if(tt_ct);                                                       
}                   
 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//minh hoa cho dap ung nhanh dung if va nha phim              
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    
void b334_32led_4yc_2bt_if()      
{                                                                    
   if((phim_bt0_c1(k_ktnp,10)==co_nhan)&&(tt_ct<3))  
   {                                     
      tt_ct++;                                       
      h332_reset_tang_tcttd_if();                                       
   }                                                         
   if((phim_bt1_c1(k_ktnp,10)==co_nhan)&&(tt_ct>0))  
   {                                                                     
      tt_ct--;                                                                                    
      h332_reset_tang_tcttd_if();                            
   }                    
   h334_32led_4yc(tt_ct);                                                       
}               

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//minh hoa cho dap ung nhanh dung if va nha phim              
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    
void b335_32led_4yc_2bt_if()                                  
{                                                                    
   if((phim_bt0_c2(20)==co_nhan)&&(tt_ct<3))  
   {                                                                                           
      tt_ct++;                                                     
      h332_reset_tang_tcttd_if();                                       
   }                                                                             
   if((phim_bt1_c2(20)==co_nhan)&&(tt_ct>0))               
   {                                                                     
      tt_ct--;                                                                                    
      h332_reset_tang_tcttd_if();                            
   }                                                                         
   h334_32led_4yc(tt_ct);                                                       
}        

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//dung thu 1 bt0 - ok              
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx         
//!void b331_32led_std_pst_tsp_tat_3bt_c2()                       
//!{                                                                   
//!   if(phim_bt0_c1(c_ktnp,0)==co_nhan) 
//!   {
//!      if(tt_ct == 0)      tt_ct = 1;  
//!      else if(tt_ct == 1) tt_ct = 2;
//!      else if(tt_ct == 2)                                    
//!      {                 
//!         tt_ct = 0;
//!         xuat_32led_don_1dw(0);
//!      }                                    
//!   }
//!   h331_32led_std_pst_tsp_tat_3bt(tt_ct);                                                       
//!}
