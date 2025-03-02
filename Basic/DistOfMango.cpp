#include <iostream>
using namespace std;

// Function to calculate the factorial of a number
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Function to calculate n choose r
int nCr(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

// Function to calculate the number of ways to distribute mangoes among persons
int distributeMangoes(int mangoes, int persons) {
    return nCr(mangoes + persons - 1, persons - 1);
}

int main() {
    int mangoes, persons;
    cout << "Enter the number of mangoes: ";
    cin >> mangoes;
    cout << "Enter the number of persons: ";
    cin >> persons;

    int ways = distributeMangoes(mangoes, persons);
    cout << "Number of ways to distribute mangoes: " << ways << endl;

    return 0;
}