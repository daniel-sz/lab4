#include <stdio.h>
#include <vector>
#include <iostream>
#include <iterator>
#include <string>
#include <map>
using namespace std;

void transform(long int);

int main(int argc, char *argv[])
{
	long int n;
	printf("%s\n", "Podaj liczbę: ");
	scanf("%ld", &n);
	cout<<"Twoja liczba to: ";
	transform(n);
	cout<<endl;
}

void transform(long int number)
{
	int last;
	vector <int> digits;
	for (int i = 0; number!=0; ++i)
	{
		last=number%10;
		digits.push_back(last);
		number/=10;
	}
	//przypisanie każdej poprawnej formy liczebnika do danej liczby
	map<int, string> hundreds;
	hundreds[1]= "sto";
	hundreds[2]= "dwieście";
	hundreds[3]= "trzysta";
	hundreds[4]= "czterysta";
	hundreds[5]= "pięćset";
	hundreds[6]= "sześćset";
	hundreds[7]= "siedemset";
	hundreds[8]= "osiemset";
	hundreds[9]= "dziewięćset";

	map<int, string> decimals;
	decimals[1]= "dziesięć";
	decimals[2]= "dwadzieścia";
	decimals[3]= "trzydzieści";
	decimals[4]= "czterdzieści";
	decimals[5]= "pięćdziesiąt";
	decimals[6]= "sześćdziesiąt";
	decimals[7]= "siedemdziesiąt";
	decimals[8]= "osiemdziesiąt";
	decimals[9]= "dziewięćdziesiąt";

	map<int, string> units;
	units[1]= "jeden";
	units[2]= "dwa";
	units[3]= "trzy";
	units[4]= "cztery";
	units[5]= "pięć";
	units[6]= "sześć";
	units[7]= "siedem";
	units[8]= "osiem";
	units[9]= "dziewięć";

	map<int, string> teens;
	teens[1]= "jedenaście";
	teens[2]= "dwanaście";
	teens[3]= "trzynaście";
	teens[4]= "czternaście";
	teens[5]= "piętnaście";
	teens[6]= "szesnaście";
	teens[7]= "siedemnaście";
	teens[8]= "osiemnaście";
	teens[9]= "dzięwiętnaście";

	for (int i=digits.size()-1;i>=0;i--) 
	{
		if(i==1 && digits[i]==1 || i==4 && digits[i]==1) cout<<teens[digits[i-1]]<<" "; 
		else if(i%3==2) cout<<hundreds[digits[i]]<<" ";
		else if(i%3==1) cout<<decimals[digits[i]]<<" ";
		else if(i%3==0 && digits[i+1]!=1) cout<<units[digits[i]]<<" ";
		if(i==3)
		{
			if(digits[i]==2 && digits[i+1]!=1|| digits[i]==3 && digits[i+1]!=1 || digits[i]==4 && digits[i+1]!=1) cout<<"tysiące ";
			else if(digits[i]==1 && digits.size()==4) cout<<"tysiąc ";
			else cout<<"tysięcy ";
		}
	}
}