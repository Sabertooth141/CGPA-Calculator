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
    double totalCredit = 0.0;
    double totalScore = 0.0;
    double gpa;
    bool isEnd = false;
    while(!isEnd) {
        cout << "Please enter the letter grade of your course one class at a time:";
        char grade;
        cin >> grade;
        grade = static_cast<char>(toupper(static_cast<unsigned char>(grade)));
        while (!isalpha(grade)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid letter:";
            cin >> grade;
        }
        courseScore.push_back(convertScore(grade));

        cout << "Please enter the credit hour of that class:";
        int creditHr;
        cin >> creditHr;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number:";
            cin >> creditHr;
        }
        courseCredit.push_back(creditHr);

        cout << "Have you finished inputting? (Y/N)";
        char over;
        cin >> over;
        over = static_cast<char>(toupper(static_cast<unsigned char>(over)));
        while (over != 'N' && over != 'Y') {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a valid letter:";
            cin >> over;
        }

        if (over == 'Y') {
            isEnd = true;
        }
    }
    for (unsigned int i = 0; i < courseScore.size(); i++) {
        totalScore += courseScore[i] * courseCredit[i];
        totalCredit += courseCredit[i];
    }

    gpa = totalScore / totalCredit;

    cout << "Your gpa is " << gpa << endl;

    return 0;
}
