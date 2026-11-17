#include <iostream>
#include <string>
#include <limits>
using namespace std;

#define SIZE 10

// Course Structure
struct Course {
    string courseName;
    Course* next;
};

// Student Structure
struct Student {
    int roll;
    string name;
    Course* courses;
    Student* next;
};

// Hash Node Structure
struct HashNode {
    int roll;
    Student* student;
    HashNode* next;
};

// Global Variables
Student* head = NULL;
HashNode* hashTable[SIZE] = {NULL};

// Hash Function
int hashFunction(int roll) {
    return roll % SIZE;
}

// Search Student using Hash Table
Student* search(int roll) {
    int index = hashFunction(roll);

    HashNode* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->roll == roll) {
            return temp->student;
        }
        temp = temp->next;
    }

    return NULL;
}

// Register Student
void registerStudent() {
    int roll;

    cout << "\nEnter Student Roll Number: ";
    cin >> roll;

    if (search(roll) != NULL) {
        cout << "Student Roll Number already exists!\n";
        return;
    }

    Student* newStudent = new Student;

    newStudent->roll = roll;

    cout << "Enter Student Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, newStudent->name);

    newStudent->courses = NULL;

    // Insert into Linked List
    newStudent->next = head;
    head = newStudent;

    // Insert into Hash Table using Chaining
    int index = hashFunction(roll);

    HashNode* newNode = new HashNode;

    newNode->roll = roll;
    newNode->student = newStudent;
    newNode->next = hashTable[index];

    hashTable[index] = newNode;

    cout << "\nStudent registered successfully!\n";
}

// Update Student
void updateStudent() {
    int roll;

    cout << "\nEnter Roll Number to update: ";
    cin >> roll;

    Student* temp = search(roll);

    if (temp == NULL) {
        cout << "Student not found!\n";
        return;
    }

    cout << "Enter New Student Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, temp->name);

    cout << "\nStudent updated successfully!\n";
}

// Enroll Course
void enrollCourse() {
    int roll;

    cout << "\nEnter Student Roll Number: ";
    cin >> roll;

    Student* student = search(roll);

    if (student == NULL) {
        cout << "Student not found!\n";
        return;
    }

    string courseName;

    cout << "Enter Course Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, courseName);

    Course* temp = student->courses;

    // Check Duplicate Course
    while (temp != NULL) {
        if (temp->courseName == courseName) {
            cout << "Already enrolled in this course!\n";
            return;
        }

        temp = temp->next;
    }

    Course* newCourse = new Course;

    newCourse->courseName = courseName;

    // Insert Course into Linked List
    newCourse->next = student->courses;
    student->courses = newCourse;

    cout << "\nCourse enrolled successfully!\n";
}

// Withdraw Course
void withdrawCourse() {
    int roll;

    cout << "\nEnter Student Roll Number: ";
    cin >> roll;

    Student* student = search(roll);

    if (student == NULL) {
        cout << "Student not found!\n";
        return;
    }

    string courseName;

    cout << "Enter Course Name to withdraw: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, courseName);

    Course* temp = student->courses;
    Course* prev = NULL;

    // Search Course in Linked List
    while (temp != NULL && temp->courseName != courseName) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Course not found!\n";
        return;
    }

    // Delete Course from Linked List
    if (prev == NULL) {
        student->courses = temp->next;
    }
    else {
        prev->next = temp->next;
    }

    delete temp;

    cout << "\nCourse withdrawn successfully!\n";
}

// Remove Student
void removeStudent() {
    int roll;

    cout << "\nEnter Roll Number to remove: ";
    cin >> roll;

    Student* temp = head;
    Student* prev = NULL;

    // Find Student in Linked List
    while (temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Student not found!\n";
        return;
    }

    // Delete Student from Linked List
    if (prev == NULL) {
        head = temp->next;
    }
    else {
        prev->next = temp->next;
    }

    // Delete Student from Hash Table
    int index = hashFunction(roll);

    HashNode* h = hashTable[index];
    HashNode* p = NULL;

    while (h != NULL && h->roll != roll) {
        p = h;
        h = h->next;
    }

    if (h != NULL) {
        if (p == NULL) {
            hashTable[index] = h->next;
        }
        else {
            p->next = h->next;
        }

        delete h;
    }

    // Delete All Enrolled Courses
    Course* c = temp->courses;

    while (c != NULL) {
        Course* next = c->next;
        delete c;
        c = next;
    }

    delete temp;

    cout << "\nStudent removed successfully!\n";
}

// Display Students
void displayStudents() {
    Student* temp = head;

    if (temp == NULL) {
        cout << "\nNo students available!\n";
        return;
    }

    cout << "\n========== STUDENT LIST ==========\n";

    while (temp != NULL) {

        cout << "\nRoll Number: " << temp->roll;
        cout << "\nStudent Name: " << temp->name;

        cout << "\nEnrolled Courses: ";

        Course* c = temp->courses;

        if (c == NULL) {
            cout << "No courses enrolled";
        }

        while (c != NULL) {
            cout << c->courseName;

            if (c->next != NULL) {
                cout << ", ";
            }

            c = c->next;
        }

        cout << "\n----------------------------------\n";

        temp = temp->next;
    }
}

// Search Student
void searchStudent() {
    int roll;

    cout << "\nEnter Roll Number to search: ";
    cin >> roll;

    Student* temp = search(roll);

    if (temp == NULL) {
        cout << "\nStudent not found!\n";
    }
    else {
        cout << "\nStudent Found!\n";

        cout << "Roll Number: " << temp->roll << endl;
        cout << "Student Name: " << temp->name << endl;

        cout << "Enrolled Courses: ";

        Course* c = temp->courses;

        if (c == NULL) {
            cout << "No courses enrolled";
        }

        while (c != NULL) {
            cout << c->courseName;

            if (c->next != NULL) {
                cout << ", ";
            }

            c = c->next;
        }

        cout << endl;
    }
}

// Free Allocated Memory
void cleanup() {

    // Delete Student Linked List and Courses
    while (head != NULL) {

        Student* temp = head;
        head = head->next;

        Course* c = temp->courses;

        while (c != NULL) {
            Course* next = c->next;
            delete c;
            c = next;
        }

        delete temp;
    }

    // Delete Hash Table Nodes
    for (int i = 0; i < SIZE; i++) {

        while (hashTable[i] != NULL) {

            HashNode* temp = hashTable[i];

            hashTable[i] = hashTable[i]->next;

            delete temp;
        }
    }
}

// Main Function
int main() {
    int choice;

    do {
        cout << "\n========================================\n";
        cout << " UNIVERSITY STUDENT REGISTRATION SYSTEM\n";
        cout << "========================================\n";

        cout << "1. Register Student\n";
        cout << "2. Update Student\n";
        cout << "3. Enroll Course\n";
        cout << "4. Withdraw Course\n";
        cout << "5. Remove Student\n";
        cout << "6. Display Students\n";
        cout << "7. Search Student\n";
        cout << "8. Exit\n";

        cout << "========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                registerStudent();
                break;

            case 2:
                updateStudent();
                break;

            case 3:
                enrollCourse();
                break;

            case 4:
                withdrawCourse();
                break;

            case 5:
                removeStudent();
                break;

            case 6:
                displayStudents();
                break;

            case 7:
                searchStudent();
                break;

            case 8:
                cout << "\nThank you for using the system!\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 8);

    cleanup();

    return 0;
}
