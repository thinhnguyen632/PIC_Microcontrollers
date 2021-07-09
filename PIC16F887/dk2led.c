#include <16F887.H>
#FUSES HS
#USE DELAY(CLOCK=10M)
#DEFINE ON_OFF PIN_D0
#DEFINE L1 PIN_C0
#DEFINE L2 PIN_C1
UNSIGNED INT I;
void main()
{
OUTPUT_DRIVE(L1);
OUTPUT_DRIVE(L2);
OUTPUT_FLOAT(ON_OFF);
OUTPUT_LOW(L1);
OUTPUT_LOW(L2);
I=0;
KT:
   IF (INPUT(ON_OFF)==0)
   {   
      DELAY_MS(20);
      IF (INPUT(ON_OFF)==0)
      {
         I++;
         IF (I>4)
         {
         I=0;
         GOTO KT;
         }
         WHILE (INPUT(ON_OFF)==0){}
      }
   }
   IF(I==1){OUTPUT_HIGH(L1); OUTPUT_LOW(L2);}
   ELSE IF(I==2){OUTPUT_HIGH(L1); OUTPUT_HIGH(L2);}
   ELSE IF(I==3){OUTPUT_HIGH(L1); OUTPUT_LOW(L2);}
   ELSE IF(I==4){OUTPUT_LOW(L1); OUTPUT_LOW(L2);}
   GOTO KT;
}


