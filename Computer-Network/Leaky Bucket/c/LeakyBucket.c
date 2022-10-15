//19BCE246-Akshat Shah
//CN Practical-9
//Leaky Bucket Problem
#include<stdio.h>
#include<stdlib.h>

//Packet Structure
struct packet{
    int time;
    int size;
}p[50];

//Main function
int main(void){
    int i,n,m,k=0;
    int bsize;  //Size of bucket
    int bfilled;//Boolean for bucket filled or not
    int outrate;//Output rate
    printf("Enter the number of packets: ");
    scanf("%d",&n);//Number of Packets
    
    //Packets input
    printf("Enter packets in the order of their Arrival Time\n");
    for(i=0;i<n;i++){
        //Time at which packet enters
        printf("Enter time of packet - %d: ", i+1);
        scanf("%d",&p[i].time);
        //Size of the given packet
        printf("Enter size of packet - %d: ", i+1);
        scanf("%d",&p[i].size);
    }

    //Size of the bucket
    printf("Enter the Bucket size: ");
    scanf("%d",&bsize);

    //Output rate of the Leaky Bucket
    printf("Enter the output rate: ");
    scanf("%d", &outrate);

    //Time of the entry of the last packet
    m=p[n-1].time;

    i=1;
    k=0;
    bfilled=0;


    while(i<=m || bfilled!=0){
        printf("\n\nAt time %d",i);
        //At a given time
        if(p[k].time==i){
            //If there is no overflow and enough space to add new packets in the bucket, new packet is inserted
            if(bsize>=bfilled+p[k].size){
                bfilled+=p[k].size;
                printf("\n%d byte packet is inserted", p[k].size);
                k++;
            }
            //Else, to avoid overflow, new packet is discarded.
            else{
                printf("\n%d byte packet is discarded.", p[k].size);
                k++;
            }
        }
        
        //If bucket is empty
        if(bfilled==0){
            printf("\nNo packets to transmit");
        }

        //If there are more bytes than the output rate, outrate bytes are transferred
        else if(bfilled>=outrate){
            bfilled-=outrate;
            printf("\n%d bytes transferred", outrate);
        }

        //Else the given number of bytes present in the bucket are transferred
        else{
            printf("\n%d bytes transferred", bfilled);
            bfilled=0;
        }

        //Prints the number of bytes present in the bucket after given time interval
        printf("\nPackets in the bucket %d byte", bfilled);
        i++;
    }
    return 0;
    //End of program
}

/*

Output :-
PS D:\CSE\SemesterV\CN\Practicals\Practical9> cd "d:\CSE\SemesterV\CN\Practicals\Practical9\" ; if ($?) { gcc 19BCE246_CN_Practical9.c -o 19BCE246_CN_Practical9 } ; if ($?) { .\19BCE246_CN_Practical9 }
Enter the number of packets: 3
Enter packets in the order of their Arrival Time
Enter time of packet - 1: 1
Enter size of packet - 1: 100
Enter time of packet - 2: 2
Enter size of packet - 2: 400
Enter time of packet - 3: 3
Enter size of packet - 3: 600
Enter the Bucket size: 500
Enter the output rate: 200


At time 1
100 byte packet is inserted
100 bytes transferred
Packets in the bucket 0 byte

At time 2
400 byte packet is inserted
200 bytes transferred
Packets in the bucket 200 byte

At time 3
600 byte packet is discarded.
200 bytes transferred
Packets in the bucket 0 byte


*/