#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void printmatrix(int a[][4])
{
    int i,j;
    printf("\n\n");
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            if(a[i][j]!=0)
            printf(" %2d ",a[i][j]);
            else
            printf("    ");
        }   printf("\n");
    } printf("\n\n");
}

void comparearray(int a[][4],int b[][4])
{
    int i,j,count=0;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            if(b[i][j] == a[i][j])
            {
                count ++;
            }
        }
    }
        if(count == 16)
        {
            printf("\n\n\n*****************************************  You Win!!  *****************************************");
            exit(0);
        }
}

int main()
{
    int a[4][4]={10,5,3,6,2,4,7,11,13,1,8,12,9,14,0,15};
    int b[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};
    int i,j,moves=50,direction,k=3,l=2,temp;
    char pname[30],key;
    printf("\n\n\n\n*******************************************  NUMBER SHIFTING GAME  *******************************************");
    printf("\n\n\n\n\n\n\n");
    printf("You are given a 4*4 matrix with random values filled like: \n\n\n");
    printmatrix(a);
    printf("\n\n\n You have to convert this random matrix to matrix which looks like this: \n\n");
    printmatrix(b);

    printf("\n\nGame Rules:\n");
    printf("\t1. You can move only one step at a time with the arrow key.\n");
    printf("\t2. You can move numbers at an empty position only.\n");
    printf("\t3. For each valid move : your total number of moves will be decreased by 1.Total moves will be given 100.\n");
    printf("\n\nWinning Situation :\n");
    printf("\t1. Number in a 4*4 matrix should be in order from 1 to 15");
    printf("\n\nPress any key to start the game!! ");
    getch();
    system("cls");  
    printf("\n\nEnter the player name: ");
    fgets(pname,30,stdin);
    pname[strcspn(pname,"\n")] = '\0';
    printf("Good Luck %s\n",pname);    
    printmatrix(a);
    while(moves!=0)
    {
        
        key = getch();
        if(key == 75)
        {
            if(l>0){
            l--;
            temp = a[k][l];
            a[k][l] = 0;
            a[k][l+1] = temp;
            moves--;
            printf("\nRemaining moves: %d\n\n",moves);
            printmatrix(a);
            comparearray(a,b);
            }
        }
    
        else if(key == 72)
        {
            if(k>0){
            k--;
            temp = a[k][l];
            a[k][l] = 0;
            a[k+1][l] = temp;
            moves--;
            printf("\nRemaining moves: %d\n\n",moves);
            printmatrix(a);
            comparearray(a,b);
            }
        }

        else if(key==77)
        {
            if(l<3){
            l++;
            temp = a[k][l];
            a[k][l] = 0;
            a[k][l-1] = temp;
            moves--;
            printf("\nRemaining moves: %d\n\n",moves);
            printmatrix(a);
            comparearray(a,b);
            }
        }

        else if(key==80)
        {
            if(k<3){
            k++;
            temp = a[k][l];
            a[k][l] = 0;
            a[k-1][l] = temp;
            moves--;
            printf("\nRemaining moves: %d\n\n",moves);
            printmatrix(a);
            comparearray(a,b);
            }
        }
        
        if(moves == 0)
        printf("You Lose");
    }

}
     
