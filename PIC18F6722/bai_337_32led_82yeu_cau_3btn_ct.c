#include <tv_kit_vdk_18f6722_all.c>

usi8 ttl, tt_dir;
usi32 x;
usi16 LT,LP;
unsigned int32 i,j,y,ydon,don_pst,don_tsp;
unsigned int16 i16,j16,y16_LT, y16_LP,don16_pst,don16_tsp;

unsigned int32 x32=0, y32_pst=1, z32=0,   y32_tsp=0x80000000; 
unsigned int16 y16_pst=1, z16_pst=0,   y16_tsp=0x8000, z16_tsp=0;

unsigned int32 v32_pst=0xfffffffe,v32_tsp=0x7fffffff;
unsigned int32 u32_pst=0x80000000,u32_tsp=1;   
unsigned int8  cnt1=1, cnt2=1; 

unsigned int32 v16_pst=0xfffe,v16_tsp=0x7fff;
unsigned int32 u16_pst=0x8000,u16_tsp=1; 

unsigned int8 k;

void h327_reset_tang_tcttd_if()
{
   ttl=0; x=0; LT=0; LP=0;
   i=32; j=0; ydon=0; y=0; don_pst=1; don_tsp=0x80000000;
   i16=16; j16=0; y16_LT=0; y16_LP=0; don16_pst=1; don16_tsp=0x8000;
   
   x32=0; z32=0;                                   
   y32_pst=1;                        
   y32_tsp=0x80000000;
   
   y16_pst=1;        z16_pst=0;                        
   y16_tsp=0x8000;   z16_tsp=0; 
   
   v32_pst=0xfffffffe;    
   v32_tsp=0x7fffffff;
   cnt1=1; cnt2=1;
   u32_tsp=0x80000000;   u32_pst=1;
   v16_pst=0xfffe;      v16_tsp=0x7fff;
   u16_pst=0x0001;      u16_tsp=0x8000;  
}

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
   
   //yeu cau 6
   if (tt_dir==4)
   {
      if (i>0)
      {
         if(i>j)
         {
            ydon = y|don_pst;
            xuat_32led_don_1dw(ydon);
            don_pst = don_pst << 1;
            j++;
         }
         if(i==j)
         {
            i--;
            j=0;
            y = ydon;
            don_pst = 1;
         }
      }
      else h327_reset_tang_tcttd_if();
   }
   
   //yeu cau 7
   if (tt_dir==5)
   {
      if (i>0)
      {
         if(i>j)
         {
            ydon = y|don_tsp;
            xuat_32led_don_1dw(ydon);
            don_tsp = don_tsp >> 1;
            j++;
         }
         if(i==j)
         {
            i--;
            j=0;
            y = ydon;
            don_tsp = 0x80000000;
         }
      }
      else h327_reset_tang_tcttd_if();
      delay_ms(10);
   }
   
   //yeu cau 8
   if (tt_dir==6)
   {
      if(i16>0)                                       
      {                            
         if(i16>j16)      
         { 
            LP = y16_LP|don16_pst;
            LT = y16_LT|don16_tsp;
            xuat_32led_don_2word(LT,LP);                     
            don16_pst = don16_pst<<1;         
            don16_tsp = don16_tsp>>1; 
            j16++;
         }
         if(i16==j16) 
         {
            i16--;
            j16=0;                                            
            y16_LP=LP;  y16_LT=LT;         
            don16_pst = 1; don16_tsp = 0X8000;
         }
      }                                             
      else  h327_reset_tang_tcttd_if();
   }
   
   //yeu cau 9
   if (tt_dir==7)
   {
      if(i16>0)                                       
      {                            
         if(i16>j16)      
         { 
            LP = y16_LP|don16_tsp;
            LT = y16_LT|don16_pst;
            xuat_32led_don_2word(LT,LP);                     
            don16_pst = don16_pst<<1;         
            don16_tsp = don16_tsp>>1; 
            j16++;
         }
         if(i16==j16) 
         {
            i16--;
            j16=0;                                            
            y16_LP=LP;  y16_LT=LT;         
            don16_pst = 1; don16_tsp = 0X8000;
         }
      }                                             
      else  h327_reset_tang_tcttd_if();
   }
   
   //yeu cau 10
   if (tt_dir==8)
   {
      if(i16>0)                                       
      {                            
         if(i16>j16)      
         { 
            LP = y16_LP|don16_pst;
            LT = y16_LT|don16_pst;
            xuat_32led_don_2word(LT,LP);                     
            don16_pst = don16_pst<<1;          
            j16++;
         }
         if(i16==j16) 
         {
            i16--;
            j16=0;                                            
            y16_LP=LP;  y16_LT=LT;         
            don16_pst = 1; don16_tsp = 0X8000;
         }
      }                                             
      else  h327_reset_tang_tcttd_if();
   }
   
   //yeu cau 11
   if (tt_dir==9)
   {
      if(i16>0)                                       
      {                            
         if(i16>j16)      
         { 
            LP = y16_LP|don16_tsp;
            LT = y16_LT|don16_tsp;
            xuat_32led_don_2word(LT,LP);                     
            don16_tsp = don16_tsp>>1;          
            j16++;
         }
         if(i16==j16) 
         {
            i16--;
            j16=0;                                            
            y16_LP=LP;  y16_LT=LT;         
            don16_pst = 1; don16_tsp = 0X8000;
         }
      }                                             
      else  h327_reset_tang_tcttd_if();
      delay_ms(10);
   }
   
   //yeu cau 12
   if (tt_dir==10)
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
      else  h327_reset_tang_tcttd_if();
   }
   
   //yeu cau 13
   if (tt_dir==11)
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
      else  h327_reset_tang_tcttd_if();
   }
   
   //yeu cau 14
   if (tt_dir==12)
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
      else  h327_reset_tang_tcttd_if();       
   }
   
   //yeu cau 15
   if (tt_dir==13)
   {
      if(cnt1<17)                                             
      {                                                      
         if(cnt2>0)                         
         {                                                          
            y16_pst = y16_pst>>1;
            y16_tsp = y16_tsp<<1;
                
            LT = v16_tsp|y16_tsp;        
            LP = v16_pst|y16_pst;                  
            xuat_32led_don_2word(LT,LP);  
            
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
      else  h327_reset_tang_tcttd_if(); 
   }
   //yeu cau 16
   if (tt_dir==14)
   {
      if(ttl<32+k)                             
      {                    
         h342_xu_ly_kds_dt_if(k);                 
         xuat_32led_don_1dw(x);
         x=(x<<1);
         ttl++;
      }                                                  
      else  h327_reset_tang_tcttd_if();
   }
   
   //yeu cau 17
   if(tt_dir==15)
   {
      if(ttl<32+k)                             
      {                        
         h343_xu_ly_kds_dp_if(k);                 
         xuat_32led_don_1dw(x);
         x=(x>>1);                                         
         ttl++;
      }                                                  
      else  h327_reset_tang_tcttd_if();
   }
   
   //yeu cau 18-33
   if(tt_dir==16)
   {
      if(ttl<16+k)                             
      {                            
         h344_xu_ly_kds_dvdrdtdp_if(k);                 
         xuat_32led_don_2word(LT,LP);      
         LT=LT>>1; LP=LP<<1;                      
         ttl++;            
      }                                                  
      else  h327_reset_tang_tcttd_if();
   }
   
   //aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa :(((
}

////////////////////////////////

void kt_bt()
{
   if(phim_bt0_c2(2)==co_nhan)
   {
      if(tt_dir<4)
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
