#include <iostream>
#include <fstream>
using namespace std;

class FindGrade {
private:
    float q1, q2, midMark, finalMark;
    float percentage, percQ, percM, percF;
    string grade;

public:
    FindGrade() : q1(0), q2(0), midMark(0), finalMark(0), percentage(0) {} // Constructor

    void getMarks();
    void calMarks();
    void calcGrade();
    void showGrade();
};

//  take input
void FindGrade::getMarks() {
    cout << "\nEnter obtained marks of Quiz 1 (0-20): ";
    cin >> q1;
    while (q1 < 0 || q1 > 20) {
        cout << "Invalid input! Marks should be between 0 and 20. Re-enter: ";
        cin >> q1;
    }

    cout << "Enter obtained marks of Quiz 2 (0-20): ";
    cin >> q2;
    while (q2 < 0 || q2 > 20) {
        cout << "Invalid input! Marks should be between 0 and 20. Re-enter: ";
        cin >> q2;
    }

    cout << "Enter obtained marks of Mid Term (0-100): ";
    cin >> midMark;
    while (midMark < 0 || midMark > 100) {
        cout << "Invalid input! Marks should be between 0 and 100. Re-enter: ";
        cin >> midMark;
    }

    cout << "Enter obtained marks of Final Term (0-100): ";
    cin >> finalMark;
    while (finalMark < 0 || finalMark > 100) {
        cout << "Invalid input! Marks should be between 0 and 100. Re-enter: ";
        cin >> finalMark;
    }

    cout << endl;
}


// calculate total grade
void FindGrade::calMarks() {
    const float QUIZ_WEIGHT = 25.0, MID_WEIGHT = 25.0, FINAL_WEIGHT = 50.0;
    const float MAX_QUIZ_MARKS = 20.0, MAX_MID_MARKS = 100.0, MAX_FINAL_MARKS = 100.0;

    float qt = q1 + q2;
    percQ = (QUIZ_WEIGHT / MAX_QUIZ_MARKS) * qt;
    percM = (MID_WEIGHT / MAX_MID_MARKS) * midMark;
    percF = (FINAL_WEIGHT / MAX_FINAL_MARKS) * finalMark;
    percentage = percQ + percM + percF;
}

void FindGrade::calcGrade() {
    if (percentage >= 90.0)
        grade = "A+";
    else if (percentage >= 85.0)
        grade = "A";
    else if (percentage >= 80.0)
        grade = "B+";
    else if (percentage >= 75.0)
        grade = "B";
    else if (percentage >= 70.0)
        grade = "C";
    else if (percentage >= 65.0)
        grade = "D";
    else
        grade = "F";
}

//  display results
void FindGrade::showGrade() {
    cout << "\n-----------------------------------------\n";
    cout << "Total Percentage: " << percentage << "" << endl;
    cout << "The obtained grade: " << grade << endl;
    cout << "-----------------------------------------\n";
    // Save the result to a file
    ofstream file("grades.txt", ios::app);
    file << "Total Percentage: " << percentage << ", Grade: " << grade << "\n";
    file.close();

}
void viewPreviousGrades() {
    ifstream file("grades.txt");
    if (!file) {
        cout << "No previous records found!" << endl;
        return;
    }

    string line;
    cout << "\nPrevious Grade Records:\n";
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

int main() {
    int choice;
    cout << "1. Calculate New Grade\n2. View Previous Grades\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        FindGrade student;
        student.getMarks();
        student.calMarks();
        student.calcGrade();
        student.showGrade();
    } else if (choice == 2) {
        viewPreviousGrades();
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}

