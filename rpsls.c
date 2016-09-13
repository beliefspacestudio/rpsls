#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main () {

	int pscore = 0;
	int cscore = 0;

	while (1) {
		int player = 0;
		char userin; //Suspect syntax?
		
		/* I know I can do the following directly with integers instead,
		but in the interests of learning... */
		printf("Rock(r), Paper(p), Scissors(s), Lizard(l), Spock(v)? [q to quit] ");
		scanf(" %c", &userin); //address of userin - changed to character, space before %c to consume whitespace
		//could I use fgets here instead? Safer?

		if (isdigit(userin)) {
			printf("Please choose a valid option: r, p or s.\n");
		} else {
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
				case 'l':
				case 'L':
					player = 4;
					break;
				case 'v':
				case 'V':
					player = 5;
					break;
				case 'q':
				case 'Q':
					printf("Goodbye! Thanks for playing!\n");
					return 0; //end program
				default:
					printf("Please choose a valid option: r, p or s.\n");
			} //endof switch
		} //endof if isdigit
	
		if (player != 0) { //Check player is set.
		
			char pc[5][9] = {"Rock","Paper","Scissors","Lizard","Spock"};//explicitly set
			char *umove = pc[player-1];  //umove pointer to location in pc array
			printf("Player: %s vs ", umove);

			//COMPUTER MOVE
			srand(time(NULL));
			int computer = (rand()%5)+1; //Random number between 1 and 5
			char cc[5][9] = {"Rock","Paper","Scissors","Lizard","Spock"};//explicitly set
			char *cmove = cc[computer-1]; //cmove pointer to location in cc array
			printf("Computer: %s\n", cmove);
			
			//ENGINE
			int win[] = {13,14,21,25,32,34,42,45,51,53}; //winning combinations
			int lose[] = {12,15,23,24,31,35,41,43,52,54}; //losing combinations
			
			if(player == computer) {
				printf("A draw\n");
			} else {
				//check who's won
				int outcome = 10 * player + computer; //math to determine combination
				//printf("DEBUG: outcome: %d\n", outcome);
				
				int n = 10;
				
				int i = 0; //Searches the win array for a match
   				while (i <= n && outcome != win[i]) {
      				i++;
      			}      			
      			int j = 0; //Searches the lose array for a match
   				while (j <= n && outcome != lose[j]) {
      				j++;
      			}
      			if(i <= n) {
      				pscore += 1;
      				printf("Player Wins!\n");
      			}
      			if (j <= n) {
      				cscore += 1;
      				printf("Computer Wins!\n");
      			}
			} //end if

			printf("Player: %d\nComputer: %d\n\n",pscore,cscore);
			
		} //endof if player
		
	} //endof while 1
	
} //endof main

/*
The logic...
pr = 1		cr = 1
pp = 2		cp = 2
ps = 3		cs = 3
pl = 4		cl = 4
pv = 5		cv = 5

// A draw:
pr cr:	1,1		rock == rock
pp cp:	2,2		paper == paper
ps cs:	3,3		scissors == scissors
pl cl:	4,4		lizard == lizard
pv cv:	5,5		spock == spock

draws = {11,22,33,44,55}

//computer wins
pr cv	1,5		rock < spock 		vaporises
pr cp	1,2		rock < paper		wraps
pp cl	2,4		paper < lizard		eats
pp cs	2,3		paper < scissors	cuts
ps cv	3,5		scissors < spock	smashes
ps cr	3,1		scissors < rock		blunts
pl cs	4,3		lizard < scissors	decapitates
pl cr	4,1		lizard < rock		crushes
pv cl	5,4		spock < lizard		poisons
pv cp	5,2		spock < paper		disproves

lose = {12,15,23,24,31,35,41,43,52,54}

//player wins
pr cl	1,4		rock > lizard		crushes
pr cs	1,3		rock > scissors		blunts
pp cv	2,5		paper > spock		disproves
pp cr	2,1		paper > rock		wraps
ps cl	3,4		scissors > lizard	decapitates
ps cp	3,2		scissors > paper	cuts
pl cv	4,5		lizard > spock		poisons
pl cp	4,2		lizard > paper		eats
pv cs	5,3		spock > scissors	smashes
pv cr	5,1		spock > rock		vaporises

win = {13,14,21,25,32,34,42,45,51,53}
*/
