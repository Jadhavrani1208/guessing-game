#include <iostream>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

void startGame(int timeLimit) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(1, 50);

    int secretNumber = distr(gen); // Generate random number between 1 and 50
    int guess;
    int attempts = 0;
    bool guessed = false;
    bool user_input(int guess, int secretNumber) ;

    cout << "Try to guess the number between 1 and 50." << endl;

    auto start = high_resolution_clock::now(); // Start the stopwatch

    while (!guessed) {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        auto now = high_resolution_clock::now(); // Get the current time
        auto elapsed = duration_cast<seconds>(now - start); // Calculate elapsed time

        if (elapsed.count() > timeLimit) {
            cout << "Time's up! You didn't guess the number in time." << endl;
            break;
        }

        guessed = user_input(guess, secretNumber);

        if (guessed) {
            cout << "Congratulations! You've guessed the number in " << attempts << " attempts." << endl;
            cout << "Time taken: " << elapsed.count() << " seconds." << endl;
        }
    }

    if (!guessed) {
        cout << "The secret number was: " << secretNumber << endl;
    }
}

bool user_input(int guess, int secretNumber) {
    if (guess == secretNumber) {
        cout << "Amazing !! You guessed the number correctly !! We appreciate your intuitions !!!" << endl;
        return true;
    } else if (guess > secretNumber && guess <= (secretNumber + 5)) {
        cout << "You are too close...!!! try a little lower number...!!" << endl;
    } else if (guess > (secretNumber + 5) && guess <= (secretNumber + 15)) {
        cout << "Your guess is a little high but you are close...!!! try more...!!" << endl;
    } else if (guess > (secretNumber + 15) && guess <= (secretNumber + 50)) {
        cout << "Your guess is too high...!!! try harder...!!" << endl;
    } else if (guess < secretNumber && guess >= (secretNumber - 5)) {
        cout << "You are too close...!!! try a little greater number...!!" << endl;
    } else if (guess < (secretNumber - 5) && guess >= (secretNumber - 15)) {
        cout << "Your guess is a little low but you are close...!!! try more...!!" << endl;
    } else if (guess < (secretNumber - 15) && guess >= (secretNumber - 50)) {
        cout << "Your guess is too low...!!! try harder...!!" << endl;
    }
    return false;
}

int main()
 {
    const int defaultTimeLimit = 30; // Fixed time limit of 30 seconds

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "You have 30 seconds to guess the number." << endl;

    startGame(defaultTimeLimit);

    return 0;
}

