#include<iostream>
#include<time.h>
using namespace std;

class tictac
{
protected:
	char mat[3][3]; //game matrix
	int move; //to store the move played by the player
public:
	tictac() //default constructor
	{
		move = 0;
	}
	int get_move(int n); //function to get the move from the player
	void initialize(); //to reset the game matrix
	void comp_move(); //function to get the move from the computer
	int check_row(); //function to check win in row
	int check_col(); //function to check win in column
	int check_diag(); //function to check win in diagonal
	void display(); //function to display the game matrix
	int game_over(); //function to display the result of the game
	void instructions_comp(); //function to display the instructions for Player 1 v/s Computer
};

class player2 :public tictac
{
public:
	player2()
	{
		mat[3][3] = { ' ' };
		move = 0;
	}
	int get_move1(int n);
	void instructions_player(); //function to display the instructions for Player 1 v/s Player 2
};

void tictac::initialize()
{
	int i, j;
	move = 0;
	for (i = 0; i<3; i++)
	{
		for (j = 0; j<3; j++)
			mat[i][j] = ' '; //reset every position
	}
	cout << endl;
}

void tictac::instructions_comp()
{
	cout << "*-*-*PLAYER 1 VS COMPUTER*-*-*" << endl;
	cout << "***INSTRUCTIONS***" << endl;
	cout << "\t\t\t" << "1" << "  | " << "2" << "  | " << "3" << endl;
	cout << "\t\t\t" << "------------" << endl;
	cout << "\t\t\t" << "4" << "  | " << "5" << "  | " << "6" << endl;
	cout << "\t\t\t" << "------------" << endl;
	cout << "\t\t\t" << "7" << "  | " << "8" << "  | " << "9" << endl;
	cout << endl;
	cout << "Every position in the grid has an unique number assigned." << endl;
	cout << "In order to play your move at the desired location, enter the number corresponding to the desired position." << endl;
	cout << endl;
	cout << "1.Player 1 always goes first and the move assigned is 'X'. The Computer's move assigned is 'O'." << endl;
	cout << "2.Player 1 and Computer alternately place Xs and Os respectively on the grid until either:" << endl;
	cout << " (a)Player 1 or Computer have all three moves in a row, column or along the diagonal." << endl;
	cout << " (b)All the nine squares are filled." << endl;
	cout << "3.If Player 1 is able to draw three Xs in a row, column or along the diagonal then PLAYER 1 WINS." << endl;
	cout << "4.If the Computer is able to draw three Os in a row, column or along the diagonal then COMPUTER WINS." << endl;
	cout << "5.If all nine squares are filled and neither Player 1 nor the Computer have three Xs or Os respectively in a row, column or along the diagonal the game ends with a DRAW." << endl;
	cout << endl;
}

int tictac::get_move(int n)
{
	int tempr, tempc;
	tempr = (n - 1) / 3; //calculating row index
	tempc = (n - 1) % 3; //calculating column index
	if (mat[tempr][tempc] == ' ')
	{
		mat[tempr][tempc] = 'X'; //store player move
		move++;
		cout << endl;
		return 1;
	}
	else
	{
		cout << "The position is already chosen, please choose a different position" << endl;
		return 0;
	}
}

void tictac::comp_move()
{
	int i, j;
	srand((unsigned)time(0)); //to generate computer move
	i = (rand() % 3); //calculating row index
	j = (rand() % 3); //calculating column index
	while (mat[i][j] != ' ') //calculate the row and column index till an empty position is found
	{
		i = (rand() % 3);
		j = (rand() % 3);
	}
	mat[i][j] = 'O'; //store computer move
	move++;
	cout << endl;
}

int tictac::check_row()
{
	int i;
	for (i = 0; i<3; i++)
	{
		if (mat[i][0] == mat[i][1] && mat[i][1] == mat[i][2] && mat[i][0] != ' ') //condition for win in a row
		{
			return 1;
		}
	}
	return 0;
}
int tictac::check_col()
{
	int j;
	for (j = 0; j<3; j++)
	{
		if (mat[0][j] == mat[1][j] && mat[1][j] == mat[2][j] && mat[0][j] != ' ') //condition for a win in column
		{
			return 1;
		}
	}
	return 0;
}

int tictac::check_diag()
{
	if (mat[0][0] == mat[1][1] && mat[1][1] == mat[2][2] && mat[0][0] != ' ') //condition for win in major diagonal
		return 1;
	else if (mat[0][2] == mat[1][1] && mat[1][1] == mat[2][0] && mat[0][2] != ' ') //condition for win in minor diagonal
		return 1;
	else
		return 0;
}

