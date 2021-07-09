                                                               
unsigned int16 hx711_read()                                             
{                                                                                               
   signed int32 kq=0;                    
   unsigned int8 i;                           
                                                                                 
   output_low(hx_ck);    
   while(input(hx_dt));                                                                                         
   for (i=0;i<24;i++)                                         
   {
      output_high(hx_ck);       
      kq=kq<<1;                           
      output_low(hx_ck);          
      if(input(hx_dt)) kq++;      
   }             
                        
    output_high(hx_ck);        
    kq=kq^0x800000;             
    output_low(hx_ck);            
                                         
    xuat_32led_don_1dw(kq);  
    kq = (12954880-kq)/280;  //nha
    //kq = (8296960-kq)/237;  //320 thay doi   d501
    //kq = (8475130-kq)/248;  //320 thay doi   ff9300 d402
    //kq = (8303028-kq)/258;  //320 thay doi    
    if(kq<0) kq = 0;                
    return(kq); 
}                             

