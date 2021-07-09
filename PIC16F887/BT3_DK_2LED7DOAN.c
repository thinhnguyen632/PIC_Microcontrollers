#include <16F887.H>
#FUSES HS
#USE DELAY(CLOCK = 10M)
#DEFINE UP PIN_E0
#DEFINE DW PIN_E1
#DEFINE START PIN_E2

SIGNED INT8 DEM,I;
CONST UNSIGNED INT8 MA7DOAN[]={0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};

VOID GIAIMA_LED7DOAN()
{
   OUTPUT_C(MA7DOAN[DEM/10]);//DEM=1 -> MA7DOAN[1/10]=> MA7DOAN[0] -> 0
   OUTPUT_D(MA7DOAN[DEM%10]);//DEM=1 -> MA7DOAN[1/10]=> MA7DOAN[1] -> 1
}

void main()
{
   SET_TRIS_C(0X00);
   SET_TRIS_D(0X00);
   SET_TRIS_E(0XFF);
   DEM=5;
GM:
   GIAIMA_LED7DOAN();
   // NHAN NUT UP
   IF (INPUT(UP)==0)
   {
      DELAY_MS(10);
      IF (INPUT(UP)==0)
      {
         WHILE (INPUT(UP)==0);
         DEM++;
         IF (DEM>15) DEM=15;
      }
   }
   // NHAN NUT DOWN
   IF (INPUT(DW)==0)
   {
      DELAY_MS(10);
      IF (INPUT(DW)==0)
      {
         WHILE (INPUT(DW)==0);
         IF (DEM>6) DEM=DEM-2;
         IF (DEM<=6) DEM=DEM;
      }
   }
   // NHAN NUT START
   IF (INPUT(START)==0)
   {
      DELAY_MS(10);
      IF (INPUT(START)==0)
      {
         WHILE (INPUT(START)==0);
         FOR (I=0;I<DEM;I++)
         {
            GIAIMA_LED7DOAN();
            DELAY_MS(200);
            OUTPUT_C(0XFF);
            OUTPUT_D(0XFF);
            DELAY_MS(200);
         }
      }
   }
   GOTO GM;
}
