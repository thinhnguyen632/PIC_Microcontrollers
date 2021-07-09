#include <16f887.h>
#FUSES HS
#USE DELAY(CLOCK=20M)

UNSIGNED INT8 YD, YC;
UNSIGNED INT16 Y,YDON,DON,I,J;

VOID XUAT_16LED()
{
   YD = Y;
   YC = Y>>8;
   OUTPUT_C(YC);
   OUTPUT_D(YD);
}

VOID CHOP_TAT_5_LAN()
{
   Y=0XFFFF;
   FOR (I=0;I<10;I++)//CHOP TAT 5 LAN
   {
      XUAT_16LED();
      DELAY_MS(100);
      Y=~Y; // Y = 0X0000 = 0000 0000 0000 0000
   }
}

VOID SANG_PHAI_TRAI()
{
   Y=0;
   FOR (I=0;I<16;I++)
   {
      Y=(Y<<1)+1; //Y = 1111 1111 1111 1111
      XUAT_16LED();
      DELAY_MS(100);
   }
}

VOID TAT_TRAI_PHAI()
{
   Y=0XFFFF;
   FOR (I=0;I<16;I++)
   {
      Y=(Y>>1); //0000 0000 0000 0000
      XUAT_16LED();
      DELAY_MS(100);
   }
}

VOID SANG_TRAI_PHAI()
{
   Y=0;
   FOR (I=0;I<16;I++)
   {
      Y=(Y>>1)+0x8000; // 1111 1111 1111 1111
      XUAT_16LED();
      DELAY_MS(100);
   }
}

VOID TAT_PHAI_TRAI()
{
   Y=0XFFFF; // 1111 1111 1111 1111
   FOR (I=0;I<16;I++)
   {
      Y=(Y<<1); // 0000 0000 0000 0000
      XUAT_16LED();
      DELAY_MS(100);
   }
}

VOID NHAP_NHAY_XEN_KE()
{
   Y=0XAAAA; // 1010 1010 1010 1010
   FOR (I=0;I<10;I++)// NHAP NHAY XEN KE 5 LAN
   {
      XUAT_16LED();
      DELAY_MS(100);
      Y=~Y; // 0101 0101 0101 0101
   }
}

VOID NHAP_NHAY_2BEN_8LED()
{
   Y=0XFF00; // 1111 1111 0000 0000
   FOR (I=0;I<10;I++)//NHAP NHAY HAI BEN 8 LED 5 LAN
   {
      XUAT_16LED();
      DELAY_MS(100);
      Y=~Y; // 0000 0000 1111 1111
   }
}

VOID DON_PHAI_TRAI()
{
   YDON = 0; 
   FOR (J=0;J<16;J++)
   {
      DON=1; //0000 0000 0001
      FOR(I=J;I<16;I++)
      {
         Y=DON+YDON; // Y = 0000 0000 0000 0001 
         XUAT_16LED(); // Y = 1000 0000 0000 0000
         DELAY_MS(100);
         DON=DON<<1; // 0000 0000 0000 0010
      }
      YDON = Y; //1000 0000 0000 0000
   }
}

VOID DON_TRAI_PHAI()
{
   YDON = 0;
   FOR (J=0;J<16;J++)
   {
      DON=0X8000; // 1000 0000 0000 0000
      FOR(I=J;I<16;I++)
      {
         Y=YDON+DON; // Y = 0000 0000 0000 0000 + 1000 0000 0000 0000
         XUAT_16LED(); // 1000 0000 0000 0000
         DELAY_MS(100);
         DON=DON>>1; // 0100 0000 0000 0000
      }
      YDON = Y; // 0000 0000 0000 0001
   }
}

VOID NHAP_MOI_BEN()
{
   I=0;
   Y=0X0000;  //0000 0000 0000 0000
   IF (I==0) // NHAP 8 LED BEN TRAI
   {
      FOR(J=0;J<5;J++)
      {
         {Y=0XFF00;
         XUAT_16LED(); // 1111 1111 0000 0000
         DELAY_MS(100);
         Y=0X0000; 
         XUAT_16LED(); // 0000 0000 0000 0000
         DELAY_MS(100);}
         I=1;
      }
   }
   IF (I==1) // NHAP NHAY 8 LED BEN PHAI
   {
      FOR(J=0;J<5;J++)
      {
         Y=0X00FF; // 0000 0000 1111 1111
         XUAT_16LED();
         DELAY_MS(100);
         Y=0X0000; // 0000 0000 0000 0000
         XUAT_16LED();
         DELAY_MS(100);
      }
   }
}

void main()
{
   SET_TRIS_D(0X00);
   SET_TRIS_C(0X00);
LAP:
   CHOP_TAT_5_LAN();
   SANG_PHAI_TRAI();
   TAT_TRAI_PHAI();
   SANG_TRAI_PHAI();
   TAT_PHAI_TRAI();
   NHAP_NHAY_XEN_KE();//5 LAN
   NHAP_NHAY_2BEN_8LED();//5LAN
   DON_PHAI_TRAI();
   DON_TRAI_PHAI();
   NHAP_MOI_BEN();//5 LAN
   Y=0;
   XUAT_16LED();
GOTO LAP;
}

