// Filename: pointers.cpp

#include <string.h>
#include <iostream>
using namespace std;


struct Student
{
  string name;
  int id;
  int* mark;

  ~Student() {
    delete[] mark;
  }
};

void initStudent(Student* ptr, int marks); // function prototype for initialization
void displayStudent(const Student* ptr, int marks); // function prototype for printing

//*********************** Main Function ************************//
int main ()
{
  int numMarks;
  int numStudents;

  cout << "How many students? ";
  cin >> numStudents;
  cout << endl;

  Student* student = new Student[numStudents];

  for (int i = 0; i < numStudents; i++) {
    cout << "New student:" << endl;
    cout << "How many marks would you like to enter? ";
    cin >> numMarks;

    initStudent(&student[i], numMarks);      // initializing the object
    cout << endl;
    displayStudent(&student[i], numMarks);   // printing the object
    cout << endl;
  }

  delete[] student;
} // end main

//-----------------Start of functions----------------------------//

void initStudent(Student* ptr, int marks) {
  cout << "Enter student name: ";
  cin >> ptr->name;

  cout << "Enter student ID: ";
  cin >> ptr->id;

  ptr->mark = new int[marks];
  for (int i = 0; i < marks; i++) {
    cout << "Enter mark " << i + 1 << ": ";
    cin >> ptr->mark[i];
  }
}

void displayStudent(const Student* ptr, int marks) {
  cout << "Student info:" << endl;
  cout << "Name: " << ptr->name << endl;
  cout << "ID: " << ptr->id << endl;

  for (int i = 0; i < marks; i++)
    cout << "Mark " << i + 1 << ": " << ptr->mark[i] << endl;
}
