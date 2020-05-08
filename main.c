#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>
#include <dirent.h>
#include "input.h"
#include "userinterface.h"
#include "prints.h"
#include "sudokulogic.h"



int main(void) {
	
	setupWindow();
	printWelcome();
	int game[9][9];
	getch();
	menu(game);
	system("cls");
	printf("Solving\n");
	solveSudoku(game);
	printSudoku(game);
	
	return 0;
}
