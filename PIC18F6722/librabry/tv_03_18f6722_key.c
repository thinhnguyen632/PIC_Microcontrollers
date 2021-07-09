//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//thu vien cho cac phim don va ban phim cam ung
//co 2 cach phat hien va chong doi phim nhan
//tra ve 
//tac gia: NDP su pham kt thuat tp hcm
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//dinh nghia cac trang thai co nhan va khong nhan phim
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
#define co_nhan      1            
#define khong_nhan   0           
#define c_ktnp       1  //co kiem tra nha phim          
#define k_ktnp       0  //khong kiem tra nha phim 
#define sole_1       false            
#define sole_2       true   

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//ham doc ma phim cua ban phim touch: tra ve ma phim 8 bit, 
//bang 0 la khong nhan, tu 1 den 16 tuong ung neu nhan 
//phim 1 den phim 16, chi co 1 phim tich cuc  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
unsigned int8 key_tip229()                
{
   unsigned int8 i,key=0; 
   {
      for(i=1;i<17;i++)
      {                                                  
         output_low(kp_ck);   
         delay_us(70);
         if (!input(kp_dt))  key = i;
         output_high(kp_ck);
         delay_us(70);
      }   
      return key;
   }
}
#define key_4x4_up() key_tip229_cdoi()
#define key_4x4_dw() key_tip229_cdoi()

unsigned int8 key_tip229_cdoi()                
{  
   unsigned int8 key1,key;   
   key = key_tip229();
   if((key>0)&&(key<17))
   {
      delay_ms(45);      
      key1=key_tip229();
      if(key1==key)  return key;     
      else return 0xff;
   }  
   else return 0xff;
} 

