#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class Student {
public:
    int rollNo;
    string name;
    float marks;

    Student(int r, string n, float m) {
        rollNo = r;
        name = n;
        marks = m;
    }
};

vector<Student> students;

void addStudent() {
    int roll;
    string name;
    float marks;

    cout << "\nEnter Roll Number: ";
    cin >> roll;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter Marks: ";
    cin >> marks;

    students.push_back(Student(roll, name, marks));
    cout << "Student added successfully.\n";
}

void displayStudents() {
    if (students.empty()) {
        cout << "\nNo records found.\n";
        return;
    }

    cout << "\n--- Student Records ---\n";
    cout << left << setw(10) << "Roll"
         << setw(20) << "Name"
         << setw(10) << "Marks" << endl;

    for (auto &s : students) {
        cout << left << setw(10) << s.rollNo
             << setw(20) << s.name
             << setw(10) << s.marks << endl;
    }
}

void searchStudent() {
    int roll;
    cout << "\nEnter Roll Number to search: ";
    cin >> roll;

    for (auto &s : students) {
        if (s.rollNo == roll) {
            cout << "\nStudent Found:\n";
            cout << "Name: " << s.name << endl;
            cout << "Marks: " << s.marks << endl;
            return;
        }
    }

    cout << "Student not found.\n";
}

void calculateAverage() {
    if (students.empty()) {
        cout << "\nNo records available.\n";
        return;
    }

    float total = 0;
    for (auto &s : students)
        total += s.marks;

    cout << "\nAverage Marks: " << total / students.size() << endl;
}

void showTopper() {
    if (students.empty()) {
        cout << "\nNo records available.\n";
        return;
    }

    auto topper = max_element(students.begin(), students.end(),
                              [](Student a, Student b) {
                                  return a.marks < b.marks;
                              });

    cout << "\nTopper Details:\n";
    cout << "Roll: " << topper->rollNo << endl;
    cout << "Name: " << topper->name << endl;
    cout << "Marks: " << topper->marks << endl;
}

int main() {
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Calculate Average\n";
        cout << "5. Show Topper\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: calculateAverage(); break;
            case 5: showTopper(); break;
            case 6: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}
