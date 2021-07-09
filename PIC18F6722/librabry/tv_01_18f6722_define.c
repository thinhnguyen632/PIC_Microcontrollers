//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Khai bao thu vien MCU PIC, ADC, Cau hinh, tan so dao dong
//khoi tao I2C, RS232, SPI neu co dung
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx           
#include    <18f6722.h>
#device     adc=10                                                                  
#fuses      nowdt,noprotect,put,Hs,CCP2C1=1                 
#use        delay(clock=20000000)//phai nam tren I2C, rs232               
#use        i2c(master,slow,sda=pin_c4,scl=pin_c3)      
#use        spi(SPI2,STREAM=SPI_2)//SPI(SPI2)
#use        rs232(stream=uart1,baud=9600,xmit=pin_c6,rcv=pin_c7)      
#use        rs232(stream=uart2,baud=9600,xmit=pin_g1,rcv=pin_g2)       

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//dinh nghia ten cac nut nhan giao tiep voi 4 port     
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx     
#define  bt0     pin_b6 
#define  bt1     pin_f1                                        
#define  bt2     pin_b4
#define  bt3     pin_b7   

#define  on      bt0       
#define  off     bt1
#define  inv     bt2

#define  up      bt0    
#define  mod     bt1
#define  dw      bt2
#define  clr     bt3

#define  stop    bt3
#define  on1     bt0     
#define  off1    bt1
#define  on2     bt2       
#define  off2    bt3
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//dinh nghia ten cac port giao tiep cua pic18f6722
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx           
//cac port giao tiep ban phim tuoch theo chuan 2 day
#define  kp_ck   pin_f3
#define  kp_dt   pin_f2
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//cac port giao tiep truc tiep voi ban phim touch   
#define  kp_01   pin_e1             
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx           
//port giao tiep voi joystick: 2 bien tro va nut nhan 
#define  btj     pin_e0  
#define  btvrx   pin_a2   //AN2 - analog
#define  btvry   pin_a1   //AN1 - analog
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//port giao tiep cam bien nhiet lm35a, lm35b         
#define  cblm35b pin_a0   //AN0 - analog
#define  cblm35a pin_a5   //AN4 - analog  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//port giao tiep cam bien khoang cach GP2D12
#define  cbkc    pin_a3   //AN3 - analog                                                     
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//port nhan xung cua T0 tu mach tao xung khi co san pham
#define  cbsp    pin_a4   //RA4/T0CKI   
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//port nhan xung cua tu ENCODER 360     
#define  rtenc_a  pin_b5          
#define  rtenc_b  pin_e4                                     
#define  rtenc_sw pin_f0   
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//cac port tao PWM1 va PWM2 de dieu khien dong co DC
#define  pwm1    pin_c2   //RC2/ECCP1/P1A  
#define  pwm2    pin_c1   //RC1/ECCP2/P2A    
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//port phat hien diem 0V cua nguon AC 220V 
#define  ph_d0   pin_b0//pin_e2     
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//port dieu khien dong co servo
#define  servo2  pin_e5                                 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//cac port giao tiep cam bien sieu am 
#define  echo    pin_e6
#define  trig    pin_e7    
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//cac port giao tiep voi module adc hx711 va load cell 
#define  hx_dt   pin_d0
#define  hx_ck   pin_d1                                 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//port giao tiep voi vi mach do nhiet do ds18b20 A và B 
#define  ds18    pin_g0
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//port giao tiep cam bien nhiet va do am 1 day DHT11 
#define  dht11   pin_g3
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//port giao tiep cam bien phay hien nguoi 
#define  pir     pin_d3       
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//port giao tiep led thu hong ngoai                        
#define  irf     pin_e2//pin_b0  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx     
//cac port giao tiep voi cac IC MBI5026 theo chuan: 
//noi tiep hoac SPI deu duoc  
#define  mbi_sdi  pin_d4   //MOSI   
#define  mbi_sck  pin_d6   //SCK   
#define  miso     pin_d5   //MISO  giao tiep RFID/NRF    
                            
#define  mbi_oe   pin_c5   //output enable    
#define  mbi_le0  pin_b3   //latch enable le/le0 
#define  mbi_le1  pin_f6   //latch enable le1
#define  mbi_le2  pin_f5
#define  mbi_le3  pin_g4                                                     
#define  mbi_le4  pin_f7
#define  mbi_le5  pin_f4                        
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//cac port giao tiep chuan SPI: MOSI va SCK la d4 va d6  
//con them cac tin hieu de giao tiep RFID    
#define  rfid_ss  pin_d2 
#define  rfid_irq pin_b1
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//cac port giao tiep chuan SPI: MOSI va SCK la d4 va d6              
//cac port giao tiep dieu khien cua module NRF                      
#define  nrf_ss  pin_d7      
#define  nrf_irq pin_b2  
#define  nrf_csn pin_e3    
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//cac port truyen du lieu UART                      
#define  tx0     pin_c6   //RC6/TX1/CK1        
#define  rx0     pin_c7   //RC7/RX1/DT1  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//cac port truyen du lieu I2C
#define  scl     pin_c3   //RC3/SCK1/SCL1        
#define  sda     pin_c4   //RC4/SDI1/SDA1
                                                   


 
       
