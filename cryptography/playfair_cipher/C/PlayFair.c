#include <stdio.h>
#define size 5
void encrypt(int *i, int *j)
{(
*i)++,(*j)++;
if((*i)==size) *i=0;
else if((*j)==size) *j=0;
}
void playfair(char ch1,char ch2, char mat[size][size])
{ int j,m,n,p,q,c,k;
for(j=0,c=0;(c<2)||(j<size);j++)
for(k=0;k<size;k++)
if(mat[j][k] == ch1)
m=j,n=k,c++;
else if(mat[j][k] == ch2)
p=j,q=k,c++;
if(m==p)
encrypt(&n,&q);
else if(n==q)
encrypt(&m,&p);
else
n+=q,q=n-q,n-=q;
printf("%c%c",mat[m][n],mat[p][q]);
}
void main()
{
char mat[size][size],key[10],str[25]={0};
int m,n,i,j;
char temp;
printf("Enter Key:");
gets(key);
m=n=0;
for(i=0;key[i]!='\0';i++)
{ for(j=0;j<i;j++)
if(key[j] == key[i]) break;
if(key[i]=='j') key[i]='i';
if(j>=i)
{
mat[m][n++] = key[i];
if(n==size)
n=0,m++;
}
} for(i=97;i<=122;i++)
{ for(j=0;key[j]!='\0';j++)
if(key[j] == i)
break;
else if(i=='j')
break;
if(key[j]=='\0')
{
mat[m][n++] = i;
if(n==size) n=0,m++;
}} printf("Enter input String:");
gets(str);
printf("\n\nMatrix :\n");
for(i=0;i<size;i++)
{
for(j=0;j<size;j++)
printf("%c\t",mat[i][j]);
printf("\n");
}
printf("\n\nEntered text :%s\nCipher Text :",str);
for(i=0;str[i]!='\0';i++)
{
temp = str[i++];
if(temp == 'j') temp='i';
if(str[i]=='\0')
playfair(temp,'x',mat);
else
{ if(str[i]=='j') str[i]='i';
if(temp == str[i])
{ playfair(temp,'x',mat);
playfair('x',str[i],mat);
}
else
playfair(temp,str[i],mat);
}}}
