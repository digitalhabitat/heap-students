// date.h
#ifndef DATE_H_EXIST
#define DATE_H_EXIST

#include <string>

// declare date class
class Date{
  private:
    int month;
    int day;
    int year;    
  public:
    Date();
    ~Date();
    void setMonth(int month);
    void setDay(int day);
    void setYear(int year);
    void setDate(std::string date);
    void printDate();
    int getMonth();
    int getDay();
    int getYear();
};

#endif
