#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{	
	int i;
	int n;      //number of points
	float x[n]; //vector of x values
	float f[n]; //vector of values of f(x)


	
	/*This problem is linearized using a logarithmic transformation ln f(x) ~ ln(a*e^bx) = ln a + bx
	Noting that the fit functions are g1(x) = 1 and g2(x) = x and the parameters
	are a1 = ln a and a2 = b, we reduce the problem to a case of linear function adjustment on the parameters
	By calling F(x) = ln f(x), we then have a new problem F(x) ~ G(x) = a1 + a2x*/
	
	
	//[ <g1,g1>   <g1,g2> ]   *   [a1]   =   [ <g1,F> ]   
	//[ <g2,g1>   <g2,g1> ]       [a2]       [ <g2,F> ]
	
	//we get a1 and a2 and, finally, we return to the initial parameters a = e^a1 and b = a2
 	
	//How are we making matrices for solving a system of equations using Cramer's rule
    //so we have to do A1 and A2 and calculate their determinants.
   
    // [ <g1,F>   <g1,g2> ]  
    // [ <g2,F>   <g2,g2> ]  // Matrix A1.
   
    // [ <g1,g1>   <g1,F> ]  
    // [ <g2,g1>   <g2,F> ]  // Matrix A2.
   
    // [ <g1,g1>   <g1,g2> ]  
    // [ <g2,g1>   <g2,g2> ]  // Matrix A.
    
    //soma1-> <g1,g2>; ; soma2-> <g2,g2>; soma3-> <g1,F> soma4-> <g2,F>
	//<g1,g1> = 1 = n; <g1,g2> = <g2,g1> = xi; <g2,g2> = xi*xi; <g1,F> = ln(xi); <g2,F> = ln(f(xi)*xi
   
    //F(x) = ln f(x)
    //g(x) = a*e^(bx)
    //g1(x) = 1
    //g2(x) = x
    //a1 = Det(A1)/Det(A)
    //a2 = Det(A2)/Det(A)
   
	float a1, a2;
	float a, b;
	float numa1;// -> Det(A1)
	float numa2;// -> Det(A2)
	float denom;// -> Det(A)
	
	printf("Digite a quantidade de pontos: ");
	scanf("%d", &n);
	if(n <= 0){
		printf("Naum eh possivel com essa quantidade de pontos");
	}
	
	else{
	printf("Quais sao os %d valores de x?\n ", n);
	for(i=0; i<n; i++){
		printf("x%d = ", i);	
		scanf("%f", &x[i]);
	}
	printf("\n");
	
	printf("Quais sa os %d valores de f(x)?\n ", n);
	for(i=0; i<n; i++){
		printf("f(x%d) = ", i);	
		scanf("%f", &f[i]);
	}
	printf("\n");

	float soma1 = 0, soma2 = 0, soma3 = 0, soma4 = 0, soma5=0;
		
	for(i = 0; i<n; i++){
		soma1 = soma1 + (x[i]);
		soma2 = soma2 + (pow(x[i],2));
		soma3 = soma3 + (log(f[i])) ;//log() -> natural logarithm(ln)
		soma4 = soma4 + (x[i]*log(f[i]));
	}
	printf("oi\n");
	
	
	numa1 = ((soma3*soma2) - (soma1*soma4));
	numa2 = ((n*soma4) - (soma3*soma1));
	denom = ((n*soma2) - (soma1*soma1));
	
	a1 = numa1/denom;
	a2 = numa2/denom;
	
	float e = 2.7183;//Euler number, approximated with 3 significant digits
	
	a = pow(e,a1);
	b = a2;
	
	printf("g(x) = %.4f*e^(%.4f*x)", a, b); 
	
	float tensao;
	tensao = a*(pow(e,(b*0.05)));		
	
	printf("\n");
	printf("A tensao com Grao de 0.05mm equivale em: %.4f MPa",tensao);
	}
	
	return 0;
}
