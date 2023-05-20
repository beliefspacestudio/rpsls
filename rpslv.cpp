#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

// colours, command line confetti
std::string reset = "\033[0m";
std::string black = "\033[30m";
std::string red = "\033[31m";
std::string green = "\033[32m";
std::string yellow = "\033[33m";
std::string blue = "\033[34m";
std::string white = "\033[37m";
std::string bgblack = "\033[40m";
std::string bgwhite = "\033[47m";

// lizard intro screen picture
void introScreen() {
    std::cout << green << "                     .)/     )/," << std::endl;
    std::cout << "                     /`-._,-'`._," << red << "o" << green << "`" << yellow << "_,-" << green << std::endl;
    std::cout << "  " << white << "STU'S  " << green << "   ,  _,-=\\,-.__,-.-.__" << red << "o" << green << "/'" << yellow << " \\" << green << std::endl;
    std::cout << "***********(_,'****)\\`******'(`*********" << std::endl;
	std::cout << "* " << bgwhite << black << "ROCK, PAPER, SCISSORS, LIZARD, SPOCK"<< reset << green << " *" << std::endl;
    std::cout << "****************************************" << std::endl;
}

int playerMove(char playerInput) {
    int playerChoice;
    switch (playerInput) {
        case 'r':
        case 'R':
            playerChoice = 0;
            break;
        case 's':
        case 'S':
            playerChoice = 1;
            break;
        case 'l':
        case 'L':
            playerChoice = 2;
            break;
        case 'p':
        case 'P':
            playerChoice = 3;
            break;
        case 'v':
        case 'V':
            playerChoice = 4;
            break;
        case 'a':
        case 'A':
            playerChoice = rand() % 5; //auto move easter egg
            break;
        case 'x':
        case 'X':
            return 777;
        default:
            return 777;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clear input
    return playerChoice;
}

int main() {

    srand(time(NULL));

    int winner;
    int action;
    int playerScore = 0;
    int computerScore = 0;
    bool continuePlaying = true;

    std::vector<std::vector<std::string>> const choice = {
        {"Rock","blunts","crushes"},
        {"Scissors","decapitate","cut"},
        {"Lizard","eats","poisons"},
        {"Paper","disproves","wraps"},
        {"Spock","vaporises","smashes"}
    };

    bool firstMove = true;

    while (true) {

        std::system("clear");
        introScreen();

        std::cout << "Player: " << yellow << playerScore << green;
        std::cout << " vs. Computer: " << blue << computerScore << reset << std::endl;
        std::cout << std::endl;

        char playerInput;
        std::cout << "Rock(r), Paper(p), Scissors(s),\n";
        std::cout << "Lizard(l) or Spock (v)?\n";
        std::cin >> playerInput;
        std::cout << std::endl;

        int player = playerMove(playerInput);
        if (player == 777) { return 0; } //exit
        std::string pmove = choice[player][0];
        std::cout << blue << "Player: " << white << pmove << std::endl;

        int computer = rand() % 5;
        std::string cmove = choice[computer][0];
        std::cout << blue << "Computer: " << white << cmove << std::endl;
        
        int draw = (player == computer) ? 1 : 0; //Assigns 1 to draw if player == computer
        
        if (draw==1) {
            std::cout << cmove << " vs " << pmove;
            std::cout << std::endl;
            std::cout << yellow << "It\'s a Draw!" << reset << std::endl;
            std::cout << std::endl;
        } else {
            int pwin1 = (computer-1+5) % 5;
            int pwin2 = (computer-2+5) % 5;
            int cwin1 = (player-1+5) % 5;
            int cwin2 = (player-2+5) % 5;
            
            if (player==pwin1) {
                winner = player;
                action = 1;
            } else if (player==pwin2) {
                winner = player;
                action = 2;
            } else if (computer==cwin1) {
                winner = computer;
                action = 1;
            } else if (computer==cwin2) {
                winner = computer;
                action = 2;
            } else if (computer==player) {
                winner = 5;
                action = 0;
            }
            
            if (winner==player) {
                playerScore++;
                std::string pact = choice[winner][action];
                std::cout << pmove << " " << red <<  pact << reset << " " << cmove;
                std::cout << std::endl;
                std::cout << green << "Player Wins!" << reset << std::endl;
            }
            if (winner==computer) {
                computerScore++;
                std::string cact = choice[winner][action];
                std::cout << cmove << " " << red << cact << reset << " " << pmove;
                std::cout << std::endl;
                std::cout << red << "Computer Wins!" << reset << std::endl;
            }
        }
        
        std::cout << "\nAnother round? (y/n)" << std::endl;
        char continueGame;
        std::cin >> continueGame;
        if (continueGame == 'n' || continueGame == 'N') {
            return 0;
        }

    }

    return 0;
};