unsigned int8 dl_tip=0;
unsigned int8 key_tip229_cdoi_c2(usi8 dl)                
{  
   unsigned int8 key;   
   key = key_tip229();
   if((key>0)&&(key<17))
   {
      delay_ms(1);  
      dl_tip++;
      if(dl_tip>dl)
      {
         dl_tip=0;
         return key;
      }
      else return 0xff;
   }  
   else return 0xff;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//cac ham con cua cac phim nhan don theo cach 1
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//phim bt0-cach 1: co chong doi, delay 20ms, cho nha phim
//dinh nghia them 1 so ten khac     
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                       
#define phim_on_c1  phim_bt0_c1    
#define phim_run_c1 phim_bt0_c1 
#define phim_up_c1  phim_bt0_c1       

int1 phim_bt0_c1(int1 ktnp,usi16 dl)   
{                    
   if (!input(bt0))   
   {        
      delay_ms(20);                                     
      if (!input(bt0))
      {
         if(ktnp) while(!input(bt0));
         delay_ms(dl);
         return co_nhan;      
      }                      
      return khong_nhan;   
   }         
  return khong_nhan;  
}     
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//phim bt1-cach 1: co chong doi, delay 20ms, cho nha phim
//dinh nghia them 1 so ten khac      
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
#define phim_off_c1   phim_bt1_c1
#define phim_inv_c1   phim_bt1_c1
#define phim_stop_c1  phim_bt1_c1   
#define phim_mode_c1  phim_bt1_c1                   
int1 phim_bt1_c1(int1 ktnp,usi16 dl)                                               
{
   if (!input(bt1))   
   {                       
      delay_ms(20);
      if (!input(bt1))
      {
         if(ktnp) while(!input(bt1));    
         delay_ms(dl);
         return co_nhan;
      } 
      return khong_nhan;
   }
   return khong_nhan;  
}       
     
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//phim bt2-cach 1: co chong doi, delay 20ms, cho nha phim
//dinh nghia them 1 so ten khac      
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  

#define phim_dw_c1    phim_bt1_c1 
int1 phim_bt2_c1(int1 ktnp,usi16 dl)      
{
   if (!input(bt2))   
   {        
      delay_ms(20);                
      if (!input(bt2))
      {
         if(ktnp) while(!input(bt2));    
         delay_ms(dl);
         return co_nhan;
      }                                     
      return khong_nhan; 
   }
   return khong_nhan;  
}      
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//phim bt3-cach 1: co chong doi, delay 20ms, cho nha phim
//dinh nghia them 1 so ten khac      
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx     

#define phim_ud_c1    phim_bt3_c1  
int1 phim_bt3_c1(int1 ktnp,usi16 dl)      
{                       
   if (!input(bt3))   
   {                       
      delay_ms(20);                       
      if (!input(bt3))
      {                      
         if(ktnp) while(!input(bt3));    
         delay_ms(dl);
         return co_nhan;
      } 
      return khong_nhan;   
      }                       
   return khong_nhan;  
}  

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx      
//ham kiem tra 2 phim on/off
//neu co nhan on lam bit tt = enable va tt phim = co nhan
//neu co nhan of lam bit tt = disable va tt phim = co nhan
//neu khong nhan thi bit tt khong doi va tt phim = khong nhan
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx     
/*
int1 phim_on_off_inv_3btn()   
{                                                      
   if(phim_on_c1(c_ktnp,0)==co_nhan)   
   {                
      tt_on_off = tt_on;
      return co_nhan;   
   }                         
   else                       
   if(phim_off_c1(c_ktnp,0)==co_nhan)
   {
      tt_on_off = tt_off;     
      return co_nhan;    
   } 
   else                       
   if(phim_inv_c1(c_ktnp,0)==co_nhan)     
   {                                                    
      tt_inv = true;                         
      return co_nhan;       
   }                        
   else   return khong_nhan;
}
  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx       
//ham kiem tra 2 phim on/off
//neu co nhan on lam bit tt = enable va tt phim = co nhan
//neu co nhan of lam bit tt = disable va tt phim = co nhan
//neu khong nhan thi bit tt khong doi va tt phim = khong nhan
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx     
int1 phim_on_off_2btn()   
{                     
   if(phim_on_c1(c_ktnp,0)==co_nhan)     
   {
      tt_on_off = tt_on;
      return co_nhan;   
   }                         
   else                       
   if(phim_off_c1(c_ktnp,0)==co_nhan)
   {
      tt_on_off = tt_off;     
      return co_nhan;    
   }
   else   return khong_nhan;                   
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                               
//ham kiem tra phim on 
//neu co nhan thi dao bit tt_on_off va tra ve co nhan
//neu khong nhan tra ve tt khong nhan
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx     
int1 phim_on_off_1btn()   
{                     
   if(phim_on_c1(c_ktnp,0)==co_nhan)   
   {
      tt_on_off = ~tt_on_off;
      return co_nhan;   
   }                         
   else   return khong_nhan;                   
}   
*/

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//cac ham con cua cac phim nhan don theo cach 2
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//phim bt0-cach 2: nhan so lan thuc hien la bien dl
//kiem tra neu co nhan thi tang bien dem dl_btn,delay 1ms.   
//Neu bien dl_btn = dl thi reset dl_btn = 0,
//xem nhu co nhan va ket thuc. 
//con lai thi xem nhu chua nhan hoac chua du thoi gian nhan
//moi chu ky thuc hien lon nhat la 1ms - khong cho nha phim 
//dinh nghia them 1 so ten khac  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    
#define phim_on_c2  phim_bt0_c2                    
#define phim_run_c2 phim_bt0_c2      
#define phim_up_c2  phim_bt0_c2  
usi16 dl_btn;
int1 phim_bt0_c2(usi16 dl)  
{                      
   if (!input(bt0))                       
   {   
      dl_btn++;   delay_ms(1);               
      if(dl_btn>=dl) 
      {  
         dl_btn=0;
         return co_nhan;
      }     
      else  return khong_nhan; 
   }
   else  return khong_nhan;    
} 
    
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//ham chong doi cach 1 cho phim bt1
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx      
#define phim_off_c2   phim_bt1_c2   
#define phim_stop_c2  phim_bt1_c2  
#define phim_mode_c2  phim_bt1_c2 
int1 phim_bt1_c2(usi16 dl)
{                      
   if (!input(bt1))   
   {           
      dl_btn++;  delay_ms(1); 
      if(dl_btn >= dl)    
      {  
         dl_btn =0;
         return co_nhan;
      }     
      else return khong_nhan; 
   }
   else return khong_nhan;    
}     

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//ham chong doi cach 1 cho phim bt31
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
#define phim_inv_c2  phim_bt2_c2  
#define phim_dw_c2   phim_bt2_c2  
int1 phim_bt2_c2(usi16 dl) 
{                      
   if (!input(bt2))   
   {                                  
      dl_btn++;  delay_ms(1); 
      if(dl_btn >= dl) 
      {  
         dl_btn =0;
         return co_nhan;   
      }     
      else return khong_nhan; 
   }
   else return khong_nhan;    
}                                       
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//ham chong doi cach 1 cho phim bt31
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx        
 
#define phim_ud_c2    phim_bt3_c2                          
int1 phim_bt3_c2(usi16 dl) 
{                      
   if (!input(bt3))    
   {                         
      dl_btn++;    delay_ms(1);                                               
      if(dl_btn >= dl) 
      {  
         dl_btn =0;                                 
         return co_nhan; 
      }     
      else return khong_nhan; 
   }
   else return khong_nhan;    
}                     

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//ham doc ma phim cua ban phim touch: tra ve ma phim 16 bit,
//bit 0 den 15 tuong ung phim 1 den 16
//khi co nhan thi bit bang 1, khong nhan thi bang 0
//cho phep nhan nhieu phim tao to hop len den 65536     
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
unsigned int16 key_tip229_multi()             
{
  unsigned int8 i; 
  unsigned int16 key_m=0;  
  for(i = 1; i < 17; i++)   
  {                       
    output_low(kp_ck);               
    if (!input(kp_dt))  
            key_m = (key_m >>1)|0x8000;
    else    key_m = (key_m >>1);      
    output_high(kp_ck);  
  }          
  return key_m;      
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//nut nhan cua joystick
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 

int1 phim_bt_joy_c1(int1 ktnp,usi16 dl)   
{                    
   if (!input(btj))   
   {                                                             
      delay_ms(20);                                     
      if (!input(btj))
      {
         if(ktnp) while(!input(btj));                
         delay_ms(dl);
         return co_nhan;      
      }                      
      return khong_nhan;   
   }         
  return khong_nhan;  
}
                         
int1 phim_bt_joy_c2(usi16 dl) 
{                      
   if (!input(btj))    
   {                         
      dl_btn++;    delay_ms(1);                                               
      if(dl_btn >= dl) 
      {  
         dl_btn =0;                                 
         return co_nhan; 
      }     
      else return khong_nhan; 
   }
   else return khong_nhan;    
}     

    
