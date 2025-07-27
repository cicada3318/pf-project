#include<stdio.h>
#include <stdlib.h>
struct candidates {
  int votes;
  char name[30];
};

int voteCount(int candidateCount);
int main(void){
	int option;
	struct candidates member[3];
	
	while(1){
		printf("\n1. Cast vote");
		printf("\n2. Show results");
		printf("\n3. Exit");
		printf("\n\nSelect an option to proceed: ");

		if (scanf("%d", &option) == 1) {
    		printf("\nProcess...");
		} else {
			while(getchar() != '\n'); // flushes if other than int input
    		option = 4;
		}

		
		switch(option){
			case 1:
				printf("\n\nSelect candidate to cast vote: ");
				break;
				
			case 2:
				printf("\n\nCurrent winning is: ");
				break;
				
			case 3:
				printf("\n\nExiting...");
				return 0;
				
			default:
				system("cls");
				printf("INVALID OPTION ... RETURNING TO MAIN MENU!\n\n");
				break;
		}
		
	}
}

int voteCount(int candidateCount){
	return 9;
}
