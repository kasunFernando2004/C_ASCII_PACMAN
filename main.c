#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

int thingamabob=1;//highscore, just need it to check if this is the first time the game is being played
void emptyCharArray(char arr[], int size)
{
    memset(arr, '\0', size);  // Set all elements to null bytes
}
int findIndexOfSmallest(float array[], int length)
{
    if (length <= 0) {
        // Handle the case of an empty array or invalid length
        printf("Invalid array length.\n");
        return -1;  // Return -1 to indicate an error
    }

    int indexOfSmallest = 0;

    for (int i = 1; i < length; ++i) {
        if (array[i] < array[indexOfSmallest] || (array[i] == array[indexOfSmallest] && i == 1)) {
            indexOfSmallest = i;
        }
    }

    return indexOfSmallest;
}

int gameWon=0;
int level=1;
char gameField[31][29][10];
char concatenatedString[31*29*10];
int score=0;
int lives=3;
int highestScore = 0;
int gameOver=0;
int CurrentXpos=14;
int CurrentYpos=23;
int  pelletEaten=0;
int FrightenFlag=0;
int FrightenTime=0;
int FrightenTimeFlag = 0;

int GameStartTime;
int TimeTime=0;
char GhostMode;

int RedKilledFlag=0;
int YellKilledFlag=0;
int PinkKilledFlag=0;
int CyanKilledFlag=0;

int RedKillKillFlag=0;
int PinkKillKillFlag=0;
int cyanKillKillFlag=0;
int YellKillKillFlag=0;

int CyanKilledTimer;
int PinkKilledTimer;
int YellKilledTimer;
int RedKilledTimer;

int RedCurXPos=26;
int RedCurYPos=1;
//float RedCurDirection[4]= {1,1,1,1};
int RedDirectionsNum=0;
int RedCurCurDirection=75;
int RedWasPellet=1;
int RedTarget[2];
int RedRandDirecX;
int RedRandDirecY;

int PinkCurXPos=1;
int PinkCurYPos=1;
//float PinkCurDirection[4]= {1,1,1,1};
int PinkDirectionsNum=0;
int PinkCurCurDirection=75;
int PinkWasPellet=1;
int PinkTarget[2];
int PinkRandDirecX;
int PinkRandDirecY;

int CyanCurXPos=26;
int CyanCurYPos=29;
//float CyanCurDirection[4]= {1,1,1,1};
int CyanDirectionsNum=0;
int CyanCurCurDirection=75;
int CyanWasPellet=1;
int CyanTarget[2];
int CyanRandDirecX;
int CyanRandDirecY;

int YellCurXPos=1;
int YellCurYPos=29;
//float YellCurDirection[4]= {1,1,1,1};
int YellDirectionsNum=0;
int YellCurCurDirection=75;
int YellWasPellet=1;
int YellowTarget[2];
int YellRandDirecX;
int YellRandDirecY;

int RedGhostSpeed=2;
int PinkGhostSpeed=2;
int CyanGhostSpeed=2;
int YellGhostSpeed=2;


