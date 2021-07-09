#include <16F887.H>
#FUSES HS
#USE DELAY(CLOCK=20M)

#INCLUDE <TV_KEY4X4_MOPHONG1.C>

#define LCD_ENABLE_PIN  PIN_E2
#define LCD_RS_PIN      PIN_E0
#define LCD_RW_PIN      PIN_E1
#define LCD_DATA4       PIN_D4
#define LCD_DATA5       PIN_D5
#define LCD_DATA6       PIN_D6
#define LCD_DATA7       PIN_D7 
#INCLUDE <LCD.C>

UNSIGNED INT8 CHUOI1[]={"                "};//16 Khoang trang
UNSIGNED INT8 CHUOI2[]={"                "};

UNSIGNED INT8 I,K,TAM;

void main()
{
   SET_TRIS_D(0);
   SET_TRIS_E(0);
   LCD_INIT();
   LAP:
      KEY4X4();//quet ma tran phim tim ma phim
      IF (MP!=0XFF)//ma phim khac 0XFF nghia la co phim da duoc nhan
      {
         IF (MP<10)//phim duoc nhan tu 0-9
         {
            FOR (I=0;I<15;I++)
            {
               CHUOI1[I]=CHUOI1[I+1];//gan phan tu sau cho phan tu truoc
            }
            CHUOI1[15]=MP+0X30;//chuyen sang bang ma ASCII
            LCD_GOTOXY(1,1);
            FOR (I=0;I<16;I++)//hien thi chuoi 1 len LCD
            {
               LCD_PUTC(CHUOI1[I]);
            }
         }
         IF (MP==10)//phim duoc nhan la phim A
         {
            FOR (I=0;I<16;I++)//sao chep chuoi 1 sang chuoi 2
            {
               CHUOI2[I]=CHUOI1[I];
            }
            FOR (K=0;K<15;K++)//sap xep chuoi 2 theo thu tu tang dan tu trai sang phai
            {
               FOR (I=K+1;I<16;I++)
               {
                  IF (CHUOI2[K]>CHUOI2[I])
                  {
                     TAM=CHUOI2[K];
                     CHUOI2[K]=CHUOI2[I];
                     CHUOI2[I]=TAM;
                  }
               }
            }
            LCD_GOTOXY(1,2);
            FOR (I=0;I<16;I++)//hien thi chuoi 2 len LCD
            {
               LCD_PUTC(CHUOI2[I]);
            }
         }
      }
      GOTO LAP;
}
