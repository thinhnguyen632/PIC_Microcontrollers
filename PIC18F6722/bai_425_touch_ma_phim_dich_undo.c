#include <tv_kit_vdk_18f6722_all.c>
unsigned int8 mp8;
unsigned int1 dich,redo;
unsigned char temp[8]={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};

void luu_led_7d()
{
   for (int i=0; i<8; i++)
   {
      temp[i]=led_7d[i];
   }
}

void h423_dpst_8led_7doan()
{
   for(int i=7; i>0; i--)
      led_7d[i] = led_7d[i-1];
}

void b423_doc_16phim_single_dpst_8led()
{
   mp8 = key_tip229_cdoi_c2(10);
   if ((mp8>0)&&(mp8<10))
   {
      h423_dpst_8led_7doan();
      led_7d[0] = ma7doan[mp8%16];
      luu_led_7d();
      xuat_8led_7doan();
      delay_ms(500);
   }
   if (mp8==16)
   {
      h423_dpst_8led_7doan();
      led_7d[0] = ma7doan[mp8%16];
      luu_led_7d();
      xuat_8led_7doan();
      delay_ms(500);
   }
}

void doc_mp_10_11()
{
   mp8 = key_tip229_cdoi_c2(10);
   if (mp8==10)
   {
      dich=1;
   }
   if (mp8==11)
   {
      dich=0;
   }
}

void doc_mp_12()
{
   mp8 = key_tip229_cdoi_c2(10);
   if (mp8==12)
   {
      for (int i=0; i<8; i++)
      {
         led_7d[i]=0xff;
         xuat_8led_7doan();
      }
   }
}

void doc_mp_13_15()
{
   mp8 = key_tip229_cdoi_c2(10);
   if (mp8==13)
   {
      redo=1;
      led_7d[0]=led_7d[4];
      led_7d[1]=led_7d[5];
      led_7d[2]=led_7d[6];
      led_7d[3]=led_7d[7];
      led_7d[4]=0xff;
      led_7d[5]=0xff;
      led_7d[6]=0xff;
      led_7d[7]=0xff;
      xuat_8led_7doan();
   }
   if (mp8==15)
   {
      if (redo==1)
      {
         for (int k=0; k<8; k++)
         {
            led_7d[k]=temp[k];
            xuat_8led_7doan();
            redo=0;
         }
      }
   }
}

void kiem_tra()
{
   doc_mp_10_11();
   doc_mp_12();
   doc_mp_13_15();
   if (dich==0)
   {
      b423_doc_16phim_single_dpst_8led();
      xuat_32led_don_4byte(0,0,0xff,0xff);
   }
   else
   {
      xuat_32led_don_4byte(0xff,0xff,0,0);
   }
}

void main()
{
   set_up_port();
   dich=0;
   redo=0;
   while(true)
   {
      kiem_tra();
   }
}
