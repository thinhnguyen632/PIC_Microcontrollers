#include <tv_kit_vdk_18f6722_all.c>  
void b302_16led_chop_tat(usi16 dl)          
{ 
   xuat_32led_don_4byte(0,0,0,0);     
   delay_ms(dl);                                        
   xuat_32led_don_4byte(0,0,0xff,0xff);
   delay_ms(dl);
}
void main()                                                        
{                                               
   set_up_port();                                                                       
   while(true)                                        
   {                                                                   
      b302_16led_chop_tat(1000);                                        
   }      
}
