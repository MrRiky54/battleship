#include <stdio.h>
#include <stdlib.h>

void main(){
    //VARIABLE DECLARATION
    char tabA[10][10];
    char tabAShot[10][10];
    int cTypeA[5]={0,4,3,2,1};
    int cTryA[5]={0,1,1,1,1};
    char tabB[10][10];
    char tabBShot[10][10];
    int cTypeB[5]={0,4,3,2,1};
    int cTryB[5]={0,1,1,1,1};
    int l, i, ver, hor, type, dir, unpossible = 0, temp = 0, sum = 0, sumTry, action=0, sumA, sumB;
    //ALLOCATION OF '-' IN THE ARRAYS
    for(i=0;i<10;i++){
        for(l=0;l<10;l++){
            tabA[i][l] = '-';
            tabB[i][l] = '-';
            tabAShot[i][l] = '-';
            tabBShot[i][l] = '-';
        }
    }
    //INTRODUCTION
    printf("\n      +++ Battleship +++      \n\n");
    printf("Version:  1.0\n");
    printf("Made By:  Riccardo Carissimi\n\n");
    sleep(1);
    //PLAYER ONE POSITIONING
    do{
        //TABLE DISPLAY
        printf("       PLAYER 1\n\n");
        printf("  0 1 2 3 4 5 6 7 8 9\n");
        for(i=0;i<10;i++){
            printf("%d %c %c %c %c %c %c %c %c %c %c\n",i,tabA[i][0],tabA[i][1],tabA[i][2],tabA[i][3],tabA[i][4],tabA[i][5],tabA[i][6],tabA[i][7],tabA[i][8],tabA[i][9]);
        }
        //CHOOSING AND POSITIONING THE SHIPS
        sum = 0;
        for(i=0;i<5;i++){
            sum = sum + cTypeA[i];
        }
        if(sum!=0){
            printf("\n\n> POSITION THE SHIP\n");
            do{
                printf("> Vertical: ");
                scanf("%d",&ver);
                if(ver>10||ver<0){
                    printf("[!] Error! Choose a Value Between 1 and 10\n");
                }
            }while(ver>10||ver<0);
            do{
                printf("> Horizontal: ");
                scanf("%d",&hor);
                if(hor>10||hor<0){
                    printf("[!] Error! Choose a Value Between 1 and 10\n");
                }
            }while(hor>10||hor<0);
            do{
                printf("> Type: \n");
                if(cTypeA[1]!=0){
                    printf("[1] o\n");
                }
                if(cTypeA[2]!=0){
                    printf("[2] oo\n");
                }
                if(cTypeA[3]!=0){
                    printf("[3] ooo\n");
                }
                if(cTypeA[4]!=0){
                    printf("[4] oooo\n");
                }
                scanf("%d",&type);
                if(type<0||type>4||cTypeA[type]==0){
                    printf("[!] Error! Choose a Valid Value\n");
                }
            }while(type<0||type>4||cTypeA[type]==0);
            do{
                do{
                    printf("> Orientation:\n");
                    printf("[1] North\n");
                    printf("[2] Est\n");
                    printf("[3] South\n");
                    printf("[4] West\n");
                    scanf("%d",&dir);
                    if(dir<0||dir>4){
                        printf("[!] Error! Choose a Valid Value\n");
                    }
                }while(dir<0||dir>4);
                switch(dir){
                    case 1:
                        for(i=0;i<type;i++){
                            temp=ver;
                            temp--;
                            if(tabA[ver][hor]!='-'){
                                unpossible = 1;
                                cTryA[dir]=0;
                            }
                        }
                        break;
                    case 2:
                        for(i=0;i<type;i++){
                            temp=hor;
                            temp++;
                            if(tabA[ver][hor]!='-'){
                                unpossible = 1;
                                cTryA[dir]=0;
                            }
                        }
                        break;
                    case 3:
                        for(i=0;i<type;i++){
                            temp=ver;
                            temp++;
                            if(tabA[ver][hor]!='-'){
                                unpossible = 1;
                                cTryA[dir]=0;
                            }
                        }
                        break;
                    case 4:
                        for(i=0;i<type;i++){
                            temp=hor;
                            temp--;
                            if(tabA[ver][hor]!='-'){
                                unpossible = 1;
                                cTryA[dir]=0;
                            }
                        }
                        break;
                }
                sumTry=0;
                for(i=0;i<5;i++){
                    sumTry=sumTry+cTryA[i];
                }
            }while(unpossible!=0&&sumTry!=0);
            if(sumTry!=0){
                cTypeA[type]--;
                switch(dir){
                    case 1:
                        ver++;
                        for(i=0;i<type;i++){
                            ver--;
                            tabA[ver][hor]='o';
                        }
                        break;
                    case 2:
                        hor--;
                        for(i=0;i<type;i++){
                            hor++;
                            tabA[ver][hor]='o';
                        }
                        break;
                    case 3:
                        ver--;
                        for(i=0;i<type;i++){
                            ver++;
                            tabA[ver][hor]='o';
                        }
                        break;
                    case 4:
                        hor++;
                        for(i=0;i<type;i++){
                            hor--;
                            tabA[ver][hor]='o';
                        }
                        break;
                }
            }
        }
        //CLEARING THE SCREEN
        system("cls");
    }while(sum!=0);

    //PLAYER TWO POSITIONING
    do{
        //TABLE DISPLAY
        printf("       PLAYER 2\n\n");
        printf("  0 1 2 3 4 5 6 7 8 9\n");
        for(i=0;i<10;i++){
            printf("%d %c %c %c %c %c %c %c %c %c %c\n",i,tabB[i][0],tabB[i][1],tabB[i][2],tabB[i][3],tabB[i][4],tabB[i][5],tabB[i][6],tabB[i][7],tabB[i][8],tabB[i][9]);
        }
        //CHOOSING AND POSITIONING THE SHIPS
        sum = 0;
        for(i=0;i<5;i++){
            sum = sum + cTypeB[i];
        }
        if(sum!=0){
            printf("\n\n> POSITION THE SHIP\n");
            do{
                printf("> Vertical: ");
                scanf("%d",&ver);
                if(ver>10||ver<0){
                    printf("[!] Error! Choose a Value Between 1 and 10\n");
                }
            }while(ver>10||ver<0);
            do{
                printf("> Horizontal: ");
                scanf("%d",&hor);
                if(hor>10||hor<0){
                    printf("[!] Error! Choose a Value Between 1 and 10\n");
                }
            }while(hor>10||hor<0);
            do{
                printf("> Type: \n");
                if(cTypeB[1]!=0){
                    printf("[1] o\n");
                }
                if(cTypeB[2]!=0){
                    printf("[2] oo\n");
                }
                if(cTypeB[3]!=0){
                    printf("[3] ooo\n");
                }
                if(cTypeB[4]!=0){
                    printf("[4] oooo\n");
                }
                scanf("%d",&type);
                if(type<0||type>4||cTypeB[type]==0){
                    printf("[!] Error! Choose a Valid Value\n");
                }
            }while(type<0||type>4||cTypeB[type]==0);
            do{
                do{
                    printf("> Orientation:\n");
                    printf("[1] North\n");
                    printf("[2] Est\n");
                    printf("[3] South\n");
                    printf("[4] West\n");
                    scanf("%d",&dir);
                    if(dir<0||dir>4){
                        printf("[!] Error! Choose a Valid Value\n");
                    }
                }while(dir<0||dir>4);
                switch(dir){
                    case 1:
                        for(i=0;i<type;i++){
                            temp=ver;
                            temp--;
                            if(tabB[ver][hor]!='-'){
                                unpossible = 1;
                                cTryB[dir]=0;
                            }
                        }
                        break;
                    case 2:
                        for(i=0;i<type;i++){
                            temp=hor;
                            temp++;
                            if(tabB[ver][hor]!='-'){
                                unpossible = 1;
                                cTryB[dir]=0;
                            }
                        }
                        break;
                    case 3:
                        for(i=0;i<type;i++){
                            temp=ver;
                            temp++;
                            if(tabB[ver][hor]!='-'){
                                unpossible = 1;
                                cTryB[dir]=0;
                            }
                        }
                        break;
                    case 4:
                        for(i=0;i<type;i++){
                            temp=hor;
                            temp--;
                            if(tabB[ver][hor]!='-'){
                                unpossible = 1;
                                cTryB[dir]=0;
                            }
                        }
                        break;
                }
                sumTry=0;
                for(i=0;i<5;i++){
                    sumTry=sumTry+cTryB[i];
                }
            }while(unpossible!=0&&sumTry!=0);
            if(sumTry!=0){
                cTypeB[type]--;
                switch(dir){
                    case 1:
                        ver++;
                        for(i=0;i<type;i++){
                            ver--;
                            tabB[ver][hor]='o';
                        }
                        break;
                    case 2:
                        hor--;
                        for(i=0;i<type;i++){
                            hor++;
                            tabB[ver][hor]='o';
                        }
                        break;
                    case 3:
                        ver--;
                        for(i=0;i<type;i++){
                            ver++;
                            tabB[ver][hor]='o';
                        }
                        break;
                    case 4:
                        hor++;
                        for(i=0;i<type;i++){
                            hor--;
                            tabB[ver][hor]='o';
                        }
                        break;
                }
            }
        }
        //CLEARING SCREEN
        system("cls");
    }while(sum!=0);

    //GAME START
    do{
        //PLAYER ONE MATCH
        do{
            do{
                //SHOTS MAP
                printf("       PLAYER 1\n\n");
                printf("  0 1 2 3 4 5 6 7 8 9\n");
                for(i=0;i<10;i++){
                    printf("%d %c %c %c %c %c %c %c %c %c %c\n",i,tabAShot[i][0],tabAShot[i][1],tabAShot[i][2],tabAShot[i][3],tabAShot[i][4],tabAShot[i][5],tabAShot[i][6],tabAShot[i][7],tabAShot[i][8],tabAShot[i][9]);
                }
                printf("\n");
                printf("[1] Attack\n");
                printf("[2] See Map\n");
                printf("[0] Exit\n");
                scanf("%d",&action);
                if(action<0||action>2){
                    printf("[!] Error! Choose a Valid Value\n");
                }
            }while(action<0||action>2);
            if(action!=0){
                switch(action){
                    case 1:
                        //ATTACK
                            //POSITION CHOOSER
                            printf("> Where Do You Want to Attack?\n");
                            do{
                                printf("> Vertical: ");
                                scanf("%d",&ver);
                                if(ver>10||ver<0){
                                    printf("[!] Error! Choose a Value Between 1 and 10\n");
                                }
                            }while(ver>10||ver<0);
                            do{
                                printf("> Horizontal: ");
                                scanf("%d",&hor);
                                if(hor>10||hor<0){
                                    printf("[!] Error! Choose a Value Between 1 and 10\n");
                                }
                            }while(hor>10||hor<0);
                            if(tabAShot[ver][hor]!='X'&&tabAShot[ver][hor]!='/'){ //CONTROLLING IF THE PLAYER HAS ALREADY SHOT THERE
                                action=0;
                                if(tabB[ver][hor]=='o'){
                                    printf("> HIT!\n");
                                    tabAShot[ver][hor]='X';
                                    tabB[ver][hor]='X';
                                }else{
                                    printf("> MISSED...\n");
                                    tabAShot[ver][hor]='/';
                                }
                                sleep(2);
                            }else{
                                printf("[!] Error! You Have Already Attacked There\n");
                            }
                        break;
                    case 2:
                        //MAP VISUALIZER
                        printf("  0 1 2 3 4 5 6 7 8 9\n");
                        for(i=0;i<10;i++){
                            printf("%d %c %c %c %c %c %c %c %c %c %c\n",i,tabA[i][0],tabA[i][1],tabA[i][2],tabA[i][3],tabA[i][4],tabA[i][5],tabA[i][6],tabA[i][7],tabA[i][8],tabA[i][9]);
                        }
                        sleep(5);
                        break;
                }
            }
            //CLEARING SCREEN
            system("cls");
        }while(action!=0);

        sumB=0;
        for(i=0;i<10;i++){
            for(l=0;l<10;l++){
                if(tabB[i][l]=='o'){
                    sumB++;
                }
            }
        }
        if(sumB!=0){
            //PLAYER TWO MATCH
            do{
                do{
                    //SHOT MAP
                    printf("       PLAYER 2\n\n");
                    printf("  0 1 2 3 4 5 6 7 8 9\n");
                    for(i=0;i<10;i++){
                        printf("%d %c %c %c %c %c %c %c %c %c %c\n",i,tabBShot[i][0],tabBShot[i][1],tabBShot[i][2],tabBShot[i][3],tabBShot[i][4],tabBShot[i][5],tabBShot[i][6],tabBShot[i][7],tabBShot[i][8],tabBShot[i][9]);
                    }
                    printf("\n");
                    printf("[1] Attack\n");
                    printf("[2] See Map\n");
                    printf("[0] Exit\n");
                    scanf("%d",&action);
                    if(action<0||action>2){
                        printf("[!] Error! Choose a Valid Value\n");
                    }
                }while(action<0||action>2);
                if(action!=0){
                    switch(action){
                        case 1:
                            //ATTACK
                                //POSITION CHOOSER
                                printf("> Where Do You Want to Attack?\n");
                                do{
                                    printf("> Vertical: ");
                                    scanf("%d",&ver);
                                    if(ver>10||ver<0){
                                        printf("[!] Error! Choose a Value Between 1 and 10\n");
                                    }
                                }while(ver>10||ver<0);
                                do{
                                    printf("> Horizontal: ");
                                    scanf("%d",&hor);
                                    if(hor>10||hor<0){
                                        printf("[!] Error! Choose a Value Between 1 and 10\n");
                                    }
                                }while(hor>10||hor<0);
                                if(tabBShot[ver][hor]!='X'&&tabBShot[ver][hor]!='/'){ //CONTROLLING IF THE PLAYER HAS ALREADY SHOT THERE
                                    action=0;
                                    if(tabA[ver][hor]=='o'){
                                        printf("> HIT!\n");
                                        tabBShot[ver][hor]='X';
                                        tabA[ver][hor]='X';
                                    }else{
                                        printf("> MISSED...\n");
                                        tabBShot[ver][hor]='/';
                                    }
                                    sleep(2);
                                }else{
                                    printf("[!] Error! You Have Already Attacked There\n");
                                }
                            break;
                        case 2:
                            //MAP VISUALIZER
                            printf("  0 1 2 3 4 5 6 7 8 9\n");
                            for(i=0;i<10;i++){
                                printf("%d %c %c %c %c %c %c %c %c %c %c\n",i,tabB[i][0],tabB[i][1],tabB[i][2],tabB[i][3],tabB[i][4],tabB[i][5],tabB[i][6],tabB[i][7],tabB[i][8],tabB[i][9]);
                            }
                            sleep(5);
                            break;
                    }
                }
                //CLEARING SCREEN
                system("cls");
            }while(action!=0);
        }
        sumA=0;
        for(i=0;i<10;i++){
            for(l=0;l<10;l++){
                if(tabA[i][l]=='o'){
                    sumA++;
                }
            }
        }
    }while(sumA!=0&&sumB!=0);
    printf("> GAME FINISHED!\n");
    if(sumB==0){
        printf("> PLAYER 1 WON\n\n\n");
    }else{
        if(sumA==0){
            printf("> PLAYER 2 WON\n\n\n");
        }
    }
}
