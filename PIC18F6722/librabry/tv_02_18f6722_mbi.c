//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                   
//dinh nghia lai ten cac loai du lieu cho ngan gon hon    
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                                                                                            
#define  usi8  unsigned int8                                        
#define  usi16 unsigned int16           
#define  usi32 unsigned int32                                                                   
#define  si8   signed   int8 
#define  si16  signed   int16                              
#define  si132 signed   int32 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//dinh nghia lai ten thay cho cac gia tri 1/0 hoac true/false     
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
#define co_reset  true
#define no_reset  false 

#define tt_on     1          
#define tt_off    0                    
#define enable    1                        
#define disable   0
#define sang      1          
#define tat       0  
#define tat_l7d  0xff     
#define cx_vn     true     //co xoa so 0 vo nghia        
#define kx_vn     false    //khong xoa so 0 vo nghia          
#define co_fill  true
#define no_fill  false 
#define c_reset    1          
#define k_reset    0 
                 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//khai bao bien 16 bit de dkhien 2relay, 2triac, 1buzzer, 
//1 step motor L298, 1 step motor A4988 vi buoc  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
unsigned int16 rbdc = 0;
#bit step_motor_enable  = rbdc.0   
#bit ms1                = rbdc.1 
#bit ms2                = rbdc.2 
#bit ms3                = rbdc.3 
#bit step               = rbdc.4 
#bit dir                = rbdc.5 
#bit servo1             = rbdc.6   

#bit step_motor_in1     = rbdc.7    
#bit step_motor_in2     = rbdc.8
#bit step_motor_in3     = rbdc.9
#bit step_motor_in4     = rbdc.10

