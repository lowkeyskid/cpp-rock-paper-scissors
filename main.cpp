#include "iostream"
#include "map"
#include "vector"
#include "time.h"

int main() {
    std::srand(time(NULL));

    int round = 0;
    int rounds = 5;
    int computer_score = 0;
    int player_score = 0;

    std::vector<std::string> actions{"rock", "paper", "scissors"};
    std::map<std::string, std::string> opposingActions;
    opposingActions["rock"] = "paper";
    opposingActions["paper"] = "scissors";
    opposingActions["scissors"] = "rock";

    while (true) {
        std::string action;
        std::string computer_action = actions[rand() % actions.size()];
        
        std::cout << "rock, paper, or scissors?" << std::endl << "> ";
        std::cin >> action;

        std::cout << "you choose: " << action << std::endl;
        std::cout << "computer choose: " << computer_action << std::endl;

        if (computer_action == action) 
        {
            std::cout << "you tied!" << std::endl;
        } 
        else if (opposingActions[action] == computer_action)
        {
            computer_score += 1;
            std::cout << "you lost, computer current score is " << computer_score << std::endl;
        } 
        else 
        {
            player_score += 1;
            std::cout << "you won, your current score is " << player_score << std::endl;
        }

        round += 1;

        if (round == rounds) 
        {
            if (player_score > computer_score) 
            {
                std::cout << "Game is over, you won!" << std::endl << "Your score: " << player_score << std::endl << "Computer score: " << computer_score;
                break;
            } 
            else if (player_score == computer_score)
            {
                std::cout << "Game is over, you tied!" << std::endl << "Your score: " << player_score << std::endl << "Computer score: " << computer_score;
                break;
            } 
            else 
            {
                std::cout << "Game is over, you lost!" << std::endl << "Your score: " << player_score << std::endl << "Computer score: " << computer_score;
                break;
            }
        }
    }

    return 0;
}
