#include <tv_kit_vdk_18f6722_all.c> 
void b313_32led_sd_tnv(usi16 dl) 
{
   usi8 i, j; usi16 LP, LPD, PDON, LT, LTD, TDON;
   LPD = 0;
   LTD = 0;
   for (j = 0; j < 16; j++)
   {
      PDON = 1;
      TDON = 0x8000;
      for (i = j; i < 16; i++)
      {
         LP = LPD + PDON;
         LT = LTD + TDON;
         xuat_32led_don_2word(LT,LP);
         delay_ms(dl);
         PDON = PDON << 1;
         TDON = TDON >> 1;
      }
      LPD = LP;
      LTD = LT;
   }
}

void main()
{ 
   set_up_port();
   while(true)
   { 
      b313_32led_sd_tnv(40);
   } 
}
