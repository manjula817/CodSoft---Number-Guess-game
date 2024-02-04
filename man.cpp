#include <iostream>
#include <cstdlib>
#include <ctime>

class RdGen {
public:
    int rnd() {
        // Generate a random number between 1 and 100
        return rand() % 100 + 1;
    }
};

int main() {
    RdGen rd;
    srand(time(0)); // Seed for random number generation

    std::cout << std::endl;
    std::cout << "WELCOME TO NUMBER GAME!!" << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;
    std::cout << "The GAME IS ABOUT GUESSING A RANDOM NUMBER UNTIL YOU ARE CORRECT!!" << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;
    std::cout << "YOU ARE GIVEN A SPECIFIC NUMBER OF CHANCES DEPENDING ON THE LEVEL OF DIFFICULTY CHOSEN!!" << std::endl;
    std::cout << "--------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "PLEASE CHOOSE THE NUMBER OF ROUNDS YOU WANT TO PLAY!!.. LET'S BEGIN..!!" << std::endl;
    std::cout << "Available from (1-5):  ";

    int rounds;
    std::cin >> rounds;
    std::cout << std::endl;

    for (int i = 0; i < rounds; i++) {
        int res = rd.rnd();
        std::cout << "Random Number is generated!!" << std::endl;
        std::cout << "-----------------------------------------------------------------------" << std::endl;
        std::cout << "Please choose the level of difficulty!!" << std::endl;
        std::cout << "1 -> Easy ..(Gives unlimited attempts)" << std::endl;
        std::cout << "2 -> Hard ..(Gives 10 attempts)" << std::endl;

        int level;
        std::cin >> level;
        std::cout << std::endl;

        if (level == 1) {
            int c = 0;
            std::cout << "You have chosen easy level!!" << std::endl;
            std::cout << "Enter your Guess!!: ";
            int guess;
            std::cin >> guess;
            
            if (guess == res) {
                std::cout << "Congrats! You guessed in 1st attempt" << std::endl;
                std::cout << "Your score is 20/20" << std::endl;
            } else {
                while (guess != res) {
                    c++;
                    if (guess < res) {
                        std::cout << "Your guess is Lower!!" << std::endl;
                    } else if (guess > res) {
                        std::cout << "Your guess is HIGHER!!" << std::endl;
                    }
                    std::cout << "Guess again!!: ";
                    std::cin >> guess;
                }
                std::cout << "Congrats! Your guess is correct!!!" << std::endl;
                std::cout << "Your score is " << 10 - c << "/10" << std::endl;
                std::cout << std::endl;
            }
        }

        if (level == 2) {
            int c = 0;
            std::cout << "You have chosen Hard level!!" << std::endl;
            std::cout << "Enter your Guess!!: ";
            int guess;
            std::cin >> guess;
            
            if (guess == res) {
                std::cout << "Congrats! You guessed in 1st attempt" << std::endl;
                std::cout << "Your score is 20/20" << std::endl;
            } else {
                while (guess != res && c != 10) {
                    c++;
                    if (guess < res) {
                        std::cout << "Your guess is Lower!!" << std::endl;
                    } else if (guess > res) {
                        std::cout << "Your guess is HIGHER!!" << std::endl;
                    }
                    std::cout << "Guess again!!: ";
                    std::cin >> guess;
                }
                std::cout << "Congrats! Your guess is correct!!!" << std::endl;
                std::cout << "Your score is " << 10 - c - 1 << "/10" << std::endl;
                std::cout << std::endl;
            }
        }

        std::cout << "Round Ended!!!" << std::endl;
        std::cout << "----------------------------------------------------------------" << std::endl;
    }

    return 0;
}
