#include <stdio.h>
void displaygrid() {
    int i,j,grid[3][3]= {{1,2,3},{4,5,6},{7,8,9}};
    printf("Enter Number of Corresponding box you want to mark\n");
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            printf("%d\t",grid[i][j]);
        }
        printf("\n");
    }
}
void updategrid(char grid[3][3]) {
    int i,j;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            printf("%c\t",grid[i][j]);
        }
        printf("\n\n");
    }
    printf("\n");
}
int markgrid(char grid[3][3],int input,int player) {
    if(input==1) {
        if(player==1) {
            if(grid[0][0]!='O' && grid[0][0]!='X') {
                grid[0][0]='X';
                return 1;
            }
        }
        else {
            if(grid[0][0]!='O' && grid[0][0]!='X') {
                grid[0][0]='O';
                return 1;
            }
        }
    }
    else if(input==2) {
        if(player==1) {
            if(grid[0][1]!='O' && grid[0][1]!='X') {
                grid[0][1]='X';
                return 1;
            }
        }
        else {
            if(grid[0][1]!='O' && grid[0][1]!='X') {
                grid[0][1]='O';
                return 1;
            }
        }
    }
    else if(input==3) {
        if(player==1) {
            if(grid[0][2]!='O' && grid[0][2]!='X') {
                grid[0][2]='X';
                return 1;
            }
        }
        else {
            if(grid[0][2]!='O' && grid[0][2]!='X') {
                grid[0][2]='O';
                return 1;
            }
        }
    }
    else if(input==4) {
        if(player==1) {
            if(grid[1][0]!='O' && grid[1][0]!='X') {
                grid[1][0]='X';
                return 1;
            }
        }
        else {
            if(grid[1][0]!='O' && grid[1][0]!='X') {
                grid[1][0]='O';
                return 1;
            }
        }
    }
    else if(input==5) {
        if(player==1) {
            if(grid[1][1]!='O' && grid[1][1]!='X') {
                grid[1][1]='X';
                return 1;
            }
        }
        else {
            if(grid[1][1]!='O' && grid[1][1]!='X') {
                grid[1][1]='O';
                return 1;
            }
        }
    }
    else if(input==6) {
        if(player==1) {
            if(grid[1][2]!='O' && grid[1][2]!='X') {
                grid[1][2]='X';
                return 1;
            }
        }
        else {
            if(grid[1][2]!='O' && grid[1][2]!='X') {
                grid[1][2]='O';
                return 1;
            }
        }
    }
    else if(input==7) {
        if(player==1) {
            if(grid[2][0]!='O' && grid[2][0]!='X') {
                grid[2][0]='X';
                return 1;
            }
        }
        else {
            if(grid[2][0]!='O' && grid[2][0]!='X') {
                grid[2][0]='O';
                return 1;
            }
        }
    }
    else if(input==8) {
        if(player==1) {
            if(grid[2][1]!='O' && grid[2][1]!='X') {
                grid[2][1]='X';
                return 1;
            }
        }
        else {
            if(grid[2][1]!='O' && grid[2][1]!='X') {
                grid[2][1]='O';
                return 1;
            }
        }
    }
    else if(input==9) {
        if(player==1) {
            if(grid[2][2]!='O' && grid[2][2]!='X') {
                grid[2][2]='X';
                return 1;
            }
        }
        else {
            if(grid[2][2]!='O' && grid[2][2]!='X') {
                grid[2][2]='O';
                return 1;
            }
        }
    }
    return 0;
}
int gameWon(char grid[3][3]) {
    if(grid[0][0]=='X' && grid[0][1]=='X' && grid[0][2]=='X') {
        return 1;
    }
    else if(grid[1][0]=='X' && grid[1][1]=='X' && grid[1][2]=='X') {
        return 1;
    }
    else if(grid[2][0]=='X' && grid[2][1]=='X' && grid[2][2]=='X') {
        return 1;
    }
    else if(grid[0][0]=='X' && grid[1][0]=='X' && grid[2][0]=='X') {
        return 1;
    }
    else if(grid[0][1]=='X' && grid[1][1]=='X' && grid[2][1]=='X') {
        return 1;
    }
    else if(grid[0][2]=='X' && grid[1][2]=='X' && grid[2][2]=='X') {
        return 1;
    }
    else if(grid[0][0]=='X' && grid[1][1]=='X' && grid[2][2]=='X') {
        return 1;
    }
    else if(grid[0][2]=='X' && grid[1][1]=='X' && grid[2][0]=='X') {
        return 1;
    }
    else {
        if(grid[0][0]=='O' && grid[0][1]=='O' && grid[0][2]=='O') {
            return 2;
        }
        else if(grid[1][0]=='O' && grid[1][1]=='O' && grid[1][2]=='O') {
            return 2;
        }
        else if(grid[2][0]=='O' && grid[2][1]=='O' && grid[2][2]=='O') {
            return 2;
        }
        else if(grid[0][0]=='O' && grid[1][0]=='O' && grid[2][0]=='O') {
            return 2;
        }
        else if(grid[0][1]=='O' && grid[1][1]=='O' && grid[2][1]=='O') {
            return 2;
        }
        else if(grid[0][2]=='O' && grid[1][2]=='O' && grid[2][2]=='O') {
            return 2;
        }
        else if(grid[0][0]=='O' && grid[1][1]=='O' && grid[2][2]=='O') {
            return 2;
        }
        else if(grid[0][2]=='O' && grid[1][1]=='O' && grid[2][0]=='O') {
            return 2;
        }
        else {
            return 3;
        }
    }
}
void takeInput() {
    int i=0,gamewon=0,input,turns=0;
    char grid[4][3]= {{'_','_','_'},{'_','_','_'},{'_','_','_'}};
    displaygrid();
    sleep(2);
    while(turns<9) {
        system("clear");
        displaygrid();
        printf("\n\n");
        updategrid(grid);
        printf("Player %d's turn\nEnter where you want to mark:",i+1);
        scanf("%d",&input);
        if(input>0 && input<10) {
            if(markgrid(grid,input,i+1)==1) {
                i=!(i);
                turns=turns+1;
                gamewon=gameWon(grid);
                if(gamewon==1 || gamewon==2) {
                    break;
                }
            }
        }
        else {
            printf("Wrong Input\n");
            sleep(2);
            continue;
        }

    }
    system("clear");
    if(gamewon==1) {
        updategrid(grid);
        printf("Player 1 won");
    }
    else if(gamewon==2) {
        updategrid(grid);
        printf("Player 2 won");
    }
    else {
        updategrid(grid);
        printf("It was a Draw");
    }
}
int main() {
    takeInput();
}