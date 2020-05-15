#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

void numberGuesserGame()
{
	int lowerLim;
	int upperLim;
	int generatedNum;
	int guessedNum = INT_MIN;

	cout << "Enter two integers for the upper and lower limits: ";
	cin >> lowerLim >> upperLim;

	generatedNum = (rand() % upperLim) + lowerLim;

	cout << "Guess what number I'm thinking of between " << lowerLim << " and " << upperLim << ": ";

	while (guessedNum != generatedNum)
	{
		cin >> guessedNum;

		if (guessedNum < generatedNum)
		{
			cout << "You guessed too low.  Try again: ";
		}
		else if (guessedNum > generatedNum)
		{
			cout << "You guessed too high.  Try again: ";
		}
		else
		{
			cout << "Correct!  You win!";
		}
	}
}

void vowelRemover()
{
	string str;
	string newStr;
	do
	{
		newStr = "";
		cout << "Enter some words, and I'll remove the vowels.  Type 'Q' to quit.\n\n";
		getline(cin, str);

		if (str == "Q" || str == "q") // return before printing "Q"
			return;

		for (int i = 0; i < str.length(); i++)
		{
			if (!(str[i] == 'a' ||
				  str[i] == 'e' ||
				  str[i] == 'i' ||
				  str[i] == 'o' ||
				  str[i] == 'u' ||
				  str[i] == 'A' ||
				  str[i] == 'E' ||
				  str[i] == 'I' ||
				  str[i] == 'O' ||
				  str[i] == 'U'))
			{
				newStr += str[i];
			}
		}

		cout << newStr << "\n\n";
	} while (str != "q" && str != "Q");
}

int main()
{
	string userChoice = "";

	while (userChoice != "q" && userChoice != "Q")
	{
		cout << "Welcome to CURT (Curt's Usesless and Ridiculous Things)!\n"
			 << "========================================================\n\n"
			 << "We have:"
		     << "\n\n ------------------------------\n"
			 << "| [1] Guess my Number          |\n"
			 << "| [2] My Computer Had a Stroke |\n"
			 << " ------------------------------\n\n"
			 << "Enter the number of the Useless Thing you'd like to experience,\n"
			 << "or type 'Q' to quit: ";
		
		getline(cin, userChoice);

		if (userChoice == "1")
		{
			system("cls");
			numberGuesserGame();
			sleep_for(seconds(3));
		}
		else if (userChoice == "2")
		{
			system("cls");
			vowelRemover();
		}
		else if (userChoice == "Q" || userChoice == "q")
		{
			return 0;
		}
		system("cls");
	}

	return 0;
}