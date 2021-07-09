#include <16F887.H>
#FUSES HS
#USE DELAY(CLOCK=20M)

#define LCD_ENABLE_PIN  PIN_E0
#define LCD_RS_PIN      PIN_E1
#define LCD_RW_PIN      PIN_E2
#define LCD_DATA4       PIN_D4
#define LCD_DATA5       PIN_D5
#define LCD_DATA6       PIN_D6
#define LCD_DATA7       PIN_D7 

#INCLUDE <LCD.C>

void main()
{
SET_TRIS_E(0);
SET_TRIS_D(0);
UNSIGNED INT8 GIO,PHUT,GIAY;

LCD_INIT();
LCD_GOTOXY(1,1);
LCD_PUTC("NGUYEN TIEN THINH");
LAP:
FOR (GIO=0;GIO<24;GIO++)
{
   FOR (PHUT=0;PHUT<60;PHUT++)
   {
      FOR (GIAY=0;GIAY<60;GIAY++)
      {
         LCD_GOTOXY(1,2);
         PRINTF(LCD_PUTC,"%02U:%02U:%02U",GIO,PHUT,GIAY);
         DELAY_MS(1000);
      }
   }
}
GOTO LAP;
}
