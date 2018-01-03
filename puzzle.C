#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int mat[3][3];
int a[9] = {-1, -1, -1, -1, -1, -1, -1, -1};
int posX;
int posY;

void initialize();
int pos_0();
void DISPLAY();
void swapUP();
void swapDOWN();
void swapLEFT();
void swapRIGHT();
void checkGOAL();
int getInvCount(int []);
int isSolvable();

int getInvCount(int arr[])
{
    int inv_count = 0,i,j;
    for (i = 0; i < (9-1); i++)
	for (j = i+1; j < 9; j++)
	     // Value 0 is used for empty space
	     if (arr[j] && arr[i] &&  arr[i] > arr[j])
		  inv_count++;
    return inv_count;
}

int isSolvable()
{
    // Count inversions in given 8 puzzle
    int invCount = getInvCount((int *)mat);
    // return true if inversion count is even.
    return (invCount%2);
}



void initialize() {
    int i = 0,j=0,k=0;
    int flag = 0;
    again:
    srand(time(NULL));
    for(i=0;i<9;i++)
	a[i] = -1;
    for (i = 0; i < 9; i++)
	{
	flag = 0;
	a[i] = rand() % 9;
		for (j = i - 1; j >= 0; j--)
		{
			if (a[j] == a[i])
				flag = 1;
		}
	if (flag == 1)
	    i -= 1;
    }
    k=0;
    for(i=0;i<3;i++)
    {
		for(j=0;j<3;j++)
		{
			mat[i][j] = a[k];
			k++;
		}
    }
    if(isSolvable()==0)
    {
	DISPLAY();
    }
    else
    {
	goto again;
    }
}

int pos_0(void)
{
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(mat[i][j] == 0)
			{
				posX=i;
				posY=j;
				return 0;
			}
		}
	}
	return 0;
}

void DISPLAY()
{
	int i,j;
	clrscr();
	printf("\n");
	for(i=0;i<3;i++)
	{
		printf("|   ||   ||   |\n");
		printf("---------------\n");
		printf("---------------\n");
		printf("|   ||   ||   |\n");
		for(j=0;j<3;j++)
		{
			if(mat[i][j] == 0)
			{
				printf("|   |");
			}
			else
			{
				printf("| %d |",mat[i][j]);
			}
		}
		printf("\n");
	}
	printf("|   ||   ||   |\n");
	printf("---------------\n");
	printf("---------------\n");
	printf("|   ||   ||   |\n");
	printf("\n\npress 0 to exit.");

}

void swapUP()
{
	pos_0();
	if( (posX+1) == (3) )
	{
		DISPLAY();
		gotoxy(30,20);
		printf("\nCannot shift DOWNwards");
		return;
	}
	else
	{
		mat[posX][posY]= mat[posX+1][posY];
		mat[posX+1][posY] = 0;
		DISPLAY();
		checkGOAL();
		return;
	}
}

void swapDOWN()
{
	pos_0();
	if( (posX-1) == (-1) )
	{
		DISPLAY();
		gotoxy(30,20);
		printf("\nCannot shift UPwards");
		return;
	}
	else
	{
		mat[posX][posY]= mat[posX-1][posY];
		mat[posX-1][posY] = 0;
		DISPLAY();
		checkGOAL();
		return;
	}
}

void swapRIGHT()
{
	pos_0();
	if( (posY+1) == (3) )
	{
		DISPLAY();
		gotoxy(30,20);
		printf("\nCannot shift RIGHTwards");
		return;
	}
	else
	{
		mat[posX][posY]= mat[posX][posY+1];
		mat[posX][posY+1] = 0;
		DISPLAY();
		checkGOAL();
		return;
	}
}

void swapLEFT()
{
	pos_0();
	if( (posY-1) == (-1) )
	{
		DISPLAY();
		gotoxy(30,20);
		printf("\nCannot shift LEFTwards");
		return;
	}
	else
	{
		mat[posX][posY]= mat[posX][posY-1];
		mat[posX][posY-1] = 0;
		DISPLAY();
		checkGOAL();
		return;
	}
}

void checkGOAL()
{
	if(mat[0][0]==1 && mat[0][1]==2 && mat[0][2]==3 && mat[1][0]==4 && mat[1][1]==5 && mat[1][2]==6 && mat[2][0]==7 && mat[2][1]==8 && mat[2][2]==0 )
	{
		clrscr();
		gotoxy(20,15);
		printf("Congratulations!, You have won the game.");
		gotoxy(20,16);
		printf("        Thanks for playing :)");
		printf("\n\nPress any key to continue...");
		getch();
		exit(0); 
		
	}
}

void main(void) {

    int key;
    clrscr();
    printf("\n");
	printf("\n                  -:HOW TO PLAY:-                  ");
	printf("\n            Just normal Game controls,             ");
	printf("\nuse W,A,S,D as direction key to move to empty block");
	printf("\n\n        W for moving the empty block UPwards     ");
	printf("\n        S for moving the empty block DOWNwards     ");
	printf("\n        A for moving the empty block LEFTwards     ");
	printf("\n        D for moving the empty block RIGHTwards    ");
	printf("\n                  Happy Playing!! :)               ");
	printf("\n             PRESS ANY KEY TO CONTINUE...");
	getch();
	fflush(stdin);
	initialize();
	while(1)
	{
		while(kbhit)
		{
			key = getch();
			break;
		}
		switch((int)key)
		{
			case 87:        //UP
			case 119: swapUP();
				break;
			case 83:        //DOWN
			case 115: swapDOWN();
				break;
			case 65:        //RIGHT
			case 97: swapRIGHT();
				break;
			case 68:        //left
			case 100: swapLEFT();
				break;
			case 48:  clrscr();
				  gotoxy(30,15);
				  printf("Thanks for playing :)");
				  printf("\n\nPress any key to continue...");
				  getch();
				  exit(0);     //EXIT
				break;
			default:  DISPLAY();
		}
	}
}