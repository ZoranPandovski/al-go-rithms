#include<stdio.h>
char STR[50],PAT[50], REP[50],ANS[50];   //Declarations
int i=0,j=0,k=0,l=0,flag=0, p=0;         //Declarations
void read()                              // Function for reading 3 strings !!
{
  printf("\n Enter the string \n");         
  scanf("%[^\n]",STR);
  printf("\n Enter the pattern string \n");
  scanf("%c*%[^\n]",PAT);
  printf("\n Enter the replace string \n");
  scanf("%c*%[^\n]",REP);
}
void match()                            // Function for comparing 2 strings !!
{
  while(STR[i]!='\0')
  {
    if(STR[j]==PAT[p])
    {
      j++;
    }
    if(PAT[p]=='\0')
    {
      flag=1;
      for(k=0;REP[k]!='\0';k++)
        ANS[i++]=REP[k];
      i=j;
      p=0;
    }
    else
    {
      ANS[l++]=STR[i++];
      j=i;
      p=0;
    }
  }
  ANS[l]='\0';
}
void main()
{ 
  void read();                      //Function calls !!
  void match();                              
  if(flag==0)
  {
    printf("\n Pattern doesn't match !!");
  }
  else
  {
    printf("\n The pattern after replacing :");
    puts(ANS);
  }
}




  
