#include <16F887.H>
#FUSES HS
#DEVICE ADC=10
#USE DELAY(CLOCK=20M)
#USE RS232(baud=9600,xmit=PIN_C6,rcv=PIN_C7)

#define LCD_ENABLE_PIN  PIN_E2
#define LCD_RS_PIN      PIN_E0
#define LCD_RW_PIN      PIN_E1
#define LCD_DATA4       PIN_D4
#define LCD_DATA5       PIN_D5
#define LCD_DATA6       PIN_D6
#define LCD_DATA7       PIN_D7
#INCLUDE <LCD.C>

#DEFINE LED PIN_B1
UNSIGNED INT8 TAM;
UNSIGNED INT8 ND=0;

void main()
{
   SET_TRIS_D(0X00);
   SET_TRIS_B(0X00);
   
   OUTPUT_LOW(LED);
   LCD_INIT();
   WHILE(TRUE)
   {
      IF(KBHIT()==1)
      {
         TAM=GETC();
         IF(TAM=='L') OUTPUT_TOGGLE(LED);
         ELSE ND=TAM;
      }
      
      LCD_GOTOXY(1,1);
      IF(INPUT_STATE(LED)) PRINTF(LCD_PUTC,"LED DANG SANG");
      ELSE PRINTF(LCD_PUTC,"LED DANG TAT ");
      
      LCD_GOTOXY(1,2);
      PRINTF(LCD_PUTC,"NHIET DO: %U",ND);
      LCD_PUTC(0XDF);
      LCD_PUTC('C');
   }
}
