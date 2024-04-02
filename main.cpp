#include <iostream>
#include <vector>
#include <cctype>
#include <limits>

using namespace std;

double convertScore(char grade) {
    switch (grade) {
        case 'A':
            return 4.0;
        case 'B':
            return 3.0;
        case 'C':
            return 2.0;
        case 'D':
            return 1.0;
        default:
            return 0.0;
    }
}

int main() {
    vector<int> courseCredit;
    vector<double> courseScore;
    bool endInput = false;
    bool notValid;
    cout << "Please enter the letter grade of your course one class at a time: ";
    char grade;
    cin >> grade;
    while (!isalpha(grade)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a letter: ";
        cin >> grade;
    }
    grade = toupper(grade, locale());
    courseScore.push_back(convertScore(grade));
    cout << "Please enter the credit hour of that class: ";


    return 0;
}
