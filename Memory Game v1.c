#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>

void menu();
void help();
void easy();
void medium();
void hard();
void insane();

int selected[4][4]={0};
int currentValue = 0 ; 
int prevX=0,prevY=0;
int pnt;

void delay(float number_of_seconds){
    /*Converting time into milli_seconds*/
    float ms = 1000 * number_of_seconds; 
  
    /*String start time*/
    clock_t start_time = clock(); 
  
    /*looping till required time is not acheived*/
    while (clock() < start_time + ms); 
} 

void gotoxy(short x, short y){/*declare the gotoxy function*/
	COORD pos ={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

int control(){
int t=0;

while ( !t ) {
	
	 if ( GetAsyncKeyState ( VK_UP ) & SHRT_MAX ) {
			t = 1;
	 }
	 else if ( GetAsyncKeyState ( VK_DOWN ) & SHRT_MAX ){
			t = 2;
	 }
	 else if ( GetAsyncKeyState ( VK_LEFT ) & SHRT_MAX ){
			t = 3;
	 }
	 else if ( GetAsyncKeyState ( VK_RIGHT ) & SHRT_MAX ){
			t = 4;

	 }
	 else if ( GetAsyncKeyState ( VK_LCONTROL) & SHRT_MAX ){
			t = 5;
	 }
	 else if ( GetAsyncKeyState ( VK_ESCAPE ) & SHRT_MAX ){
			t = 6;
	 }
	}

	return t;
}

void swap (int *a, int *b){ 
	int temp = *a; 
	*a = *b; 
	*b = temp; 
} 

void randomize (int array[], int p){ 
	int i,j;
	
	srand ( time(NULL) );
	for (i = p-1; i > 0; i--) 
	{ 
		j = rand() % (i+1);
		swap(&array[i], &array[j]); 
	} 
} 

int isSame (int current , int next ){
		if ( current == next )
			return 1;
		 else 
		  	return 0;
}

int score(int x){
	return(pnt+=x);
}

void drawMap(int array[][4]){
	system("cls");
	int row,column,i,j;
	
	for(row=0;row<10;row+=3){	
		i=0;
		for(column=0;column<4;column++){
        	if(selected[i][j]==1) {
				gotoxy(row,column);
				printf("[%c]",array[i][j]);} 
			else {
				gotoxy(row,column);
				printf("[@]");
            }
        j++;
        }
     i++;
    }

    gotoxy(0,5);
    printf("Done");
    gotoxy(0,6);
    printf("Your score=%d",pnt);
    gotoxy(0,8);
    printf("Select \'Done\' to quit.");
}

void read(int x, int y, int array[][4]){
	
	while(x<=4&&y==5){
		system("cls");
		gotoxy(7,7);
		printf("Game Over. Your score=%d.",pnt);
		delay(4);
		exit(0);
		}
	
	switch(x){
			case 1 : 
				if(selected[x-1][y]==1){
				 	selected[x-1][y]=0;
					gotoxy(0,7);
				 	printf("Try again");
				 	delay(0.6);
				 }			 
				else{
					 
					if (currentValue == 0){
						//first value
						prevX = x;
						prevY = y;
						currentValue = array[x-1][y];
						selected[x-1][y]=1;
					} else if( isSame(currentValue,array[x-1][y]) ==1 ){
						/// compare value
					 	selected[x-1][y]=1;
					 	currentValue = 0;
					 	score(2);
					 }	
					 else {
					 	gotoxy(0,7);
				 		printf("Wrong! You selected %c",array[x-1][y]);
				 		delay(0.6);
					 	selected[prevX-1][prevY] = 0;
					 	selected[x-1][y]=0;
					 	currentValue = 0;
					 	score(-1);
					 }
			}	 
				break;
			case 4 : 
				if(selected[x-3][y]==1){
					selected[x-3][y]=0;
					gotoxy(0,7);
				 	printf("Try again");
				 	delay(0.6);
				 }	
				 
				else{
					if (currentValue == 0 ){
							//first value
							prevX = x;
							prevY = y;
							currentValue = array[x-3][y];
							selected[x-3][y]=1;
						} else if( isSame(currentValue,array[x-3][y]) ==1 ) {
						 	selected[x-3][y]=1;
						 	currentValue = 0;
						 	score(2);
						 }else {
						 	gotoxy(0,7);
				 			printf("Wrong! You selected %c",array[x-3][y]);
				 			delay(0.6);
						 	selected[prevX-3][prevY] = 0;
						 	selected[x-3][y]=0;
						 	currentValue = 0;
						 	score(-1);
						 }
					}	 
				break;
			case 7 :
				if(selected[x-5][y]==1){
					selected[x-5][y]=0;
					gotoxy(0,7);
				 	printf("Try again");
				 	delay(0.6);
					 }	
			else{
				if (currentValue == 0 ){
						//first value
						prevX = x;
						prevY = y;
						currentValue = array[x-5][y];
						selected[x-5][y]=1;
					} else if( isSame(currentValue,array[x-5][y]) ==1 ) {
					 	selected[x-5][y]=1;
					 	currentValue = 0;
					 	score(2);
					 }else {
					 	gotoxy(0,7);
				 		printf("Wrong! You selected %c",array[x-5][y]);
				 		delay(0.6);
					 	selected[prevX-5][prevY] = 0;
					 	selected[x-5][y]=0;
					 	currentValue = 0;
					 	score(-1);
					 }
				}	 
				break;
			case 10 :
				if(selected[x-7][y]==1){
					selected[x-7][y]=0;
					gotoxy(0,7);
				 	printf("Try again");
				 	delay(0.6);
				 }	
				 
				else{
				if (currentValue == 0 ){
						//first value
						prevX = x;
						prevY = y;
						currentValue = array[x-7][y];
						selected[x-7][y]=1;
					} else if( isSame(currentValue,array[x-7][y]) ==1 ) {
					 	selected[x-7][y]=1;
					 	currentValue = 0;
					 	score(2);
					 }else {
					 	gotoxy(0,7);
				 		printf("Wrong! You seleceted %c",array[x-7][y]);
				 		delay(0.6);
					 	selected[prevX-7][prevY] = 0;
					 	selected[x-7][y]=0;
					 	currentValue = 0;
					 	score(-1);
					 }
				}	 
				break;
				default:;
			}
		
			drawMap(array);
			
}



int main(){
	system("cls");
	int h;
gotoxy(26,6);
printf(".------..------..------..------..------..------.");
gotoxy(26,7);
printf("|M.--. ||E.--. ||M.--. ||O.--. ||R.--. ||Y.--. |");
gotoxy(26,8);
printf("| (\\/) || (\\/) || (\\/) || :/\\: || :(): || (\\/) |");
gotoxy(26,9);
printf("| :\\/: || :\\/: || :\\/: || :\\/: || ()() || :\\/: |");
gotoxy(26,10);
printf("| '--'M|| '--'E|| '--'M|| '--'O|| '--'R|| '--'Y|");
gotoxy(26,11);
printf("`------'`------'`------'`------'`------'`------'");
gotoxy(26,12);
printf("\t  .------..------..------..------.");
gotoxy(26,13);
printf("\t  |G.--. ||A.--. ||M.--. ||E.--. |");
gotoxy(26,14);
printf("\t  | :/\\: || (\\/) || (\\/) || (\\/) |");
gotoxy(26,15);
printf("\t  | :\\/: || :\\/: || :\\/: || :\\/: |");
gotoxy(26,16);
printf("\t  | '--'G|| '--'A|| '--'M|| '--'E|");
gotoxy(26,17);
printf("\t  `------'`------'`------'`------'");
gotoxy(26,19);
printf("Loading<                                       >");
gotoxy(34,19);
for (h=0;h<=39;h++)
{
	if(h==39)
		printf("\a");
	else	
	printf("=");delay(0.01);
}
gotoxy(40,20);
printf("Loading completed.");
gotoxy(26,22);
printf("Enter any key to Start.....");
getch();
menu();
}

void help(){
	system("cls");
	int x;
gotoxy(27,5);
printf("                   _        ");
gotoxy(27,6);
printf("      /\\  /\\  ___ | | _ __  ");
gotoxy(27,7);
printf("     / /_/ / / _ \\| || '_ \\ ");
gotoxy(27,8);
printf("    / __  / |  __/| || |_) |");
gotoxy(27,9);
printf("    \\/ /_/   \\___||_|| .__/ ");
gotoxy(27,10);
printf("                     |_|    ");
gotoxy(27,11);
printf("===============================================");
gotoxy(27,12);
printf("Controls:");
gotoxy(27,13);
printf("Use arrow key to control the cursor.");
gotoxy(27,14);
printf("Use Left Ctrl Key to select your options.");
gotoxy(27,15);
printf("Enjoy!");
gotoxy(27,16);
printf("===============================================");
gotoxy(27,17);
printf("Press any key to return");
getch();
menu();
}

void menu(){
	int x;
	system("cls");
gotoxy(27,6);
printf("      /\\/\\    ___  _ __   _   _ ");
gotoxy(27,7);
printf("     /    \\  / _ \\| '_ \\ | | | |");
gotoxy(27,8);
printf("    / /\\/\\ \\|  __/| | | || |_| |");
gotoxy(27,9);
printf("    \\/    \\/ \\___||_| |_| \\__,_|");
gotoxy(27,10);
printf("======================================");
gotoxy(27,11);
printf("1.\tEasy");
gotoxy(27,12);
printf("2.\tMedium");
gotoxy(27,13);
printf("3.\tHard");
gotoxy(27,14);
printf("4.\tInsane");
gotoxy(27,15);
printf("5.\tHelp");
gotoxy(27,16);
printf("======================================");
gotoxy(27,17);
printf("Please enter your option:");
gotoxy(27,18);
	scanf("%d",&x);

switch(x){
	case 1:easy();
		break;
	case 2:medium();
		break;
	case 3:hard();
		break;
	case 4:insane();
		break;	
	case 5:help();
		break;		
	default:menu();
	}
	
}

void easy(){
	
	system("cls");
	int h,t,x,y,row,column,i,j,z;
	int Board[16]={65,65,66,66,67,67,68,68,69,69,70,70,71,71,72,72};
	int BoardA[4][4];
	int p = sizeof(Board)/ sizeof(Board[0]); 
	randomize (Board, p); 
		z=0;
for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            BoardA[i][j] = Board[z++];
        }
    }
    
gotoxy(26,10);
printf("Loading<                                       >");
gotoxy(34,10);
for (h=0;h<39;h++)
{
	printf("=");delay(0.01);
}
gotoxy(34,12);
printf("Enter any key to Start.....");
getch();
system("cls");
j=0;
for(row=0;row<10;row+=3)
{ 	i=0;
	for(column=0;column<4;column++)
	{
	gotoxy(row,column);
		printf("[%c]",BoardA[i][j]);
		 j++;
	}
	i++;
}
printf("\nPress any key when ready... ");
getch();

drawMap(BoardA);
    
	t = 0;
	t = control();
	gotoxy(0,0);
	x = 1;
	y = 1;
	getch();

	while(t != 6){
		t = control();
		switch(t){
		case 1: --y;gotoxy(x,y);
				if(y<0)
					y+=1;
				break;
		case 2: ++y;gotoxy(x,y);
				break;
		case 3: --x;gotoxy(x,y);
				if(x<0)
					x+=1;
				break;
		case 4: ++x;gotoxy(x,y);
				break;
		case 5: if(x>=0&&x<=10&&y>=0&&y<=3)
				read(x,y,BoardA);
				else if(x<=3&&y==5)
				read(x,y,BoardA);
				else;
				break;
		default:;		
			}
		}
	
	}
	
