#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct players {
    char name[20],word[30],noun[8];
    int lives,wins;
};
void convertToUpperCase(char *str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        str[i] = toupper(str[i]);
    }
}
void displayword(struct players *player) {
    int i,j;
    printf("Lives:");
    for(i=0; i<player->lives; i++) {
        printf("❤️ ");
    }
    printf("\n");
    printf("Word type: %s\n",player->noun);
    for(i=0; i<strlen(player->word); i++) {
        if(player->lives>0) {
            if(player->word==' '){
                printf(" %c",player->word[i]);
            }
            else{
                printf("_ ");
            }
        }
        else {
            printf(" %c",player->word[i]);
        }
    }
    printf("\n");
}
void clearScreen() {
    system("clear"); // For Unix/Linux-based systems
    // For Windows, use: system("cls");
}
int strchar(char word[],char target) {
    int i,found=0;
    for(i=0; i<strlen(word); i++) {
        if(word[i]==target) {
            found=1;
            break;
        }
    }
    if(found==1) {
        return i;
    }
    else {
        return -1;
    }
}
void updateword(struct players *player,char guess[]) {
    int i,incomplete=0;
    clearScreen();
    printf("Lives:");
    for(i=0; i<player->lives; i++) {
        printf("❤️ ");
    }
    printf("\n");
    printf("Word Type: %s\n",player->noun);
    for (i = 0; i < strlen(player->word); i++) {
        if (strchar(guess, player->word[i]) >= 0 || player->word[i]==' ') {
            printf("%c ", player->word[i]);
        } else {
            printf("_ ");
            incomplete=1;
        }
    }
    printf("\n");
    if(incomplete==0) {
        player->lives=0;
        player->wins=player->wins+1;
        printf("Congratulations 🎉🎉 %s You guessed the word \"%s\" correct\n", player->name, player->word);
        sleep(2);
        }
    else if(player->lives==0){
        printf("Sorry %s You couldnt guess the word \"%s\"\n",player->name,player->word);
        sleep(2);
    }
}
void guess(struct players *player) {
    char wordguess[30],correctguess[15]= {0};
    int i;
    int j=0;
    while(player->lives>0) {
        printf("Guess Character/Word:");
        gets(wordguess);
        convertToUpperCase(&wordguess);
        if (strlen(wordguess) > 1) {
            if (strcmp(wordguess, player->word) == 0) {
                printf("Congratulations 🎉🎉 %s You guessed the word \"%s\" correct\n", player->name, player->word);
                sleep(2);
                player->wins = player->wins + 1;
                player->lives = 0;
                break;
            } else {
                printf("Sorry %s You couldnt guess the word \"%s\"\n",player->name,player->word);
                sleep(2);
                player->lives = 0;
                break;
            }
        }
        else {
            if(strchar(correctguess,wordguess[0])>=0) {
                printf("You already guessed this character \n");
            }
            else if (strchar(player->word, wordguess[0]) >= 0) {
                correctguess[j]=wordguess[0];
                j++;
                updateword(player, correctguess);
            } else {
                player->lives = player->lives - 1;
                updateword(player, correctguess);
            }
        }
    }
}
void initialiseGame() {
    struct players player[2];
    int i=0;
    printf("Enter Name Player1: ");
    gets(player[0].name);
    printf("Enter Name Player2: ");
    gets(player[1].name);
    sleep(2);
    player[0].wins=0;
    player[1].wins=0;
    while(player[1].wins<3 && player[0].wins<3) {
        clearScreen();
        printf("%s's turn to guess:\n",player[i].name);
        printf("Enter Type of Word(Name,Place,Thing,Animal): ");
        gets(player[i].noun);
        convertToUpperCase(&player[i].noun);
        printf("Enter Word: ");
        gets(player[i].word);
        convertToUpperCase(&player[i].word);
        player[i].lives=6;
        sleep(2);
        clearScreen();
        printf("Guess word %s\n",player[i].name);
        displayword(&player[i]);
        guess(&player[i]);
        i=!(i);
    }
    if(player[0].wins==3){
        printf("%s is the winner of this series",player[0].name);
    }
    else{
        printf("%s is the winner of this series",player[1].name);
    }
}
int main() {
    initialiseGame();
}