#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

struct game {
    char grid[10][10];
    char word1[10];
    char word2[10];
    char word3[10];
    char word4[10];
    char word5[10];
    char word6[10];
    char word7[10];
    char word8[10];
};

const int ROWS = 10, COLS = 10;
struct game puzzle;

void ReadWordPuzzleFromFile(char num, FILE *file) {
    char c;
    do {
        c = fgetc(file);
    } while (c != num);
    c = fgetc(file);
    
    int i, x;
    for (i = 0; i < ROWS; ++i) {
        for (x = 0; x < COLS; x++) {
            puzzle.grid[i][x] = fgetc(file);
        }
    }
}

void ReadAnsFromFile(FILE *file, int lineNumber, struct game *puzzle) {
    int currentLine;
    for (currentLine = 1; currentLine < lineNumber; ++currentLine) {
        char c;
        do {
            c = fgetc(file);
        } while (c != '\n');
    }

    int i;
    for (i = 0; i < 10; i++) {
        puzzle->word1[i] = fgetc(file);
        if (puzzle->word1[i] == '\n' || puzzle->word1[i] == EOF) {
            puzzle->word1[i] = '\0';
            break;
        }
    }
    for (i = 0; i < 10; i++) {
        puzzle->word2[i] = fgetc(file);
        if (puzzle->word2[i] == '\n' || puzzle->word2[i] == EOF) {
            puzzle->word2[i] = '\0';
            break;
        }
    }
    for (i = 0; i < 10; i++) {
        puzzle->word3[i] = fgetc(file);
        if (puzzle->word3[i] == '\n' || puzzle->word3[i] == EOF) {
            puzzle->word3[i] = '\0';
            break;
        }
    }
    for (i = 0; i < 10; i++) {
        puzzle->word4[i] = fgetc(file);
        if (puzzle->word4[i] == '\n' || puzzle->word4[i] == EOF) {
            puzzle->word4[i] = '\0';
            break;
        }
    }
    for (i = 0; i < 10; i++) {
        puzzle->word5[i] = fgetc(file);
        if (puzzle->word5[i] == '\n' || puzzle->word5[i] == EOF) {
            puzzle->word5[i] = '\0';
            break;
        }
    }
    for (i = 0; i < 10; i++) {
        puzzle->word6[i] = fgetc(file);
        if (puzzle->word6[i] == '\n' || puzzle->word6[i] == EOF) {
            puzzle->word6[i] = '\0';
            break;
        }
    }
    for (i = 0; i < 10; i++) {
        puzzle->word7[i] = fgetc(file);
        if (puzzle->word7[i] == '\n' || puzzle->word7[i] == EOF) {
            puzzle->word7[i] = '\0';
            break;
        }
    }
    for (i = 0; i < 10; i++) {
        puzzle->word8[i] = fgetc(file);
        if (puzzle->word8[i] == '\n' || puzzle->word8[i] == EOF) {
            puzzle->word8[i] = '\0';
            break;
        }
    }
}

void DisplayWordPuzzle(int score) {
    printf(" WORD PUZZLE:\t\t\tScore: %d\n", score);
    int i, x;
    for (i = 0; i < ROWS; ++i) {
        for (x = 0; x < COLS; ++x) {
            printf("----");
        }
        printf("-\n");

        for (x = 0; x < COLS; ++x) {
            printf("| %c ", puzzle.grid[i][x]);
        }
        printf("|\n");
    }

    for (x = 0; x < COLS; ++x) {
        printf("----");
    }
    printf("-\n");
}


int main() {
	srand(time(NULL));
	char PlayAgain;
    int PlayAgainFlag;
    
    
    
    do{
    	FILE *file = fopen("Puzzles.txt", "r");
    if (file == NULL) {
        printf("ERROR: Opening File.\n");
        return 1;
    }
    
    int num = rand() % 3 + 1;
    char char_num = num + 48;
    
    ReadWordPuzzleFromFile(char_num, file);
    ReadAnsFromFile(file, 2, &puzzle);
    fclose(file);
    
    char user_ans[10];
    	int score = 0;
    	do{
    	    DisplayWordPuzzle(score);
    	    printf(" Word: ");
            gets(user_ans);
            
            if(strcmp(user_ans,puzzle.word1)==0){
            	printf(" You found a word!\n");
            	score++;
            	puzzle.word1[0] = '\0';
		    }else if(strcmp(user_ans,puzzle.word2)==0){
            	printf(" You found a word!\n");
            	score++;
            	puzzle.word2[0] = '\0';
		    }else if(strcmp(user_ans,puzzle.word3)==0){
            	printf(" You found a word!\n");
            	score++;
            	puzzle.word3[0] = '\0';
		    }else if(strcmp(user_ans,puzzle.word4)==0){
            	printf(" You found a word!\n");
            	score++;
            	puzzle.word4[0] = '\0';
		    }else if(strcmp(user_ans,puzzle.word5)==0){
            	printf(" You found a word!\n");
            	score++;
            	puzzle.word5[0] = '\0';
		    }else if(strcmp(user_ans,puzzle.word6)==0){
            	printf(" You found a word!\n");
            	score++;
            	puzzle.word6[0] = '\0';
		    }else if(strcmp(user_ans,puzzle.word7)==0){
            	printf(" You found a word!\n");
            	score++;
            	puzzle.word7[0] = '\0';
		   }else if(strcmp(user_ans,puzzle.word8)==0){
            	printf(" You found a word!\n");
            	score++;
            	puzzle.word8[0] = '\0';
	    	}else{
	    	    printf(" Try Again.\n");
	    	}
	    	Sleep(2000);
		    system("cls");
	    }while(score != 8);
	    
	    AskAgain:
	    system("cls");
	    printf("\n\t>>Do you want to play again?");
	    printf("\n\t  [Y] or [y] = YES");
	    printf("\n\t  [N] or [n] = NO");
	    printf("\n\t>>");
	    scanf(" %c", & PlayAgain);
	    switch(PlayAgain){
	    	case 'Y':
	    	case 'y':
	    		PlayAgainFlag = 1;
	    		break;
	    	case 'N':
	    	case 'n':
	    		PlayAgainFlag = 0;
	    		break;
	    	default:
	    		system("cls");
	    		printf("ERROR: Invalid Input.");
	    		Sleep(2000);
	    		goto AskAgain;
	    	    break;
		}
    }while(PlayAgainFlag == 1);
    return 0;
}
