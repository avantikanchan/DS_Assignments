#include<iostream> // Fixed typo: iostrem -> iostream
using namespace std;

int main()
{
    int rollNo[10];
    int marks[10];

    int n = 0; // Keeps track of how many students have been added
    int choice;
    int searchRoll;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by Roll No.\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // 1. Add student 
        if (choice == 1) // Fixed syntax: if{choice == 1} -> if (choice == 1)
        { 
            if (n >= 10) {
                cout << "Database full! Cannot add more students.\n";
            } else {
                cout << "\nEnter Roll Number: ";
                cin >> rollNo[n];
                cout << "Enter Marks: ";
                cin >> marks[n];
                n++; // Increment count after adding
                cout << "Student added successfully!\n";
            }
        }
        
        // 2. Display All Students
        else if (choice == 2) 
        {
            if (n == 0) {
                cout << "No records found.\n";
            } else {
                cout << "\n--- Student Records ---\n";
                for (int i = 0; i < n; i++) {
                    cout << "Roll No: " << rollNo[i] << " | Marks: " << marks[i] << endl;
                }
            }
        }
        
        // 3. Search Student by Roll No.
        else if (choice == 3) 
        {
            if (n == 0) {
                cout << "No records available to search.\n";
            } else {
                cout << "\nEnter Roll Number to search: ";
                cin >> searchRoll;
                
                bool found = false;
                for (int i = 0; i < n; i++) {
                    if (rollNo[i] == searchRoll) {
                        cout << "Record Found! Roll No: " << rollNo[i] << " | Marks: " << marks[i] << endl;
                        found = true;
                        break; // Exit the loop early since we found the student
                    }
                }
                if (!found) {
                    cout << "Student with Roll Number " << searchRoll << " not found.\n";
                }
            }
        }
        
        // 4. Exit
        else if (choice == 4) 
        {
            cout << "Exiting the program. Goodbye!\n";
        }
        
        // Invalid choice
        else 
        {
            cout << "Invalid choice! Please choose between 1 and 4.\n";
        }

    } while (choice != 4);

    return 0;
}
