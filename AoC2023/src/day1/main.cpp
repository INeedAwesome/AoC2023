#include <iostream>
#include <string>


/*
1abc2
pqr3stu8vwx
a1b2c3d4e5f
treb7uchet

->

12 +
38 + 
15 +
77

-> skip numbers if found in the middle
-> if only one number is found, make it form a two-digit number

*/

using std::string;

int finalResult = 0;

void FindAndCombine(string str) 
{
	string firstNumber = "0";
	string lastNumber = "0";

	// find first number
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (firstNumber == "0")
			{
				firstNumber = str[i];
				break;
			}
		}
	}

	// find last number
	for (int i = str.size(); i >= 0; i--)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (lastNumber == "0")
			{
				lastNumber = str[i];
				break;
			}
		}
	}
	finalResult += stoi(firstNumber + lastNumber);
}

int main ()
{
	std::cout << "Hello World!\n";
	
	FILE* file;
	file = fopen("Input.txt", "r");
	if (!file)
	{
		std::cout << "File does not exist!" << std::endl;
		return 0;
	}

	int c = 0;
	string charactersToBeRead;
	int stringPosition = 0;

	do
	{
		do
		{
			c = fgetc(file);

			if (c == -1)
			{
				break;
			}
			charactersToBeRead += c;
			

		} while (c != '\n');

		FindAndCombine(charactersToBeRead);
		charactersToBeRead = "";

	} while (c != EOF);

	std::cout << "Final result = " << finalResult;

	return 0;
}