#bit triac_1            = rbdc.11   //1=on,0=off
#bit triac_2            = rbdc.12   //1=on,0=off
#bit buzzer             = rbdc.13   //1=on,0=off
#bit relay_1            = rbdc.14   //1=on,0=off
#bit relay_2            = rbdc.15   //1=on,0=off     

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//ma 7 doan de giai ma hien thi tren cac led 7 doan             
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
const unsigned char ma7doan[16]= 
{  0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,
   0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
#define     maso0    0xc0              
                                                     
#define tat_32led()   xuat_32led_don_1dw(0) 
#define sang_32led()  xuat_32led_don_1dw(0xffffffff)

                                                          

void khoi_tao_cac_bien();   
void xoa_tat_ca_cac_module();
void xuat_32led_don();      
void xuat_rbdc();
void xuat_3led_matran();
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//ham 301: khoi tao cac port cua PIC18F6722
//xuat du lieu dieu khien tat het cac module
//reset tat cac bien da khai bao
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    
void set_up_port()
{            
   set_tris_a(0xff);                      
   set_tris_b(0b11110001);        
   set_tris_c(0b11000001);
   output_high(mbi_oe);                          
   output_low(pwm1);
   output_low(pwm2);   
   
   set_tris_d(0b00001000);
   set_tris_e(0b01011111);                                            
   set_tris_f(0b00000111);    
   set_tris_g(0b00010110);//(0x16);    
   
   output_low(mbi_le0);   
   output_low(mbi_le1);
   output_low(mbi_le2);
   output_low(mbi_le3); 
   output_low(mbi_le4);    
   output_low(mbi_le5);
                    output_high(kp_ck);
   rbdc=0;         
            
   xoa_tat_ca_cac_module();
   output_low(mbi_oe); 
   output_high(rfid_ss);
   output_high(nrf_ss);       
   setup_spi2(SPI_MASTER|SPI_L_TO_H|SPI_XMIT_L_TO_H); 
//!   khoi_tao_cac_bien();                                                              
   setup_adc(adc_clock_div_2);      
   setup_adc_ports(an0_to_an4|vss_vdd ); 
   //setup_timer_1(t1_disabled);
}                         
                                                      
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//ham 301: ham xuat du lieu 1 word theo chuan SPI        
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx       
void xuat_1word(usi16 x)
{                                                         
   spi_write2(x>>8);   spi_write2(x);
}                             
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//ham 302: ham xuat du lieu cua bien rbdc module relay, buzzer, 
//dong co, triac, relay
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
void xuat_rbdc()
{     
   xuat_1word(rbdc);   
   output_high(mbi_le5);   output_low(mbi_le5); 
}                     
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//ham 302: ham xuat du lieu 2 byte ra module lcd 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
void xuat_lcd(usi8 ctrl,db)     
{            
   spi_write2(~ctrl);      spi_write2(~db);                             
   output_high(mbi_le3);   output_low(mbi_le3); 
}           
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//ham 303: chuong trinh con xuat du lieu 1 word ra glcd 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
void xuat_glcd(usi8 ctrl,db)
{            
   spi_write2(~ctrl);      spi_write2(~db);  
   output_high(mbi_le4);   output_low(mbi_le4); 
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//ham 304: ham xuat du lieu 4 word ra module 3 led ma tran
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
usi16 wlmt[4]= {0,0,0,0};
void xuat_3led_matran()
{  
   xuat_1word(wlmt[3]);    xuat_1word(wlmt[2]);
   xuat_1word(wlmt[1]);    xuat_1word(wlmt[0]);
   output_high(mbi_le2);   output_low(mbi_le2); 
}                                            
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//ham 305: ham xuat 8 byte ra module 8 led 7 doan 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
usi8 led_7d[8]={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
void xuat_8led_7doan()
{  
   si8 i;
   for(i=7;i>-1;i--)       spi_write2(~led_7d[i]);    
   output_high(mbi_le1);   output_low(mbi_le1);   
}   
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//ham 306: ham xuat 2 word ra 32 module led don   
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                       
void xuat_32led_don_2word(usi16 wld1,usi16 wld0)                   
{                                              
   xuat_1word(wld1);       xuat_1word(wld0);                    
   output_high(mbi_le0);   output_low(mbi_le0);  
}  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//ham 307: ham xoa tat ca cac module 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
void xoa_tat_ca_cac_module()   
{                        
   xuat_rbdc();      
   xuat_glcd(0xff,0xff);              
   xuat_lcd(0xff,0xff);          
   xuat_3led_matran();          
   xuat_8led_7doan();        
   xuat_32led_don_2word(0,0);        
}                       
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//ham 308: ham xuat 1 double word ra module 32 led don
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
void xuat_32led_don_1dw(usi32 dwld)
{     
   usi16  wd1,wd0;
   wd1 = dwld>>16;  wd0 = dwld;
   xuat_32led_don_2word(wd1,wd0);
} 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//ham 309: ham xuat 4 byte ra module 32 led don
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx         
void xuat_32led_don_4byte(usi8 bld3,bld2,bld1,bld0)
{                    
   spi_write2(bld3);       spi_write2(bld2);
   spi_write2(bld1);       spi_write2(bld0);      
   output_high(mbi_le0);   output_low(mbi_le0);  
} 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//ham 310: ham xuat 1 byte ra module 32 led don
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
void xuat_32led_don_1byte(usi8 b0)
{     
   xuat_32led_don_4byte(0,0,0,b0);
}   
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                   
//ham 311: ham dieu khien buzzer keu
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
void buzzer_on()
{    
   buzzer=1;   xuat_rbdc();         
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                   
//ham 312: ham tat buzzer 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
void buzzer_off()
{     
   buzzer=0;   xuat_rbdc();
}
void buzzer_on_off(usi16 dl)
{     
   buzzer=1;
   xuat_rbdc();
   delay_ms(dl);
   buzzer=0;
   xuat_rbdc();
   
}  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                   
//ham 313: ham dieu khien relay 1 on 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
void relay_1_on()
{    
   relay_1=1;  xuat_rbdc();         
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                   
//ham 314: ham dieu khien relay 1 off 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
void relay_1_off()
{    
   relay_1=0;  xuat_rbdc();         
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                   
//ham 315: ham dieu khien relay 2 on 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
void relay_2_on()
{    
   relay_2=1;  xuat_rbdc();         
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                   
//ham 316: ham dieu khien relay 2 off 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
void relay_2_off()
{    
   relay_2=0;  xuat_rbdc();         
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                   
//ham 317: ham dieu khien relay 1 va 2 on 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
void relay_1_relay_2_on()
{    
   relay_1=1;  relay_2=1;  xuat_rbdc();         
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                   
//ham 318: ham dieu khien relay 1 va 2 off 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
void relay_1_relay_2_off()
{    
   relay_1=0;  relay_2=0;  xuat_rbdc();         
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                   
//ham 319: ham dieu khien triac 1 on 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
void triac_1_on()
{    
   triac_1=1;  xuat_rbdc();         
}    
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                   
//ham 320: ham dieu khien triac 1 off 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
void triac_1_off()
{    
   triac_1=0;  xuat_rbdc();         
}             
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                   
//ham 321: ham dieu khien triac 2 on 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
void triac_2_on()
{    
   triac_2=1;  xuat_rbdc();         
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                   
//ham 322: ham dieu khien triac 2 off 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void triac_2_off()
{    
   triac_2=0;
   xuat_rbdc();        
}   
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                   
//ham 323: ham dieu khien triac 1 va 2 on 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
void triac_1_triac_2_on()
{    
   triac_1=1;  triac_2=1;   xuat_rbdc();        
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                   
//ham 324: ham dieu khien triac 1 va 2 off
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
void triac_1_triac_2_off()
{    
   triac_1=0;  triac_2=0;
   xuat_rbdc();         
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    
//xuat 1 bit roi tra lai ket qua sau khi dich di 1 bit
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    
/*                              
unsigned  int8 xuat_1bit(unsigned int8 bytexuat)
{
      unsigned int8   xbitx;   
      #bit bserix  = xbitx.0
      xbitx = bytexuat;
                                            
      output_bit(mbi_sdi,bserix);    
      output_low(mbi_sck); 
      output_high(mbi_sck);
      xbitx= xbitx>>1;   
      return(xbitx);  
}
*/       


//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//ham 302: xuat 1 word 2 byte 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx        
//!void xuat_1word(usi16 x)
//!{
//!   int8 i;
//!   #bit bmsb  = x.15
//!   for (i=0;i<16;i++)       
//!   {                                                 
//!      output_bit(mbi_sdi,bmsb);                      
//!      output_high(mbi_sck);
//!      output_low(mbi_sck);  
//!      x = x << 1;         
//!   }                 
//!}      

//!int1 tt_led=0,tt_on_off=0,tt_ena_dis=0,tt_inv=0; 
//!int1 t0_on_off=0,tt_1btn=0;   
//!int1 t3_on_off=0; 
//!int1 refresh=0;                                   
//!//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    
//!//ham 301: ham khoi tao cac port va ic chot                      
//!//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
//!unsigned int32  x=0; 
//!unsigned int16  LP=0, LT=0, mp16, ma_16led, t0, t0_tam;
//!unsigned int8   mp8;              
//!unsigned int8   tt_ct=0, tt_ct_td=0;        
//!unsigned int16  dl_btn=0;                  
//!
//!                                
//!signed int8 giay=0,phut=0,gio=0,ngay=1,thang=1,nam,thu=2,bdn=0,gt_mod=0;  
//!signed int8 giay_tam=0,thoi_gian_chinh;
//!signed int16  i,dem=0, dem_tam=-1,giay_cai=5,giay_dem=0;                                        
//!                             
//!unsigned int8 ma_8led;//,bl0=0,bl1=0,bl2=0,bl3=0;        
//!unsigned int8  ch_ngan,ngan,tram,chuc,donvi;  
//!unsigned int8  dg32=32, dt32=0;             
//!unsigned int32 x32=0, y32_pst=1, z32=0,   y32_tsp=0x80000000;    
//!unsigned int8  dg16=32, dt16=0;     
//!unsigned int16 y16_pst=1, z16_pst=0,   y16_tsp=0x8000, z16_tsp=0; 
//!
//!unsigned int32 v32_pst=0xfffffffe,v32_tsp=0x7fffffff;
//!unsigned int32 u32_pst=0x80000000,u32_tsp=1;   
//!unsigned int8  cnt1=1, cnt2=1; 
//!
//!unsigned int32 v16_pst=0xfffe,v16_tsp=0x7fff;
//!unsigned int32 u16_pst=0x8000,u16_tsp=1; 
//!
//!unsigned int8 ttl;                                   
//!int1 co_ngat = 0;//no  
//!unsigned int8 channel;                    


//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
//ham 302: ham khoi tao cac bien 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
//!void khoi_tao_cac_bien()   
//!{
//!   x=ma7doan[1];  rbdc = 0;        refresh=0;
//!   i=0; LP=0; LT=0;   
//!   x=0;    
//!   
//!   tt_on_off=0;  tt_led=0;
//!   mp8=0; mp16=0;     ma_8led =0;     ma_16led =0;
//!                                        
//!   t0 = 0, t0_tam = 1;
//!   
//!   bdn = 0; giay = 0; phut = 0; gio = 0;
//!   ngay = 0; thang = 0; nam = 0; thu = 0;
//!   gt_mod=0; 
//!   dl_btn=0;    thoi_gian_chinh=0;
//!   
//!   tt_ena_dis=0;
//!   t0_on_off=0; t3_on_off=0;
//!   tt_1btn=0;
//!   tt_inv=0;     
//!   
//!   giay_cai=5;  giay_dem=0;              
//!   t3_on_off=0;                        
//!                                           
//!   //bl0=0;bl1=0;bl2=0;bl3=0;                        
//!   tt_ct=0; tt_ct_td=0; 
//!   dem_tam=-1;
//!   ch_ngan=0;ngan=0;tram=0;chuc=0;donvi=0; 
//!   
//!   dg32=32; dt32=0;                                                           
//!   x32=0; y32_pst=1; z32=0;   y32_tsp=0x80000000;
//!   
//!   dg16=16; dt16=0;
//!   y16_pst=1;        z16_pst=0;   
//!   y16_tsp=0x8000;   z16_tsp=0;  
//!   channel=0;                                                            
//!}    
