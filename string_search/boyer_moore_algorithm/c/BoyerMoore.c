#include <stdio.h>
#include <string.h>
#include<math.h>
#define SIZE 128
#define Min(a,b) (((a)<(b))?(a):(b))

void *CalculatedLast(char *); //function prototypes
int Last(char);
int BooyerMoor(char *,char *);

int alphabet[SIZE];

void main(){

	char *text = "dcabcdabc";
	char *pattern = "abcdabc";
	
		
        CalculatedLast(pattern);

	printf("%d\n",BooyerMoor(text,pattern));

}

void *CalculatedLast(char *P)
{
	int count;
	int i;
	int m= strlen(P);
	//initializing array elements to "-1"
	for(count = 0; count<SIZE; count++){
		alphabet[count] = -1;

	}

	//assigning dictionary values
	for(i = (m-1); i>=0;i--){
		if(alphabet[ (int)P[i]]==-1){
			alphabet[(int) P[i]] = i;
		}
	}
}

int Last(char C)
{
	return alphabet[(int) C];
	
}

int BooyerMoor(char *T,char *P)
{
	int m = strlen(P);
	int n = strlen(T);
	int i = m-1;  //using for calculate the shifts
	int j = m-1; //using for indexing the pattern

	while(i<n-m){
		//check whether a match was found
		if(P[i]==T[i]){
			if(j==0){
				//return the number of shift has made
				return i;
			}
			else{	//else slide through the pattern and text untill both are
				i = i-1;
				j = j-1;
			}
		}
		else{
			i += m - Min(j,1+Last(T[i])); //find the minimum from the pattern index 
							//and the text Last function
			j = m - 1;
		}
	}
	printf("No Match");
}
