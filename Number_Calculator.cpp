#include <iostream>
#include <vector>
using namespace std;

/*
The first number is 123456789, the second is 123456798, the third is 123456879 and so on. 
No digit can repeat so 122345675 is not a valid number in this sequence.
The problem was "Write a program in that outputs the 100,000th number as fast as possible. 
Use any algorithm, except you cannot pre-calculate the answer and then write a program that just prints the result. 
Your entry must calculate the number!".
*/

int main() {
	vector<int> set(10);	
	int count = 0;	
	for(int i=123456789; i<987654321; ++i)
	{		
		bool validNumber = true;
		std::fill(set.begin(), set.end(), 0);

		int digit = i;
		while(digit)
		{
			int remainder = digit % 10;
			if (remainder == 0)
			{
				validNumber = false;
				break;
			}
			if (set[remainder] == 0)
			{
				set[remainder] = 1;
			}
			else
			{
				validNumber = false;
				break;
			}
			digit = digit / 10;
		}

		if (validNumber)
		{
			count++;
			if (count == 100000) {
				cout<<i;
				return i;
			}
		}
	}
}