
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//dinh nghia bien dieu khien LCD va cac bit cua bien
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
#define chan_lm35a      4 
#define chan_lm35b      0
#define chan_js_vrx     1
#define chan_js_vry     2
#define chan_cbkc       3
//ham 703: do nhiet lm35a, lm35b, dkhien den, bao dong
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
#define nd_tren  35                                                      
#define nd_duoi  33         
int1 ttqn=0;    

void so_sanh_nd_dk_buzzer(usi16 nd) 
{                                
   if((nd>nd_tren)&&(ttqn==0))        
   {
      ttqn = 1;                                                              
      buzzer_on();                                   
      triac_1_off();
   }                                                                           
   else if((nd<nd_tren)&&(ttqn==1))
   {
      ttqn = 0; 
      buzzer_off();
   }
   else if((nd<nd_duoi)&&(ttqn==0))  triac_1_on();
}

float h601_adc_read(usi8 solan, chan)                      
{
   float kq_adc;  usi8 i;
   set_adc_channel(chan);               
   delay_us(20);
   kq_adc = 0;             
   for(i=0;i<solan;i++)       
   {
      kq_adc = kq_adc + read_adc();   
   }                                    
   kq_adc = kq_adc/solan;
   return kq_adc; 
}

usi16 so_ng,so_tp;
void float_to_ng_2so_tp(float st)                      
{   
   so_ng = st/1;       //nguyen                          
   st = st-so_ng;      //tphan
   st = st*100;                                                         
   so_tp = st/1;   
} 
