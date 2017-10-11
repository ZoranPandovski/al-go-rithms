#include<stdio.h>
#include<string.h>
int flag;
int gcd(int n1, int n2){
    if(n1==1 || n2==1){
        return 1;
    }
    if(n1==n2){
      return 0;
    }
    if(n1>n2){
        return gcd(n1-n2,n2);
    }
    else{
        return gcd(n1,n2-n1);
    }
}
int main(){
    char lang[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9',' '};
    char pt[5],key[5];
    int len = 63;
    int i,j,k;
    int ptm[2][2],keym[2][2];
    printf("Enter Plain Text: ");
    scanf("%s",pt);
    printf("Enter Key Of Length 4 Of Prime Numbers:");
    for(i=0;i<4;i++){
        key[i] = getche();
    }
    printf("\n\n");
    if(strlen(pt)!=4){
        printf("Length Of Plain Text Should Be Equal To 4\n");
        exit(0);
    }
    int flag=-1;
    for(i=0;i<4;i++){
        if((i+1)%2==1){
            flag++;
        }
        for(j=0;j<len;j++){
            if(pt[i] == lang[j]){
                ptm[flag][i%2] = j;
            }
            if(key[i] == lang[j]){
                keym[flag][i%2] = j;
            }
        }
    }
    int ctm[2][2];
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            ctm[i][j] = 0;
        }
    }
    printf("\nCipher Text: ");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            for(k=0;k<2;k++){
                ctm[i][j] += keym[i][k] * ptm[k][j];
            }
            ctm[i][j] = ctm[i][j]%len;
            printf("%c",lang[ctm[i][j]]);
        }
    }
    printf("\n\n");
    flag = keym[0][0]*keym[1][1] - keym[0][1]*keym[1][0];
    int inv_num;
    i = -1;
    j = 1;
    int f = flag;
    if(flag<0){
        f = -(flag);
    }
    if(!gcd(f,len)){
        printf("Key Is Not Good, Try Another Key.");
    }
    while(1){
        if((flag * i)%len==1){
            inv_num = i;
            break;
        }
        i--;
        if((flag*j)%len==1){
            inv_num = j;
            break;
        }
        j++;
    }
    flag = keym[1][1];
    keym[1][1] = keym[0][0];
    keym[0][0] = flag;
    keym[0][1] = -keym[0][1];
    keym[1][0] = -keym[1][0];
    int dtm[2][2];
    printf("\nDecrypted Text: ");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            dtm[i][j]=0;
            for(k=0;k<2;k++){
                dtm[i][j] += keym[i][k] * ctm[k][j] * inv_num ;
            }
            if(dtm[i][j]<0){
                flag = len-((-dtm[i][j])%len);
                printf("%c",lang[flag]);
            }
            else{
                printf("%c",lang[dtm[i][j]%len]);
            }
        }
    }
    return 0;
}
