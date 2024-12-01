#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
using namespace std;

// Function to generate computer's random choice
char ComputerChoice() {
    int num = rand() % 3;  // Generate a random number between 0 and 2
    if (num == 0) return 'r';  // Rock
    else if (num == 1) return 'p';  // Paper
    else return 's';  // Scissors
}

// Function to determine the winner of the round and update scores
void pointWinner(char c, char u, int& user, int& com) {
    if (c == u) {
        cout << "It's a draw!\n";
        return;
    }

    switch (u) {
    case 'r':  // User chooses Rock
        if (c == 's') {  // Rock beats Scissors
            user += 1;
            cout << "User wins this round!\n";
        }
        else if (c == 'p') {  // Paper beats Rock
            com += 1;
            cout << "Computer wins this round!\n";
        }
        break;

    case 'p':  // User chooses Paper
        if (c == 'r') {  // Paper beats Rock
            user += 1;
            cout << "User wins this round!\n";
        }
        else if (c == 's') {  // Scissors beats Paper
            com += 1;
            cout << "Computer wins this round!\n";
        }
        break;

    case 's':  // User chooses Scissors
        if (c == 'p') {  // Scissors beats Paper
            user += 1;
            cout << "User wins this round!\n";
        }
        else if (c == 'r') {  // Rock beats Scissors
            com += 1;
            cout << "Computer wins this round!\n";
        }
        break;

    default:
        cout << "Something went wrong!\n";
    }
}

// Function to print user and computer choices
void PrintChoices(char com, char user) {
    cout << "User choice: " << user << endl;
    cout << "Computer choice: " << com << endl;
}

// Function to check and declare the final winner of the game
void CheckgameWinner(int com, int user) {
    cout << "\nFinal Scores:\n";
    cout << "User: " << user << endl;
    cout << "Computer: " << com << endl;

    if (user > com) {
        cout << "Congratulations! You won the game!\n";
    }
    else if (com > user) {
        cout << "Computer won the game! Better luck next time.\n";
    }
    else {
        cout << "It's a tie game!\n";
    }
}

int main() {
    int user = 0;  // User score
    int com = 0;   // Computer score
    char comChoice;
    char userChoice;

    srand(time(0));  // Seed random number generator

    // Game loop: Continue until either user or computer reaches 3 points
    while (user < 3 && com < 3) {
        do {
            cout << "\nEnter your choice: Rock-r, Paper-p, Scissors-s\n";
            cin >> userChoice;
        } while (userChoice != 'r' && userChoice != 'p' && userChoice != 's');

        comChoice = ComputerChoice();
        PrintChoices(comChoice, userChoice);
        pointWinner(comChoice, userChoice, user, com);

        // Print current scores after each round
        cout << "Current Scores: User = " << user << ", Computer = " << com << "\n";
    }

    // Check and declare the final winner
    CheckgameWinner(com, user);

    return 0;
}
