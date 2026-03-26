#include <iostream>
#include <random>

using namespace std;

int main() {
    // Random number setup
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 100);

    int secretNumber = dist(gen);
    int guess;

    cout << "🎯 Number Guessing Game (1 - 100)\n";

    do {
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess > secretNumber) {
            cout << "Too high! 📉\n";
        } 
        else if (guess < secretNumber) {
            cout << "Too low! 📈\n";
        } 
        else {
            cout << "🎉 Correct! You guessed it!\n";
        }

    } while (guess != secretNumber);

    return 0;
}