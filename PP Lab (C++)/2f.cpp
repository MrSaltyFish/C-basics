// Anvesh Khode
// 2f - Write a program to design KBC interface for 10
// questions and display the winning amount.

#include <iostream>

int main() {
    std::string questions[10] = {
        "Q1: Which planet is known as the 'Blue Planet'?",
        "Q2: Who wrote the play 'Hamlet'?",
        "Q3: What is the largest mammal on Earth?",
        "Q4: What gas do plants release during photosynthesis?",
        "Q5: Which country is known as the 'Land of the Rising Sun'?",
        "Q6: What is the chemical symbol for the element silver?",
        "Q7: Who discovered the law of gravity?",
        "Q8: What is the largest desert in the world?",
        "Q9: What is the symbol for the chemical element hydrogen?",
        "Q10: How many players are there on a standard soccer team?"};

    std::string options[10][4] = {
        {"A. Mars", "B. Earth", "C. Neptune", "D. Jupiter"},
        {"A. William Shakespeare", "B. Charles Dickens", "C. Jane Austen",
         "D. Mark Twain"},
        {"A. Elephant", "B. Blue Whale", "C. Lion", "D. Giraffe"},
        {"A. Oxygen", "B. Carbon dioxide", "C. Nitrogen", "D. Hydrogen"},
        {"A. Japan", "B. China", "C. South Korea", "D. Australia"},
        {"A. Ag", "B. Si", "C. Sv", "D. Sl"},
        {"A. Albert Einstein", "B. Isaac Newton", "C. Galileo Galilei",
         "D. Nikola Tesla"},
        {"A. Sahara Desert", "B. Gobi Desert", "C. Antarctic Desert",
         "D. Arabian Desert"},
        {"A. Hg", "B. Hy", "C. H", "D. Hd"},
        {"A. 9", "B. 10", "C. 11", "D. 12"}};

    char answers[10] = {'B', 'A', 'B', 'A', 'A', 'A', 'B', 'A', 'C', 'C'};

    int prizeMoney[10] = {1000,  2000,  3000,  5000,   10000,
                          20000, 40000, 80000, 160000, 320000};

    int totalAmount = 0;
    bool allCorrect = true;

    std::cout << "Welcome to KBC!"
              << "\n";

    for(int i = 0; i < 10; ++i) {
        std::cout << questions[i] << "\n";
        for(int j = 0; j < 4; ++j) {
            std::cout << options[i][j] << "\n";
        }

        char choice;
        std::cout << "Your answer (A/B/C/D): ";
        std::cin >> choice;

        if(choice == answers[i]) {
            std::cout << "Correct answer! You've won Rs." << prizeMoney[i]
                      << "\n";
            totalAmount += prizeMoney[i];
        } else {
            std::cout << "Sorry, wrong answer. You've lost all your winnings."
                      << "\n";
            totalAmount = 0;
            allCorrect = false;
            break;
        }

        char quit;
        if(i != 9) {
            std::cout << "Do you want to quit (Y/N)? ";
            std::cin >> quit;

            if(quit == 'Y' || quit == 'y') {
                std::cout << "Congratulations! You've won a total of Rs."
                          << totalAmount << "\n";
                break;
            }
        }
    }

    if(allCorrect) {
        std::cout
            << "Congratulations! You've answered all questions correctly and "
               "won Rs."
            << totalAmount << "\n";
    } else if(totalAmount == 0) {
        std::cout << "You've lost the game. Better luck next time!"
                  << "\n";
    }

    return 0;
}