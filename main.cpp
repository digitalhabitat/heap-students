// main.cpp

#include "student.h"
#include <iostream>

int main(){

  // instantiate a student object POINTER with the name c
  // the new operator allocates memory for the data type or class
  // the null parameter constructor stores on the heap
  // so we must make sure we can properly delete them off the heap as well

  std::cout << "Press enter to instantiate a single class on the heap.";
  std::cout << std::endl;
  std::cin.ignore();

  // dynamically allocate Student object and assign the address to c
  Student *c = new Student();

  c->loadData();
  //c->printName();
  c->write_fullReport();
  c->write_shortReport();
  c->write_alphaReport();

  // delete c off of the heap
  delete c;
  
  std::cout << "object deleted, Press enter to continue" << std::endl;  
  std::cin.ignore();

  return 0;
}
