#include <stdio.h>
#include <stdlib.h>

int main(){

	int n,i,mem[9],mem_space_counter[9]={2,4,8,16,32,64,128,256,512},internal_frag[9],external_frag=0,j,flag=0;
	printf("Enter the number of processes\n");
	scanf("%d",&n);
	int size[n];


	for(i=0;i<n;i++){
		printf("Enter the size of the %d process in kb\n",(i+1));
		scanf("%d",&size[i]);	
	}


	for(i=0;i<9;i++){
		mem[i]=0;
		internal_frag[i]=0;
        }
	printf("\n\n");

	printf("                        ***PARTITION***\n");
	for(i=0;i<9;i++){
		printf("|  %d  |",mem_space_counter[i]);
	}
	printf("\n\n");
	

	for(i=0;i<n;i++){
		if(size[i]>0){
			for(j=0;j<9;j++){
				if(mem[j]==0 && mem_space_counter[j]>=size[i] ){
					mem[j]=1;									
					printf("Process %d is alotted to %d kb partition\n",(i+1),mem_space_counter[j]);
					internal_frag[j]=mem_space_counter[j]-size[i];
					size[i]=0;
					break;
					}
			}
		}
	  }		
	printf("\n");
	printf("\n");
    
	for(i=0;i<9;i++){
		printf("Internal fragmentation for %d kb partition is %d\n",(i+1),internal_frag[i]);

	}
	printf("\n\n");



	for(i=0;i<n;i++){
		for(j=0;j<9;j++){
			if(internal_frag[j]>size[i] && size[i]>0){
				printf("External fragmentation for %d kb process is available at %dth patition\n",size[i],j);
	flag=1;}}}
	
	printf("\n\n");
	if(flag==0)
        printf("There is no external fragmentation\n");

	return 0;
  }

	
