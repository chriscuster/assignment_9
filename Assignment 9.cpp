/*
Christopher Custer
CS


*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


//function to generate the score of the game
void generateScoreText(int[], int, string&);



//function to read in user input for bowling data
//void getPlayerRolls(int[], int&)
//{
//
//}



//function to store bowling data from file
//bool readPlayerRolls(int[], int&, string filename)
//{
//
//}

int main()
{
	string a = "Hello, world!!!!!";
	string score = "";
	char menuOption = ' ';
	int userRolls[21] = { 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5 };
	//bowling menu
	cout << "[R]ead roll data from a file" << endl;
	cout << "[I]nput roll data manually" << endl;
	cout << "[Q]uit Program" << endl;

	//loop to ensure user data is good
	while (true)
	{
		cout << "Enter selection: ";
		cin >> menuOption;

		switch (menuOption)
		{
		case 'R':
		case 'r':
			//open file for input using the bool function
			cout << a;
			break;
		case 'i':
		case 'I':
			cout << "input roll values" << endl;
			
			generateScoreText(userRolls, 21, score);
			cout << score;








			break;
		case 'q':
		case 'Q':
			cout << "quitting..." << endl;
			break;
		default:
			cout << "Incorrect input please select option from bracketed characters []." << endl;
			continue;
		}
		break;
	}




}

void generateScoreText(int arr[], int ttlRolls, string& score)
{
	bool isFirstRoll = true;
	int strikeRollNumber = 0;
	int ttlScore = 0;
	int frameScore = 0;
	// for 10 frames 1-10, 11th for calculating 10th frame
	int frames[12] = { };
	int frameIdx = 1;
	bool isSpare = false;

	for (int roll = 0; roll < ttlRolls; roll++)
	{
		// if last roll
		if (roll == ttlRolls)
		{
			frames[frameIdx] += arr[roll];
		}
		// if first roll
		else if (isFirstRoll)
		{
			frames[frameIdx] += arr[roll];
			isFirstRoll = false;

			// check for spare
			if (isSpare)
			{
				frames[frameIdx - 1] += arr[roll];
				isSpare = false;
			}
		}
		else
		{
			// add prev with this
			frames[frameIdx] += arr[roll];
			// check for spare
			if (frames[frameIdx] == 10)
			{
				isSpare = true;
			}
			if (frameIdx < 10)
			{
				frameIdx++;
				isFirstRoll = true;
			}
		}
	}

	//adding frame total
	for (int i = 1; i <= frameIdx && i < 11; i++)
	{
		ttlScore += frames[i];
	}
	score = to_string(ttlScore);
}


