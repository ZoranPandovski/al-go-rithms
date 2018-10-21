/* 
 * @Author: Sahana Muralikrishnan
 * @Email: sahana_m_student@headstartschool.org
 *
 * C code to convert temperature from farenheit to celcius using formula (F-32)*(5/9)
 */

#include<stdio.h>
int main()
{
	int farenheit;
	float celcius;
	printf("Enter temperature in farenheit\n");
	scanf("%d",&farenheit);

	celcius=(farenheit-32)*((float)5/9);

	printf("The temperature after conversion to Celcius is %.2f\n",celcius);

}
