#include <16F887.H>
#FUSES HS
#USE DELAY(CLOCK=20M)

#DEFINE UP PIN_B0
#DEFINE DOWN PIN_B1

#define LCD_ENABLE_PIN  PIN_E2
#define LCD_RS_PIN      PIN_E0
#define LCD_RW_PIN      PIN_E1
#define LCD_DATA4       PIN_D4
#define LCD_DATA5       PIN_D5
#define LCD_DATA6       PIN_D6
#define LCD_DATA7       PIN_D7

#INCLUDE <LCD.C>

UNSIGNED INT8 SP,SOMAX;

VOID HIENTHI_SP()
{
   LCD_GOTOXY(1,2);
   PRINTF(LCD_PUTC,"SAN PHAM: %02U",SP);
}

VOID HIENTHI_SOMAX()
{
   LCD_GOTOXY(1,1);
   PRINTF(LCD_PUTC,"SAN PHAM MAX: %2U",SOMAX);
}

void main()
{
   SET_TRIS_D(0);
   SET_TRIS_E(0);
   
   LCD_INIT();
   
   SOMAX=15;
   HIENTHI_SOMAX();
   
   SETUP_TIMER_0(T0_EXT_L_TO_H|T0_DIV_1);
   SET_TIMER0(0);
   
LAP:
   SP=GET_TIMER0();
   HIENTHI_SP();
   HIENTHI_SOMAX();
   
   IF(INPUT(UP)==0)
   {
      DELAY_MS(10);
      IF(INPUT(UP)==0)
      {
         IF (SOMAX<20) SOMAX++;
         WHILE(INPUT(UP)==0);
      }
   }
   IF(INPUT(DOWN)==0)
   {
      DELAY_MS(10);
      IF(INPUT(DOWN)==0)
      {
         IF (SOMAX>10) SOMAX--;
         WHILE(INPUT(DOWN)==0);
      }
   }
   
   IF(SP==SOMAX)
   {
      WHILE(TRUE)
      {
         LCD_GOTOXY(1,2);
         LCD_PUTC("DA DU SAN PHAM");
         DELAY_MS(300);
         LCD_GOTOXY(1,2);
         LCD_PUTC("              ");
         DELAY_MS(300);
      }
   }
   GOTO LAP;
}
