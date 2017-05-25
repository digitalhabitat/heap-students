// address.cpp (implementation)
#include "address.h"
#include <iostream>

using namespace std;

Address::Address(){
  Address::address1 = string("n/a");
  Address::address2 = string("n/a");
  Address::city = string("n/a");
  Address::state = string("n/a");
  Address::zipCode = int(0);
} // end null parameter constructor

Address::~Address(){
} // end Address desctructor

void Address::setAddress1(string address){
  Address::address1 = address;
} // end setAddress method

void Address::setAddress2(string address){
  Address::address2 = address;
} // end setAddress2 method

void Address::setCity(string icity){
  Address::city = icity;
} // end setCity method

void Address::setState(string istate){
  Address::state = istate;
} // end setState method

void Address::setZip(int izip){
  Address::zipCode = izip;
} // end setZip method

void Address::printFullAddress(){
  cout << "StreetAddress: " << address1 << endl;
  cout << "Address2: " << address2 << endl;
  cout << "City: " << city << endl;
  cout << "State: " << state << endl;
  cout << "ZipCode: " << zipCode << endl;
} // end printFfullAddress method

string Address::getAddress1(){
  return address1;
} // end getAddress1 method 

string Address::getAddress2(){
  return address2;
} // end getAddress2 method

string Address::getCity(){
  return city;
} // end getCity method

string Address::getState(){
  return state;
} // end getState method

int Address::getZipCode(){
  return zipCode;
} // end getZipCode method
