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
			if(game[i][j] == 0){
				guess = 1;
				while(guess <= 9){
					if(isValid(game,i,j,guess)){
						*(*(game+i)+j) = guess;
						solveSudoku(game);
						if(isSolved(game)) return;
					}
					if(guess==9 && !isValid(game,i,j,guess)){
						*(*(game+i)+j) = 0;
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
