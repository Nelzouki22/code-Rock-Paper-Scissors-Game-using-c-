#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

string get_user_choice() {
    string user_choice;
    cout << "Enter your choice (rock, paper, scissors): ";
    cin >> user_choice;
    while (user_choice != "rock" && user_choice != "paper" && user_choice != "scissors") {
        cout << "Invalid choice. Please enter rock, paper, or scissors: ";
        cin >> user_choice;
    }
    return user_choice;
}

string get_computer_choice() {
    string choices[] = { "rock", "paper", "scissors" };
    int random_index = rand() % 3;
    return choices[random_index];
}

string determine_winner(string user_choice, string computer_choice) {
    if (user_choice == computer_choice) {
        return "It's a tie!";
    }
    else if ((user_choice == "rock" && computer_choice == "scissors") ||
        (user_choice == "paper" && computer_choice == "rock") ||
        (user_choice == "scissors" && computer_choice == "paper")) {
        return "You win!";
    }
    else {
        return "Computer wins!";
    }
}

void play_game() {
    cout << "Welcome to Rock-Paper-Scissors!" << endl;
    string user_choice = get_user_choice();
    string computer_choice = get_computer_choice();
    cout << "You chose: " << user_choice << endl;
    cout << "Computer chose: " << computer_choice << endl;
    string result = determine_winner(user_choice, computer_choice);
    cout << result << endl;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation
    play_game();
    return 0;
}