int startTime;
int action;
int prevAction=72;
int keyHit=0;
int valMove=0;
char Continuee='y';
int ContinueeFlag=0;
int main()
{
    while (Continuee=='y')
    {
        gameWon = 0;
        gameField[31][29][10];
        concatenatedString[31*29*10];
        gameOver = 0;
        CurrentXpos = 14;
        CurrentYpos = 23;
        pelletEaten = 0;
        FrightenFlag = 0;
        FrightenTime = 0;
        FrightenTimeFlag = 0;

        GameStartTime;
        TimeTime = 0;
        GhostMode;

        RedKilledFlag = 0;
        YellKilledFlag = 0;
        PinkKilledFlag = 0;
        CyanKilledFlag = 0;

        RedKillKillFlag = 0;
        PinkKillKillFlag = 0;
        cyanKillKillFlag = 0;
        YellKillKillFlag = 0;

        CyanKilledTimer;
        PinkKilledTimer;
        YellKilledTimer;
        RedKilledTimer;

        RedCurXPos = 26;
        RedCurYPos = 1;
         float RedCurDirection[4] = {1, 1, 1, 1};
        RedDirectionsNum = 0;
        RedCurCurDirection = 75;
        RedWasPellet = 1;
        RedTarget[2];
        RedRandDirecX;
        RedRandDirecY;

        PinkCurXPos = 1;
        PinkCurYPos = 1;
        float PinkCurDirection[4] = {1, 1, 1, 1};
        PinkDirectionsNum = 0;
        PinkCurCurDirection = 75;
        PinkWasPellet = 1;
        PinkTarget[2];
        PinkRandDirecX;
        PinkRandDirecY;

        CyanCurXPos = 26;
        CyanCurYPos = 29;
        float CyanCurDirection[4] = {1, 1, 1, 1};
        CyanDirectionsNum = 0;
        CyanCurCurDirection = 75;
        CyanWasPellet = 1;
        CyanTarget[2];
        CyanRandDirecX;
        CyanRandDirecY;

        YellCurXPos = 1;
        YellCurYPos = 29;
        float YellCurDirection[4] = {1, 1, 1, 1};
        YellDirectionsNum = 0;
        YellCurCurDirection = 75;
        YellWasPellet = 1;
        YellowTarget[2];
        YellRandDirecX;
        YellRandDirecY;

        RedGhostSpeed = 2;
        PinkGhostSpeed = 2;
        CyanGhostSpeed = 2;
        YellGhostSpeed = 2;

        startTime;
        action;
        prevAction = 72;
        keyHit = 0;
        valMove = 0;

        if (ContinueeFlag==1)
        {
            ContinueeFlag=0;
            score=0;
            lives=3;
            level=1;
        }


        emptyCharArray(concatenatedString,sizeof(concatenatedString));
        //initialising game field
        for (int i=0;i<31;i++)
        {
            for (int j=0;j<29;j++)
            {
                if (j==28)
                {
                    strcpy(gameField[i][j],"\033[1;34m\n\033[0m"); //first bit of text makes color blue, next bit of text sets the color to default so it doesn't affect the next thing being printed
                }
                else if (j == 0 & (i>=0 & i<=9)||j == 27 & (i>=0 & i<=9))
                {
                    strcpy(gameField[i][j],"\033[1;34m#\033[0m");
                }
                else if ((i==9 & (j>=0 & j<=5))||(i==9 & (j>=27-5 & j<=27-0)))
                {
                    strcpy(gameField[i][j],"\033[1;34m#\033[0m");
                }
                else if ((j==5 & (i>=9 &  i<=13))||(j==27-5 & (i>=9 &  i<=13)))
                {
                    strcpy(gameField[i][j],"\033[1;34m#\033[0m");
                }
                else if ((i == 13 & (j>=0 & j<=5))||(i == 13 & (j>=27-5 & j<=27-0)))
                {
                    strcpy(gameField[i][j],"\033[1;34m#\033[0m");
                }
                else if ((i == 15 & (j>=0 & j<=5))||(i == 15 & (j>=27-5 & j<=27-0)))
                {
                    strcpy(gameField[i][j],"\033[1;34m#\033[0m");
                }
                else if (j == 5 & (i>=15 & i<=19)||j == 27-5 & (i>=15 & i<=19))
                {
                    strcpy(gameField[i][j],"\033[1;34m#\033[0m");
                }
                else if (i == 19 & (j>=0 & j<=5)||i == 19 & (j>=27-5 & j<=27-0))
                {
                    strcpy(gameField[i][j],"\033[1;34m#\033[0m");
                }
                else if (j==0 & (i>=19 &  i<=24)||j==27-0 & (i>=19 &  i<=24))
                {
                    strcpy(gameField[i][j],"\033[1;34m#\033[0m");
                }
                else if ((j<=2 & j>=0) & (i==24 || i==25)||(j<=27-0 & j>=27-2) & (i==24 || i==25))
                {
                    strcpy(gameField[i][j],"\033[1;34m#\033[0m");
                }
                else if (j==0 & (i>=25 &  i<=30)||j==27-0 & (i>=25 &  i<=30))
                {
                    strcpy(gameField[i][j],"\033[1;34m#\033[0m");
                }
                else if ((j>=2 & j<=5) & (i>=2 & i<=4)||((j>=27-5 & j<=27-2) & (i>=2 & i<=4)))
                {
                    strcpy(gameField[i][j],"\033[1;34m#\033[0m");
                }
                else if ((j>=7 & j<=11) & (i>=2 & i<=4)||((j>=27-11 & j<=27-7) & (i>=2 & i<=4)))
                {
                    strcpy(gameField[i][j],"\033[1;34m#\033[0m");
                }
                else if ((j>=2 & j<=5) & (i>=6 & i<=7)||((j>=27-5 & j<=27-2) & (i>=6 & i<=7)))
                {
                    strcpy(gameField[i][j],"\033[1;34m#\033[0m");
                }
                else if ((j>=7 & j<=8) & (i>=6 & i<=13)||((j>=27-8 & j<=27-7) & (i>=6 & i<=13)))
                {
                    strcpy(gameField[i][j],"\033[1;34m#\033[0m");
                }
                else if ((j>=7 & j<=11) & (i>=9 & i<=10)||((j>=27-11 & j<=27-7) & (i>=9 & i<=10)))
                {
                    strcpy(gameField[i][j],"\033[1;34m#\033[0m");
                }
                else if ((j>=7 & j<=8) & (i>=15 & i<=19)||((j>=27-8 & j<=27-7) & (i>=15 & i<=19)))
                {
                    strcpy(gameField[i][j],"\033[1;34m#\033[0m");
                }
                else if ((j>=7 & j<=11) & (i>=21 & i<=22)||((j>=27-11 & j<=27-7) & (i>=21 & i<=22)))
                {
                    strcpy(gameField[i][j],"\033[1;34m#\033[0m");
                }
                else if ((j>=2 & j<=5) & (i>=21 & i<=22)||((j>=27-5 & j<=27-2) & (i>=21 & i<=22)))
                {
                    strcpy(gameField[i][j],"\033[1;34m#\033[0m");
                }
                else if ((j>=4 & j<=5) & (i>=21 & i<=25)||((j>=27-5 & j<=27-4) & (i>=21 & i<=25)))
                {
                    strcpy(gameField[i][j],"\033[1;34m#\033[0m");
                }
                else if ((j>=2 & j<=11) & (i>=27 & i<=28)||((j>=27-11 & j<=27-2) & (i>=27 & i<=28)))
                {
                    strcpy(gameField[i][j],"\033[1;34m#\033[0m");
                }
                else if ((j>=7 & j<=8) & (i>=24 & i<=28)||((j>=27-8 & j<=27-7) & (i>=24 & i<=28)))
                {
                    strcpy(gameField[i][j],"\033[1;34m#\033[0m");
                }
                else if ((j==13) & (i>=24 & i<=28)||((j==27-13) & (i>=24 & i<=28)))
                {
                    strcpy(gameField[i][j],"\033[1;34m#\033[0m");
                }
                else if ((j>=10 & j<=13) & (i>=24 & i<=25)||((j>=27-13 & j<=27-10) & (i>=24 & i<=25)))
                {
                    strcpy(gameField[i][j],"\033[1;34m#\033[0m");
                }
                else if ((j==13) & (i>=18 & i<=22)||((j==27-13) & (i>=18 & i<=22)))
                {
                    strcpy(gameField[i][j],"\033[1;34m#\033[0m");
                }
                else if ((j>=10  & j<=13) & (i>=18 & i<=19)||((j>=27-13  & j<=27-10) & (i>=18 & i<=19)))
                {
                    strcpy(gameField[i][j],"\033[1;34m#\033[0m");
                }
                else if ((j>=10  & j<=17) & (i>=6 & i<=7))
                {
                    strcpy(gameField[i][j],"\033[1;34m#\033[0m");
                }
                else if ((j>=13  & j<=14) & (i>=6 & i<=10))
                {
                    strcpy(gameField[i][j],"\033[1;34m#\033[0m");
                }
                else if ((j>=10  & j<=17) & (i==12 || i==16))
                {
                    strcpy(gameField[i][j],"\033[1;34mO\033[0m");
                }
                else if (((j==10 || j==17) & (i>=12 & i<=16)))
                {
                    strcpy(gameField[i][j],"\033[1;34mO\033[0m");
                }
                else if (i == 0)
                {
                    strcpy(gameField[i][j],"\033[1;34m#\033[0m");
                }
                else if (i == 30)
                {
                    strcpy(gameField[i][j],"\033[1;34m#\033[0m");
                }
                else if ((j == 13 ||j==14) & (0<=i & i<=4))
                {
                    strcpy(gameField[i][j],"\033[1;34m#\033[0m");
                }
                else if (i==30 & j==28)
                {
                    strcpy(gameField[i][j],"\0");
                }
                else
                {
                    strcpy(gameField[i][j],"\033[1;37m.\033[0m");
                }
                strcat(concatenatedString,gameField[i][j]);
            }
        }
        for (int j=0;j<=4;j++)
        {
            for (int i=10;i<=12;i++)
            {
                concatenatedString[(i*29+j)*12+7]=' ';
                concatenatedString[(i*29+(27-j))*12+7]=' ';
                concatenatedString[((28-i)*29+j)*12+7]=' ';
                concatenatedString[((28-i)*29+(27-j))*12+7]=' ';
            }
        }
        for (int j=11;j<=16;j++)
        {
            for (int i=13;i<=15;i++)
            {
                concatenatedString[(i*29+j)*12+7]=' ';
            }
        }
        for (int i=12;i<=15;i++)
        {
            concatenatedString[(12*29+i)*12+5]='5';
        }
        concatenatedString[(CurrentYpos*29+CurrentXpos)*12+5]='3';
        concatenatedString[(CurrentYpos*29+CurrentXpos)*12+7]='@';
        concatenatedString[(RedCurYPos*29+RedCurXPos)*12+5]='1';
        concatenatedString[(RedCurYPos*29+RedCurXPos)*12+7]='A';

        concatenatedString[(PinkCurYPos*29+PinkCurXPos)*12+5]='5';
        concatenatedString[(PinkCurYPos*29+PinkCurXPos)*12+7]='A';

        concatenatedString[(CyanCurYPos*29+CyanCurXPos)*12+5]='6';
        concatenatedString[(CyanCurYPos*29+CyanCurXPos)*12+7]='A';

        concatenatedString[(YellCurYPos*29+YellCurXPos)*12+5]='3';
        concatenatedString[(YellCurYPos*29+YellCurXPos)*12+7]='A';

        concatenatedString[(3*29+1)*12+7]='*';
        concatenatedString[(3*29+26)*12+7]='*';
        concatenatedString[(23*29+26)*12+7]='*';
        concatenatedString[(23*29+1)*12+7]='*';

        system("cls");
        printf("level:%d\n",level);
        printf("score:%d lives:%d highscore:%d\n",score,lives,highestScore);
        printf("pellet consumed:%d\n",pelletEaten);
        printf("Game state:%d\n",gameWon);
        printf("%s",concatenatedString);
        Sleep(2000);
        //game loop
        int pucFrame=0;
        int ScatterFlag=1;
        int ChaseFlag=0;
        GameStartTime=clock();
        GhostMode='S';
        while (gameOver==0 && gameWon==0)
        {
            if (ScatterFlag==1 && TimeTime==7)
            {
                ScatterFlag=0;
                ChaseFlag=1;
                GameStartTime=clock();
                GhostMode='C';
            }
            if (ChaseFlag==1 && TimeTime==20)
            {
                ScatterFlag=1;
                ChaseFlag=0;
                GameStartTime=clock();
                GhostMode='S';
            }

            if (FrightenFlag==1)
            {
                if (FrightenTimeFlag==0)
                {
                    FrightenTime=clock();
                    FrightenTimeFlag=1;

                    RedGhostSpeed=8;
                    PinkGhostSpeed=8;
                    CyanGhostSpeed=8;
                    YellGhostSpeed=8;
                }
                if((clock()-FrightenTime)/CLOCKS_PER_SEC<=8)
                {
                    GhostMode='F';
                }
                else
                {
                    FrightenFlag=0;
                    FrightenTimeFlag=0;
                    RedGhostSpeed=2;
                    PinkGhostSpeed=2;
                    CyanGhostSpeed=2;
                    YellGhostSpeed=2;
                    if (ChaseFlag==1)
                    {
                        GhostMode='C';
                    }
                    else if (ScatterFlag==1)
                    {
                        GhostMode='S';
                    }
                }
            }
            if (CyanKilledFlag==1)
            {
                if ((clock()-CyanKilledTimer)/CLOCKS_PER_SEC<=7)
                {
                    CyanGhostSpeed=1;
                }
                else
                {
                    CyanGhostSpeed=2;
                    CyanKilledFlag=0;
                    cyanKillKillFlag=1;
                }
            }
            if (PinkKilledFlag==1)
            {
                if ((clock()-PinkKilledTimer)/CLOCKS_PER_SEC<=7)
                {
                    PinkGhostSpeed=1;
                }
                else
                {
                    PinkGhostSpeed=2;
                    PinkKilledFlag=0;
                    PinkKillKillFlag=1;
                }
            }
            if (YellKilledFlag==1)
            {
                if ((clock()-YellKilledTimer)/CLOCKS_PER_SEC<=7)
                {
                    YellGhostSpeed=1;
                }
                else
                {
                    YellGhostSpeed=2;
                    YellKilledFlag=0;
                    YellKillKillFlag=1;
                }
            }
            if (RedKilledFlag==1)
            {
                if ((clock()-RedKilledTimer)/CLOCKS_PER_SEC<=7)
                {
                    RedGhostSpeed=1;
                }
                else
                {
                    RedGhostSpeed=2;
                    RedKilledFlag=0;
                    RedKillKillFlag=1;
                }
            }
            pucFrame++;
            startTime=clock();
            while((clock()-startTime)<1)
            {
                valMove=0;
                keyHit=0;
                if (kbhit())
                {
                    action=_getch();
                    if (action==224)
                    {
                        action  = _getch();
                        if (action==75)
                        {
                            if (!(concatenatedString[(CurrentYpos*29+CurrentXpos-1)*12+7]=='#'||concatenatedString[(CurrentYpos*29+CurrentXpos-1)*12+7]=='O'))
                            {
                                valMove=1;
                            }
                            prevAction=75;
                        }
                        if (action==77)
                        {
                            prevAction=77;
                            if (!(concatenatedString[(CurrentYpos*29+CurrentXpos+1)*12+7]=='#'||concatenatedString[(CurrentYpos*29+CurrentXpos+1)*12+7]=='O'))
                            {
                                valMove=1;
                            }
                        }
                        if (action==80)
                        {
                            prevAction=80;
                            if (!(concatenatedString[((CurrentYpos+1)*29+CurrentXpos)*12+7]=='#'||concatenatedString[((CurrentYpos+1)*29+CurrentXpos)*12+7]=='O'))
                            {
                                valMove=1;
                            }
                        }
                        if (action==72)
                        {
                            prevAction=72;
                            if (!(concatenatedString[((CurrentYpos-1)*29+CurrentXpos)*12+7]=='#'||concatenatedString[((CurrentYpos-1)*29+CurrentXpos)*12+7]=='O'))
                            {
                                valMove=1;
                            }
                        }
                    }
                    keyHit=1;
                }
            }
            if (keyHit==0)
            {
                if (prevAction==75)
                {
                    if (!(concatenatedString[(CurrentYpos*29+CurrentXpos-1)*12+7]=='#'||concatenatedString[(CurrentYpos*29+CurrentXpos-1)*12+7]=='O'))
                    {
                        valMove=1;
                    }
                    prevAction=75;
                }
                if (prevAction==77)
                {
                    prevAction=77;
                    if (!(concatenatedString[(CurrentYpos*29+CurrentXpos+1)*12+7]=='#'||concatenatedString[(CurrentYpos*29+CurrentXpos+1)*12+7]=='O'))
                    {
                        valMove=1;
                    }
                }
                if (prevAction==80)
                {
                    prevAction=80;
                    if (!(concatenatedString[((CurrentYpos+1)*29+CurrentXpos)*12+7]=='#'||concatenatedString[((CurrentYpos+1)*29+CurrentXpos)*12+7]=='O'))
                    {
                        valMove=1;
                    }
                }
                if (prevAction==72)
                {
                    prevAction=72;
                    if (!(concatenatedString[((CurrentYpos-1)*29+CurrentXpos)*12+7]=='#'||concatenatedString[((CurrentYpos-1)*29+CurrentXpos)*12+7]=='O'))
                    {
                        valMove=1;
                    }
                }
            }
            //handling if pacman goes through the tunnels to get to the otherside of the screen
            //code for how the ghosts move in chase mode/scatter mode when they haven't hit a junction
            if ((pucFrame)%RedGhostSpeed==0)
            {
                RedDirectionsNum=0;
                for (int i=0;i<4;i++)
                {
                    RedCurDirection[i]=1;
                }

                switch (RedWasPellet)
                {
                    case 1:
                        concatenatedString[(RedCurYPos*29+RedCurXPos)*12+5] = '7';
                        concatenatedString[(RedCurYPos*29+RedCurXPos)*12+7] = '.';
                        break;
                    case 0:
                        concatenatedString[(RedCurYPos*29+RedCurXPos)*12+7] = ' ';
                        break;
                    case 2:
                        concatenatedString[(RedCurYPos*29+RedCurXPos)*12+5] = '7';
                        concatenatedString[(RedCurYPos*29+RedCurXPos)*12+7] = '*';
                        break;
                    case 3:
                        concatenatedString[(RedCurYPos*29+RedCurXPos)*12+5] = '5';
                        concatenatedString[(RedCurYPos*29+RedCurXPos)*12+7] = 'O';
                        break;
                }


                switch (RedCurCurDirection)
                {
                case 75:
                    if (concatenatedString[(RedCurYPos*29+RedCurXPos-1)*12+7]=='.'||concatenatedString[(RedCurYPos*29+RedCurXPos-1)*12+7]=='\n')
                    {
                        RedWasPellet=1;
                        RedCurXPos-=1;
                    }
                    else if (concatenatedString[(RedCurYPos*29+RedCurXPos-1)*12+7]==' '||concatenatedString[(RedCurYPos*29+RedCurXPos-1)*12+7]=='A')
                    {
                        RedWasPellet=0;
                        RedCurXPos-=1;
                    }
                    else if (concatenatedString[(RedCurYPos*29+RedCurXPos-1)*12+7]=='*')
                    {
                        RedWasPellet=2;
                        RedCurXPos-=1;
                    }
                    else if (concatenatedString[(RedCurYPos*29+RedCurXPos-1)*12+7]=='O' && concatenatedString[(RedCurYPos*29+RedCurXPos-1)*12+5]=='5')
                    {
                        RedWasPellet=3;
                        RedCurXPos-=1;
                    }
                    else if (concatenatedString[(RedCurYPos*29+RedCurXPos-1)*12+7]=='@')
                    {
                        RedWasPellet=0;
                        RedCurXPos-=1;
                        if (FrightenFlag==0)
                        {
                            gameOver=1;
                        }
                        else
                        {
                            gameOver=0;
                        }
                    }
                    break;
                case 77:
                    if (concatenatedString[(RedCurYPos*29+RedCurXPos+1)*12+7]=='.'||concatenatedString[(RedCurYPos*29+RedCurXPos+1)*12+7]=='\n')
                    {
                        RedWasPellet=1;
                        RedCurXPos+=1;
                    }
                    else if (concatenatedString[(RedCurYPos*29+RedCurXPos+1)*12+7]==' '||concatenatedString[(RedCurYPos*29+RedCurXPos+1)*12+7]=='A')
                    {
                        RedWasPellet=0;
                        RedCurXPos+=1;
                    }
                    else if (concatenatedString[(RedCurYPos*29+RedCurXPos+1)*12+7]=='*')
                    {
                        RedWasPellet=2;
                        RedCurXPos+=1;
                    }
                    else if (concatenatedString[(RedCurYPos*29+RedCurXPos+1)*12+7]=='O' && concatenatedString[(RedCurYPos*29+RedCurXPos-1)*12+5]=='5')
                    {
                        RedWasPellet=3;
                        RedCurXPos+=1;
                    }
                    else if (concatenatedString[(RedCurYPos*29+RedCurXPos+1)*12+7]=='@')
                    {
                        RedWasPellet=0;
                        RedCurXPos+=1;
                        if (FrightenFlag==0)
                        {
                            gameOver=1;
                        }
                        else
                        {
                            gameOver=0;
                        }
                    }
                    break;
                case 80:
                    if (concatenatedString[((RedCurYPos+1)*29+RedCurXPos)*12+7]=='.')
                    {
                        RedWasPellet=1;
                        RedCurYPos+=1;
                    }
                    else if (concatenatedString[((RedCurYPos+1)*29+RedCurXPos)*12+7]==' '||concatenatedString[((RedCurYPos+1)*29+RedCurXPos)*12+7]=='A')
                    {
                        RedWasPellet=0;
                        RedCurYPos+=1;
                    }
                    else if (concatenatedString[((RedCurYPos+1)*29+RedCurXPos)*12+7]=='*')
                    {
                        RedWasPellet=2;
                        RedCurYPos+=1;
                    }
                    else if (concatenatedString[((RedCurYPos+1)*29+RedCurXPos)*12+7]=='O' && concatenatedString[((RedCurYPos+1)*29+RedCurXPos)*12+5]=='5'&&RedKilledFlag==1)
                    {
                        RedWasPellet=3;
                        RedCurYPos+=1;
                    }
                    else if (concatenatedString[((RedCurYPos+1)*29+RedCurXPos)*12+7]=='@')
                    {
                        RedWasPellet=0;
                        RedCurYPos+=1;
                        if (FrightenFlag==0)
                        {
                            gameOver=1;
                        }
                        else
                        {
                            gameOver=0;
                        }
                    }
                    break;
                case 72:
                    if (concatenatedString[((RedCurYPos-1)*29+RedCurXPos)*12+7]=='.')
                    {
                        RedWasPellet=1;
                        RedCurYPos-=1;
                    }
                    else if (concatenatedString[((RedCurYPos-1)*29+RedCurXPos)*12+7]==' '||concatenatedString[((RedCurYPos-1)*29+RedCurXPos)*12+7]=='A')
                    {
                        RedWasPellet=0;
                        RedCurYPos-=1;
                    }
                    else if (concatenatedString[((RedCurYPos-1)*29+RedCurXPos)*12+7]=='*')
                    {
                        RedWasPellet=2;
                        RedCurYPos-=1;
                    }
                    else if (concatenatedString[((RedCurYPos-1)*29+RedCurXPos)*12+7]=='O' && concatenatedString[((RedCurYPos-1)*29+RedCurXPos)*12+5]=='5')
                    {
                        RedWasPellet=3;
                        RedCurYPos-=1;
                    }
                    else if (concatenatedString[((RedCurYPos-1)*29+RedCurXPos)*12+7]=='@')
                    {
                        RedWasPellet=0;
                        RedCurYPos-=1;
                        if (FrightenFlag==0)
                        {
                            gameOver=1;
                        }
                        else
                        {
                            gameOver=0;
                        }
                    }
                    break;
                }
                if (RedCurXPos==-1)
                {
                    RedCurXPos=27;
                    if (concatenatedString[(14*29+27)*12+7]=='.')
                    {
                        RedWasPellet=1;
                    }
                    else if (concatenatedString[(14*29+27)*12+7]==' ')
                    {
                        RedWasPellet=0;
                    }
                }
                else if (RedCurXPos==28)
                {
                    RedCurXPos=0;
                    if (concatenatedString[(14*29+0)*12+7]=='.')
                    {
                        RedWasPellet=1;
                    }
                    else if (concatenatedString[(14*29+0)*12+7]==' ')
                    {
                        RedWasPellet=0;
                    }
                }
                //checking the  presence of walls around the ghost at its new tile
                if (concatenatedString[((RedCurYPos)*29+RedCurXPos-1)*12+7]=='#'||(concatenatedString[((RedCurYPos)*29+RedCurXPos-1)*12+7]=='O'&&(concatenatedString[((RedCurYPos)*29+RedCurXPos-1)*12+5]=='4'||(concatenatedString[((RedCurYPos)*29+RedCurXPos-1)*12+5]=='5'&& RedKilledFlag==0))))//checking left
                {
                    RedDirectionsNum+=1;
                    RedCurDirection[0]=10000;
                }
                if (concatenatedString[((RedCurYPos-1)*29+RedCurXPos)*12+7]=='#'||(concatenatedString[((RedCurYPos-1)*29+RedCurXPos)*12+7]=='O'&&(concatenatedString[((RedCurYPos-1)*29+RedCurXPos)*12+5]=='4'||(concatenatedString[((RedCurYPos-1)*29+RedCurXPos)*12+5]=='5'&&RedKilledFlag==0)))) //checking Up
                {
                    RedDirectionsNum+=1;
                    RedCurDirection[1]=10000;
                }
                if (concatenatedString[((RedCurYPos)*29+RedCurXPos+1)*12+7]=='#'||(concatenatedString[((RedCurYPos)*29+RedCurXPos+1)*12+7]=='O'&&(concatenatedString[((RedCurYPos)*29+RedCurXPos+1)*12+5]=='4'||(concatenatedString[((RedCurYPos)*29+RedCurXPos+1)*12+5]=='5'&&RedKilledFlag==0)))) //checking Right
                {
                    RedDirectionsNum+=1;
                    RedCurDirection[2]=10000;
                }
                if (concatenatedString[((RedCurYPos+1)*29+RedCurXPos)*12+7]=='#'||(concatenatedString[((RedCurYPos+1)*29+RedCurXPos)*12+7]=='O'&&(concatenatedString[((RedCurYPos+1)*29+RedCurXPos)*12+5]=='4'||(concatenatedString[((RedCurYPos+1)*29+RedCurXPos)*12+5]=='5'&&RedKilledFlag==0)))) //checking Down
                {
                    RedDirectionsNum+=1;
                    RedCurDirection[3]= 10000;
                }

                //checking if ghost hits a corner
                if (!(RedCurDirection[1]==10000 && RedCurDirection[3]==10000) && !(RedCurDirection[0]==10000 && RedCurDirection[2]==10000))
                {
                    if (RedCurDirection[0]==10000 &&  RedCurDirection[3]==10000) //bottom left corner
                    {
                        if (RedCurCurDirection==75)
                        {
                            RedCurCurDirection=72;
                        }
                        else if (RedCurCurDirection==80)
                        {
                            RedCurCurDirection=77;
                        }
                    }
                    else if (RedCurDirection[0]==10000 &&  RedCurDirection[1]==10000)  //top left corner
                    {
                        if (RedCurCurDirection==72)
                        {
                            RedCurCurDirection=77;
                        }
                        else if (RedCurCurDirection==75)
                        {
                            RedCurCurDirection=80;
                        }
                    }
                    else if (RedCurDirection[1]==10000 &&  RedCurDirection[2]==10000)//top  right corner
                    {
                        if (RedCurCurDirection==77)
                        {
                            RedCurCurDirection=80;
                        }
                        else if (RedCurCurDirection==72)
                        {
                            RedCurCurDirection=75;
                        }
                    }
                    else if (RedCurDirection[2]==10000 &&  RedCurDirection[3]==10000)//bottom right  corner
                    {
                        if (RedCurCurDirection==80)
                        {
                            RedCurCurDirection=75;
                        }
                        else if (RedCurCurDirection==77)
                        {
                            RedCurCurDirection=72;
                        }

                    }
                }
                //code for the choice  the ghost makes if  it hits  a tri/quad intersection
                if (RedDirectionsNum<2)
                {
                    //making it so that the ghost can't turn around and go the direction it came from
                    switch (RedCurCurDirection)
                    {
                    case 75:
                        RedCurDirection[2]=10000;
                        break;
                    case 72:
                        RedCurDirection[3]=10000;
                        break;
                    case 77:
                        RedCurDirection[0]=10000;
                        break;
                    case  80:
                        RedCurDirection[1]=10000;
                        break;
                    }

                    if (GhostMode=='S')
                    {
                        RedTarget[0]= 26;
                        RedTarget[1]= 1;
                    }
                    else if (GhostMode=='C')
                    {
                        RedTarget[0] = CurrentXpos;
                        RedTarget[1] = CurrentYpos;
                    }
                    else if (GhostMode=='F')
                    {
                        srand((unsigned int)time(NULL));

                        RedTarget[0] =  rand()%26;
                        RedTarget[1] = rand()%29;
                    }


                    if (RedKilledFlag==1)
                    {
                        RedTarget[0] = 15;
                        RedTarget[1] = 14;
                    }
                    for  (int i=0;i<4;i++)
                    {
                        if (RedCurDirection[i]!=10000)
                        {
                            switch (i)
                            {
                                case 0:
                                    RedCurDirection[0] = (RedCurXPos - 1 - RedTarget[0]) * (RedCurXPos - 1 - RedTarget[0]) + (RedCurYPos - RedTarget[1]) * (RedCurYPos - RedTarget[1]);
                                    break;
                                case 1:
                                    RedCurDirection[1] = (RedCurXPos - RedTarget[0]) * (RedCurXPos - RedTarget[0]) + (RedCurYPos - 1 - RedTarget[1]) * (RedCurYPos - 1 - RedTarget[1]);
                                    break;
                                case 2:
                                    RedCurDirection[2] = (RedCurXPos + 1 - RedTarget[0]) * (RedCurXPos + 1 - RedTarget[0]) + (RedCurYPos - RedTarget[1]) * (RedCurYPos - RedTarget[1]);
                                    break;
                                case 3:
                                    RedCurDirection[3] = (RedCurXPos - RedTarget[0]) * (RedCurXPos - RedTarget[0]) + (RedCurYPos + 1 - RedTarget[1]) * (RedCurYPos + 1 - RedTarget[1]);
                                    break;
                            }

                        }
                    }
                    switch(findIndexOfSmallest(RedCurDirection,4))
                    {
                    case 0:
                        RedCurCurDirection=75;
                        break;
                    case 1:
                        RedCurCurDirection=72;
                        break;
                    case 2:
                        RedCurCurDirection=77;
                        break;
                    case 3:
                        RedCurCurDirection=80;
                        break;
                    }
                    if (RedKilledFlag==0 && (clock()-RedKilledTimer)/CLOCKS_PER_SEC==8 && RedKillKillFlag==1)
                    {
                        if (concatenatedString[(11*29+14)*12+7]=='.')
                        {
                            RedWasPellet=1;
                        }
                        else if (concatenatedString[(11*29+14)*12+7]==' ')
                        {
                            RedWasPellet=0;
                        }
                        RedCurXPos=14;
                        RedCurYPos=11;
                        RedCurCurDirection=75;
                        RedKillKillFlag=0;
                    }
                }
            }


            if (pucFrame%PinkGhostSpeed==0)
            {
                PinkDirectionsNum=0;
                for (int i=0;i<4;i++)
                {
                    PinkCurDirection[i]=1;
                }

                switch (PinkWasPellet)
                {
                    case 1:
                        concatenatedString[(PinkCurYPos * 29 + PinkCurXPos) * 12 + 5] = '7';
                        concatenatedString[(PinkCurYPos * 29 + PinkCurXPos) * 12 + 7] = '.';
                        break;
                    case 0:
                        concatenatedString[(PinkCurYPos * 29 + PinkCurXPos) * 12 + 7] = ' ';
                        break;
                    case 2:
                        concatenatedString[(PinkCurYPos * 29 + PinkCurXPos) * 12 + 5] = '7';
                        concatenatedString[(PinkCurYPos * 29 + PinkCurXPos) * 12 + 7] = '*';
                        break;
                    case 3:
                        concatenatedString[(PinkCurYPos * 29 + PinkCurXPos) * 12 + 5] = '5';
                        concatenatedString[(PinkCurYPos * 29 + PinkCurXPos) * 12 + 7] = 'O';
                        break;
                }

                switch (PinkCurCurDirection)
                {
                case 75:
                    if (concatenatedString[(PinkCurYPos * 29 + PinkCurXPos - 1) * 12 + 7] == '.' || concatenatedString[(PinkCurYPos * 29 + PinkCurXPos - 1) * 12 + 7] == '\n')
                    {
                        PinkWasPellet = 1;
                        PinkCurXPos -= 1;
                    }
                    else if (concatenatedString[(PinkCurYPos * 29 + PinkCurXPos - 1) * 12 + 7] == ' ' || concatenatedString[(PinkCurYPos * 29 + PinkCurXPos - 1) * 12 + 7] == 'A')
                    {
                        PinkWasPellet = 0;
                        PinkCurXPos -= 1;
                    }
                    else if (concatenatedString[(PinkCurYPos * 29 + PinkCurXPos - 1) * 12 + 7] == '*')
                    {
                        PinkWasPellet = 2;
                        PinkCurXPos -= 1;
                    }
                    else if (concatenatedString[(PinkCurYPos * 29 + PinkCurXPos - 1) * 12 + 7] == 'O' && concatenatedString[(PinkCurYPos * 29 + PinkCurXPos - 1) * 12 + 5] == '5')
                    {
                        PinkWasPellet = 3;
                        PinkCurXPos -= 1;
                    }
                    else if (concatenatedString[(PinkCurYPos * 29 + PinkCurXPos - 1) * 12 + 7] == '@')
                    {
                        PinkWasPellet = 0;
                        PinkCurXPos -= 1;
                        if (FrightenFlag == 0)
                        {
                            gameOver = 1;
                        }
                        else
                        {
                            gameOver = 0;
                        }
                    }
                    break;
                case 77:
                    if (concatenatedString[(PinkCurYPos * 29 + PinkCurXPos + 1) * 12 + 7] == '.' || concatenatedString[(PinkCurYPos * 29 + PinkCurXPos + 1) * 12 + 7] == '\n')
                    {
                        PinkWasPellet = 1;
                        PinkCurXPos += 1;
                    }
                    else if (concatenatedString[(PinkCurYPos * 29 + PinkCurXPos + 1) * 12 + 7] == ' ' || concatenatedString[(PinkCurYPos * 29 + PinkCurXPos + 1) * 12 + 7] == 'A')
                    {
                        PinkWasPellet = 0;
                        PinkCurXPos += 1;
                    }
                    else if (concatenatedString[(PinkCurYPos * 29 + PinkCurXPos + 1) * 12 + 7] == '*')
                    {
                        PinkWasPellet = 2;
                        PinkCurXPos += 1;
                    }
                    else if (concatenatedString[(PinkCurYPos * 29 + PinkCurXPos + 1) * 12 + 7] == 'O' && concatenatedString[(PinkCurYPos * 29 + PinkCurXPos - 1) * 12 + 5] == '5')
                    {
                        PinkWasPellet = 3;
                        PinkCurXPos += 1;
                    }
                    else if (concatenatedString[(PinkCurYPos * 29 + PinkCurXPos + 1) * 12 + 7] == '@')
                    {
                        PinkWasPellet = 0;
                        PinkCurXPos += 1;
                        if (FrightenFlag == 0)
                        {
                            gameOver = 1;
                        }
                        else
                        {
                            gameOver = 0;
                        }
                    }
                    break;
                case 80:
                    if (concatenatedString[((PinkCurYPos + 1) * 29 + PinkCurXPos) * 12 + 7] == '.')
                    {
                        PinkWasPellet = 1;
                        PinkCurYPos += 1;
                    }
                    else if (concatenatedString[((PinkCurYPos + 1) * 29 + PinkCurXPos) * 12 + 7] == ' ' || concatenatedString[((PinkCurYPos + 1) * 29 + PinkCurXPos) * 12 + 7] == 'A')
                    {
                        PinkWasPellet = 0;
                        PinkCurYPos += 1;
                    }
                    else if (concatenatedString[((PinkCurYPos + 1) * 29 + PinkCurXPos) * 12 + 7] == '*')
                    {
                        PinkWasPellet = 2;
                        PinkCurYPos += 1;
                    }
                    else if (concatenatedString[((PinkCurYPos + 1) * 29 + PinkCurXPos) * 12 + 7] == 'O' && concatenatedString[((PinkCurYPos + 1) * 29 + PinkCurXPos) * 12 + 5] == '5'&&PinkKilledFlag==1)
                    {
                        PinkWasPellet = 3;
                        PinkCurYPos += 1;
                    }
                    else if (concatenatedString[((PinkCurYPos + 1) * 29 + PinkCurXPos) * 12 + 7] == '@')
                    {
                        PinkWasPellet = 0;
                        PinkCurYPos += 1;
                        if (FrightenFlag == 0)
                        {
                            gameOver = 1;
                        }
                        else
                        {
                            gameOver = 0;
                        }
                    }
                    break;
                case 72:
                    if (concatenatedString[((PinkCurYPos - 1) * 29 + PinkCurXPos) * 12 + 7] == '.')
                    {
                        PinkWasPellet = 1;
                        PinkCurYPos -= 1;
                    }
                    else if (concatenatedString[((PinkCurYPos - 1) * 29 + PinkCurXPos) * 12 + 7] == ' ' || concatenatedString[((PinkCurYPos - 1) * 29 + PinkCurXPos) * 12 + 7] == 'A')
                    {
                        PinkWasPellet = 0;
                        PinkCurYPos -= 1;
                    }
                    else if (concatenatedString[((PinkCurYPos - 1) * 29 + PinkCurXPos) * 12 + 7] == '*')
                    {
                        PinkWasPellet = 2;
                        PinkCurYPos -= 1;
                    }
                    else if (concatenatedString[((PinkCurYPos - 1) * 29 + PinkCurXPos) * 12 + 7] == 'O' && concatenatedString[((PinkCurYPos - 1) * 29 + PinkCurXPos) * 12 + 5] == '5')
                    {
                        PinkWasPellet = 3;
                        PinkCurYPos -= 1;
                    }
                    else if (concatenatedString[((PinkCurYPos - 1) * 29 + PinkCurXPos) * 12 + 7] == '@')
                    {
                        PinkWasPellet = 0;
                        PinkCurYPos -= 1;
                        if (FrightenFlag == 0)
                        {
                            gameOver = 1;
                        }
                        else
                        {
                            gameOver = 0;
                        }
                    }
                    break;
                }


                if (PinkCurXPos==-1)
                {
                    PinkCurXPos=27;
                    if (concatenatedString[(14*29+27)*12+7]=='.')
                    {
                        PinkWasPellet=1;
                    }
                    else if (concatenatedString[(14*29+27)*12+7]==' ')
                    {
                        PinkWasPellet=0;
                    }
                }
                else if (PinkCurXPos==28)
                {
                    PinkCurXPos=0;
                    if (concatenatedString[(14*29+0)*12+7]=='.')
                    {
                        PinkWasPellet=1;
                    }
                    else if (concatenatedString[(14*29+0)*12+7]==' ')
                    {
                        PinkWasPellet=0;
                    }
                }

                //checking the  presence of walls around the ghost at its new tile
                if (concatenatedString[((PinkCurYPos)*29+PinkCurXPos-1)*12+7]=='#'||(concatenatedString[((PinkCurYPos)*29+PinkCurXPos-1)*12+7]=='O'&&(concatenatedString[((PinkCurYPos)*29+PinkCurXPos-1)*12+5]=='4'||(concatenatedString[((PinkCurYPos)*29+PinkCurXPos-1)*12+5]=='5'&& PinkKilledFlag==0))))//checking left
                {
                    PinkDirectionsNum+=1;
                    PinkCurDirection[0]=10000;
                }
                if (concatenatedString[((PinkCurYPos-1)*29+PinkCurXPos)*12+7]=='#'||(concatenatedString[((PinkCurYPos-1)*29+PinkCurXPos)*12+7]=='O'&&(concatenatedString[((PinkCurYPos-1)*29+PinkCurXPos)*12+5]=='4'||(concatenatedString[((PinkCurYPos-1)*29+PinkCurXPos)*12+5]=='5'&&PinkKilledFlag==0)))) //checking Up
                {
                    PinkDirectionsNum+=1;
                    PinkCurDirection[1]=10000;
                }
                if (concatenatedString[((PinkCurYPos)*29+PinkCurXPos+1)*12+7]=='#'||(concatenatedString[((PinkCurYPos)*29+PinkCurXPos+1)*12+7]=='O'&&(concatenatedString[((PinkCurYPos)*29+PinkCurXPos+1)*12+5]=='4'||(concatenatedString[((PinkCurYPos)*29+PinkCurXPos+1)*12+5]=='5'&&PinkKilledFlag==0)))) //checking Right
                {
                    PinkDirectionsNum+=1;
                    PinkCurDirection[2]=10000;
                }
                if (concatenatedString[((PinkCurYPos+1)*29+PinkCurXPos)*12+7]=='#'||(concatenatedString[((PinkCurYPos+1)*29+PinkCurXPos)*12+7]=='O'&&(concatenatedString[((PinkCurYPos+1)*29+PinkCurXPos)*12+5]=='4'||(concatenatedString[((PinkCurYPos+1)*29+PinkCurXPos)*12+5]=='5'&&PinkKilledFlag==0)))) //checking Down
                {
                    PinkDirectionsNum+=1;
                    PinkCurDirection[3]= 10000;
                }

                //checking if ghost hits a corner
                if (!(PinkCurDirection[1]==10000 && PinkCurDirection[3]==10000) && !(PinkCurDirection[0]==10000 && PinkCurDirection[2]==10000))
                {
                    if (PinkCurDirection[0]==10000 &&  PinkCurDirection[3]==10000) //bottom left corner
                    {
                        if (PinkCurCurDirection==75)
                        {
                            PinkCurCurDirection=72;
                        }
                        else if (PinkCurCurDirection==80)
                        {
                            PinkCurCurDirection=77;
                        }
                    }
                    else if (PinkCurDirection[0]==10000 &&  PinkCurDirection[1]==10000)  //top left corner
                    {
                        if (PinkCurCurDirection==72)
                        {
                            PinkCurCurDirection=77;
                        }
                        else if (PinkCurCurDirection==75)
                        {
                            PinkCurCurDirection=80;
                        }
                    }
                    else if (PinkCurDirection[1]==10000 &&  PinkCurDirection[2]==10000)//top  right corner
                    {
                        if (PinkCurCurDirection==77)
                        {
                            PinkCurCurDirection=80;
                        }
                        else if (PinkCurCurDirection==72)
                        {
                            PinkCurCurDirection=75;
                        }
                    }
                    else if (PinkCurDirection[2]==10000 &&  PinkCurDirection[3]==10000)//bottom right  corner
                    {
                        if (PinkCurCurDirection==80)
                        {
                            PinkCurCurDirection=75;
                        }
                        else if (PinkCurCurDirection==77)
                        {
                            PinkCurCurDirection=72;
                        }

                    }
                }
                //code for the choice  the ghost makes if  it hits  a tri/quad intersection
                if (PinkDirectionsNum<2)
                {
                    //making it so that the ghost can't turn around and go the direction it came from
                        switch (PinkCurCurDirection)
                        {
                            case 75:
                                PinkCurDirection[2]=10000;
                                break;
                            case 72:
                                PinkCurDirection[3]=10000;
                                break;
                            case 77:
                                PinkCurDirection[0]=10000;
                                break;
                            case  80:
                                PinkCurDirection[1]=10000;
                                break;
                        }
                        if (GhostMode=='C')
                        {
                            switch (prevAction)
                            {
                            case 75:
                                PinkTarget[0]=CurrentXpos-4;
                                PinkTarget[1]=CurrentYpos;
                                break;
                            case  72:
                                PinkTarget[0]=CurrentXpos;
                                PinkTarget[1]=CurrentYpos-4;
                                break;
                            case 77:
                                PinkTarget[0]=CurrentXpos+4;
                                PinkTarget[1]=CurrentYpos;
                                break;
                            case 80:
                                PinkTarget[0]=CurrentXpos;
                                PinkTarget[1]=CurrentYpos+4;
                                break;
                            }
                            if (PinkTarget[0]>27)
                            {
                                PinkTarget[0]=27;
                            }
                            if (PinkTarget[0]<0)
                            {
                                PinkTarget[0]=0;
                            }
                            if (PinkTarget[1]>30)
                            {
                                PinkTarget[1]=30;
                            }
                            if (PinkTarget[1]<0)
                            {
                                PinkTarget[1]=0;
                            }
                        }
                        else if (GhostMode=='S')
                        {
                            PinkTarget[0]=1;
                            PinkTarget[1]=1;
                        }
                        else if (GhostMode=='F')
                        {
                            srand((unsigned int)time(NULL));

                            PinkTarget[0] =  rand()%26;
                            PinkTarget[1] = rand()%29;
                        }

                        if (PinkKilledFlag==1)
                        {
                            PinkTarget[0] = 15;
                            PinkTarget[1] = 14;
                        }

                    for  (int i=0;i<4;i++)
                    {
                        if (PinkCurDirection[i]!=10000)
                        {
                            switch (i)
                            {
                                case 0:
                                    PinkCurDirection[0] = (PinkCurXPos - 1 - PinkTarget[0]) * (PinkCurXPos - 1 - PinkTarget[0]) + (PinkCurYPos - PinkTarget[1]) * (PinkCurYPos - PinkTarget[1]);
                                    break;
                                case 1:
                                    PinkCurDirection[1] = (PinkCurXPos - PinkTarget[0]) * (PinkCurXPos - PinkTarget[0]) + (PinkCurYPos - 1 - PinkTarget[1]) * (PinkCurYPos - 1 - PinkTarget[1]);
                                    break;
                                case 2:
                                    PinkCurDirection[2] = (PinkCurXPos + 1 - PinkTarget[0]) * (PinkCurXPos + 1 - PinkTarget[0]) + (PinkCurYPos - PinkTarget[1]) * (PinkCurYPos - PinkTarget[1]);
                                    break;
                                case 3:
                                    PinkCurDirection[3] = (PinkCurXPos - PinkTarget[0]) * (PinkCurXPos - PinkTarget[0]) + (PinkCurYPos + 1 - PinkTarget[1]) * (PinkCurYPos + 1 - PinkTarget[1]);
                                    break;
                            }
                        }
                    }
                    switch(findIndexOfSmallest(PinkCurDirection,4))
                    {
                        case 0:
                            PinkCurCurDirection=75;
                            break;
                        case 1:
                            PinkCurCurDirection=72;
                            break;
                        case 2:
                            PinkCurCurDirection=77;
                            break;
                        case 3:
                            PinkCurCurDirection=80;
                            break;
                    }
                    if (PinkKilledFlag==0 && (clock()-PinkKilledTimer)/CLOCKS_PER_SEC==8&&PinkKillKillFlag==1)
                    {
                        if (concatenatedString[(11*29+14)*12+7]=='.')
                        {
                            PinkWasPellet=1;
                        }
                        else if (concatenatedString[(11*29+14)*12+7]==' ')
                        {
                            PinkWasPellet=0;
                        }
                        PinkCurXPos=14;
                        PinkCurYPos=11;
                        PinkCurCurDirection=77;
                        PinkKillKillFlag=0;
                    }
                }
            }


            if (pucFrame%CyanGhostSpeed==0)
            {
                CyanDirectionsNum=0;
                for (int i=0;i<4;i++)
                {
                    CyanCurDirection[i]=1;
                }

                switch (CyanWasPellet)
                {
                    case 1:
                        concatenatedString[(CyanCurYPos * 29 + CyanCurXPos) * 12 + 5] = '7';
                        concatenatedString[(CyanCurYPos * 29 + CyanCurXPos) * 12 + 7] = '.';
                        break;
                    case 0:
                        concatenatedString[(CyanCurYPos * 29 + CyanCurXPos) * 12 + 7] = ' ';
                        break;
                    case 2:
                        concatenatedString[(CyanCurYPos * 29 + CyanCurXPos) * 12 + 5] = '7';
                        concatenatedString[(CyanCurYPos * 29 + CyanCurXPos) * 12 + 7] = '*';
                        break;
                    case 3:
                        concatenatedString[(CyanCurYPos * 29 + CyanCurXPos) * 12 + 5] = '5';
                        concatenatedString[(CyanCurYPos * 29 + CyanCurXPos) * 12 + 7] = 'O';
                        break;
                }

                switch (CyanCurCurDirection)
                {
                    case 75:
                        if (concatenatedString[(CyanCurYPos * 29 + CyanCurXPos - 1) * 12 + 7] == '.' || concatenatedString[(CyanCurYPos * 29 + CyanCurXPos - 1) * 12 + 7] == '\n')
                        {
                            CyanWasPellet = 1;
                            CyanCurXPos -= 1;
                        }
                        else if (concatenatedString[(CyanCurYPos * 29 + CyanCurXPos - 1) * 12 + 7] == ' ' || concatenatedString[(CyanCurYPos * 29 + CyanCurXPos - 1) * 12 + 7] == 'A')
                        {
                            CyanWasPellet = 0;
                            CyanCurXPos -= 1;
                        }
                        else if (concatenatedString[(CyanCurYPos * 29 + CyanCurXPos - 1) * 12 + 7] == '*')
                        {
                            CyanWasPellet = 2;
                            CyanCurXPos -= 1;
                        }
                        else if (concatenatedString[(CyanCurYPos * 29 + CyanCurXPos - 1) * 12 + 7] == 'O' && concatenatedString[(CyanCurYPos * 29 + CyanCurXPos - 1) * 12 + 5] == '5')
                        {
                            CyanWasPellet = 3;
                            CyanCurXPos -= 1;
                        }
                        else if (concatenatedString[(CyanCurYPos * 29 + CyanCurXPos - 1) * 12 + 7] == '@')
                        {
                            CyanWasPellet = 0;
                            CyanCurXPos -= 1;
                            if (FrightenFlag == 0)
                            {
                                gameOver = 1;
                            }
                            else
                            {
                                gameOver = 0;
                            }
                        }
                        break;
                    case 77:
                        if (concatenatedString[(CyanCurYPos * 29 + CyanCurXPos + 1) * 12 + 7] == '.' || concatenatedString[(CyanCurYPos * 29 + CyanCurXPos + 1) * 12 + 7] == '\n')
                        {
                            CyanWasPellet = 1;
                            CyanCurXPos += 1;
                        }
                        else if (concatenatedString[(CyanCurYPos * 29 + CyanCurXPos + 1) * 12 + 7] == ' ' || concatenatedString[(CyanCurYPos * 29 + CyanCurXPos + 1) * 12 + 7] == 'A')
                        {
                            CyanWasPellet = 0;
                            CyanCurXPos += 1;
                        }
                        else if (concatenatedString[(CyanCurYPos * 29 + CyanCurXPos + 1) * 12 + 7] == '*')
                        {
                            CyanWasPellet = 2;
                            CyanCurXPos += 1;
                        }
                        else if (concatenatedString[(CyanCurYPos * 29 + CyanCurXPos + 1) * 12 + 7] == 'O' && concatenatedString[(CyanCurYPos * 29 + CyanCurXPos - 1) * 12 + 5] == '5')
                        {
                            CyanWasPellet = 3;
                            CyanCurXPos += 1;
                        }
                        else if (concatenatedString[(CyanCurYPos * 29 + CyanCurXPos + 1) * 12 + 7] == '@')
                        {
                            CyanWasPellet = 0;
                            CyanCurXPos += 1;
                            if (FrightenFlag == 0)
                            {
                                gameOver = 1;
                            }
                            else
                            {
                                gameOver = 0;
                            }
                        }
                        break;
                    case 80:
                        if (concatenatedString[((CyanCurYPos + 1) * 29 + CyanCurXPos) * 12 + 7] == '.')
                        {
                            CyanWasPellet = 1;
                            CyanCurYPos += 1;
                        }
                        else if (concatenatedString[((CyanCurYPos + 1) * 29 + CyanCurXPos) * 12 + 7] == ' ' || concatenatedString[((CyanCurYPos + 1) * 29 + CyanCurXPos) * 12 + 7] == 'A')
                        {
                            CyanWasPellet = 0;
                            CyanCurYPos += 1;
                        }
                        else if (concatenatedString[((CyanCurYPos + 1) * 29 + CyanCurXPos) * 12 + 7] == '*')
                        {
                            CyanWasPellet = 2;
                            CyanCurYPos += 1;
                        }
                        else if (concatenatedString[((CyanCurYPos + 1) * 29 + CyanCurXPos) * 12 + 7] == 'O' && concatenatedString[((CyanCurYPos + 1) * 29 + CyanCurXPos) * 12 + 5] == '5' && CyanKilledFlag==1)
                        {
                            CyanWasPellet = 3;
                            CyanCurYPos += 1;
                        }
                        else if (concatenatedString[((CyanCurYPos + 1) * 29 + CyanCurXPos) * 12 + 7] == '@')
                        {
                            CyanWasPellet = 0;
                            CyanCurYPos += 1;
                            if (FrightenFlag == 0)
                            {
                                gameOver = 1;
                            }
                            else
                            {
                                gameOver = 0;
                            }
                        }
                        break;
                    case 72:
                        if (concatenatedString[((CyanCurYPos - 1) * 29 + CyanCurXPos) * 12 + 7] == '.')
                        {
                            CyanWasPellet = 1;
                            CyanCurYPos -= 1;
                        }
                        else if (concatenatedString[((CyanCurYPos - 1) * 29 + CyanCurXPos) * 12 + 7] == ' ' || concatenatedString[((CyanCurYPos - 1) * 29 + CyanCurXPos) * 12 + 7] == 'A')
                        {
                            CyanWasPellet = 0;
                            CyanCurYPos -= 1;
                        }
                        else if (concatenatedString[((CyanCurYPos - 1) * 29 + CyanCurXPos) * 12 + 7] == '*')
                        {
                            CyanWasPellet = 2;
                            CyanCurYPos -= 1;
                        }
                        else if (concatenatedString[((CyanCurYPos - 1) * 29 + CyanCurXPos) * 12 + 7] == 'O' && concatenatedString[((CyanCurYPos - 1) * 29 + CyanCurXPos) * 12 + 5] == '5')
                        {
                            CyanWasPellet = 3;
                            CyanCurYPos -= 1;
                        }
                        else if (concatenatedString[((CyanCurYPos - 1) * 29 + CyanCurXPos) * 12 + 7] == '@')
                        {
                            CyanWasPellet = 0;
                            CyanCurYPos -= 1;
                            if (FrightenFlag == 0)
                            {
                                gameOver = 1;
                            }
                            else
                            {
                                gameOver = 0;
                            }
                        }
                        break;
                }



                if (CyanCurXPos==-1)
                {
                    CyanCurXPos=27;
                    if (concatenatedString[(14*29+27)*12+7]=='.')
                    {
                        CyanWasPellet=1;
                    }
                    else if (concatenatedString[(14*29+27)*12+7]==' ')
                    {
                        CyanWasPellet=0;
                    }
                }
                else if (CyanCurXPos==28)
                {
                    CyanCurXPos=0;
                    if (concatenatedString[(14*29+0)*12+7]=='.')
                    {
                        CyanWasPellet=1;
                    }
                    else if (concatenatedString[(14*29+0)*12+7]==' ')
                    {
                        CyanWasPellet=0;
                    }
                }

                //checking the  presence of walls around the ghost at its new tile
                if (concatenatedString[((CyanCurYPos)*29+CyanCurXPos-1)*12+7]=='#'||(concatenatedString[((CyanCurYPos)*29+CyanCurXPos-1)*12+7]=='O'&&(concatenatedString[((CyanCurYPos)*29+CyanCurXPos-1)*12+5]=='4'||(concatenatedString[((CyanCurYPos)*29+CyanCurXPos-1)*12+5]=='5'&& CyanKilledFlag==0))))//checking left
                {
                    CyanDirectionsNum+=1;
                    CyanCurDirection[0]=10000;
                }
                if (concatenatedString[((CyanCurYPos-1)*29+CyanCurXPos)*12+7]=='#'||(concatenatedString[((CyanCurYPos-1)*29+CyanCurXPos)*12+7]=='O'&&(concatenatedString[((CyanCurYPos-1)*29+CyanCurXPos)*12+5]=='4'||(concatenatedString[((CyanCurYPos-1)*29+CyanCurXPos)*12+5]=='5'&&CyanKilledFlag==0)))) //checking Up
                {
                    CyanDirectionsNum+=1;
                    CyanCurDirection[1]=10000;
                }
                if (concatenatedString[((CyanCurYPos)*29+CyanCurXPos+1)*12+7]=='#'||(concatenatedString[((CyanCurYPos)*29+CyanCurXPos+1)*12+7]=='O'&&(concatenatedString[((CyanCurYPos)*29+CyanCurXPos+1)*12+5]=='4'||(concatenatedString[((CyanCurYPos)*29+CyanCurXPos+1)*12+5]=='5'&&CyanKilledFlag==0)))) //checking Right
                {
                    CyanDirectionsNum+=1;
                    CyanCurDirection[2]=10000;
                }
                if (concatenatedString[((CyanCurYPos+1)*29+CyanCurXPos)*12+7]=='#'||(concatenatedString[((CyanCurYPos+1)*29+CyanCurXPos)*12+7]=='O'&&(concatenatedString[((CyanCurYPos+1)*29+CyanCurXPos)*12+5]=='4'||(concatenatedString[((CyanCurYPos+1)*29+CyanCurXPos)*12+5]=='5'&&CyanKilledFlag==0)))) //checking Down
                {
                    CyanDirectionsNum+=1;
                    CyanCurDirection[3]= 10000;
                }

                //checking if ghost hits a corner
                if (!(CyanCurDirection[1]==10000 && CyanCurDirection[3]==10000) && !(CyanCurDirection[0]==10000 && CyanCurDirection[2]==10000))
                {
                    if (CyanCurDirection[0]==10000 &&  CyanCurDirection[3]==10000) //bottom left corner
                    {
                        if (CyanCurCurDirection==75)
                        {
                            CyanCurCurDirection=72;
                        }
                        else if (CyanCurCurDirection==80)
                        {
                            CyanCurCurDirection=77;
                        }
                    }
                    else if (CyanCurDirection[0]==10000 &&  CyanCurDirection[1]==10000)  //top left corner
                    {
                        if (CyanCurCurDirection==72)
                        {
                            CyanCurCurDirection=77;
                        }
                        else if (CyanCurCurDirection==75)
                        {
                            CyanCurCurDirection=80;
                        }
                    }
                    else if (CyanCurDirection[1]==10000 &&  CyanCurDirection[2]==10000)//top  right corner
                    {
                        if (CyanCurCurDirection==77)
                        {
                            CyanCurCurDirection=80;
                        }
                        else if (CyanCurCurDirection==72)
                        {
                            CyanCurCurDirection=75;
                        }
                    }
                    else if (CyanCurDirection[2]==10000 &&  CyanCurDirection[3]==10000)//bottom right  corner
                    {
                        if (CyanCurCurDirection==80)
                        {
                            CyanCurCurDirection=75;
                        }
                        else if (CyanCurCurDirection==77)
                        {
                            CyanCurCurDirection=72;
                        }

                    }
                }
                //code for the choice  the ghost makes if  it hits  a tri/quad intersection
                if (CyanDirectionsNum<2)
                {
                    //making it so that the ghost can't turn around and go the direction it came from
                    switch (CyanCurCurDirection)
                    {
                        case 75:
                            CyanCurDirection[2]=10000;
                            break;
                        case 72:
                            CyanCurDirection[3]=10000;
                            break;
                        case 77:
                            CyanCurDirection[0]=10000;
                            break;
                        case  80:
                            CyanCurDirection[1]=10000;
                            break;
                    }

                    if (GhostMode=='C')
                    {
                        CyanTarget[0]=(2*CurrentXpos-RedCurXPos)%28;
                        CyanTarget[1]=(2*CurrentYpos-RedCurYPos)%30;
                    }
                    else if(GhostMode=='S')
                    {
                        CyanTarget[0]= 26;
                        CyanTarget[1]=29;
                    }
                    else if (GhostMode=='F')
                    {
                        srand((unsigned int)time(NULL));

                        CyanTarget[0] =  rand()%26;
                        CyanTarget[1] = rand()%29;
                    }

                    if (CyanKilledFlag==1)
                    {
                        CyanTarget[0] = 15;
                        CyanTarget[1] = 14;
                    }
                    for  (int i=0;i<4;i++)
                    {
                        if (CyanCurDirection[i]!=10000)
                        {
                            switch (i)
                            {
                                case 0:
                                    CyanCurDirection[0] = (CyanCurXPos - 1 - CyanTarget[0]) * (CyanCurXPos - 1 - CyanTarget[0]) + (CyanCurYPos - CyanTarget[1]) * (CyanCurYPos - CyanTarget[1]);
                                    break;
                                case 1:
                                    CyanCurDirection[1] = (CyanCurXPos - CyanTarget[0]) * (CyanCurXPos - CyanTarget[0]) + (CyanCurYPos - 1 - CyanTarget[1]) * (CyanCurYPos - 1 - CyanTarget[1]);
                                    break;
                                case 2:
                                    CyanCurDirection[2] = (CyanCurXPos + 1 - CyanTarget[0]) * (CyanCurXPos + 1 - CyanTarget[0]) + (CyanCurYPos - CyanTarget[1]) * (CyanCurYPos - CyanTarget[1]);
                                    break;
                                case 3:
                                    CyanCurDirection[3] = (CyanCurXPos - CyanTarget[0]) * (CyanCurXPos - CyanTarget[0]) + (CyanCurYPos + 1 - CyanTarget[1]) * (CyanCurYPos + 1 - CyanTarget[1]);
                                    break;
                            }

                        }
                    }
                    switch(findIndexOfSmallest(CyanCurDirection,4))
                    {
                        case 0:
                            CyanCurCurDirection=75;
                            break;
                        case 1:
                            CyanCurCurDirection=72;
                            break;
                        case 2:
                            CyanCurCurDirection=77;
                            break;
                        case 3:
                            CyanCurCurDirection=80;
                            break;
                    }
                    if (CyanKilledFlag==0 && (clock()-CyanKilledTimer)/CLOCKS_PER_SEC==8&&cyanKillKillFlag==1)
                    {

                        if (concatenatedString[(11*29+14)*12+7]=='.')
                        {
                            CyanWasPellet=1;
                        }
                        else if (concatenatedString[(11*29+14)*12+7]==' ')
                        {
                            CyanWasPellet=0;
                        }
                        CyanCurXPos=14;
                        CyanCurYPos=11;
                        CyanCurCurDirection=77;
                        cyanKillKillFlag=0;
                    }
                }
            }

            if (pucFrame%YellGhostSpeed==0)
            {
                YellDirectionsNum=0;
                for (int i=0;i<4;i++)
                {
                    YellCurDirection[i]=1;
                }

                switch (YellWasPellet)
                {
                    case 1:
                        concatenatedString[(YellCurYPos * 29 + YellCurXPos) * 12 + 5] = '7';
                        concatenatedString[(YellCurYPos * 29 + YellCurXPos) * 12 + 7] = '.';
                        break;
                    case 0:
                        concatenatedString[(YellCurYPos * 29 + YellCurXPos) * 12 + 7] = ' ';
                        break;
                    case 2:
                        concatenatedString[(YellCurYPos * 29 + YellCurXPos) * 12 + 5] = '7';
                        concatenatedString[(YellCurYPos * 29 + YellCurXPos) * 12 + 7] = '*';
                        break;
                    case 3:
                        concatenatedString[(YellCurYPos * 29 + YellCurXPos) * 12 + 5] = '5';
                        concatenatedString[(YellCurYPos * 29 + YellCurXPos) * 12 + 7] = 'O';
                        break;
                }

                switch (YellCurCurDirection)
                {
                    case 75:
                        if (concatenatedString[(YellCurYPos * 29 + YellCurXPos - 1) * 12 + 7] == '.' || concatenatedString[(YellCurYPos * 29 + YellCurXPos - 1) * 12 + 7] == '\n')
                        {
                            YellWasPellet = 1;
                            YellCurXPos -= 1;
                        }
                        else if (concatenatedString[(YellCurYPos * 29 + YellCurXPos - 1) * 12 + 7] == ' ' || concatenatedString[(YellCurYPos * 29 + YellCurXPos - 1) * 12 + 7] == 'A')
                        {
                            YellWasPellet = 0;
                            YellCurXPos -= 1;
                        }
                        else if (concatenatedString[(YellCurYPos * 29 + YellCurXPos - 1) * 12 + 7] == '*')
                        {
                            YellWasPellet = 2;
                            YellCurXPos -= 1;
                        }
                        else if (concatenatedString[(YellCurYPos * 29 + YellCurXPos - 1) * 12 + 7] == 'O' && concatenatedString[(YellCurYPos * 29 + YellCurXPos - 1) * 12 + 5] == '5')
                        {
                            YellWasPellet = 3;
                            YellCurXPos -= 1;
                        }
                        else if (concatenatedString[(YellCurYPos * 29 + YellCurXPos - 1) * 12 + 7] == '@')
                        {
                            YellWasPellet = 0;
                            YellCurXPos -= 1;
                            if (FrightenFlag == 0)
                            {
                                gameOver = 1;
                            }
                            else
                            {
                                gameOver = 0;
                            }
                        }
                        break;
                    case 77:
                        if (concatenatedString[(YellCurYPos * 29 + YellCurXPos + 1) * 12 + 7] == '.' || concatenatedString[(YellCurYPos * 29 + YellCurXPos + 1) * 12 + 7] == '\n')
                        {
                            YellWasPellet = 1;
                            YellCurXPos += 1;
                        }
                        else if (concatenatedString[(YellCurYPos * 29 + YellCurXPos + 1) * 12 + 7] == ' ' || concatenatedString[(YellCurYPos * 29 + YellCurXPos + 1) * 12 + 7] == 'A')
                        {
                            YellWasPellet = 0;
                            YellCurXPos += 1;
                        }
                        else if (concatenatedString[(YellCurYPos * 29 + YellCurXPos + 1) * 12 + 7] == '*')
                        {
                            YellWasPellet = 2;
                            YellCurXPos += 1;
                        }
                        else if (concatenatedString[(YellCurYPos * 29 + YellCurXPos + 1) * 12 + 7] == 'O' && concatenatedString[(YellCurYPos * 29 + YellCurXPos - 1) * 12 + 5] == '5')
                        {
                            YellWasPellet = 3;
                            YellCurXPos += 1;
                        }
                        else if (concatenatedString[(YellCurYPos * 29 + YellCurXPos + 1) * 12 + 7] == '@')
                        {
                            YellWasPellet = 0;
                            YellCurXPos += 1;
                            if (FrightenFlag == 0)
                            {
                                gameOver = 1;
                            }
                            else
                            {
                                gameOver = 0;
                            }
                        }
                        break;
                    case 80:
                        if (concatenatedString[((YellCurYPos + 1) * 29 + YellCurXPos) * 12 + 7] == '.')
                        {
                            YellWasPellet = 1;
                            YellCurYPos += 1;
                        }
                        else if (concatenatedString[((YellCurYPos + 1) * 29 + YellCurXPos) * 12 + 7] == ' ' || concatenatedString[((YellCurYPos + 1) * 29 + YellCurXPos) * 12 + 7] == 'A')
                        {
                            YellWasPellet = 0;
                            YellCurYPos += 1;
                        }
                        else if (concatenatedString[((YellCurYPos + 1) * 29 + YellCurXPos) * 12 + 7] == '*')
                        {
                            YellWasPellet = 2;
                            YellCurYPos += 1;
                        }
                        else if (concatenatedString[((YellCurYPos + 1) * 29 + YellCurXPos) * 12 + 7] == 'O' && concatenatedString[((YellCurYPos + 1) * 29 + YellCurXPos) * 12 + 5] == '5'&&YellKilledFlag==1)
                        {
                            YellWasPellet = 3;
                            YellCurYPos += 1;
                        }
                        else if (concatenatedString[((YellCurYPos + 1) * 29 + YellCurXPos) * 12 + 7] == '@')
                        {
                            YellWasPellet = 0;
                            YellCurYPos += 1;
                            if (FrightenFlag == 0)
                            {
                                gameOver = 1;
                            }
                            else
                            {
                                gameOver = 0;
                            }
                        }
                        break;
                    case 72:
                        if (concatenatedString[((YellCurYPos - 1) * 29 + YellCurXPos) * 12 + 7] == '.')
                        {
                            YellWasPellet = 1;
                            YellCurYPos -= 1;
                        }
                        else if (concatenatedString[((YellCurYPos - 1) * 29 + YellCurXPos) * 12 + 7] == ' ' || concatenatedString[((YellCurYPos - 1) * 29 + YellCurXPos) * 12 + 7] == 'A')
                        {
                            YellWasPellet = 0;
                            YellCurYPos -= 1;
                        }
                        else if (concatenatedString[((YellCurYPos - 1) * 29 + YellCurXPos) * 12 + 7] == '*')
                        {
                            YellWasPellet = 2;
                            YellCurYPos -= 1;
                        }
                        else if (concatenatedString[((YellCurYPos - 1) * 29 + YellCurXPos) * 12 + 7] == 'O' && concatenatedString[((YellCurYPos - 1) * 29 + YellCurXPos) * 12 + 5] == '5')
                        {
                            YellWasPellet = 3;
                            YellCurYPos -= 1;
                        }
                        else if (concatenatedString[((YellCurYPos - 1) * 29 + YellCurXPos) * 12 + 7] == '@')
                        {
                            YellWasPellet = 0;
                            YellCurYPos -= 1;
                            if (FrightenFlag == 0)
                            {
                                gameOver = 1;
                            }
                            else
                            {
                                gameOver = 0;
                            }
                        }
                        break;
                }



                if (YellCurXPos==-1)
                {
                    YellCurXPos=27;
                    if (concatenatedString[(14*29+27)*12+7]=='.')
                    {
                        YellWasPellet=1;
                    }
                    else if (concatenatedString[(14*29+27)*12+7]==' ')
                    {
                        YellWasPellet=0;
                    }
                }
                else if (YellCurXPos==28)
                {
                    YellCurXPos=0;
                    if (concatenatedString[(14*29+0)*12+7]=='.')
                    {
                        YellWasPellet=1;
                    }
                    else if (concatenatedString[(14*29+0)*12+7]==' ')
                    {
                        YellWasPellet=0;
                    }
                }

                //checking the  presence of walls around the ghost at its new tile
                if (concatenatedString[((YellCurYPos)*29+YellCurXPos-1)*12+7]=='#'||(concatenatedString[((YellCurYPos)*29+YellCurXPos-1)*12+7]=='O'&&(concatenatedString[((YellCurYPos)*29+YellCurXPos-1)*12+5]=='4'||(concatenatedString[((YellCurYPos)*29+YellCurXPos-1)*12+5]=='5'&& YellKilledFlag==0))))//checking left
                {
                    YellDirectionsNum+=1;
                    YellCurDirection[0]=10000;
                }
                if (concatenatedString[((YellCurYPos-1)*29+YellCurXPos)*12+7]=='#'||(concatenatedString[((YellCurYPos-1)*29+YellCurXPos)*12+7]=='O'&&(concatenatedString[((YellCurYPos-1)*29+YellCurXPos)*12+5]=='4'||(concatenatedString[((YellCurYPos-1)*29+YellCurXPos)*12+5]=='5'&&YellKilledFlag==0)))) //checking Up
                {
                    YellDirectionsNum+=1;
                    YellCurDirection[1]=10000;
                }
                if (concatenatedString[((YellCurYPos)*29+YellCurXPos+1)*12+7]=='#'||(concatenatedString[((YellCurYPos)*29+YellCurXPos+1)*12+7]=='O'&&(concatenatedString[((YellCurYPos)*29+YellCurXPos+1)*12+5]=='4'||(concatenatedString[((YellCurYPos)*29+YellCurXPos+1)*12+5]=='5'&&YellKilledFlag==0)))) //checking Right
                {
                    YellDirectionsNum+=1;
                    YellCurDirection[2]=10000;
                }
                if (concatenatedString[((YellCurYPos+1)*29+YellCurXPos)*12+7]=='#'||(concatenatedString[((YellCurYPos+1)*29+YellCurXPos)*12+7]=='O'&&(concatenatedString[((YellCurYPos+1)*29+YellCurXPos)*12+5]=='4'||(concatenatedString[((YellCurYPos+1)*29+YellCurXPos)*12+5]=='5'&&YellKilledFlag==0)))) //checking Down
                {
                    YellDirectionsNum+=1;
                    YellCurDirection[3]= 10000;
                }


                //checking if ghost hits a corner
                if (!(YellCurDirection[1]==10000 && YellCurDirection[3]==10000) && !(YellCurDirection[0]==10000 && YellCurDirection[2]==10000))
                {
                    if (YellCurDirection[0]==10000 &&  YellCurDirection[3]==10000) //bottom left corner
                    {
                        if (YellCurCurDirection==75)
                        {
                            YellCurCurDirection=72;
                        }
                        else if (YellCurCurDirection==80)
                        {
                            YellCurCurDirection=77;
                        }
                    }
                    else if (YellCurDirection[0]==10000 &&  YellCurDirection[1]==10000)  //top left corner
                    {
                        if (YellCurCurDirection==72)
                        {
                            YellCurCurDirection=77;
                        }
                        else if (YellCurCurDirection==75)
                        {
                            YellCurCurDirection=80;
                        }
                    }
                    else if (YellCurDirection[1]==10000 &&  YellCurDirection[2]==10000)//top  right corner
                    {
                        if (YellCurCurDirection==77)
                        {
                            YellCurCurDirection=80;
                        }
                        else if (YellCurCurDirection==72)
                        {
                            YellCurCurDirection=75;
                        }
                    }
                    else if (YellCurDirection[2]==10000 &&  YellCurDirection[3]==10000)//bottom right  corner
                    {
                        if (YellCurCurDirection==80)
                        {
                            YellCurCurDirection=75;
                        }
                        else if (YellCurCurDirection==77)
                        {
                            YellCurCurDirection=72;
                        }

                    }
                }
                //code for the choice  the ghost makes if  it hits  a tri/quad intersection
                if (YellDirectionsNum<2)
                {
                    //making it so that the ghost can't turn around and go the direction it came from
                    switch (YellCurCurDirection)
                    {
                        case 75:
                            YellCurDirection[2]=10000;
                            break;
                        case 72:
                            YellCurDirection[3]=10000;
                            break;
                        case 77:
                            YellCurDirection[0]=10000;
                            break;
                        case  80:
                            YellCurDirection[1]=10000;
                            break;
                    }

                    if (GhostMode=='C')
                    {
                        if ((YellCurXPos-CurrentXpos)*(YellCurXPos-CurrentXpos)+(YellCurYPos-CurrentYpos)*(YellCurYPos-CurrentYpos)>=64)
                        {
                            YellowTarget[0]=CurrentXpos;
                            YellowTarget[1]=CurrentYpos;
                        }
                        else
                        {
                            YellowTarget[0]=1;
                            YellowTarget[1]=29;
                        }
                    }
                    else if (GhostMode=='S')
                    {
                        YellowTarget[0]=1;
                        YellowTarget[1]=29;
                    }
                    else if (GhostMode=='F')
                    {
                        srand((unsigned int)time(NULL));

                        YellowTarget[0] =  rand()%26;
                        YellowTarget[1] = rand()%29;
                    }
                    if (YellKilledFlag==1)
                    {
                        YellowTarget[0] = 15;
                        YellowTarget[1] = 14;
                    }
                    for  (int i=0;i<4;i++)
                    {
                        if (YellCurDirection[i]!=10000)
                        {
                            switch (i)
                            {
                                case 0:
                                    YellCurDirection[0] = (YellCurXPos - 1 - YellowTarget[0]) * (YellCurXPos - 1 - YellowTarget[0]) + (YellCurYPos - YellowTarget[1]) * (YellCurYPos - YellowTarget[1]);
                                    break;
                                case 1:
                                    YellCurDirection[1] = (YellCurXPos - YellowTarget[0]) * (YellCurXPos - YellowTarget[0]) + (YellCurYPos - 1 - YellowTarget[1]) * (YellCurYPos - 1 - YellowTarget[1]);
                                    break;
                                case 2:
                                    YellCurDirection[2] = (YellCurXPos + 1 - YellowTarget[0]) * (YellCurXPos + 1 - YellowTarget[0]) + (YellCurYPos - YellowTarget[1]) * (YellCurYPos - YellowTarget[1]);
                                    break;
                                case 3:
                                    YellCurDirection[3] = (YellCurXPos - YellowTarget[0]) * (YellCurXPos - YellowTarget[0]) + (YellCurYPos + 1 - YellowTarget[1]) * (YellCurYPos + 1 - YellowTarget[1]);
                                    break;
                            }
                        }
                    }
                    switch(findIndexOfSmallest(YellCurDirection,4))
                    {
                        case 0:
                            YellCurCurDirection=75;
                            break;
                        case 1:
                            YellCurCurDirection=72;
                            break;
                        case 2:
                            YellCurCurDirection=77;
                            break;
                        case 3:
                            YellCurCurDirection=80;
                            break;
                    }
                    if (YellKilledFlag==0 && (clock()-YellKilledTimer)/CLOCKS_PER_SEC==8&&YellKillKillFlag==1)
                    {
                        if (concatenatedString[(11*29+14)*12+7]=='.')
                        {
                            YellWasPellet=1;
                        }
                        else if (concatenatedString[(11*29+14)*12+7]==' ')
                        {
                            YellWasPellet=0;
                        }
                        YellCurXPos=14;
                        YellCurYPos=11;
                        YellCurCurDirection=77;
                        YellKillKillFlag=0;
                    }
                }
            }
            concatenatedString[(RedCurYPos*29+RedCurXPos)*12+7]='A';


            concatenatedString[(PinkCurYPos*29+PinkCurXPos)*12+7]='A';


            concatenatedString[(CyanCurYPos*29+CyanCurXPos)*12+7]='A';


            concatenatedString[(YellCurYPos*29+YellCurXPos)*12+7]='A';

            if (FrightenFlag==1)
            {
                if ((clock()-FrightenTime)/CLOCKS_PER_SEC<=5)
                {
                    concatenatedString[(RedCurYPos*29+RedCurXPos)*12+5]='4';

                    concatenatedString[(PinkCurYPos*29+PinkCurXPos)*12+5]='4';

                    concatenatedString[(CyanCurYPos*29+CyanCurXPos)*12+5]='4';

                    concatenatedString[(YellCurYPos*29+YellCurXPos)*12+5]='4';
                }
                else
                {
                    if ((clock()-FrightenTime)/CLOCKS_PER_SEC%2==0)
                    {
                        concatenatedString[(RedCurYPos*29+RedCurXPos)*12+5]='7';

                        concatenatedString[(PinkCurYPos*29+PinkCurXPos)*12+5]='7';

                        concatenatedString[(CyanCurYPos*29+CyanCurXPos)*12+5]='7';

                        concatenatedString[(YellCurYPos*29+YellCurXPos)*12+5]='7';
                    }
                    else
                    {
                        concatenatedString[(RedCurYPos*29+RedCurXPos)*12+5]='4';

                        concatenatedString[(PinkCurYPos*29+PinkCurXPos)*12+5]='4';

                        concatenatedString[(CyanCurYPos*29+CyanCurXPos)*12+5]='4';

                        concatenatedString[(YellCurYPos*29+YellCurXPos)*12+5]='4';
                    }
                }
            }
            else

            {
                concatenatedString[(RedCurYPos*29+RedCurXPos)*12+5]='1';


                concatenatedString[(PinkCurYPos*29+PinkCurXPos)*12+5]='5';


                concatenatedString[(CyanCurYPos*29+CyanCurXPos)*12+5]='6';


                concatenatedString[(YellCurYPos*29+YellCurXPos)*12+5]='3';
            }

            if (RedKilledFlag==1)
            {
                concatenatedString[(RedCurYPos*29+RedCurXPos)*12+5]='7';
            }
            if (PinkKilledFlag==1)
            {
                concatenatedString[(PinkCurYPos*29+PinkCurXPos)*12+5]='7';
            }
            if (CyanKilledFlag==1)
            {
                concatenatedString[(CyanCurYPos*29+CyanCurXPos)*12+5]='7';
            }
            if (YellKilledFlag==1)
            {
                concatenatedString[(YellCurYPos*29+YellCurXPos)*12+5]='7';
            }
            if ((CurrentXpos==RedCurXPos&&CurrentYpos==RedCurYPos))
            {
                if (GhostMode!='F')
                {
                    gameOver=1;
                    lives-=1;
                }
                else
                {
                    concatenatedString[(RedCurYPos*29+RedCurXPos)*12+7]='A';
                    concatenatedString[(RedCurYPos*29+RedCurXPos)*12+5]='1';
                    RedKilledFlag=1;
                    RedKilledTimer=clock();
                    gameOver=0;
                    score+=200;
                }
            }
            else if ((CurrentXpos==PinkCurXPos&&CurrentYpos==PinkCurYPos))
            {
                if (GhostMode!='F')
                {
                    gameOver=1;
                    lives-=1;
                }
                else
                {
                    concatenatedString[(PinkCurYPos*29+PinkCurXPos)*12+7]='A';
                    concatenatedString[(PinkCurYPos*29+PinkCurXPos)*12+5]='5';
                    PinkKilledFlag=1;
                    PinkKilledTimer=clock();
                    gameOver=0;
                    score+=200;

                }
            }
            else if ((CurrentXpos==CyanCurXPos&&CurrentYpos==CyanCurYPos))
            {
                if (GhostMode!='F')
                {
                    gameOver=1;
                    lives-=1;
                }
                else
                {
                    concatenatedString[(CyanCurYPos*29+CyanCurXPos)*12+7]='A';
                    concatenatedString[(CyanCurYPos*29+CyanCurXPos)*12+5]='6';
                    CyanKilledFlag=1;
                    CyanKilledTimer=clock();
                    gameOver=0;
                    score+=200;
                }
            }
            else if ((CurrentXpos==YellCurXPos&&CurrentYpos==YellCurYPos))
            {
                if (GhostMode!='F')
                {
                    gameOver=1;
                    lives-=1;
                }
                else
                {
                    concatenatedString[(YellCurYPos*29+YellCurXPos)*12+7]='A';
                    concatenatedString[(YellCurYPos*29+YellCurXPos)*12+5]='3';
                    YellKilledFlag=1;
                    YellKilledTimer=clock();
                    gameOver=0;
                    score+=200;
                }
            }

            //upddating pacmans position on screen
            if (gameOver==0)
            {
                if (pucFrame%2==0)
                {
                    if (valMove == 1)
                    {
                        switch (prevAction)
                        {
                            case 75:
                                CurrentXpos -= 1;
                                concatenatedString[(CurrentYpos * 29 + CurrentXpos + 1) * 12 + 7] = ' ';
                                break;

                            case 77:
                                CurrentXpos += 1;
                                concatenatedString[(CurrentYpos * 29 + CurrentXpos - 1) * 12 + 7] = ' ';
                                break;

                            case 80:
                                CurrentYpos += 1;
                                concatenatedString[((CurrentYpos - 1) * 29 + CurrentXpos) * 12 + 7] = ' ';
                                break;

                            case 72:
                                CurrentYpos -= 1;
                                concatenatedString[((CurrentYpos + 1) * 29 + CurrentXpos) * 12 + 7] = ' ';
                                break;
                        }
                    }
                    if (CurrentXpos==-1)
                    {
                        CurrentXpos=27;
                    }
                    else if (CurrentXpos==28)
                    {
                        CurrentXpos=0;
                    }
                    if (concatenatedString[((CurrentYpos)*29+CurrentXpos)*12+7]=='.')
                    {
                        score+=10;
                        pelletEaten+=1;
                    }

                    if (concatenatedString[((CurrentYpos)*29+CurrentXpos)*12+7]=='*')
                    {
                        score+=50;
                        pelletEaten+=1;
                        FrightenFlag=1;
                        FrightenTime=clock();
                    }
                    concatenatedString[(CurrentYpos*29+CurrentXpos)*12+5]='3';
                    concatenatedString[(CurrentYpos*29+CurrentXpos)*12+7]='@';
                }
            }

            if (pelletEaten>=285)
            {
                gameWon=1;
                for (int i=0;i<29;i++)
                {
                    for (int j=0;j<31;j++)
                    {
                        if (concatenatedString[(j*29+i)*12+7]=='.')
                        {
                            gameWon=0;
                        }
                    }
                }
            }

            if (thingamabob==1||score>=highestScore)
            {
                highestScore=score;
            }
            //
            //printing the current game board
            TimeTime = (clock()- GameStartTime)/CLOCKS_PER_SEC;
            system("cls");
            printf("level:%d\n",level);
            printf("score:%d lives:%d highscore:%d\n",score,lives,highestScore);
            printf("pellet consumed:%d\n",pelletEaten);
            printf("Game state:%d\n",gameWon);
            printf("Time:%d\n",TimeTime);
            printf("Ghost Mode:%c\n",GhostMode);;
            printf("Fright timer:%d\n",(clock()-FrightenTime)/CLOCKS_PER_SEC);
            printf("%s",concatenatedString);
            Sleep(30);
        }
        char Message[]={'G','A','M','E','O','V','E','R'};
        char Message2[]={'C','O','N','T','I','N','U','E','?'};
        char Message3[]={'(','Y','/','N',')'};

        if (gameOver==1 && lives==0)
        {
            if ((CurrentXpos==RedCurXPos&&CurrentYpos==RedCurYPos))
            {

                concatenatedString[(RedCurYPos*29+RedCurXPos)*12+7]='A';
                concatenatedString[(RedCurYPos*29+RedCurXPos)*12+5]='1';
            }
            else if ((CurrentXpos==PinkCurXPos&&CurrentYpos==PinkCurYPos))
            {

                concatenatedString[(PinkCurYPos*29+PinkCurXPos)*12+7]='A';
                concatenatedString[(PinkCurYPos*29+PinkCurXPos)*12+5]='5';
            }
            else if ((CurrentXpos==CyanCurXPos&&CurrentYpos==CyanCurYPos))
            {
                concatenatedString[(CyanCurYPos*29+CyanCurXPos)*12+7]='A';
                concatenatedString[(CyanCurYPos*29+CyanCurXPos)*12+5]='6';
            }
            else if ((CurrentXpos==YellCurXPos&&CurrentYpos==YellCurYPos))
            {
                concatenatedString[(YellCurYPos*29+YellCurXPos)*12+7]='A';
                concatenatedString[(YellCurYPos*29+YellCurXPos)*12+5]='3';
            }
            system("cls");
            printf("level:%d\n",level);
            printf("score:%d lives:%d highscore:%d\n",score,lives,highestScore);
            printf("pellet consumed:%d\n",pelletEaten);
            printf("Game state:%d\n",gameWon);
            printf("%s",concatenatedString);
            Sleep(1000);
            for (int i=0;i<4;i++)
            {
                concatenatedString[(13*29+12+i)*12+5]='1';
                concatenatedString[(13*29+12+i)*12+7]=Message[i];
            }
            for (int i=4;i<8;i++)
            {
                concatenatedString[(14*29+12+i-4)*12+5]='1';
                concatenatedString[(14*29+12+i-4)*12+7]=Message[i];
            }
            system("cls");
            printf("level:%d\n",level);
            printf("score:%d lives:%d highscore:%d\n",score,lives,highestScore);
            printf("pellet consumed:%d\n",pelletEaten);
            printf("Game state:%d\n",gameWon);
            printf("%s",concatenatedString);
            Sleep(1000);
            for (int i=0;i<9;i++)
            {
                concatenatedString[(15*29+12+i-2)*12+5]='1';
                concatenatedString[(15*29+12+i-2)*12+7]=Message2[i];
            }
            system("cls");
            printf("level:%d\n",level);
            printf("score:%d lives:%d highscore:%d\n",score,lives,highestScore);
            printf("pellet consumed:%d\n",pelletEaten);
            printf("Game state:%d\n",gameWon);
            printf("%s",concatenatedString);
            Sleep(1000);
            for (int i=0;i<5;i++)
            {
                concatenatedString[(16*29+12+i)*12+5]='1';
                concatenatedString[(16*29+12+i)*12+7]=Message3[i];
            }
            system("cls");
            printf("level:%d\n",level);
            printf("score:%d lives:%d highscore:%d\n",score,lives,highestScore);
            printf("pellet consumed:%d\n",pelletEaten);
            printf("Game state:%d\n",gameWon);
            printf("%s",concatenatedString);

            while (1)
            {
                Continuee = _getch();
                if (Continuee=='Y'||Continuee=='y')
                {
                    ContinueeFlag=1;
                    thingamabob++;
                    break;
                }
                else if (Continuee=='N'||Continuee=='n')
                {
                    break;
                }
                else
                {
                    //loop
                }
            }
        }

        if (gameOver==1 && lives!=0)
        {
            if ((CurrentXpos==RedCurXPos&&CurrentYpos==RedCurYPos))
            {

                concatenatedString[(RedCurYPos*29+RedCurXPos)*12+7]='A';
                concatenatedString[(RedCurYPos*29+RedCurXPos)*12+5]='1';
            }
            else if ((CurrentXpos==PinkCurXPos&&CurrentYpos==PinkCurYPos))
            {

                concatenatedString[(PinkCurYPos*29+PinkCurXPos)*12+7]='A';
                concatenatedString[(PinkCurYPos*29+PinkCurXPos)*12+5]='5';
            }
            else if ((CurrentXpos==CyanCurXPos&&CurrentYpos==CyanCurYPos))
            {
                concatenatedString[(CyanCurYPos*29+CyanCurXPos)*12+7]='A';
                concatenatedString[(CyanCurYPos*29+CyanCurXPos)*12+5]='6';
            }
            else if ((CurrentXpos==YellCurXPos&&CurrentYpos==YellCurYPos))
            {
                concatenatedString[(YellCurYPos*29+YellCurXPos)*12+7]='A';
                concatenatedString[(YellCurYPos*29+YellCurXPos)*12+5]='3';
            }
            char MMessage5[] = {'Y','O','U'};
            char MMessage6[] = {'D','I','E','D'};
            char MMessage7[] = {'L','I','V','E','S',':'};
            for (int i=0;i<3;i++)
            {
                concatenatedString[(13*29+12+i-1)*12+5]='1';
                concatenatedString[(13*29+12+i-1)*12+7]=MMessage5[i];
            }
            for (int i=0;i<4;i++)
            {
                concatenatedString[(14*29+12+i-1)*12+5]='1';
                concatenatedString[(14*29+12+i-1)*12+7]=MMessage6[i];
            }
            system("cls");
            printf("level:%d\n",level);
            printf("score:%d lives:%d highscore:%d\n",score,lives,highestScore);
            printf("pellet consumed:%d\n",pelletEaten);
            printf("Game state:%d\n",gameWon);
            printf("%s",concatenatedString);
            Sleep(1000);
            for (int i=0;i<6;i++)
            {
                concatenatedString[(15*29+12+i-1)*12+5]='1';
                concatenatedString[(15*29+12+i-1)*12+7]=MMessage7[i];
            }
            if (lives==2)
            {
                concatenatedString[(15*29+12+6-1)*12+5]='1';
                concatenatedString[(15*29+12+6-1)*12+7]='2';
            }
            else if (lives==1)
            {
                concatenatedString[(15*29+12+6-1)*12+5]='1';
                concatenatedString[(15*29+12+6-1)*12+7]='1';
            }
            system("cls");
            printf("level:%d\n",level);
            printf("score:%d lives:%d highscore:%d\n",score,lives,highestScore);
            printf("pellet consumed:%d\n",pelletEaten);
            printf("Game state:%d\n",gameWon);
            printf("%s",concatenatedString);
            Sleep(2000);
            gameOver=0;
        }

        char Message4[] = {'L','E','V','E','L','C','L','E','A','R','E','D'};
        char Message5[] = {'N','E','X','T','L','E','V','E','L','I','N',':'};

        if (gameWon==1)
        {
            system("cls");
            printf("level:%d\n",level);
            printf("score:%d lives:%d highscore:%d\n",score,lives,highestScore);
            printf("pellet consumed:%d\n",pelletEaten);
            printf("Game state:%d\n",gameWon);
            printf("%s",concatenatedString);
            Sleep(1000);
            for (int i=0;i<5;i++)
            {
                concatenatedString[(13*29+12+i-1)*12+5]='2';
                concatenatedString[(13*29+12+i-1)*12+7]=Message4[i];
            }
            for (int i=5;i<=11;i++)
            {
                concatenatedString[(14*29+12+i-6)*12+5]='2';
                concatenatedString[(14*29+12+i-6)*12+7]=Message4[i];
            }
            system("cls");
            printf("level:%d\n",level);
            printf("score:%d lives:%d highscore:%d\n",score,lives,highestScore);
            printf("pellet consumed:%d\n",pelletEaten);
            printf("Game state:%d\n",gameWon);
            printf("%s",concatenatedString);
            Sleep(1000);
            concatenatedString[(14*29+17)*12+5]='4';
            concatenatedString[(14*29+17)*12+7]='O';

            for (int i=11;i<=16;i++)
            {
                for (int j=13;j<=15;j++)
                {
                    concatenatedString[(j*29+i)*12+7]=' ';
                }
            }
            for (int i=0;i<4;i++)
            {
                concatenatedString[(13*29+12+i-1)*12+5]='2';
                concatenatedString[(13*29+12+i-1)*12+7]=Message5[i];
            }
            for (int i=4;i<=8;i++)
            {
                concatenatedString[(14*29+12+i-4-1)*12+5]='2';
                concatenatedString[(14*29+12+i-4-1)*12+7]=Message5[i];
            }
            for (int i=9;i<12;i++)
            {
                concatenatedString[(15*29+12+i-9-1)*12+5]='2';
                concatenatedString[(15*29+12+i-9-1)*12+7]=Message5[i];
            }
            concatenatedString[(15*29+14)*12+5]='2';
            concatenatedString[(15*29+14)*12+7]='5';
            system("cls");
            printf("level:%d\n",level);
            printf("score:%d lives:%d highscore:%d\n",score,lives,highestScore);
            printf("pellet consumed:%d\n",pelletEaten);
            printf("Game state:%d\n",gameWon);
            printf("%s",concatenatedString);
            Sleep(1000);
            concatenatedString[(15*29+14)*12+5]='2';
            concatenatedString[(15*29+14)*12+7]='4';
            system("cls");
            printf("level:%d\n",level);
            printf("score:%d lives:%d highscore:%d\n",score,lives,highestScore);
            printf("pellet consumed:%d\n",pelletEaten);
            printf("Game state:%d\n",gameWon);
            printf("%s",concatenatedString);
            Sleep(1000);
            concatenatedString[(15*29+14)*12+5]='2';
            concatenatedString[(15*29+14)*12+7]='3';
            system("cls");
            printf("level:%d\n",level);
            printf("score:%d lives:%d highscore:%d\n",score,lives,highestScore);
            printf("pellet consumed:%d\n",pelletEaten);
            printf("Game state:%d\n",gameWon);
            printf("%s",concatenatedString);
            Sleep(1000);
            concatenatedString[(15*29+14)*12+5]='2';
            concatenatedString[(15*29+14)*12+7]='2';
            system("cls");
            printf("level:%d\n",level);
            printf("score:%d lives:%d highscore:%d\n",score,lives,highestScore);
            printf("pellet consumed:%d\n",pelletEaten);
            printf("Game state:%d\n",gameWon);
            printf("%s",concatenatedString);
            Sleep(1000);
            concatenatedString[(15*29+14)*12+5]='2';
            concatenatedString[(15*29+14)*12+7]='1';
            system("cls");
            printf("level:%d\n",level);
            printf("score:%d lives:%d highscore:%d\n",score,lives,highestScore);
            printf("pellet consumed:%d\n",pelletEaten);
            printf("Game state:%d\n",gameWon);
            printf("%s",concatenatedString);
            Sleep(1000);
            concatenatedString[(15*29+14)*12+5]='2';
            concatenatedString[(15*29+14)*12+7]='0';
            system("cls");
            printf("level:%d\n",level);
            printf("score:%d lives:%d highscore:%d\n",score,lives,highestScore);
            printf("pellet consumed:%d\n",pelletEaten);
            printf("Game state:%d\n",gameWon);
            printf("%s",concatenatedString);
            Sleep(1000);
            level++;
            gameWon=0;
        }
    }

    return 0;
}
