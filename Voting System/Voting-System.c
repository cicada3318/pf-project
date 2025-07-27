#include<stdio.h>
#include <stdlib.h>
#include <string.h>


struct candidates {
  int votes;
  char name[30];
};
struct candidates member[5];

int voteCount();
int castVote();

int main(void){
	strcpy(member[0].name, "John");
	strcpy(member[1].name, "Jerry");
	strcpy(member[2].name, "Jack");
	strcpy(member[3].name, "Joe");
	strcpy(member[4].name, "Joker");
	
	int option;
	
	while(1){
		printf("\n-------------------------------------\n");
		printf("\n1. Cast vote");
		printf("\n2. Show results");
		printf("\n3. Exit");
		printf("\n\nSelect an option to proceed: ");

		if (scanf("%d", &option) == 1) {
    		printf("\n-------------------------------------\n");
		} else {
			while(getchar() != '\n'); // flushes if other than int input
		}

		
		switch(option){
			case 1:
				printf("\n\nSelect candidate to cast vote: ");
				printf("\n");
				int voteAdd = castVote();
				member[voteAdd].votes += 1;
				break;
				
			case 2:
				printf("\n\nCurrent winning is: ");
				int max = voteCount();
				printf("\nCurrent winning is: %s\n", member[max].name);
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

int voteCount() {
    system("cls");
    
    int maxVotes = member[0].votes;
    int maxIndex = 0;

    for (int i = 0; i < 5; i++) {
        printf("%s has %d votes.\n", member[i].name, member[i].votes);

        if (member[i].votes > maxVotes) {
            maxVotes = member[i].votes;
            maxIndex = i;
        }
    }
	return maxIndex;
}


int castVote(){
	int choice;
	for(int i = 0 ; i < 5 ; i++){
		printf("\n%d. %s", i+1, member[i].name);
	}
	printf("\n\nPlease enter your choice: ");
	if (scanf("%d", &choice) == 1 && choice < 6) {
		system("cls");
    	printf("\nYou voted for: %s", member[choice - 1].name);
    	printf("\nThank you for voting!\n");
    	return choice - 1;
		} 
	else {
		while(getchar() != '\n'); // flushes if other than int input
    	system("cls");
		printf("INVALID CANDIDATE ... RETURNING TO MAIN MENU!\n\n");
		}
}
