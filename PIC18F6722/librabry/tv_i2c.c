                 
#define  ds13_addr_wr 0xd0
#define  ds13_addr_rd 0xd1
#define  ds13_addr_me 0x00

//!#define  ma_ds13      0xff                                                      
usi8 giay_tam;
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//khai bao mang: giay-phut-gio-thu-ngay-thang-nam-madk_msds  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx      
usi8 time_w[9]={0x30,0x09,0x15,0x01,0x20,0x09,0x20,0x90,0x96};  
usi8 time_r[9]={0x30,0x30,0x10,0x08,0x20,0x02,0x20,0x90,0x96};
#define  giay_ds time_r[0]              
#define  phut_ds time_r[1]                  
#define  gio_ds  time_r[2]
#define  ma_qd   time_w[8] 
#define  ma_ds   time_r[8] 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//cap nhat time: giay-phut-gio-thu-ngay-thang-nam-madk_msds  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
void ds1307_cap_nhat_time(int1 sel)                 
{         
   usi8 i;
   i2c_start();
   i2c_write(ds13_addr_wr);        
   i2c_write(0x00);   
   for(i=0;i<9;i++)                          
   {  
      if(sel)  i2c_write(time_w[i]);
      else     i2c_write(time_r[i]);
   }
   i2c_stop();                                
}                      
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//doc thoi gian   
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                             
void ds1307_doc_time(usi8 j)     
{   
   usi8 i; 
   i2c_start();
   i2c_write(ds13_addr_wr);
   i2c_write(ds13_addr_me);                     
   i2c_start();                
                
   i2c_write(ds13_addr_rd);
   for(i=0;i<j;i++) time_r[i]=i2c_read();  
                                 
   i = i2c_read(0); //not ack, don't care i  
   i2c_stop();
}    
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//kiem tra ma da luu: sai thi cap nhat, dung thi thoat
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx           
void ds1307_kiem_tra_ma()   
{                                              
   ds1307_doc_time(8);
   if(ma_qd!=ma_ds[8])   
   ds1307_cap_nhat_time(1);   
}



//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//thu vien cua pcf8591: 4adc:2lm35, joystick, 1dac: led
//step size bang 5
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
#define  pcf_addr_wr  0x90                    
#define  pcf_addr_rd  0x91

#define  pcf_chan0 0x40
#define  pcf_chan1 0x41
#define  pcf_chan2 0x42
#define  pcf_chan3 0x43
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//ham thiet lap kenh
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                    
void pcf8591_chonkenh(usi8 kenh)
{                                  
   i2c_start();
   i2c_write(pcf_addr_wr);
   i2c_write(kenh);
   i2c_stop();
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//ham vua chon kenh, vua xuat du lieu ra DAC
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
void pcf8591_xuat_dac(usi8 dac_out)
{
   i2c_start();                     
   i2c_write(pcf_addr_wr);
   i2c_write(pcf_chan0);
   i2c_write(dac_out);
   i2c_stop();             
}                    
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//ham thiet lap kenh va doc ket qua cua lan truoc 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
usi8  pcf8591_doc_adc(usi8 ch)
{    
   usi8 kq; 
   kq=0;  
   pcf8591_chonkenh(ch);
   i2c_start();                           
   i2c_write(pcf_addr_rd);        
   kq= i2c_read(0);
   i2c_stop();
   return kq;
}



                                                                
