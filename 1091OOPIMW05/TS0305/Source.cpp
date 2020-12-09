#include <iostream>
#include <string>

#define MAX 1000 //approximately max size of drawing board

using namespace std;

int main()
{
	std::string board[MAX][MAX]; // declaration of array of string 
	std::string type;
	int x, y;

	cin >> x >> y; // board size input

	//filling the board with "*" character
	for (int i = 0; i < y; i++)
		for (int j = 0; j < x; j++)
			board[j][i] = "*";

	//looping until EXIT is entered
	while (1)
	{
		cin >> type;

		if (type == "EXIT")
			break;

		//the condition for square
		if (type == "S")
		{
			int widthS, xS, yS;

			cin >> widthS;
			cin >> xS >> yS;

			bool safe = true; //the boolean variable whether not drawing the board if out of range is reach of hitting other object

			//test case if the entered square coordinate is outside the draw board
			if ((xS > x) || (yS > y) || (xS < 0) || (yS < 0))
			{
				cout << "Out of range." << endl << endl;
				safe = false;
			}
			else if ((board[xS][yS] != "*") || ((xS + widthS) > x) || ((yS + widthS) > y))
			{
				cout << "Out of range." << endl << endl;
				safe = false;
			}
			else
			{
				//xGain and yGain is the countermeasure for overlapping drawing 
				//xGain store the coordinate which the "X" has been drawed and yGain store y coordinate
				//index is to store how many points has been drawed so far
				int xGain[100] = { 0 }, yGain[100] = { 0 }, index = 0;

				for (int i = 0; i < widthS; i++)
				{
					for (int j = 0; j < widthS; j++)
					{
						if ((board[xS][yS] == "*") && safe)
						{
							board[xS][yS] = "X";
							xGain[index] = xS;
							yGain[index] = yS;
							index++;
							xS++;
						}
						else
						{
							safe = false;
						}
					}
					yS++;
					xS -= widthS;
				}

				//if drawing hits another object, the board will revert back to the orginal board by back tracing the xGain and yGain
				if (!safe)
				{
					while (index != 0)
					{
						board[xGain[index]][yGain[index]] = "X";
						index--;
					}
				}
			}

			// if the object can be drawed, the board then will be printed according to the type of object and size
			if (safe)
			{
				for (int i = 0; i < x; i++)
				{
					for (int j = 0; j < y; j++)
					{
						cout << board[j][i];
					}
					cout << endl;
				}
				cout << endl;
			}
		}

		// condition for triangle shape
		else if (type == "T")
		{
			std::string typeT;
			int widthT, xT, yT;
			cin >> widthT >> xT >> yT;

			widthT -= 1; //decrease by 1 is to max the size become right value because another 1 is for the coordinate
			bool safe = true;//the boolean variable whether not drawing the board if out of range is reach of hitting other object

			//test case if the entered square coordinate is outside the draw board
			if ((xT > x) || (yT > y) || (xT < 0) || (yT < 0))
			{
				cout << "Out of range." << endl << endl;
				safe = false;
			}
			else if ((board[xT][yT] != "*"))
			{
				cout << "Out of range." << endl << endl;
				safe = false;
			}
			else
			{
				//xGain and yGain is the countermeasure for overlapping drawing 
				//xGain store the coordinate which the "X" has been drawed and yGain store y coordinate
				//index is to store how many points has been drawed so far
				int xGain[100] = { 0 }, yGain[100] = { 0 }, index = 0;

				cin >> typeT;

				//type LU triangle
				if (typeT == "LU")
				{
					if (((xT - widthT) < 0) || ((yT - widthT) < 0))
					{
						cout << "Out of range." << endl << endl;;
						safe = false;
					}
					else
					{
						for (int i = 0; i <= widthT; i++)
						{
							int tempX = xT;
							for (int j = 0; j <= widthT - i; j++)
							{
								if ((board[xT][yT] == "*") && safe)
								{
									board[xT][yT] = "X";
									xGain[index] = j;
									yGain[index] = i;
									index++;
									xT--;
								}
								else
								{
									safe = false;
								}
							}
							xT = tempX;
							yT--;
						}

						if (!safe)
						{
							while (index != 0)
							{
								board[xGain[index]][yGain[index]] = "X";
								index--;
							}
						}
					}
				}

				//type LD triangle
				else if (typeT == "LD")
				{
					if (((xT - widthT) < 0) || ((yT + widthT) > y))
					{
						cout << "Out of range." << endl << endl;;
						safe = false;
					}
					else
					{
						for (int i = 0; i <= widthT; i++)
						{
							int tempX = xT;
							for (int j = 0; j <= widthT - i; j++)
							{
								if ((board[xT][yT] == "*") && safe)
								{
									board[xT][yT] = "X";
									xGain[index] = j;
									yGain[index] = i;
									index++;
									xT--;
								}
								else
								{
									safe = false;
								}
							}
							xT = tempX;
							yT++;
						}

						if (!safe)
						{
							while (index != 0)
							{
								board[xGain[index]][yGain[index]] = "X";
								index--;
							}
						}
					}
				}

				//type RU triangle
				else if (typeT == "RU")
				{
					if (((xT + widthT) > x) || ((yT - widthT) < 0))
					{
						cout << "Out of range." << endl << endl;;
						safe = false;
					}
					else
					{
						for (int i = 0; i <= widthT; i++)
						{
							int tempX = xT;
							for (int j = 0; j <= widthT - i; j++)
							{
								if ((board[xT][yT] == "*") && safe)
								{
									board[xT][yT] = "X";
									xGain[index] = j;
									yGain[index] = i;
									index++;
									xT++;
								}
								else
								{
									safe = false;
								}
							}
							xT = tempX;
							yT--;
						}

						if (!safe)
						{
							while (index != 0)
							{
								board[xGain[index]][yGain[index]] = "X";
								index--;
							}
						}
					}
				}

				//type RD triagle
				else if (typeT == "RD")
				{
					if (((xT + widthT) > x) || ((yT + widthT) > y))
					{
						cout << "Out of range." << endl << endl;;
						safe = false;
					}
					else
					{
						for (int i = 0; i <= widthT; i++)
						{
							int tempX = xT;
							for (int j = 0; j <= widthT - i; j++)
							{
								if ((board[xT][yT] == "*") && safe)
								{
									board[xT][yT] = "X";
									xGain[index] = j;
									yGain[index] = i;
									index++;
									xT++;
								}
								else
								{
									safe = false;
								}
							}
							xT = tempX;
							yT++;
						}

						if (!safe)
						{
							while (index != 0)
							{
								board[xGain[index]][yGain[index]] = "X";
								index--;
							}
						}
					}
				}
			}

			// if the object can be drawed, the board then will be printed according to the type of object and size
			if (safe)
			{
				for (int i = 0; i < x; i++)
				{
					for (int j = 0; j < y; j++)
					{
						cout << board[j][i];
					}
					cout << endl;
				}
				cout << endl;
			}
		}

		//shape Line condition
		else if (type == "L")
		{
			int distance, x1L, y1L, x2L, y2L;
			bool straight = true;

			cin >> x1L >> y1L >> x2L >> y2L;

			bool safe = true;

			//check if the line is straight or not 
			if (y1L == y2L)
			{
				distance = abs(x2L - x1L);
				straight = true;
			}
			else
			{
				distance = abs(x2L - x1L);
				straight = false;
			}

			//the if to check whether the two coordinates of line is outside draw board
			if ((x1L > x) || (y1L > y) || (x2L > x) || (y2L > y) || (x1L < 0) || (y1L < 0) || (x2L < 0) || (y2L < 0))
			{
				cout << "Out of range." << endl << endl;;
				safe = false;
			}
			else if ((board[x1L][y1L] != "*"))
			{
				cout << "Out of range." << endl << endl;;
				safe = false;
			}
			else
			{
				//xGain and yGain is the countermeasure for overlapping drawing 
				//xGain store the coordinate which the "X" has been drawed and yGain store y coordinate
				//index is to store how many points has been drawed so far
				int xGain[100] = { 0 }, yGain[100] = { 0 }, index = 0;

				if (straight)
				{
					//this case if to draw the line downwards if x2 coordinate is larger than x1
					if (x1L < x2L)
					{
						for (int i = 0; i < distance; i++)
						{
							if ((board[x1L][y1L] == "*") && safe)
							{
								board[x1L][y1L] = "X";
								xGain[index] = x1L;
								yGain[index] = y1L;
								index++;
								x1L++;
							}
							else
							{
								safe = false;
							}
						}

						if ((board[x2L][y2L] == "*") && safe)
						{
							board[x2L][y2L] = "X";
							xGain[index] = x2L;
							yGain[index] = y2L;
							index++;
							x2L++;
						}
						else
							safe = false;

						if (!safe)
						{
							while (index != 0)
							{
								board[xGain[index]][yGain[index]] = "X";
								index--;
							}
						}
					}
					//this case if to draw the line downwards if x2 coordinate is smaller than x1
					else
					{
						for (int i = 0; i < distance; i++)
						{
							if ((board[x1L][y1L] == "*") && safe)
							{
								board[x1L][y1L] = "X";
								xGain[index] = x1L;
								yGain[index] = y1L;
								index++;
								x1L--;
							}
							else
							{
								safe = false;
							}
						}

						if ((board[x2L][y2L] == "*") && safe)
						{
							board[x2L][y2L] = "X";
							xGain[index] = x2L;
							yGain[index] = y2L;
							index++;
							x2L--;
						}
						else
							safe = false;

						if (!safe)
						{
							while (index != 0)
							{
								board[xGain[index]][yGain[index]] = "X";
								index--;
							}
						}
					}
				}

				//the condition if the line is not straight (in this case diagonally)
				else
				{
					// case for x1 is smaller than x2
					if (x1L < x2L)
					{
						for (int i = 0; i < distance; i++)
						{
							if ((board[x1L][y1L] == "*") && safe)
							{
								board[x1L][y1L] = "X";
								xGain[index] = x1L;
								yGain[index] = y1L;
								index++;
								x1L++;
								y1L++;
							}
							else
							{
								safe = false;
							}
						}


						if ((board[x2L][y2L] == "*") && safe)
						{
							board[x2L][y2L] = "X";
							xGain[index] = x2L;
							yGain[index] = y2L;
							index++;
							x2L++;
						}
						else
							safe = false;


						if (!safe)
						{
							while (index != 0)
							{
								board[xGain[index]][yGain[index]] = "X";
								index--;
							}
						}
					}
					//test case for x1 is smaller than x2
					else if (x1L > x2L)
					{
						for (int i = 0; i < distance; i++)
						{
							if ((board[x1L][y1L] == "*") && safe)
							{
								board[x1L][y1L] = "X";
								xGain[index] = x1L;
								yGain[index] = y1L;
								index++;
								x1L--;
								y1L--;
							}
							else
							{
								safe = false;
							}
						}


						if ((board[x2L][y2L] == "*") && safe)
						{
							board[x2L][y2L] = "X";
							xGain[index] = x2L;
							yGain[index] = y2L;
							index++;
							x2L--;
						}
						else
							safe = false;


						if (!safe)
						{
							while (index != 0)
							{
								board[xGain[index]][yGain[index]] = "X";
								index--;
							}
						}
					}
				}
			}

			// if the object can be drawed, the board then will be printed according to the type of object and size
			if (safe)
			{
				for (int i = 0; i < x; i++)
				{
					for (int j = 0; j < y; j++)
					{
						cout << board[j][i];
					}
					cout << endl;
				}
				cout << endl;
			}

		}

	}
	return 0;
}
