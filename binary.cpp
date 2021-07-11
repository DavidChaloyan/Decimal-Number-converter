//convert program
#include <iostream>
#include <math.h>
using namespace std;

void bin(int dec) 	//function covert decimal number to binary.
{
	int bin=0;
	for (int j=0; dec > 0; j++)
	{
		bin += (dec % 2)*pow(10,j); 
		dec /= 2;

	}
	cout<<"Your number in binary " << bin<<endl; 	//printing binary number.
}

void octal (int dec)	//function convert decimal number to octal.
{
	int bin=0;
	for (int j=0; dec >0; j++)
	{
		bin +=(dec % 8) *pow(10, j);
		dec /= 8;
	}
	cout<<"Your number in octal " <<bin<<endl;	//printing octal number.
}

void hex (int dec)	//function convert decimla number to hexadecimal.
{
	char hexaNum[100];	//char array to store hexadecimal number.
	int i=0;
	while ( dec != 0)
	{
		int temp = 0;	//check if temp < 10.
		temp = dec % 16;

		if (temp < 10) 
		{
			hexaNum[i]= temp +48;
			i++;
		} 
		else
		{
			hexaNum[i] = temp +55;
			i++;
		}
		
			dec = dec / 16;
	}
		

			cout<<"Your number in Hexadecimal ";	//printing hexadecimal number  array in reverse order.
		for (int j = i - 1; j >= 0; j--)
		{
			cout<<hexaNum[j];
		}
		
			cout<<endl;
}
	
int main () 
{
	int x;
	cout<<"Input a number"<<endl;
	cin >> x;
	bin(x);			//calling convert functions.
	octal(x);
	hex(x);
	return 0;
}


