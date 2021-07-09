#include <16F887.H>
#FUSES HS
#DEVICE ADC=10
#USE DELAY(CLOCK=20M)
#USE RS232(baud=9600,xmit=PIN_C6,rcv=PIN_C7)

#DEFINE LED PIN_B4
#DEFINE ND PIN_B5

UNSIGNED INT8 TEMP1;
UNSIGNED INT16 NHIETDO;

void main()
{
   SET_TRIS_B(0XFF);
   //PORT_B_PULLUPS(TRUE);
   
   SETUP_ADC(ADC_CLOCK_INTERNAL);
   SETUP_ADC_PORTS(SAN5|VSS_VDD);
   SET_ADC_CHANNEL(5);
   DELAY_US(10);
   
   WHILE(TRUE)
   {
      SET_ADC_CHANNEL(5);
      DELAY_US(10);
      NHIETDO=READ_ADC()/2.046;
      TEMP1=NHIETDO;
      
      IF(INPUT(LED)==0)
      {
         DELAY_MS(10);
         IF(INPUT(LED)==0)
         {
            WHILE(INPUT(LED)==0){}
            PUTC('L');
         }
      }
      IF(INPUT(ND)==0)
      {
         DELAY_MS(10);
         IF(INPUT(ND)==0)
         {
            WHILE(INPUT(ND)==0){}
            PUTC(TEMP1);
         }
      }
      DELAY_MS(10);
   }
}
