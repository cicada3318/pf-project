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
	strcpy(member[0].name, "Captain");
	strcpy(member[1].name, "Laptop Wala Uncle");
	strcpy(member[2].name, "Vigo Wali Sarkar");
	strcpy(member[3].name, "plastice princess");
	strcpy(member[4].name, "Joker");
	
	int option;
	
	while(1){
		printf("\n-------------------------------------\n");
		printf("\n1. vote do biryani lo");
		printf("\n2. results dekhlo (koi faida nhi jesa wo chahe ge wesa he hoga)");
		printf("\n3. Mere ko apne ghr jana ha");
		printf("\n\nHan Ustad konsa: ");

		if (scanf("%d", &option) == 1) {
    		printf("\n-------------------------------------\n");
		} else {
			while(getchar() != '\n'); // flushes if other than int input
		}

		
		switch(option){
			case 1:
				printf("\n\nBiryani gai Pait ma ab vote de apni merzi se: ");
				printf("\n");
				int voteAdd = castVote();
				member[voteAdd].votes += 1;
				break;
				
			case 2:
				int max = voteCount();
				printf("\nYe ha jis ko is bar moka de rhe ha wo: %s\n", member[max].name);
				break;
				
			case 3:
				printf("\n\nExiting...");
				return 0;
				
			default:
				system("cls");
				printf("Aby Sale ... Nikl ****!\n\n");
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
	printf("\n\nHan ustab konsa: ");
	if (scanf("%d", &choice) == 1 && choice < 6) {
		system("cls");
    	printf("\ndekh le is ko diya ha: %s", member[choice - 1].name);
    	printf("\ntera kaam hogya ab nikl!\n");
    	return choice - 1;
		} 
	else {
		while(getchar() != '\n'); // flushes if other than int input
    	system("cls");
		printf("Aby Bewree Esa koi banda nhi yaha ... Ja Dafa Ho!\n\n");
		}
}
