void ds1307_hthi_text_lcd()
{
   lcd_goto_xy(0,0);
   lcd_data("CLOCK DS1307 ");
}

void ds1307_hthi_thu_lcd()
{
   lcd_goto_xy(3,0);
   switch (time_r[3])
   {
      case 1:  lcd_data("Sunday:    ");   break;
      case 2:  lcd_data("Monday:    ");   break;
      case 3:  lcd_data("Tuesday:   ");   break;
      case 4:  lcd_data("Wednesday: ");   break;
      case 5:  lcd_data("Thursday:  ");   break;
      case 6:  lcd_data("Friday:    ");   break;
      case 7:  lcd_data("Saturday:  ");   break;
      default: break;
   }
}

void ds1307_hthi_ntn_lcd()
{
   lcd_hthi_byte(time_r[4],3,12);
   lcd_data("-");
   lcd_hthi_byte(time_r[5],3,15);
   lcd_data("-");
   lcd_hthi_byte(time_r[6],3,18);
}

void ds1307_hthi_giay_lcd_soto()
{
   lcd_hien_thi_so_to(giay_ds/16,1,14);
   lcd_hien_thi_so_to(giay_ds%16,1,17);
}

void ds1307_hthi_phut_lcd_soto()
{
   lcd_hien_thi_so_to(phut_ds/16,1,7);
   lcd_hien_thi_so_to(phut_ds%16,1,10);
}

void ds1307_hthi_gio_lcd_soto()
{
   lcd_hien_thi_so_to(gio_ds/16,1,0);
   lcd_hien_thi_so_to(gio_ds%16,1,3);
}

void ds1307_hthi_lcd_soto()
{
   ds1307_hthi_giay_lcd_soto();
   if(giay_ds==0)
   {
      ds1307_hthi_phut_lcd_soto();
      if(phut_ds==0)
      {
         ds1307_hthi_gio_lcd_soto();
         if(gio_ds==0)
         {
            ds1307_hthi_ntn_lcd();
            ds1307_hthi_thu_lcd();
         }
      }
   }
}
