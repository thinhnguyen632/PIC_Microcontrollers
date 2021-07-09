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
   if (tt_dir==10)
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
   
}

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
