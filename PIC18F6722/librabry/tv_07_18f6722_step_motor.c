//thu vien dieu khien dong co buoc 
//nguyen dinh phu - dai hoc su pham ky thuat tp hcm
//cac ham dieu khien step motor

unsigned int16 stepmotor_fs[]=  {0x0700,0x0680,0x0580,0x0380};
unsigned int16 stepmotor_hs[]=  
{0x0380,0x0300,0x0600,0x0000,0x0400,0x0480,0x0580,0x0780};
                                                                                             
unsigned int8 stepmotor_i=0, stepmotor_delay;
int1 stepmotor_tn=0,stepmotor_onoff=0;
int1 stepmotor_fh=1;  

void step_motor_run_tn_fs()
{
   rbdc=rbdc & 0xf87f;           
   rbdc=rbdc|stepmotor_fs[stepmotor_i];
   xuat_rbdc();                            
   if(stepmotor_tn)  stepmotor_i++; //thuan
   else              stepmotor_i--; //nghich 
   stepmotor_i = stepmotor_i & 0x03;
} 

void step_motor_run_tn_hs()
{
   rbdc=rbdc & 0xf87f;           
   rbdc=rbdc|stepmotor_hs[stepmotor_i];
   xuat_rbdc();                      
   if(stepmotor_tn)  stepmotor_i++; //thuan
   else              stepmotor_i--; //nghich 
   stepmotor_i = stepmotor_i & 0x07;
}    

void step_motor_stop()
{
   rbdc=rbdc & 0xf87f;           
   xuat_rbdc();                      
}   

void step_motor_run_fs_hs()
{
   if(stepmotor_fh) step_motor_run_tn_fs();
   else             step_motor_run_tn_hs();           
}  