void medium(){
	
	system("cls");
	int h,t,x,y,row,column,i,j,z;

	int Board[16]={65,65,66,66,67,67,68,68,69,69,70,70,71,71,72,72};
	int BoardA[4][4];
	int p = sizeof(Board)/ sizeof(Board[0]); 
	randomize (Board, p); 
		z=0;
for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            BoardA[i][j] = Board[z++];
        }
    }

	
gotoxy(26,10);
printf("Loading<                                       >");
gotoxy(34,10);
for (h=0;h<39;h++)
{
	printf("=");delay(0.01);
}
gotoxy(34,12);
printf("Enter any key to Start.....");
getch();
system("cls");
j=0;
for(row=0;row<10;row+=3)
{ 	i=0;
	for(column=0;column<4;column++)
	{
	gotoxy(row,column);
		printf("[%c]",BoardA[i][j]);
		 j++;
	}
	i++;
}

for (h=10;h>=1;h--)
{
	gotoxy(3,5);
	printf("%2d",h);delay(1);
}


drawMap(BoardA);
    
  
	t = 0;
	t = control();
	gotoxy(0,0);
	x = 1;
	y = 1;
	getch();

	while(t != 6){
		t = control();
		switch(t){
		case 1: --y;gotoxy(x,y);
				if(y<0)
					y+=1;
				break;
		case 2: ++y;gotoxy(x,y);
				break;
		case 3: --x;gotoxy(x,y);
				if(x<0)
					x+=1;
				break;
		case 4: ++x;gotoxy(x,y);
				break;
		case 5: if(x>=0&&x<=10&&y>=0&&y<=3)
				read(x,y,BoardA);
				else if(x<=3&&y==5)
				read(x,y,BoardA);
				else;
				break;
		default:;
			}
		}
	

	}

