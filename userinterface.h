#ifndef _INTERFACE_
#define _INTERFACE_

#include <stdlib.h>

void printWelcome(){
	system("cls");
	printf("\n\t   SSSSSSSSSSSSSSS                               d::::::d                 kkkkkkkk                             \n");
	printf("\t SS:::::::::::::::S                              d::::::d                 k::::::k                             \n");
	printf("\tS:::::SSSSSS::::::S                              d::::::d                 k::::::k                             \n");
	printf("\tS:::::S     SSSSSSS                              d:::::d                  k::::::k                             \n");
	printf("\tS:::::S            uuuuuu    uuuuuu      ddddddddd:::::d    ooooooooooo    k:::::k    kkkkkkkuuuuuu    uuuuuu  \n");
	printf("\tS:::::S            u::::u    u::::u    dd::::::::::::::d  oo:::::::::::oo  k:::::k   k:::::k u::::u    u::::u  \n");
	printf("\t S::::SSSS         u::::u    u::::u   d::::::::::::::::d o:::::::::::::::o k:::::k  k:::::k  u::::u    u::::u  \n");
	printf("\t  SS::::::SSSSS    u::::u    u::::u  d:::::::ddddd:::::d o:::::ooooo:::::o k:::::k k:::::k   u::::u    u::::u  \n");
	printf("\t    SSS::::::::SS  u::::u    u::::u  d::::::d    d:::::d o::::o     o::::o k::::::k:::::k    u::::u    u::::u  \n");
	printf("\t       SSSSSS::::S u::::u    u::::u  d:::::d     d:::::d o::::o     o::::o k:::::::::::k     u::::u    u::::u  \n");
	printf("\t            S:::::Su::::u    u::::u  d:::::d     d:::::d o::::o     o::::o k:::::::::::k     u::::u    u::::u  \n");
	printf("\t            S:::::Su:::::uuuu:::::u  d:::::d     d:::::d o::::o     o::::o k::::::k:::::k    u:::::uuuu:::::u  \n");
	printf("\tSSSSSSS     S:::::Su:::::::::::::::uud::::::ddddd::::::ddo:::::ooooo:::::ok::::::k k:::::k   u:::::::::::::::uu\n");
	printf("\tS::::::SSSSSS:::::S u:::::::::::::::u d:::::::::::::::::do:::::::::::::::ok::::::k  k:::::k   u:::::::::::::::u\n");
	printf("\tS:::::::::::::::SS   uu::::::::uu:::u  d:::::::::ddd::::d oo:::::::::::oo k::::::k   k:::::k   uu::::::::uu:::u\n");
	printf("\t SSSSSSSSSSSSSSS       uuuuuuuu  uuuu   ddddddddd   ddddd   ooooooooooo   kkkkkkkk    kkkkkkk    uuuuuuuu  uuuu\n\n");
	printf("\t   SSSSSSSSSSSSSSS                  lllllll                                                              \n");
	printf("\t SS:::::::::::::::S                 l:::::l                                                              \n");
	printf("\tS:::::SSSSSS::::::S                 l:::::l                                                              \n");
	printf("\tS:::::S     SSSSSSS                 l:::::l                                                              \n");
	printf("\tS:::::S               ooooooooooo    l::::lvvvvvvv           vvvvvvv eeeeeeeeeeee    rrrrr   rrrrrrrrr   \n");
	printf("\tS:::::S             oo:::::::::::oo  l::::l v:::::v         v:::::vee::::::::::::ee  r::::rrr:::::::::r  \n");
	printf("\t S::::SSSS         o:::::::::::::::o l::::l  v:::::v       v:::::ve::::::eeeee:::::eer:::::::::::::::::r \n");
	printf("\t  SS::::::SSSSS    o:::::ooooo:::::o l::::l   v:::::v     v:::::ve::::::e     e:::::err::::::rrrrr::::::r\n");
	printf("\t    SSS::::::::SS  o::::o     o::::o l::::l    v:::::v   v:::::v e:::::::eeeee::::::e r:::::r     r:::::r\n");
	printf("\t       SSSSSS::::S o::::o     o::::o l::::l     v:::::v v:::::v  e:::::::::::::::::e  r:::::r     rrrrrrr\n");
	printf("\t            S:::::So::::o     o::::o l::::l      v:::::v:::::v   e::::::eeeeeeeeeee   r:::::r            \n");
	printf("\t            S:::::So::::o     o::::o l::::l       v:::::::::v    e:::::::e            r:::::r            \n");
	printf("\tSSSSSSS     S:::::So:::::ooooo:::::ol::::::l       v:::::::v     e::::::::e           r:::::r            \n");
	printf("\tS::::::SSSSSS:::::So:::::::::::::::ol::::::l        v:::::v       e::::::::eeeeeeee   r:::::r            \n");
	printf("\tS:::::::::::::::SS  oo:::::::::::oo l::::::l         v:::v         ee:::::::::::::e   r:::::r            \n");
	printf("\t SSSSSSSSSSSSSSS      ooooooooooo   llllllll          vvv            eeeeeeeeeeeeee   rrrrrrr            \n\n\n\n");
	printf("\t\t\t\t\t\tPRESS ANY KEY TO START.\n");	
}

void setupWindow(){
	WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
    	wColor = (csbi.wAttributes & 0xF0) + (1 & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
     }
	HWND hWnd;
    SetConsoleTitle("SudokuSolver");
    keybd_event(VK_MENU,0x38,0,0);
	keybd_event(VK_RETURN,0x1c,0,0);
	keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
	keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

void menu(int game[9][9]){
	int input;
	printf("\n\n\t\tPlease select:\n");
	printf("\n\t\t\t1 - Manual input\n");
	printf("\t\t\t2 - File input\n");
	printf("\t\t\t3 - Exit\n");
	scanf("%d",&input);
	if(input == 1){
		getInput(game);
	} else if(input == 2){
		printf("chegou aqui\n");
		getch();
		getFileInput(game);
		printf("aqui 2\n");
		getch();
	} else{
		system("cls");
		printf("\n\n\t\tThank you for using SudokuSolver.\n");
		printf("\t\tWritten in C by Pedro Gaya\n");
		printf("\t\tgithub: gayapedro\n");
		exit(1);
	}
}

void printFiles(){
	struct dirent *arquivo;
    DIR *dr = opendir("."); 
    while ((arquivo = readdir(dr)) != NULL){
    		if(arquivo->d_name[arquivo->d_namlen-1]=='t' && arquivo->d_name[arquivo->d_namlen-2]=='x' && arquivo->d_name[arquivo->d_namlen-3]=='t' && arquivo->d_name[arquivo->d_namlen-4]=='.'){
    			printf("%s\n",arquivo->d_name);
			}
    }
    closedir(dr);
}

#endif
