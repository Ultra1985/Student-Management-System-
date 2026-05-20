#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
public:
    int id;
    string name;
    float marks;

    Student(int i, string n, float m) {
        id = i;
        name = n;
        marks = m;
    }

    void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks << endl;
        cout << "-------------------" << endl;
    }
};

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name;
            float marks;

            cout << "Enter ID: ";
            cin >> id;

            cin.ignore();

            cout << "Enter Name: ";
            getline(cin, name);

            cout << "Enter Marks: ";
            cin >> marks;

            students.push_back(Student(id, name, marks));

            cout << "Student Added Successfully!\n";
        }

        else if (choice == 2) {
            if (students.empty()) {
                cout << "No students found.\n";
            } else {
                cout << "\n--- Student Records ---\n";

                for (int i = 0; i < students.size(); i++) {
                    students[i].display();
                }
            }
        }

        else if (choice == 3) {
            int searchId;
            bool found = false;

            cout << "Enter Student ID to Search: ";
            cin >> searchId;

            for (int i = 0; i < students.size(); i++) {
                if (students[i].id == searchId) {
                    cout << "\nStudent Found:\n";
                    students[i].display();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Student not found.\n";
            }
        }

        else if (choice == 4) {
            int deleteId;
            bool found = false;

            cout << "Enter Student ID to Delete: ";
            cin >> deleteId;

            for (int i = 0; i < students.size(); i++) {
                if (students[i].id == deleteId) {
                    students.erase(students.begin() + i);
                    cout << "Student Deleted Successfully!\n";
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Student not found.\n";
            }
        }

        else if (choice == 5) {
            cout << "Exiting Program...\n";
        }

        else {
            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}