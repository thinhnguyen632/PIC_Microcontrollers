#define at24_addr_wr 0xa0
#define at24_addr_rd 0xa1
void at24_reset()
{                
   i2c_start();         
   i2c_stop();
}
void at24_khoi_tao_ghi(usi16 addr)
{                 
   i2c_start();                       
   i2c_write(at24_addr_wr);  
   i2c_write(addr>>8);         
   i2c_write(addr);         
}
    
void at24_khoi_tao_doc(usi16 addr)
{   
   i2c_start();
   i2c_write(at24_addr_wr);  
   i2c_write(addr>>8);        
   i2c_write(addr);           
   i2c_start();                
   i2c_write(at24_addr_rd);  
}    
void at24_ghi_1byte(usi16 addr,usi8 data_1byte)
{          
   i2c_start();                     
   i2c_write(at24_addr_wr);  
   i2c_write(addr>>8);         
   i2c_write(addr);   
   i2c_write(data_1byte);   
   i2c_stop();
}

unsigned int8 at24_doc_1byte(usi16 addr)
{   
   unsigned int8 data_1byte;
   i2c_start();           
   i2c_write(at24_addr_wr);  
   i2c_write(addr>>8);        
   i2c_write(addr);           
   i2c_start();                
   i2c_write(at24_addr_rd);  
   data_1byte = i2c_read(0);
   i2c_stop();
   return(data_1byte);
}  

