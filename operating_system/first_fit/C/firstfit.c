#include <stdio.h>
#include <stdlib.h>

int main(){

	int n,i,mem[9],mem_space_counter[9]={2,4,8,16,32,64,128,256,512},internal_frag[9],external_frag=0,j=5,k=0;
	printf("Enter the number of processes\n");
	scanf("%d",&n);
	int size[n];


	for(i=0;i<n;i++){
		printf("Enter the size of the %d process in kb\n",(i+1));
		scanf("%d",&size[i]);	
	}


	for(i=0;i<9;i++){
		mem[i]=0;
		internal_frag[i]=mem_space_counter[i];
        }
	printf("\n\n");

	printf("                        ***PARTITION***\n");
	for(i=0;i<9;i++){
		printf("|  %d  |",mem_space_counter[i]);
	}
	printf("\n\n");
	

	for(i=0;i<n;i++){
		k=0;
		if(size[i]>0){
			while(k<9){
				k++;
				if(mem[j]==0 && mem_space_counter[j]>=size[i] ){
					mem[j]=1;									
					printf("Process %d is alotted to %d kb partition\n",(i+1),mem_space_counter[j]);
					internal_frag[j]=mem_space_counter[j]-size[i];
					size[i]=0;
					if(j==8){
						j=0;
					}else{
						j++;
					}
					break;
					}
			}
		}
	  }		
	printf("\n");
	printf("\n");


	for(i=0;i<9;i++){
		printf("Internal fragmentation for %d kb partition is %d\n",(i+1),internal_frag[i]);
		external_frag=external_frag+internal_frag[i];
	}
	printf("\n\n");

	printf("External fragmentation is %d\n",external_frag);
	printf("\n\n");

	return 0;
  }

	
