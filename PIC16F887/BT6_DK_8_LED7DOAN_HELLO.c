#include <16F887.H>
#FUSES HS
#USE DELAY (CLOCK=20M)

//dp/gfedcba
//1//0001001//=>0X89=>H
//1//0000110//=>0X86=>E
//1//1000111//=>0XC7=>L
//1//0000001//=>0XC0=>O

CONST UNSIGNED INT8 MA_HELLO[21]={0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0X89,0X86,0XC7,0XC7,0XC0,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF};
UNSIGNED INT8 DLHT[8]={0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF,0XFF};
UNSIGNED INT8 QUET;

VOID HIENTHI()
{
   UNSIGNED INT8 I,Q;
   FOR (Q=0;Q<25;Q++)
   {
      QUET=0XFE;
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
   UNSIGNED INT8 J,CHAY,BD;
   SET_TRIS_C(0X00);
   SET_TRIS_D(0X00);
   LAP:
   FOR(BD=0;BD<14;BD++)
      {
         CHAY=BD;
         FOR(J=0;J<8;J++)
         {
         DLHT[J]=MA_HELLO[CHAY];
         CHAY++;
         }
      HIENTHI();
      }
   GOTO LAP;
}
