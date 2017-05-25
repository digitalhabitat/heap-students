// date.cpp (implementation)
#include "date.h"
#include <iostream>
#include <sstream>

using namespace std;

Date::Date(){
  Date::month = int(0);
  Date::day = int(0);
  Date::year = int(0);
} // end null parameter constructor

Date::~Date(){
  //delete month, day, year;
} // end date destructor

void Date::setMonth(int num){
  month = num;
} // end setMonth method

void Date::setDay(int num){
  day = num;
} // end setDay method

void Date::setYear(int num){
  year = num;
} // end setYear method

void Date::printDate(){
  cout << month << "/" << day << "/" << year << endl;
} // end printDate()

void Date::setDate(string date){
  
  // Separate data from forward slashes(/) in data in string 
  // and assign data to Date variables
  
  stringstream current;
  stringstream converter;

  string value;
  int int_num;
  
  // cleat out current and converter
  current.clear();
  current.str("");

  converter.clear();
  converter.str("");
 
  // load string data into current
  current.str(date);
  
  // grab data till '/' is reached and assign data
  getline(current,value,'/');
  converter << value;
  converter >> int_num;
  month = int_num;

  converter.clear();
  converter.str("");
 
  // repeat last process
  getline(current,value,'/');
  converter << value;
  converter >> int_num;
  day = int_num;

  converter.clear();
  converter.str("");

  // repeat again no delimiter necessary
  getline(current,value);
  converter << value;
  converter >> int_num;
  year = int_num; 
} // end setDate method

int Date::getMonth(){
  return month;
} // end getMonth() method

int Date::getDay(){
  return day;
} // end getDay() method

int Date::getYear(){
  return year;
} // end getYear() method

