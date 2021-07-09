//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//dinh nghia bien dieu khien GLCD va cac bit cua bien      
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
unsigned int8 glcd_ctr;   
#bit glcd_p    = glcd_ctr.5           
#bit glcd_rs   = glcd_ctr.4
#bit glcd_rw   = glcd_ctr.3
#bit glcd_e    = glcd_ctr.2
#bit glcd_nc   = glcd_ctr.1
#bit glcd_psb  = glcd_ctr.0                             
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Dinh nghia cac lenh dieu khien cua GLCD
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
#define glcd_text_mode      0x30
#define glcd_graphic_mode   0x36                     

#define glcd_clear_display  0x01
#define glcd_cursor_display 0x0c
#define glcd_entry_mode     0x06

#define glcd_addr_line0     0x80
#define glcd_addr_line1     0x90
#define glcd_addr_line2     0x88
#define glcd_addr_line3     0x98
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//ham 621: xuat data/lenh ra glcd
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
void glcd_xuat_db(int8 db)
{
   glcd_e=1; xuat_glcd(glcd_ctr,db); 
   delay_us(20);
   glcd_e=0; xuat_glcd(glcd_ctr,db);  
}                                 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//ham 622: xuat lenh ra glcd    
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
void glcd_command(int8 db)   
{
   glcd_rs = 0;
   glcd_xuat_db(db);      
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//ham 623: xuat data ra glcd
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
void glcd_data(int8 db)                 
{
   glcd_rs = 1;     
   glcd_xuat_db(db);     
} 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//ham 624: khoi tao GLCD 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
void setup_glcd (int8 glcd_fs_mode)
{                     
   glcd_psb = 1;
   glcd_nc = 1;                             
   glcd_e  = 0;
   glcd_rw = 0;          
   glcd_p =0;         
   glcd_command(glcd_fs_mode);         
   delay_us(10);
   glcd_command(glcd_cursor_display);       
   delay_us(10);    
   glcd_command(glcd_clear_display);      
   delay_ms(10);                                          
   glcd_command(glcd_entry_mode);      
   delay_us(10);                                               
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//ham 608: xuat data ra glcd
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
void glcd_clear()                 
{   
   glcd_command(glcd_clear_display);      
   delay_ms(10);     
}  
void glcd_text_or_graphic(int8 x)                 
{                                   
   glcd_command(x);         
   delay_us(10);     
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//dinh nghia cac hang so kich thuoc hinh anh cua GLCD       
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx     
#define glcd_ngang  16 //16x16=256 pixel
#define glcd_doc    32 //32 hang
#define glcd_width  128 //danh cho thu vien graphic.c
int8 doc, ngang;
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xay dung loai du lieu dots: dung de xu diem anh
//dang word va byte de de truy xuat
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                              
typedef union 
{ 
  unsigned int16 word; 
  unsigned int8 nbyte[2]; 
} dots;     

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xay dung loai du lieu gd_ram kieu co cau truc "struct"      
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx     
typedef struct 
{ 
  int1 refresh; 
  dots pixel[glcd_doc][glcd_ngang];    
} gd_ram;      
gd_ram gdram_vdk; 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//ham 610: xoa vung nho gdram_vdk cung mau glcd_color  
//nhung chua xuat ra GLCD 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
void glcd_mau_nen(int1 glcd_color) 
{  
  int16 d; 
  if(glcd_color)  d=0xffff; else d=0;
  for (doc=0; doc<glcd_doc; doc++) 
  { 
    for (ngang=0; ngang<glcd_ngang; ngang++) 
    { 
      gdram_vdk.pixel[doc][ngang].word = d; 
    } 
  } 
  gdram_vdk.refresh = true; 
} 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//ham 610: lam 1 pixel co mau la color nhung chua xuat ra GLCD      
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
void glcd_pixel(int8 x, int8 y, int1 color)                     
{ 
  int8  b; 
  if(y>31){x += 128; y-= 32;};                 
  doc = y; 
  ngang = x/16;                                         
  b = 15 - (x % 16);   
  if(color==1) bit_set(gdram_vdk.pixel[doc][ngang].word,b); 
  else         bit_clear(gdram_vdk.pixel[doc][ngang].word,b); 
  gdram_vdk.refresh = true;     
} 

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//ham 610: ham xuat toan bo du lieu 16x32=512word ra GLCD      
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
void gdram_vdk_to_gdram_glcd_all() 
{ 
  if(gdram_vdk.refresh) 
  { 
    for(doc=0; doc<glcd_doc; doc++) 
    { 
      glcd_command(0x80+doc);   // set vertical address. 
      glcd_command(0x80+0);   // set horizontal address. 

      for(ngang=0; ngang<glcd_ngang; ngang++) 
      {                                  
        glcd_data(gdram_vdk.pixel[doc][ngang].nbyte[1]);    
        glcd_data(gdram_vdk.pixel[doc][ngang].nbyte[0]);    
      } 
    } 
    gdram_vdk.refresh = false; 
  } 
} 
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//ham 610: ham xuat 1 vung du lieu bat dau tai (x,y) 
//va rong va cao ra GLCD
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 
void gdram_vdk_to_gdram_glcd_area(int8 x,int8 y,int8 rong, int8 cao)
{                                                 
  int8 hesox,hesoy; 
  if (gdram_vdk.refresh) 
  {       
      if(((rong+x)/16)!=0) rong=((rong)/16)+1;
      else                 rong=((rong)/16); 
      x = x/16;
      for(doc=y;doc<(y+cao);doc++) 
      { 
         if(doc>31)
            {  
               hesoy = doc-32;
               hesox = 8+x;
               }
         else 
         {
            hesoy = doc;
            hesox = x;
            }
         glcd_command(0x80+hesoy);   
         glcd_command(0x80+hesox);  
      
         for(ngang=hesox; ngang<(hesox+rong); ngang++) 
         { 
            glcd_data( gdram_vdk.pixel[hesoy][ngang].nbyte[1]);   // write high byte. 
            glcd_data( gdram_vdk.pixel[hesoy][ngang].nbyte[0]);   // write low byte. 
         } 
       } 
    gdram_vdk.refresh = false; 
  }      
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//vung du lieu nhi phan cua anh logo spkt
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   

const unsigned char logo_spk [] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xa0, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x03, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x20, 0x00, 0x00, 0x00,
                                                                   
0x00, 0x00, 0x00, 0x02, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x30, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x02, 0x30, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x00, 0x00, 0x30, 0x00, 0x7e, 0x00,
0x00, 0xfe, 0x00, 0x07, 0xe0, 0x00, 0x3f, 0x00, 0x01, 0xf8, 0x00, 0x03, 0xe0, 0x00, 0x1f, 0x80,
0x03, 0xf0, 0x00, 0x01, 0xc0, 0x00, 0x0f, 0xc0, 0x03, 0xe0, 0x00, 0x01, 0xc0, 0x00, 0x07, 0xe0,
0x07, 0xc0, 0x00, 0x03, 0xc0, 0x00, 0x03, 0xf0, 0x0f, 0xc0, 0x00, 0x17, 0xf4, 0x00, 0x01, 0xf0,

0x0f, 0x80, 0x00, 0x1d, 0x98, 0x00, 0x00, 0xf8, 0x1f, 0x00, 0x00, 0x11, 0x8c, 0x00, 0x00, 0xf8,
0x1f, 0x01, 0x00, 0x31, 0x84, 0x00, 0x80, 0x7c, 0x3e, 0x06, 0x00, 0x31, 0x86, 0x00, 0x20, 0x7c,
0x3e, 0x18, 0x00, 0x71, 0x86, 0x00, 0x1c, 0x3e, 0x3c, 0x43, 0x00, 0x31, 0x84, 0x00, 0xc3, 0x3e,
0x7c, 0x0c, 0x00, 0x11, 0x8c, 0x00, 0x38, 0x1e, 0x7c, 0x31, 0x00, 0x1d, 0x98, 0x00, 0x86, 0x1f,
0x78, 0xc6, 0x00, 0x1f, 0xfc, 0x00, 0x63, 0x1f, 0x78, 0x18, 0x00, 0x03, 0xc0, 0x00, 0x0c, 0x1f,

0xf8, 0x63, 0x80, 0x01, 0x80, 0x00, 0xc7, 0x0f, 0xf9, 0x8e, 0x00, 0x00, 0x00, 0x00, 0x38, 0x8f,
0xf8, 0x38, 0x80, 0x00, 0x00, 0x01, 0x0c, 0x0f, 0xf8, 0xc3, 0x80, 0x00, 0x00, 0x00, 0xe3, 0x8f,
0xf9, 0x8e, 0x00, 0x00, 0x00, 0x00, 0x30, 0xcf, 0xf8, 0x38, 0xf8, 0x00, 0x00, 0x1f, 0x9e, 0x0f,
0xf8, 0xe3, 0xfe, 0x00, 0x00, 0x7f, 0xe3, 0x8f, 0xf9, 0x9f, 0xff, 0xc0, 0x03, 0xff, 0xf9, 0xcf,
0x78, 0xff, 0xff, 0xe0, 0x07, 0xff, 0xff, 0x0f, 0x78, 0x1f, 0xff, 0xe0, 0x07, 0xff, 0xfc, 0x1f,

0x7c, 0x07, 0xff, 0xe0, 0x07, 0xff, 0xe0, 0x1f, 0x7c, 0x00, 0xff, 0xe0, 0x07, 0xff, 0x80, 0x1e,
0x7c, 0x00, 0x1f, 0xe0, 0x07, 0xfc, 0x00, 0x3e, 0x3e, 0x01, 0xcf, 0xe0, 0x07, 0xf3, 0x80, 0x3e,
0x3e, 0x01, 0xff, 0xe0, 0x03, 0xff, 0x80, 0x7c, 0x1f, 0x01, 0xff, 0xe0, 0x03, 0xff, 0xc0, 0x7c,
0x1f, 0x01, 0xff, 0xc0, 0x03, 0xff, 0xc0, 0xf8, 0x0f, 0x83, 0xff, 0xc0, 0x01, 0xff, 0xc0, 0xf8,
0x0f, 0x83, 0xff, 0xc0, 0x01, 0xff, 0xc1, 0xf0, 0x07, 0xc3, 0xff, 0x80, 0x01, 0xff, 0xe3, 0xf0,

0x03, 0xe3, 0xff, 0x80, 0x01, 0xff, 0xe7, 0xe0, 0x03, 0xf7, 0xff, 0x80, 0x00, 0xff, 0xef, 0xc0,
0x01, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0x80,
0x00, 0x7f, 0xff, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x3f, 0xff, 0x00, 0x00, 0xff, 0xfe, 0x00,
0x00, 0x1f, 0xff, 0x00, 0x00, 0x7f, 0xf8, 0x00, 0x00, 0x0f, 0xfe, 0x00, 0x00, 0x7f, 0xf0, 0x00,
0x00, 0x03, 0xff, 0x00, 0x00, 0x7f, 0xe0, 0x00, 0x00, 0x00, 0xff, 0xfc, 0x1f, 0xff, 0x80, 0x00,

0x00, 0x00, 0x7f, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xf8, 0x00, 0x00,
0x00, 0x00, 0x01, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x00
};

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Ham xuat anh logo spk ra GLCD theo cach truc tiep
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                 
//!void glcd_xuat_anh(int width,int height,int x,int y) 
//!{                                        
//!   unsigned int i=0, j=0, k=0;                                                   
//!   unsigned int16 n=0;                                      
//!   ngang=0;      n=0;                                 
//!   for(j=0;j<height;j++)          //doc                              
//!   {                           
//!      if(j>31) {ngang=8; k=j-32;}
//!      else k=j;                                              
//!      glcd_command(0x80+(y+k)); //vertical address. 
//!      glcd_command(0x80+((x/16)+ngang));   //horizontal address.
//!                                                                                
//!      for(i=0;i<width/16;i++) 
//!      {                                 
//!         glcd_data(logo_spk[n]);    n++;                                                     
//!         glcd_data(logo_spk[n]);    n++;                                   
//!      }                                                        
//!   }                                                          
//!}    
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Ham xuat anh logo spk ra GLCD
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx                 
//!void glcd_xuat_anh_ok(int width,int height,int x,int y) 
//!{                       
//!   unsigned int i=0, j=0, k=0;                                                   
//!   unsigned int16 n=0;  
//!   ngang=0;                                                 
//!   for(j=0;j<height;j++)  //cot tinh theo pixel                                                                     
//!   {                           
//!      if(j>31) {ngang=8; k=j-32;}     //chuyen vung                       
//!      else k=j;                                               
//!      for(i=0;i<width/16;i++)                                   
//!      {                                 
//!         gdram_vdk.pixel[y+k][x/16+ngang+i].nbyte[1] = logo_spk[n]; 
//!         n++;                                                     
//!         gdram_vdk.pixel[y+k][x/16+ngang+i].nbyte[0] = logo_spk[n]; 
//!         n++;                                   
//!      } 
//!   }                                                          
//!}                                                                                       
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//Ham xuat anh logo spkt ra GLCD
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx    
void glcd_xuat_anh(int width,int height,int x,int y) 
{                       
   unsigned int i=0, j=0, k=0;                                                   
   unsigned int16 n=0; 
   for(j=0;j<height;j++)                                     
   {    
      i=0;
      do
      {                                
         for(k=8;k>0;k--)
         {                  
            glcd_pixel(x+i,y+j,bit_test(logo_spk[n],(k-1))); 
            i++;                      
         }                 
         n++;           
      }while(i<width);  
   } 
}

void glcd_xuat_anh_c3(int width,int height,int x,int y) 
{                       
   unsigned int i=0, j=0, k=0;                                                   
   unsigned int16 count=0; 
   for(j=0;j<height;j++)                                     
   {    
      for(;i<width;) 
      { 
         for(k=8;k>0;k--)
         {
            glcd_pixel(x+i,y+j,bit_test(logo_spk[count],(k-1))); 
            i++;                        
         } 
         count++;           
      }                                   
      i=0; 
   } 
}
       