void hard(){
	
	system("cls");
	int h,t,x,y,row,column,i,j,z;

	int Board[16]={65,65,66,66,67,67,68,68,69,69,70,70,71,71,72,72};
	int BoardA[4][4];
	int p = sizeof(Board)/ sizeof(Board[0]); 
	randomize (Board, p); 
		z=0;
for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            BoardA[i][j] = Board[z++];
        }
    }

	
gotoxy(26,10);
printf("Loading<                                       >");
gotoxy(34,10);
for (h=0;h<39;h++)
{
	printf("=");delay(0.01);
}
gotoxy(34,12);
printf("Enter any key to Start.....");
getch();
system("cls");
j=0;
for(row=0;row<10;row+=3)
{ 	i=0;
	for(column=0;column<4;column++)
	{
	gotoxy(row,column);
		printf("[%c]",BoardA[i][j]);
		 j++;
	}
	i++;
}

for (h=10;h>=1;h--)
{
	gotoxy(3,5);
	printf("%2d",h);delay(0.3);
}

drawMap(BoardA);
    
  
	t = 0;
	t = control();
	gotoxy(0,0);
	x = 1;
	y = 1;
	getch();

	while(t != 6){
		t = control();
		switch(t){
		case 1: --y;gotoxy(x,y);
				if(y<0)
					y+=1;
				break;
		case 2: ++y;gotoxy(x,y);
				break;
		case 3: --x;gotoxy(x,y);
				if(x<0)
					x+=1;
				break;
		case 4: ++x;gotoxy(x,y);
				break;
		case 5: if(x>=0&&x<=10&&y>=0&&y<=3)
				read(x,y,BoardA)
;				else if(x<=3&&y==5)
				read(x,y,BoardA);
				else;
				break;
		default:;
			}
		}
	

	}

