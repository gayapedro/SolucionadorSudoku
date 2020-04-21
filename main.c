#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int tries;
clock_t t;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void printSudoku(int game[9][9]){
	system("cls");
	printf("Try %d\n\n",tries);
	int i,j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if(game[i][j]==0) printf("  ");
			else printf("%d ",game[i][j]);
			if(j==2) printf("  ");
			if(j==5) printf("  ");
			if(j==8) printf("\n");
			if(i==2 && j==8) printf("\n");
			if(i==5 && j==8) printf("\n");
		}
	}
}

int isSolved(int game[9][9]){
	int i,j,sum;
	for(i=0;i<9;i++){
		sum = 0;
		for(j=0;j<9;j++){
			sum+=game[i][j];
		}
		if(sum != 45) return 0;
	}
	for(i=0;i<9;i++){
		sum = 0;
		for(j=0;j<9;j++){
			sum+=game[j][i];
		}
		if(sum != 45) return 0;
	}
	return 1;
}

void solveSudoku(int game[9][9]){
	int i,j,guess;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if(isSolved(game)){
				printSudoku(game);
				t = clock() - t;
				double taken = ((double)t)/CLOCKS_PER_SEC;
				printf("\n%f segundos\n",taken);
				getch();
			}
			if(game[i][j] == 0){
				guess = 1;
				while(guess <= 9){
					tries++;
					if(isValid(game,i,j,guess)){
						//printSudoku(game);
						game[i][j] = guess;
						solveSudoku(game);
					}
					if(guess==9 && !isValid(game,i,j,guess)){
						game[i][j] = 0;
						return;
					}
					guess++;
				}
			}
		}
	}
}

int isValidBlock(int game[9][9],int i, int j, int value){
	int a,b;
	if(i<=2 && j<=2){
		for(a=0;a<3;a++){
			for(b=0;b<3;b++){
				if(value == game[a][b]) return 0;
			}
		}
	} else if(i<=2 && j>=3 && j<=5){
		for(a=0;a<3;a++){
			for(b=3;b<6;b++){
				if(value == game[a][b]) return 0;
			}
		}
	} else if(i<=2 && j>=6){
		for(a=0;a<3;a++){
			for(b=6;b<9;b++){
				if(value == game[a][b]) return 0;
			}
		}
	} else if(i>=3 && i<=5 && j<=2){
		for(a=3;a<6;a++){
			for(b=0;b<3;b++){
				if(value == game[a][b]) return 0;
			}
		}
	} else if(i>=3 && i<=5 && j>=3 && j<=5){
		for(a=3;a<6;a++){
			for(b=3;b<6;b++){
				if(value == game[a][b]) return 0;
			}
		}
	} else if(i>=3 && i<=5 && j>=6){
		for(a=3;a<6;a++){
			for(b=6;b<9;b++){
				if(value == game[a][b]) return 0;
			}
		}
	} else if(i>=6 && j<=2){
		for(a=6;a<9;a++){
			for(b=0;b<3;b++){
				if(value == game[a][b]) return 0;
			}
		}
	} else if(i>=6 && j>=3 && j<=5){
		for(a=6;a<9;a++){
			for(b=3;b<6;b++){
				if(value == game[a][b]) return 0;
			}
		}
	} else if(i>=6 && j>=6){
		for(a=6;a<9;a++){
			for(b=6;b<9;b++){
				if(value == game[a][b]) return 0;
			}
		}
	}
	return 1;
}

int isValid(int game[9][9],int i,int j,int value){
	int i1,i2;
	for(i1=0;i1<9;i1++){
		if(value == game[i][i1]) return 0;
	}
	for(i2=0;i2<9;i2++){
		if(value == game[i2][j]) return 0;
	}
	if(isValidBlock(game,i,j,value) == 0) return 0;
	return 1;
}

int main(void) {
	char line[9];
	int countline,i,a,b,game[9][9];
	countline = 1;
	/*
	int game[9][9] = {{0,6,0,3,0,0,8,0,4},
			{5,3,7,0,9,0,0,0,0},
			{0,4,0,0,0,6,3,0,7},
			{0,9,0,0,5,1,2,3,8},
			{0,0,0,0,0,0,0,0,0},
			{7,1,3,6,2,0,0,4,0},
			{3,0,6,4,0,0,0,1,0},
			{0,0,0,0,6,0,5,2,3},
			{1,0,2,0,0,9,0,8,0}
			};
	int game2[9][9] = {{6,2,9,1,7,8,4,3,5},
					   {8,4,5,3,6,2,7,9,1},
					   {1,3,7,0,9,4,8,0,6},
					   {2,7,8,6,4,3,5,1,9},
					   {3,9,1,2,8,5,6,7,4},
					   {4,5,6,7,1,9,2,8,3},
					   {9,6,3,8,5,7,1,4,2},
					   {5,8,4,9,2,1,3,6,7},
					   {7,1,2,4,3,6,9,5,8}};
	*/
	printf("Please type in the sudoku you want to solve line by line (0 for blank):\n\n");
	while(countline < 10){
		scanf("%s",line);
		for(i=0;i<9;i++){
			game[countline-1][i] = line[i]-'0';
		}
		countline++;
	}
	for(a=0;a<9;a++){
		for(b=0;b<9;b++){
			printf("%d",game[a][b]);
		}
		printf("\n");
	}
	system("cls");
	printf("Solving\n");
	t = clock();
	solveSudoku(game);
	return 0;
}
