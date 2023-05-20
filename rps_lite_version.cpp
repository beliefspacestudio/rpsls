#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

int playerMove() {
    int playerChoice;

    char playerInput;
    std::cout << "Rock(r), Paper(p) or Scissors(s))?\n";
    std::cin >> playerInput;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clear input

    std::vector<char> playerCh = {'r','s','p'};
    for (size_t i = 0; i < playerCh.size(); ++i) {
        if (playerCh[i] == playerInput) {
            return i;
        }
    }
    return -1;
}

int main() {

    srand(time(NULL));

    int winner;
    int action;
    int playerScore = 0;
    int computerScore = 0;
    bool continuePlaying = true;

    std::vector<std::vector<std::string>> const choice = {
        {"Rock","blunts"},
        {"Scissors","cut"},
        {"Paper","wraps"}
    };

    while (true) {

        std::system("clear");
        std::cout <<  "Rock, Paper, Scissors\n";

        std::cout << "Player: " << playerScore << " vs. Computer: " << computerScore << "\n\n";

        int computer = rand() % 3;
        std::string cmove = choice[computer][0];

        int player = playerMove();
        if (player == -1) { return 0; } //exit on invalid input
        std::string pmove = choice[player][0];

        std::cout << "Player: " << pmove << "\n";
         std::cout << "Computer: " << cmove << "\n";
        
        int draw = (player == computer) ? 1 : 0;

        if (draw==1) {

            std::cout << cmove << " vs " << pmove;
            std::cout << std::endl;
            std::cout << "It\'s a Draw!\n\n";

        } else {

            int pwin1 = (computer-1+3) % 3;
            int cwin1 = (player-1+3) % 3;
            
            if (player==pwin1) {
                winner = player;
                action = 1;
            } else if (computer==cwin1) {
                winner = computer;
                action = 1;
            } else if (computer==player) {
                winner = 3;
                action = 0;
            }
            
            if (winner==player) {
                playerScore++;
                std::string pact = choice[winner][action];
                std::cout << pmove << " " <<  pact << " " << cmove;
                std::cout << "\nPlayer Wins!\n";
            }

            if (winner==computer) {
                computerScore++;
                std::string cact = choice[winner][action];
                std::cout << cmove << " " << cact << " " << pmove;
                std::cout << "\nComputer Wins!\n";
            }

            
        }
        
        std::cout << "\nAnother round? (y/n)\n";
        char continueGame;
        std::cin >> continueGame;
        if (continueGame == 'n' || continueGame == 'N') {
            return 0;
        }

    }

    return 0;
};