#include <16f887.h>
#FUSES HS
#USE DELAY(CLOCK=20M)

#DEFINE UP PIN_B0
#DEFINE DW PIN_B1
#DEFINE START_STOP PIN_B2
#DEFINE ENABLE PIN_C7 //cho phep L298

UNSIGNED INT16 VALUE, CAPTOCDO;//SET_PWM1_ DUTY(VALUE): THAY DOI DONG CO DC
UNSIGNED INT1 TTDC; //TRANG THAI DONG CO

VOID KT_START_STOP()//NHAN START DONG CO CHAY TU CAP 1
{
   IF (INPUT(START_STOP)==0)
   {
      DELAY_MS(20);
      IF (INPUT(START_STOP)==0)
      {
         WHILE (INPUT(START_STOP)==0);
         TTDC=~TTDC;
         IF (TTDC==1) {CAPTOCDO=1;}
         ELSE {CAPTOCDO=0;}
      }
   }
}

VOID KT_UP()// NHAN UP CAPTOCDO DONG CO TANG 1
{
   IF (INPUT(UP)==0)
   {
      DELAY_MS(20);
      IF (INPUT(UP)==0)
      {
         WHILE (INPUT(UP)==0);
         CAPTOCDO++;
         IF (CAPTOCDO>10) {CAPTOCDO=10;}
      }
   }
}

VOID KT_DW()// NHAN DW CAPTOCDO DONG CO GIAM 1
{
   IF (INPUT(DW)==0)
   {
      DELAY_MS(20);
      IF (INPUT(DW)==0)
      {
         WHILE (INPUT(DW)==0);
         CAPTOCDO--;
         IF (CAPTOCDO<1) {CAPTOCDO=1;}
      }
   }
}

void main()
{
   SET_TRIS_C(0X00);
   SET_TRIS_B(0XFF);
   
   OUTPUT_LOW(PIN_C3);
   SETUP_CCP1(CCP_PWM);//THIET LAP CHAN CCP1 LA CHAN PHAT XUNG PWM
   SETUP_TIMER_2(T2_DIV_BY_16,249,1);//800/(0.2*PRESCALER)=<256 => PRESCALER~15.6 => CHON HE SO CHIA 16///////800/(0.2*16)=250 => CHON PERIOD = 249
   SET_TIMER2(0);
   OUTPUT_HIGH(ENABLE);
   
   VALUE=0;
   TTDC=0;
   CAPTOCDO=0;
   SET_PWM1_DUTY(VALUE);
   
   WHILE(TRUE)
   {
      KT_START_STOP();
      IF (TTDC==1)//CHI KIEM TRA NUT NHAN UP, DW KHI DONG CO CHAY
      {
         KT_UP();
         KT_DW();
      }
      
      VALUE=CAPTOCDO*100;//duty cyle=value/[(period+1)*4]// duty cyle = captocdo/10
      SET_PWM1_DUTY(VALUE);
   }
}
