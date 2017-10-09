var n1 = '00101101';
var n2 = '00011101';

function add() {

    n1.toString();
    n2.toString();

    var len1 = n1.length;
    var len2 = n2.length;
    var carry = 0;
    var res = [];
    
    if(len1>=len2) {
        for(var k=0;i<len1;i++){
            res[i]=0;
            if(!(n1[i]==0||n1[i]==1)){
                console.log('Not Binary numbers');
                return 0;
            }
        }
        var j=len2-1;
        var i=len1-1;
        for(i;j>=0;i--) {
            if(carry==0 && n1[i]==0 && n2[j]==0) {
                res[i]=0;
                carry =0;
                j--;
            } else if(carry==0 && n1[i]==1 && n2[j]==1) {
                carry = 1;
                res[i]= 0;
                j--;
            } else if(carry==1 && n1[i]==0 && n2[j]==1) {
                carry = 1;
                res[i]= 0;
                j--;
            } else if(carry==1 && n1[i]==1 && n2[j]==0) {
                carry = 1;
                res[i]= 0;
                j--;
            } else if(carry==1 && n1[i]==1 && n2[i]==1) {
                carry = 1;
                res[i]= 1;
                j--;
            } else {
                carry = 0;
                res[i]= 1;
                j--;
            }
        }
        for(i;i>=0;i--) {
            if(j==-1) {
                res[i]=Number(carry) + Number(n1[i]);
            } else {
                res[i]=n1[i];
            }
        }
        res.toString();
        console.log(res.join(''));
    } else {
        for(var k=0;i<len2;i++){
            res[i]=0;
            if(!(n2[i]==0||n2[i]==1)){
                console.log('Not binary numbers');
                return 0;
            }
        }
        var j=len1-1;
        var i=len2-1;
        for(i;j>=0;i--) {
            if(carry==0 && n2[i]==0 && n1[j]==0) {
                res[i]=0;
                carry =0;
                j--;
            } else if(carry==0 && n2[i]==1 && n1[j]==1) {
                carry = 1;
                res[i]= 0;
                j--;
            } else if(carry==1 && n2[i]==0 && n1[j]==1) {
                carry = 1;
                res[i]= 0;
                j--;
            } else if(carry==1 && n2[i]==1 && n1[j]==0) {
                carry = 1;
                res[i]= 0;
                j--;
            } else if(carry==1 && n2[i]==1 && n1[i]==1) {
                carry = 1;
                res[i]= 1;
                j--;
            } else {
                carry = 0;
                res[i]= 1;
                j--;
            }
        }
        for(i;i>=0;i--) {
            if(j==-1) {
                res[i]=Number(carry) + Number(n2[i]);
            } else {
                res[i]=n2[i];
            }
        }
        res.toString();
        console.log(res.join(''));
    }
}