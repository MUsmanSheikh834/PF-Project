#include <stdio.h>
#include <stdlib.h>
#include "MathsQuiz.h"
#include "TicTacToe.h"
#include "WordPuzzle.h"
#include "hangman.h"
int main() {
	int games;
	char play='Y';
	while(play=='Y'|| play=='y' ){
		system("cls");
		printf("Welcome To MAMU Games: \n");
		printf("1. Hangman\n");
		printf("2. Tic Tac Toe\n");
		printf("3. Math Puzzle\n");
		printf("4. Word Puzzle\n");
		printf("Enter which game you want to play: ");
		scanf("%d", &games);
		getchar();
		system("cls");
	    switch(games){
		    case 1:
			    hangman();
				break;
			case 2:
				TicTacToe();
				break;
			case 3: 
		    	MathsQuiz();
				break;
			case 4:
				WordPuzzle();
				break;
			default:
				printf("Invalid Choice. Choose From The Given Options.");
				continue;
				break;
    	}
    	printf("\nDo You Want To Play Again[Y/N][y/n]");
    	scanf(" %c",&play);
    }
}