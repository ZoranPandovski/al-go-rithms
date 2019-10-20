#include <stdio.h>

int main()
{
    int  i,j,ii,jj,n;
    int count=0, max_count=0, start_index=0, temp_start_index=0;
    int data[100] ;


	printf("Input Array n : ");
	scanf("%d",&n);
	printf("\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&data[i]);
	}
	printf("%d  ",data[0]);
	printf("\n");
	
        for(int i=0; i < n+1; ++i)
        {
   	    for (j=n;j>=0;--j)
   	    {
   	       for (ii=i,jj=j;;++ii,--jj)
   	       {
   	          if (data[ii]==data[jj])
   	          {
   	             if (count==0)
   	             {
   	                temp_start_index=ii;
   	             }
  	             ++count;
  	             if (ii==jj)
        	     {
                    	count=count*2-1;
                    	break;
              	     }
                     else{
                       if (ii>jj)
                       {
                          --count;
                          count=count*2;
                          break;
                       }
               	  }

           }

           else
           {
               count=0;
               break;
           }
       }


       if (count>max_count)
       {
           max_count=count;
           start_index=temp_start_index;
           count=0;
           temp_start_index=0;

       }
   }
 }
 printf("Subarray palindrom\n");
 
  for (i=start_index;i<start_index+max_count;++i)
  {
    printf("%d ",data[i]);
  }
  return 0;
 }