void insane(){
	
	system("cls");
	int h,t,x,y,row,column,i,j,z;

	int Board[16]={65,65,66,66,67,67,68,68,69,69,70,70,71,71,72,72};
	int BoardA[4][4];
	int p = sizeof(Board)/ sizeof(Board[0]); 
	randomize (Board, p); 
		z=0;
for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            BoardA[i][j] = Board[z++];
        }
    }

	
gotoxy(26,10);
printf("Loading<                                       >");
gotoxy(34,10);
for (h=0;h<39;h++)
{
	printf("=");delay(0.01);
}
gotoxy(34,12);
printf("Enter any key to Start.....");
getch();
system("cls");
j=0;
for(row=0;row<10;row+=3)
{ 	i=0;
	for(column=0;column<4;column++)
	{
	gotoxy(row,column);
		printf("[%c]",BoardA[i][j]);
		 j++;
	}
	i++;
}
for (h=10;h>=1;h--)
{
	gotoxy(3,5);
	printf("%2d",h);delay(0.1);
}

drawMap(BoardA);
    
  
	t = 0;
	t = control();
	gotoxy(0,0);
	x = 1;
	y = 1;
	getch();

	while(t != 6){
		t = control();
		switch(t){
		case 1: --y;gotoxy(x,y);
				if(y<0)
					y+=1;
				break;
		case 2: ++y;gotoxy(x,y);
				break;
		case 3: --x;gotoxy(x,y);
				if(x<0)
					x+=1;
				break;
		case 4: ++x;gotoxy(x,y);
				break;
		case 5: if(x>=0&&x<=10&&y>=0&&y<=3)
				read(x,y,BoardA);
				else if(x<=3&&y==5)
				read(x,y,BoardA);
				else;
				break;
		default:;
			}
		}
	

	}



