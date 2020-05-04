#include <string.h>
#include "prints.h"

void getInput(int game[9][9]){
	printf("e aqui?\n");
	getch();
	int countline = 1,i,j,k;
	for(j=0;j<9;j++){
		for(k=0;k<9;k++){
			*(*(game+k)+j) = -1;
		}
	}
	system("cls");
	printf("\n\t\tPlease type in the sudoku you want to solve line by line (0 for blank):\n\n");
	while(countline < 10){
		for(i=0;i<9;i++){
			printInput(game,countline-1,i);
			char c = getch();
			*(*(game+countline-1)+i) = c - '0';
		}
		countline++;
	}
}

void getFileInput(int game[9][9]){
	int i,countline;
	char line[9];
	char inputname[100];
	system("cls");
	printf("\t\t\t\n\nPlease type in the desired input file name (excluding .txt):\n");
	scanf("%s",inputname);
	strcat(inputname,".txt");
	FILE *inputfile = fopen(inputname,"r");
	if(inputfile == NULL){
		printf("\n\n\t\t\tError. The file could not be open.\n");
	}else{
		countline = 0;
		while(fscanf(inputfile,"%s",line) == 1){
			for(i=0;i<9;i++){
				*(*(game+countline)+i) = line[i] - '0';
			}
			countline++;
		}
		printSudoku(game);
		getch();
	}
	
}
