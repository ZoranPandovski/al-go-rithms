/* 
 * @Author: Sahana Muralikrishnan
 * @Email: sahana_m_student@headstartschool.org
 *
 * C code to convert temperature from farenheit to celcius using formula (F-32)*(5/9)
 * 
 * Test with 95 -> 35.00
 * Test with -12 -> -24.44
 * Test with 0 -> -17.78
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
