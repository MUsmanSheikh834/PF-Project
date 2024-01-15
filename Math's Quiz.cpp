#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int score = 0;

void DisplayIntro() {
    system("cls"); 

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t    ******************************************\n");
    printf("\t\t\t\t\t\t\t    *           Welcome to MathQuest         *\n");
    printf("\t\t\t\t\t\t\t    *           ====================         *\n");
    printf("\t\t\t\t\t\t\t    ******************************************\n\n");
    
    Sleep(2000);

    printf("\t\t\t\t\t\t\t    Solve challenging math problems & earn points.\n");
    Sleep(1500);
    printf("\t\t\t\t\t\t\t    Select your preferred difficulty level.\n");
    Sleep(1500);
    printf("\t\t\t\t\t\t\t    Answer 8 questions in 8 seconds each.\n\n");
    Sleep(1500);

    printf("\t\t\t\t\t\t\t    Loading");
    for (int i = 0; i < 3; i++) {
        Sleep(1500);
        printf(".\a");
    }
    Sleep(2000);
    
    system("cls");
}

char SelectLevel(){
	char lvl;
	do{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	    printf("\t\t\t\t\t\t\t    *********************************************\n");
        printf("\t\t\t\t\t\t\t    * Select a level from the following:        *\n");
        printf("\t\t\t\t\t\t\t    *                                           *\n");
        printf("\t\t\t\t\t\t\t    *   --> [E] or [e] = EASY                   *\n");
        printf("\t\t\t\t\t\t\t    *   --> [M] or [m] = MEDIUM                 *\n");
        printf("\t\t\t\t\t\t\t    *   --> [H] or [h] = HARD                   *\n");
        printf("\t\t\t\t\t\t\t    *                                           *\n");
        printf("\t\t\t\t\t\t\t    *********************************************\n\n");
	    printf("\t\t\t\t\t\t\t    Level: ");
	    scanf("%c", & lvl);
	    Sleep(1500);
	    system("cls");
    }while(lvl!='E'&&lvl!='e'&&lvl!='M'&&lvl!='M'&&lvl!='m'&&lvl!='H'&&lvl!='h');
    return lvl;
}

int RandomNumber(int min, int max){
	return rand() % (max - min + 1) + min;
}

void Level(int min, int max){
	int num_1, num_2;
    int rand_operator = RandomNumber(1, 4);
    do {
        num_1 = RandomNumber(min, max);
        num_2 = RandomNumber(min, max);
    } while ((rand_operator == 2) && (num_1 % num_2 != 0));
   
    int ans, user_ans;
    clock_t start_time, end_time;
    float elapsed_time;
    printf("\t       score: %d\n", score);
    printf("\t\t\t\t\t\t\t    *******************\n");
    printf("\t\t\t\t\t\t\t    *   ");
	switch(rand_operator){
		case 1:
			ans = num_1 + num_2;
            printf("%2d + %2d = ?", num_1, num_2);
            break;
		case 2:
			ans = num_1 / num_2;
            printf("%2d / %2d = ?", num_1, num_2);
		    break;
		case 3:
			ans = num_1 * num_2;
            printf("%2d * %2d = ?", num_1, num_2);
			break;
		case 4:
			ans = num_1 - num_2;
            printf("%2d - %2d = ?", num_1, num_2);
			break;
		default:
		break;
	}
	printf("   *\n");
	printf("\t\t\t\t\t\t\t    *******************\n\n");
	printf("\t\t\t\t\t\t\t    Ans: ");
	start_time = clock();
	scanf("%d", & user_ans);
	end_time = clock();
	elapsed_time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
	printf("\t\t\t\t\t\t\t    Time Taken: %.1f\n", elapsed_time);
	if(user_ans == ans && elapsed_time <= 8.0){
		score++;
		printf("\t\t\t\t\t\t\t    Score: +1");
	}else{
		printf("\t\t\t\t\t\t\t    Score: +0");
	}
	
	Sleep(1500);
	
	system("cls");
}

int main(){
	srand(time(NULL));
	int Num_of_Questions;
	
	DisplayIntro();
    char lvl = SelectLevel();
    for(Num_of_Questions = 1; Num_of_Questions <= 8; Num_of_Questions++){
    	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    	printf("\t\t\t\t\t\t\t    Q%d)", Num_of_Questions);
        switch(lvl){
    	    case 'E':
    	    case 'e':
    		    Level(1,20);
    		    break;
	    case 'M':
    	    case 'm':
    		    Level(30,50);
    		    break;
            case 'H':
    	    case 'h':
    		    Level(60,80);
    		    break;
        }
    }
}
