#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char choice[5][3][11] = {
{"Rock","blunts","crushes"},
{"Scissors","decapitate","cut"},
{"Lizard","eats","poisons"},
{"Paper","disproves","wraps"},
{"Spock","vaporises","smashes"}
};

int w,a;

int main () {

	srand(time(NULL));
	
	int computer = (rand()%5);
	char *cmove = choice[computer][0];

	int player = (rand()%5);
	char *pmove = choice[player][0];
	
	int pwin1 = (computer-1+5) % 5;
	int pwin2 = (computer-2+5) % 5;
	int cwin1 = (player-1+5) % 5;
	int cwin2 = (player-2+5) % 5;
	
	if (player==pwin1) {
		w = player;
		a = 1;
	} else if (player==pwin2) {
		w = player;
		a = 2;
	} else if (computer==cwin1) {
		w = computer;
		a = 1;
	} else if (computer==cwin2) {
		w = computer;
		a = 2;
	} else if (computer==player) {
		w = 5;
		a = 0;
	}
	
	if (w==player) {
		char *pact = choice[w][a];
		printf("\nPlayer\'s %s %s Computer\'s %s\n\n", pmove, pact, cmove);
		printf("Player Wins!\n\n");
	} else if (w==computer) {
		char *cact = choice[w][a];
		printf("\nComputer\'s %s %s Players\'s %s\n\n", cmove, cact, pmove);
		printf("Player Wins!\n\n");
	} else if (player==computer){
		printf("Computer\'s %s draws against Player\'s %s\n\n", cmove, pmove);
	} else {
		return 0;
	}
	
}