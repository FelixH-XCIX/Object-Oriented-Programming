#include "Form.h"


int main()
{
	Form form1;
	form1.SetInputWord("SWIMMING");
	form1.ProcessInputWord();
	form1.SetFileName("words.txt");
	form1.Load_CompaerWord();
	form1.PrintFoundWords();
	return 0;
}