signed int8 rti;
signed int8 vt_tr=0,vt_ht=5;
void vitri_rotary_360()
{
        if((input(rtenc_a)==0)&&(input(rtenc_b)==0)) vt_ht=0;  
   else if((input(rtenc_a)==1)&&(input(rtenc_b)==0)) vt_ht=1;   
   else if((input(rtenc_a)==1)&&(input(rtenc_b)==1)) vt_ht=2;   
   else if((input(rtenc_a)==0)&&(input(rtenc_b)==1)) vt_ht=3;        
}

void doc_rotary_360(signed int8 ght, signed int8 ghd)
{
   vitri_rotary_360();
   if(vt_tr==0)
   {
           if(vt_ht==1)  rti++;
      else if(vt_ht==3)  rti--;
   }
   else if(vt_tr==1)
   {
           if(vt_ht==2)  rti++; 
      else if(vt_ht==0)  rti--; 
   }
   else if(vt_tr==2)
   {
           if(vt_ht==3)  rti++; 
      else if(vt_ht==1)  rti--; 
   }
   else if(vt_tr==3)
   {
           if(vt_ht==0)  rti++;  
      else if(vt_ht==2)  rti--; 
   }     
   vt_tr=vt_ht;   
   if(rti>ght)       rti = ght;
   if((rti)<(ghd))   rti = ghd;
}

 
