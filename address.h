// address.h
#ifndef ADDRESS_H_EXIST
#define ADDRESS_H_ESIST

#include <string>

//declare address class
class Address{
  private:
    std::string address1;
    std::string address2;
    std::string city;
    std::string state;
    int zipCode;
  public:
    Address();
    ~Address();
    void setAddress1(std::string address1);
    void setAddress2(std::string address2);
    void setCity(std::string city);
    void setState(std::string state);
    void setZip(int zip);
    void printFullAddress();
    std::string getAddress1();
    std::string getAddress2();
    std::string getCity();
    std::string getState();
    int getZipCode();

};

#endif
