//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//cac ham xuat cac ma ra 8 led 7 doan
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
//unsigned char led_7d[8]={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
unsigned char bcd_8led[8]={0,0,0,0,0,0,0,0};   
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx         
//ham 401: chuong trinh con xuat 8 byte ra 8 led 7 doan
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                                    
void gxx()
{  
   bcd_8led[0]=0;
}
                                                                 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//cac ham giai ma va xuat cac ma ra 8 led 7 doan
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
//ham 402: giam ma 7 doan so bcd: 2 so, vi tri led thu y, xvn  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
void giaima_bcd_2so_vitri_vn(usi8 x,y, int1 xvn)
{                                        
   led_7d[y]   = ma7doan[x%16];       
   led_7d[y+1] = ma7doan[x/16];     
   if(xvn==true)                                                   
   {
      if (led_7d[y+1]==maso0) led_7d[y+1]=0xff;                                 
   }
}                   
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
//ham 403: giam ma 7 doan 2 so, xoa so vn, vi tri led thu y  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
void giaima_bin_2so_vitri_vn(usi8 x,y, int1 xvn)
{                                        
   led_7d[y]   = ma7doan[x%10];       
   led_7d[y+1] = ma7doan[x/10%10];     
   if(xvn==true)                                                   
   {
      if (led_7d[y+1]==maso0) led_7d[y+1]=0xff;                                 
   }
}    
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                
//ham 404: giam ma 7 doan 3 so, xoa so vn, vi tri led thu y   
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
void giaima_bin_3so_vitri_vn(usi16 x, usi8 y, int1 xvn)
{                                        
   led_7d[y]   = ma7doan[x%10];       
   led_7d[y+1] = ma7doan[x/10%10];
   led_7d[y+2] = ma7doan[x/100%10];
   if(xvn==true)
   {
      if (led_7d[y+2]==maso0)
      {
         led_7d[y+2]=0xff;
         if (led_7d[y+1]==maso0) led_7d[y+1]=0xff;
      }
   }            
}    
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
//ham 405: giam ma 7 doan 4 so, xoa so vn, vi tri led thu y  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
void giaima_bin_4so_vitri_vn(usi16 x, usi8 y, int1 xvn)
{                                        
   led_7d[y]   = ma7doan[x%10];       
   led_7d[y+1] = ma7doan[x/10%10];
   led_7d[y+2] = ma7doan[x/100%10];
   led_7d[y+3] = ma7doan[x/1000%10];
   if(xvn==true)                                  
   {
      if (led_7d[y+3]==maso0) 
      {
         led_7d[y+3]=0xff;
         if (led_7d[y+2]==maso0) 
         {
            led_7d[y+2]=0xff; 
            if (led_7d[y+1]==maso0) led_7d[y+1]=0xff;   
         }
      }                        
   }          
}  

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
//ham 406: giam ma 7 doan 5 so, xoa so vn, vi tri led thu y   
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    
void giaima_bin_5so_vitri_vn(usi16 x, usi8 y, int1 xvn)
{                              
   led_7d[y]   = ma7doan[x%10];       
   led_7d[y+1] = ma7doan[x/10%10];
   led_7d[y+2] = ma7doan[x/100%10];
   led_7d[y+3] = ma7doan[x/1000%10]; 
   led_7d[y+4] = ma7doan[x/1000%10]; 
   if(xvn==true)
   {                      
      if (led_7d[y+4]==maso0)
      {                       
         led_7d[y+4]=0xff;
         if (led_7d[y+3]==maso0) 
         {
            led_7d[y+3]=0xff; 
            if (led_7d[y+2]==maso0) 
            {  
               led_7d[y+2]=0xff; 
               if (led_7d[y+1]==maso0) led_7d[y+1]=0xff;  
            }
         }
      }                        
   }              
}   
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//cac ham giai ma va xuat cac ma ra 8 led 7 doan
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
//ham 421: giam ma va hien thi 2 so tren 2 led 7 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
void  giai_ma_hien_thi_2so(usi16 z, usi8 y,int1 xvn)
{         
   giaima_bin_2so_vitri_vn(z,y,xvn);          
   xuat_8led_7doan();   
}                                               
 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
//ham 422: giam ma va hien thi 3 so tren 3 led 7 doan 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
void  giai_ma_hien_thi_3so(usi16 z, usi8 y,int1 xvn)
{         
   giaima_bin_3so_vitri_vn(z,y,xvn);        
   xuat_8led_7doan();   
}    
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
//ham 423: giam ma va hien thi 4 so tren 4 led 7 doan 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
void  giai_ma_hien_thi_4so(usi16 z, usi8 y,int1 xvn)
{         
   giaima_bin_4so_vitri_vn(z,y,xvn);         
   xuat_8led_7doan();   
}  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
//ham 424: giam ma va hien thi 5 so tren 4 led 7 doan 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
void  giai_ma_hien_thi_5so(usi16 z, usi8 y,int1 xvn)
{         
   giaima_bin_5so_vitri_vn(z,y,xvn);         
   xuat_8led_7doan();   
}     
        