void tictac::display()
{
	cout << "\t\t\t" << mat[0][0] << "  | " << mat[0][1] << "  | " << mat[0][2] << endl;
	cout << "\t\t\t" << "------------" << endl;
	cout << "\t\t\t" << mat[1][0] << "  | " << mat[1][1] << "  | " << mat[1][2] << endl;
	cout << "\t\t\t" << "------------" << endl;
	cout << "\t\t\t" << mat[2][0] << "  | " << mat[2][1] << "  | " << mat[2][2] << endl;
	cout << endl;
}

int tictac::game_over()
{
	int i, j, k;
	i = check_row();
	j = check_col();
	k = check_diag();
	if (i == 1 || j == 1 || k == 1)
	{
		if ((move + 1) % 2 == 0)
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	else if (move == 9)
	{
		return 3;
	}
	return 0;
}

void player2::instructions_player()
{
	cout << "*-*-*PLAYER 1 VS PLAYER 2*-*-*" << endl;
	cout << "***INSTRUCTIONS***" << endl;
	cout << "\t\t\t" << "1" << "  | " << "2" << "  | " << "3" << endl;
	cout << "\t\t\t" << "------------" << endl;
	cout << "\t\t\t" << "4" << "  | " << "5" << "  | " << "6" << endl;
	cout << "\t\t\t" << "------------" << endl;
	cout << "\t\t\t" << "7" << "  | " << "8" << "  | " << "9" << endl;
	cout << endl;
	cout << "Every position in the grid has an unique number assigned." << endl;
	cout << "In order to play your move at the desired location, enter the number corresponding to the desired position." << endl;
	cout << endl;
	cout << "1.Player 1 always goes first and the move assigned is 'X'. Player 2 is assigned with move 'O'." << endl;
	cout << "2.Player 1 and Player 2 alternately place Xs and Os respectively on the grid until either:" << endl;
	cout << " (a)Player 1 or Player 2 have all three moves in a row, column or along the diagonal." << endl;
	cout << " (b)All the nine squares are filled." << endl;
	cout << "3.If Player 1 is able to draw three Xs in a row, column or along the diagonal then PLAYER 1 WINS." << endl;
	cout << "4.If Player 2 is able to draw three Os in a row, column or along the diagonal then PLAYER 2 WINS." << endl;
	cout << "5.If all nine squares are filled and neither Player 1 nor Player 2 have three Xs or Os respectively in a row, column or along the diagonal the game ends with a DRAW." << endl;
	cout << endl;
}

int player2::get_move1(int n)
{
	int tempr, tempc;
	tempr = (n - 1) / 3; //calculating row index
	tempc = (n - 1) % 3; //calculating column index
	if (mat[tempr][tempc] == ' ')
	{
		mat[tempr][tempc] = 'O'; //store player move
		move++;
		cout << endl;
		return 1;
	}
	else
	{
		cout << "The position is already chosen, please choose a different position" << endl;
		return 0;
	}
}

int main()
{
	tictac obj1;
	player2 obj2,obj3;
	int s, temp, pos, i,j;
	char p1[10], p2[10];
	char ans;
	do
	{
		temp = 10;
		obj1.initialize();
		obj2.initialize();
		cout << "***TIC TAC TOE***" << endl;
		cout << "1.Player 1 v/s Computer:" << endl;
		cout << "2.Player 1 v/s Player 2:" << endl;
		cout << "Enter your choice:" << endl;
		cin >> s;
		switch (s)
		{
		case 1:cout << "***Player 1 v/s Computer***" << endl;
			cout << "Player 1: Enter your name:" << endl;
			cin >> p1;
			cout << "Welcome " << p1 << "!!!" << endl;
			obj1.instructions_comp();
			cout << "Let's begin the game!" << endl;
			obj1.display();
			while (temp>0)
			{
				cout << endl;
				if (temp % 2 == 0)
				{
				T:
					try 
					{
						cout << p1 << ": Enter the position at which the move is to be played:" << endl;
						cin >> pos;
						if (pos >= 10 || pos <= 0)
							throw pos;
					}
					catch (int e)
					{
						cout << "Exception found, please enter the correct position" << endl;
						goto T;
					}
					j=obj1.get_move(pos);
					while (j == 0)
					{
					Q:
						try
						{
							cout << p1 << ": Enter the position at which the move is to be played:" << endl;
							cin >> pos;
							if (pos >= 10 && pos <= 0)
								throw pos;
						}
						catch (int e)
						{
							cout << "Exception found, please enter the correct position" << endl;
							goto Q;
						}
						j = obj1.get_move(pos);
					}
					i = obj1.game_over();
					if (i == 1)
					{
						cout << "***" << p1 << " Wins***" << endl;
						obj1.display();
						cout << endl;
						break;
					}
					else if (i == 2)
					{
						cout << "***Computer Wins***" << endl;
						obj1.display();
						cout << endl;
						break;
					}
					else if (i == 3)
					{
						cout << "***It's a Draw***" << endl;
						obj1.display();
						cout << endl;
						break;
					}
					obj1.display();
					cout << endl;
					temp--;
				}
				if (temp % 2 != 0)
				{
					cout << "Computer plays:" << endl;
					obj1.comp_move();
					i = obj1.game_over();
					if (i == 1)
					{
						obj1.display();
						cout << endl;
						break;
					}
					else if (i == 2)
					{
						cout << "***Computer Wins***" << endl;
						obj1.display();
						cout << endl;
						break;
					}
					else if (i == 3)
					{
						cout << "***It's a Draw***" << endl;
						obj1.display();
						cout << endl;
						break;
					}
					obj1.display();
					cout << endl;
					temp--;
				}
			}
			break;
		case 2:cout << "***Player 1 v/s Player 2***" << endl;
			cout << "Player 1: Enter your name:" << endl;
			cin >> p1;
			cout << "Player 2: Enter your name:" << endl;
			cin >> p2;
			cout << "Welcome " << p1 << " and " << p2 << "!!!" << endl;
			obj2.instructions_player();
			cout << "Let's begin the game!" << endl;
			obj2.display();
			while (temp>0)
			{
				cout << endl;
				if (temp % 2 == 0)
				{
				P:
					try
					{
						cout << p1 << ": Enter the position at which the move is to be played:" << endl;
						cin >> pos;
						if (pos >= 10 || pos <= 0)
							throw pos;
					}
					catch (int e)
					{
						cout << "Exception found, please enter the correct position" << endl;
						goto P;
					}
					j = obj2.get_move(pos);
					while (j == 0)
					{
					A:
						try
						{
							cout << p1 << ": Enter the position at which the move is to be played:" << endl;
							cin >> pos;
							if (pos >= 10 && pos <= 0)
								throw pos;
						}
						catch (int e)
						{
							cout << "Exception found, please enter the correct position" << endl;
							goto A;
						}
						j = obj2.get_move(pos);
					}
					i = obj2.game_over();
					if (i == 1)
					{
						cout << "***" << p1 << " Wins***" << endl;
						obj2.display();
						cout << endl;
						break;
					}
					else if (i == 2)
					{
						cout << "***" << p2 << " Wins***" << endl;
						obj2.display();
						cout << endl;
						break;
					}
					else if (i == 3)
					{
						cout << "***It's a Draw***" << endl;
						obj2.display();
						cout << endl;
						break;
					}
					obj2.display();
					cout << endl;
					temp--;
				}
				if (temp % 2 != 0)
				{
				B:
					try
					{
						cout << p2 << ": Enter the position at which the move is to be played:" << endl;
						cin >> pos;
						if (pos >= 10 || pos <= 0)
							throw pos;
					}
					catch (int e)
					{
						cout << "Exception found, please enter the correct position" << endl;
						goto B;
					}
					j = obj2.get_move1(pos);
					while (j == 0)
					{
					C:
						try
						{
							cout << p2 << ": Enter the position at which the move is to be played:" << endl;
							cin >> pos;
							if (pos >= 10 && pos <= 0)
								throw pos;
						}
						catch (int e)
						{
							cout << "Exception found, please enter the correct position" << endl;
							goto C;
						}
						j = obj2.get_move1(pos);
					}
					i = obj2.game_over();
					if (i == 1)
					{
						obj2.display();
						cout << endl;
						break;
					}
					else if (i == 2)
					{
						cout << "***" << p2 << " Wins***" << endl;
						obj2.display();
						cout << endl;
						break;
					}
					else if (i == 3)
					{
						cout << "***It's a Draw***" << endl;
						obj2.display();
						cout << endl;
						break;
					}
					obj2.display();
					cout << endl;
					temp--;
				}
			}
			break;
		default:
			break;
		}
		cout << "Do you want to play again? (y/n)" << endl;
		cin >> ans;
	} while (ans == 'y');
	system("PAUSE");
	return 0;
}