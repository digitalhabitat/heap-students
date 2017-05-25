// student.h
#ifndef STUDENT_H_EXIST
#define STUDENT_H_EXIST

// The data for student "address" and "date" are designed as their own class
// we must remember to include their header files in this student header
// This allow us to declare the classes Address and Date
// as a property of Student (a class that contains more classes)

#include "address.h"
#include "date.h"
#include <string>

// Now that the address and date header files have been included in the student
// header file we only need to include student.h when using this class
// Student is the complete class with other classes pack inside

// delcare properites as pointers to store on heap
// look at implementation for more info

// declare student class
class Student{
  private:
    std::string *Surname;
    std::string *GivenName;
    Address *address;
    Date *dob;
    Date *graduation; 
    double *gpa;
    int *creditHours;
  public:
    Student();
    ~Student();
    void setLastName(std::string name);
    void setFirstName(std::string name);
    void setGpa(double gpa);
    void setCreditHours(int credits);
    void printName();
    void loadData();
    void write_fullReport();
    void write_shortReport();
    void write_alphaReport();
    void swap(int a, int b);
    
}; // end student class declaration

#endif
