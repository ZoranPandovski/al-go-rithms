#include <string.h>


int isAnagram(char string1[],char string2[]) 
{
	char temp;

	for(int i=0; string1[i]!=0; i++)
	{
		for(int j=i+1; string1[j]!=0; j++)
		{
			if(string1[i]>string1[j])
			{
				temp=string1[i];
				string1[i]=string1[j];
				string1[j]=temp;
					
			}
		}
	}

	for(int i=0; string2[i]!=0; i++)
	{
		for(int j=i+1; string2[j]!=0; j++)
		{
			if(string2[i]>string2[j])
			{
				temp=string2[i];
				string2[i]=string2[j];
				string2[j]=temp;
					
			}
		}
	}


	if(strcmp(string1,string2)==0)
		return 1;
	else 
		return 0;

}
