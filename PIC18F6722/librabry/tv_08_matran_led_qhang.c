//Thu vien kit moi
#include <tv_09_font.c>
const unsigned int8 ma_quet_hang[8]={0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};
#define  mau_xanh  0
#define  mau_do    1
#define  mau_cam   2
#define  slkt_ht   60
unsigned int8 dl_hthi[6*slkt_ht+24+24];
unsigned int8 dl_cot_cd[48];
unsigned int8 dl_cot_dich[48];
unsigned int16 slkt;                 
                  
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//ham lay so luong ky tu cua chuoi
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void lay_so_luong_ky_tu_chuoi()
{   
   slkt=0;
   while(chuoi_hthi[slkt])   slkt++;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//ham xoa du lieu vung nho chua ma hien thi cua chuoi ve 0x00
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void xoa_dl_hienthi()
{   
   unsigned int16 j;     
   for(j=0;j<6*slkt_ht;j++)  dl_hthi[j]=0;
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//ham xoa vung nho chua du lieu 48 cot xanh do
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void xoa_dl_48_cot()
{
   unsigned int8 j;
   for(j=0;j<48;j++) dl_cot_cd[j]=0;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//ham lay ma cua chuoi bat ky theo ma led ma tran
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void lay_ma_ky_tu(usi8 slkt_x)
{   
   unsigned int8  kytu,i,j;
   unsigned int16  n;
   n=0;
   xoa_dl_hienthi();
   for (i=0; i<slkt_x; i++)
   {                                         
      kytu = chuoi_hthi[i];
      for(j=0;j<6 ;j++,n++)  
      dl_hthi[n+24]=mt_kytu[kytu][j]; 
   }                      
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//ham lay ma cua 1 so cua cac con so theo ma led ma tran
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void lay_ma_1_so_matran(usi8 so, vitri_luu)
{   
   unsigned int8  j; 
   so = so + 0x30;  //vi tri bat dau so la 0x30    
   for(j=0;j<6 ;j++)  
   dl_hthi[j+vitri_luu*6]=mt_kytu[so][j];
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//sap xep cac ky tu mau xanh 1,2,3,4 tong la 24 byte
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void sapxep_vitri_24byte_cot_xanh(usi16 k)
{
   signed int8 i;
   for(i=0; i<8;i++)  dl_cot_cd[i+32] = dl_hthi[i+k]; 
   for(i=8; i<16;i++) dl_cot_cd[i+8]  = dl_hthi[i+k]; 
   for(i=16;i<24;i++) dl_cot_cd[i-16] = dl_hthi[i+k];                   
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//sap xep cac ky tu mau do 1,2,3,4 tong la 24 byte
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void sapxep_vitri_24byte_cot_do(unsigned int16 k)
{   
   signed int8 i;
   for(i=0; i<8;i++)   dl_cot_cd[i+40] = dl_hthi[i+k]; 
   for(i=8; i<16;i++)  dl_cot_cd[i+16] = dl_hthi[i+k]; 
   for(i=16;i<24;i++)  dl_cot_cd[i-8]  = dl_hthi[i+k];    
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//ham copy 48 cot de hien thi
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void  copy_48_cot_hienthi()
{     
   unsigned int8 i;
   for(i=0;i<48;i++) dl_cot_dich[i]= dl_cot_cd[i];
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx  
//xuat 1 bit roi tra lai ket qua sau khi dich di 1 bit
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx   
unsigned int8 tao_dl_word1(usi8 x)
{ 
   #bit bserix  = x.0       
   wlmt[1] = (wlmt[1]<<1) + bserix;         
   x = x>>1;        
   return(x);  
}
unsigned int8 tao_dl_word2(usi8 x)
{ 
   #bit bserix  = x.0    
   wlmt[2] = (wlmt[2]<<1) + bserix;    
   x = x>>1;   
   return(x);  
}
unsigned int8 tao_dl_word3(usi8 x)
{ 
   #bit bserix  = x.0  
   wlmt[3] = (wlmt[3]<<1) + bserix;    
   x = x>>1;   
   return(x);  
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//ham copy tung bit cua 48 byte du lieu vung nho co s
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void copy_1_bit_cua_48_cot_hienthi()
{     
   unsigned int8 i;
   for(i=0;i<16;i++)  dl_cot_dich[i]= tao_dl_word1(dl_cot_dich[i]);
   for(i=16;i<32;i++) dl_cot_dich[i]= tao_dl_word2(dl_cot_dich[i]);
   for(i=32;i<48;i++) dl_cot_dich[i]= tao_dl_word3(dl_cot_dich[i]);
}
                                                                          
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void xuat_dulieu_tat_matran()
{    
   wlmt[3]=0;  wlmt[2]=0;
   wlmt[1]=0;  wlmt[0]=0;
   xuat_3led_matran();
}


void ma_tran_xoa_va_copy_dl(usi16 vitri,usi8 mau)
{
   xoa_dl_48_cot();        
   if(mau==mau_xanh)         
      sapxep_vitri_24byte_cot_xanh(vitri);
   else if(mau==mau_do)      
      sapxep_vitri_24byte_cot_do(vitri);
   else if(mau==mau_cam)     
   {
      sapxep_vitri_24byte_cot_do(vitri);
      sapxep_vitri_24byte_cot_xanh(vitri);
   }
}
void ma_tran_quet_8_hang()
{
   unsigned int8 k; 
   for(k=0;k<8;k++)
   {
      copy_1_bit_cua_48_cot_hienthi();
      wlmt[0]= ma_quet_hang[k];                  
      xuat_3led_matran();                                                                      
      delay_us(500); 
      xuat_dulieu_tat_matran();
   }      
}
unsigned int8 ck=0;
int1 ttx=1;
void ma_tran_quet_hang_if(usi8 sck,usi16 vitri,usi8 mau)
{   
   if(ttx) 
   {
      ma_tran_xoa_va_copy_dl(vitri, mau);
      ttx=0;
   }                                                 
   if(ck<sck)
   {                         
      copy_48_cot_hienthi();
      ma_tran_quet_8_hang();
      ck++;
   }  
   else ck=0;
}
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
void ma_tran_quet_hang(usi8 sck, usi16 vitri, usi8 mau)
{
   unsigned int8 ck; 
   ma_tran_xoa_va_copy_dl(vitri, mau);
   for(ck=0;ck<sck;ck++)
   {                   
      copy_48_cot_hienthi();
      ma_tran_quet_8_hang();
   }
}

/*
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//xuat 1 bit roi tra lai ket qua sau khi dich di 1 bit
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
unsigned  int8 xuat_1bit(unsigned int8 bx)
{ 
   #bit bitbx  = bx.0                                           
   output_bit(mbi_sdi,bitbx);    
   output_low(mbi_sck); 
   output_high(mbi_sck);
   bx= bx>>1;   
   return(bx);  
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
//doi 1 bit  sang thu tu cot
//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
unsigned int8 doi_1_bit_1_sang_thutux(unsigned int8 bx)
{   
   unsigned int8 ttcot=0;
   bx= bx>>1;
   while(bx!=0)
   {
      ttcot++;
      bx= bx>>1;
   }   
   return(ttcot);
}
*/          
