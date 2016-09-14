#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {

	int pscore = 0;
	int cscore = 0;

	while (1) {
		int player = 0;
		char userin;
	
		printf("Rock(r), Paper(p), Scissors(s)? [q to quit] ");
		scanf("%s", &userin);
	
		switch(userin) {
			case 'r':
			case 'R':
				player = 1;
				break;
			case 'p':
			case 'P':
				player = 2;
				break;
			case 's':
			case 'S':
				player = 3;
				break;
			case 'q':
			case 'Q':
				printf("Goodbye! Thanks for playing!\n");
				return 0; //end program
			default:
				printf("Please choose a valid option: r, p or s.\n");
		}
	
		if (player != 0) { //Check player is set.
		
			char pc[3][9] = {"Rock", "Paper", "Scissors"}; //explicitly set to avoid memory overrun
			char *umove = pc[player-1];  //pointer to umove
			printf("Player: %s vs ", umove);

			//COMPUTER MOVE
			srand(time(NULL));
			int computer = (rand()%3)+1; //Random number between 1 and 3
			char cc[3][9] = {"Scissors", "Paper", "Rock"}; //backward to make maths work
			char *cmove = cc[computer-1]; //pointer to cmove
			printf("Computer: %s\n", cmove);
			
			//ENGINE
			int outcome = 11 % ( 11 % (player + computer) );	//modulus maths determines winner
			if (outcome == 2) {
				printf("A draw\n");
			} else if (outcome == 1) {
				cscore += 1;
				printf("Computer wins\n");
			} else if (outcome == 0) {
					pscore += 1;
					printf("Player wins\n");
			} else {
				printf("My mind is going\n");
			}
			printf("Player: %d\nComputer: %d\n\n",pscore,cscore);
			
		} //end if
		
	} //end while
	
}

/*
pr = 1		cr = 3
pp = 2		cp = 2
ps = 3		cs = 1

// A draw:
pr cr:	1,3		11 % (1 + 3) = 3	11 % 3 = 2		rock == rock
pp cp:	2,2		11 % (2 + 2) = 3	11 % 3 = 2		paper == paper
ps cs:	3,1		11 % (3 + 1) = 3	11 % 3 = 2		scissors == scissors

//computer wins
pr cp	1,2		11 % (1 + 2) = 2	11 % 2 = 1		rock < paper		wraps
pp cs	2,1		11 % (2 + 1) = 2	11 % 2 = 1		paper < scissors	cuts
ps cr	3,3		11 % (3 + 3) = 5	11 % 5 = 1		scissors < rock		blunts

//player wins
pr cs	1,1		11 % (1 + 1) = 1	11 % 1 = 0		rock > scissors		blunts
pp cr	2,3		11 % (2 + 3) = 1	11 % 1 = 0		paper > rock		wraps
ps cp	3,2		11 % (3 + 2) = 1	11 % 1 = 0		scissors > paper	cuts
*/