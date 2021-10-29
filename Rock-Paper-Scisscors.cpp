// Duc Tran
// Rock Paper Scissors 

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

bool play_again = false;
const int  ROCK = 1, SCISSORS = 2, PAPER = 3;

int computer_choice(int comp_choice);

void displayComp_choice(int comp_choice);

int user_choice(int human_choice);

void find_winner(int comp_choice, int user_number);

void ask_to_play();

int main()
{
	int comp_choice = 1;
	int	human_choice = 1;

	do
	{
		comp_choice = computer_choice(comp_choice);

		human_choice = user_choice(human_choice);

		displayComp_choice(comp_choice);

		find_winner(comp_choice, human_choice);

		ask_to_play();
	} while (play_again == true);
}


int computer_choice(int comp_choice)
{
	srand(time(0));
	return comp_choice = rand() % 3 + 1;
}


void displayComp_choice(int comp_choice)
{
	cout << "\nComputer Choice = ";

	if (comp_choice == 1)
		cout << "Rock";
	else if (comp_choice == 2)
		cout << "Scissors";
	else if (comp_choice == 3)
		cout << "Paper";
	cout << endl;
}


int user_choice(int human_choice)
{
	int num;
	cout << "\nChoose 'rock', 'scissors', or 'paper'.\n";
	cout << "Enter (1) for rock, (2) for scissors, or (3) for paper: ";
	
	while (!(cin >> num) || (num < 1 || num > 3))
	{
		cin.clear();
		cin.ignore();
		cout << "\nInvalid choice!!!" << endl;
		cout << "Number must be between 1 and 3! Enter your choice again: \n";
	}
	return num;
}


void find_winner(int comp_choice, int human_choice)
{
	int sum = comp_choice + human_choice * 10;
	if (comp_choice == ROCK)
	{
		switch (sum)
		{
		case 11: sum = 11;		//	10 and 1
			cout << "Tie. Let's play again to determine the winner.\n";
			break;
		case 21: sum = 21; 		//	20 and 1
			cout << "Rock smashes scissors. Computer wins!!!\n";
			break;
		case 31: sum = 31;		//	30 and 1
			cout << "Paper covers rock. You win!!!\n";
			break;
		default:
			cout << "Invalid Value!!!";
		}
	}

	if (comp_choice == SCISSORS)
	{
		switch (sum)
		{
		case 12: sum = 12;		//	10 and 2	
			cout << "Rock smashes scissors. You win!!!\n";
			break;
		case 22: sum = 22;		//	20 and 2
			cout << "Tie. Let's play again to determine the winner.\n";
			break;
		case 32: sum = 32;		//	30 and 2
			cout << "Scissors cuts paper. Computer win!!!\n";
			break;
		default:
			cout << "Invalid Value!!!";
		}
	}

	if (comp_choice == PAPER)
	{
		switch (sum)
		{
		case 13: sum = 13;		//	10 and 3
			cout << "Paper covers rock. Computer wins!!!\n";
			break;
		case 23: sum = 23;		//	20 and 3
			cout << "Scissors cuts paper. You win!!!\n";
			break;
		case 33: sum = 33;		//	30 and 3
			cout << "Tie. Let's play again to determine the winner.\n";
			break;
		default:
			cout << "Invalid Value!!!";
		}
	}
}

void ask_to_play() {
	string choice;
	cout << "Want to play again? Yes (y) or No (n): " << endl;
	cin >> choice;
	if (choice == "yes" || choice == "y") {
		play_again = true;
	}
	else {
		play_again = false;
	}
}