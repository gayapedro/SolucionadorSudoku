void printSudoku(int game[9][9]){
	system("cls");
	int i,j;
	for(i=0;i<9;i++){
		printf("\t\t");
		for(j=0;j<9;j++){
			if(game[i][j]==0) printf("  ");
			else printf("%d ",game[i][j]);
			if(j==2) printf("  ");
			else if(j==5) printf("  ");
			else if(j==8) printf("\n");
			if(i==2 && j==8) printf("\n");
			else if(i==5 && j==8) printf("\n");
		}
	}
}

void printInput(int game[9][9],int a,int b){
	system("cls");
	int i,j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if(i==a && j==b) printf("X ");
			else if(game[i][j]==-1) printf("  ");
			else if(game[i][j]==0) printf("  ");
			else if(i<a) printf("%d ",game[i][j]);
			else if(i==a && j<=b) printf("%d ",game[i][j]);
			if(j==2) printf("  ");
			else if(j==5) printf("  ");
			else if(j==8) printf("\n");
			if(i==2 && j==8) printf("\n");
			else if(i==5 && j==8) printf("\n");
		}
	}
}
