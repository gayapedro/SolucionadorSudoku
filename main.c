#include <stdio.h>
#include <stdlib.h>
int tries;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void solveSudoku(int game[9][9]){
	int i,j,guess;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if(game[i][j] == 0){
				guess = 1;
				while(guess <= 9){
					tries++;
					if(isValid(game,i,j,guess)){
						game[i][j] = guess;
						printSudoku(game);
						solveSudoku(game);
					}
					guess++;
					if(guess==9 && !isValid(game,i,j,guess)){
						game[i][j] = 0;
						return;
					}
				}
			}
		}
	}
}

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
	tries = 0;
	int game[9][9] = {
						{4,6,7,9,2,1,3,5,8},
						{8,9,5,4,7,3,2,6,1},
						{2,3,1,8,6,5,7,4,9},
						{5,1,3,6,9,8,4,2,7},
						{9,2,8,7,0,4,6,1,3},
						{7,4,6,1,3,2,9,8,5},
						{3,5,4,2,8,7,1,9,6},
						{1,8,9,3,4,6,5,7,2},
						{6,7,2,5,1,9,8,3,4}
					};
					
	int game2[9][9] = {{0,2,0,4,5,6,7,8,9},
					   {4,5,7,0,8,0,2,3,6},
					   {6,8,9,2,3,7,0,4,0},
					   {0,0,5,3,6,2,9,7,4},
					   {2,7,4,0,9,0,6,5,3},
					   {3,9,6,5,7,4,8,0,0},
					   {0,4,0,6,1,8,3,9,7},
					   {7,6,1,0,4,0,5,2,8},
					   {9,3,8,7,2,5,0,6,0}
					   };
	
	int game3[9][9] = {{0,6,0,5,0,4,0,3,0},
					   {1,0,0,0,9,0,0,0,8},
					   {0,0,0,0,0,0,0,0,0},
					   {9,0,0,0,5,0,0,0,6},
					   {0,4,0,6,0,2,0,7,0},
					   {7,0,0,0,4,0,0,0,5},
					   {0,0,0,0,0,0,0,0,0},
					   {4,0,0,0,8,0,0,0,1},
					   {0,5,0,2,0,3,0,4,0}};
	
	solveSudoku(game3);
	return 0;
}
