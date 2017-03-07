#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

unsigned int maxpoint;
char name[30];

int main()
{

    unsigned int random,bigpt=0,plpt=0,cmpt=0,a;
    char choice;
    srand(time(NULL));
    init();
    printf("press any key to continue...");
    getch();
    printf("\r");
    printf("                            \r");
    while(bigpt<maxpoint)
    {
        random=rand()%3+1;
        printf("enter your choice : ");
        choice=getche();
        printf("\n\n");
        switch(choice)
        {
        case 'r':
        case 'R':
            if(random==1)
                printf("Computer chose rock.\nIt is a tie !!\t\tscore : you = %d, com = %d\n\n",plpt,cmpt);
            if(random==2)
            {
                printf("Computer chose paper.\nCom gained a point !!");
                cmpt++;
                printf("\t\tscore : you - %d, com - %d\n\n",plpt,cmpt);
            }
            if(random==3)
            {
                printf("Computer chose scissor.\nYou gained a point !!");
                plpt++;
                printf("\t\tscore : you - %d, com - %d\n\n",plpt,cmpt);
            }
            break;


        case 'p':
        case 'P':
            if(random==1)
            {
                printf("Computer chose rock.\nYou gained a point !!");
                plpt++;
                printf("\t\tscore : you - %d, com - %d\n\n",plpt,cmpt);
            }
            if(random==2)
                printf("Computer chose paper.\nIt is a tie !!\t\tscore : you = %d, com = %d\n\n",plpt,cmpt);
            if(random==3)
            {
                printf("Computer chose scissor.\nCom gained a point !!");
                cmpt++;
                printf("\t\tscore : you - %d, com - %d\n\n",plpt,cmpt);
            }
            break;


        case 's':
        case 'S':
            if(random==1)
            {
                printf("Computer chose rock.\nCom gained a point !!");
                cmpt++;
                printf("\t\tscore : you - %d, com - %d\n\n",plpt,cmpt);
            }
            if(random==2)
                {
                printf("Computer chose paper.\nYou gained a point !!");
                plpt++;
                printf("\t\tscore : you - %d, com - %d\n\n",plpt,cmpt);
                }
            if(random==3)
                printf("Computer chose scissor.\nIt is a tie !!\t\tscore : you = %d, com = %d\n\n",plpt,cmpt);
            break;

        default:
            printf("\n\nPlease, enter only r,R,p,P,s,S\n\n");
        }

            if(plpt!=cmpt)
            bigpt=(plpt>cmpt?plpt:cmpt);
            printf("\n");
    }

    for(a=0;a<80;a++)
            printf("=");
    printf("\n\n");

    if(plpt==maxpoint)
        printf("\t\t\t       %s WON !!!",name);
    if(cmpt==maxpoint)
        printf("\t\t\tSorry, %s ! COM WON",name);

    printf("\n\n");

    for(a=0;a<80;a++)
        printf("=");

        getch();
        printf("\n\n");

}


/*



    This is the initial function


*/


int init()
{

    int a;

    reinit:
    clrscr();
    printf("\t\tWelcome to the game of ROCK-PAPER-SCISSORS\n\n");
    printf("Firstly, enter your name : ");
    scanf("%s",name);
    printf("\nNow, enter the number to score in order to finish the game (the goal) : ");
    rescan:
    scanf("%d",&maxpoint);
    if(maxpoint<0)
       {
           clrscr();
           printf("\n\t   NEXT TIME, ENTER A NUMBER IF ASKED FOR SCORE !!! ERROR !!!\n\n");
           getch();
           exit(26);
       }
    if(maxpoint==0)
    {
        printf("\n\nPlease enter a non-zero positive goal point : ");
        goto rescan;
    }
    if(maxpoint>100)
    {
        printf("\n\n\t\t\tYou were expected to enter a number less than or equal to 100");
        maxpoint=NULL;
        goto reinit;
    }
    printf("\n\n\t\tSecondly, the rules of the game are as follows : ");
    printf("\n\n");

    /// The rules :

    for(a=0;a<80;a++)
        printf("=");
    printf("\n\n");

    printf("1) Each player gets 1 point on beating the other player.\n");
    printf("2) The first one to score %-3d points wins.\n",maxpoint);
    printf("3) The computer has not been programmed to always win.\n");
    printf("4) In case you doubt rule 3, then, to tell you, the computer selects BEFORE you.");
    printf("5) To be truthful, the computer always picks an option at random.\n");
    printf("6) To choose an option, just PRESS the first letter. For eg : r,R,p,P,s,S.\n");
    printf("7) Rock beats scissor, scissor beats paper, paper beats rock.\n\n");
    for(a=0;a<80;a++)
        printf("=");
    printf("\n");

    /// The rules end here-----

    return maxpoint;
}
