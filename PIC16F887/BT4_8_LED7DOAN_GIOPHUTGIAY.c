#include <16F887.H>
#FUSES HS
#USE DELAY (CLOCK=20M)

CONST UNSIGNED INT8 MA7DOAN[10]={0XC0,0XF9,0XA4,0XB0,0X99,0X92,0X82,0XF8,0X80,0X90};
UNSIGNED INT8 DLHT[8]={0XC0,0XC0,0XBF,0XC0,0XC0,0XBF,0XC0,0XC0};
UNSIGNED INT8 GIO,PHUT,GIAY,QUET;

VOID HIENTHI()
{
   UNSIGNED INT8 I,Q;
   FOR (Q=0;Q<5;Q++)
   {
      QUET=0XFE;//11111110
      FOR (I=0;I<8;I++)
      {  
         OUTPUT_D(QUET);//CHON 1 LED
         OUTPUT_C(DLHT[I]);//XUAT DLHT
         DELAY_MS(4); //DELAY
         OUTPUT_C(0XFF); //CHONG LEM
         QUET=(QUET<<1)+1;//CHON LED TIEP THEO 
      }
   }   
}

void main()
{
   SET_TRIS_C(0X00);
   SET_TRIS_D(0X00);
   WHILE(TRUE)
   {
      FOR(GIO=0;GIO<24;GIO++)
      {
         FOR(PHUT=0;PHUT<60;PHUT++)
         {
            FOR(GIAY=0;GIAY<60;GIAY++)
            {
               DLHT[7]=MA7DOAN[GIAY%10];
               DLHT[6]=MA7DOAN[GIAY/10];
               DLHT[4]=MA7DOAN[PHUT%10];
               DLHT[3]=MA7DOAN[PHUT/10];
               DLHT[1]=MA7DOAN[GIO%10];
               DLHT[0]=MA7DOAN[GIO/10];
               HIENTHI();
            }
         }
      }
      DLHT[7]=MA7DOAN[0];
      DLHT[6]=MA7DOAN[0];
      DLHT[4]=MA7DOAN[0];
      DLHT[3]=MA7DOAN[0];
      DLHT[1]=MA7DOAN[0];
      DLHT[0]=MA7DOAN[0];
      HIENTHI();
   }
}
