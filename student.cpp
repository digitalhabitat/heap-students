// student.cpp (implementation)

#include "student.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>

using namespace std;


Student::Student(){
  // new allows us to store on the heap using the type specifier like an object
  // Here the pointers declared in the interfaced are assigned to 50 
  // element arrays stored on the heap

  Surname = new string[50];
  GivenName = new string[50];
  address = new Address[50];
  dob = new Date[50];
  graduation = new Date[50];
  gpa = new double[50];
  creditHours = new int[50];

  // the arrays however have no intialization, they could contain anything
  // the process below assigns sensible default values for each element
  
  fill_n(Surname, 50, "anonymous");
  fill_n(GivenName, 50, "anonymous");
  fill_n(address, 50, Address());
  fill_n(dob, 50, Date());
  fill_n(graduation, 50, Date());
  fill_n(gpa, 50, 0);
  fill_n(creditHours, 50, 0);

} // end null parameter constructor

Student::~Student(){
  // The destructor is necessary for removing things off the heap
  // this is similar to deleting nodes in linked list
  // where its important manage the data creation/destruction properly
  // to avoid memory leaks
  // objects responsible for allocating memory should be responsible for 
  // destroying it. Your calls to new should be equal to the calls to delete.
  delete[] Surname;
  delete[] GivenName;
  delete[] address;
  delete[] dob;
  delete[] graduation;
  delete[] gpa;
  delete[] creditHours;
}

void Student::printName(){
  stringstream ss;
  int i;
  for( i = 0; i < 50 ; i++){
    cout << "Full Name: " << GivenName[i] << " " << Surname[i] << endl;
    address[i].printFullAddress();
    dob[i].printDate();
    graduation[i].printDate();
    cout.precision(4);
    cout << "GPA: " << gpa[i] << endl;
    cout << "Credit Hours Complete: " << creditHours[i] << endl;
    cout << endl;
  }
}

void Student::loadData(){  
  // Parsing and File I/O declarations
  // instantiate ifstream(input stream class) object
  // instantiate ofstream(output stream class) object
 
  ifstream inFile;
  ofstream outFile;

  string currentLine;
  string subLine;

  stringstream current;
  stringstream converter;  

  int i;
  int int_num;
  double double_num;

  inFile.open("students.dat");
  if (inFile.is_open()){
    // Read student.dat file and assign data to heap variables
    i = 0;
    // loads currentLine(string) till delimiter character \n is found
    getline(inFile,currentLine);
    while(getline(inFile,currentLine)){

    // set no errors and clear stringstreams
    current.clear();
    current.str(""); 

    // load contents of currentLine(string) into current(stringstream)
    current.str(currentLine);
    
    // separate data from commas and assign to heap variables rinse and repeat  
    getline(current,subLine,',');
    Surname[i] = subLine; 

    getline(current,subLine,',');  
    GivenName[i] = subLine;
    
    getline(current,subLine,',');
    address[i].setAddress1(subLine);

    getline(current,subLine,',');
    address[i].setAddress2(subLine);

    getline(current,subLine,',');
    address[i].setCity(subLine);
    
    getline(current,subLine,',');
    address[i].setState(subLine);
    
    getline(current,subLine,',');
    // this method is passes the string data to a stringstream
    // then passes the stringstream data to int variable
    converter << subLine;
    converter >> int_num;
    address[i].setZip(int_num);

    getline(current,subLine,',');
    dob[i].setDate(subLine);

    getline(current,subLine,',');
    graduation[i].setDate(subLine);
     
    // clean out converter
    converter.clear();
    converter.str("");
    
    getline(current,subLine,',');
    // convert string to double for assignment to gpa
    converter << subLine;
    converter >> double_num;
    gpa[i] = double_num;

    converter.clear();
    converter.str("");

    getline(current,subLine);
    converter << subLine;
    converter >> int_num;
    creditHours[i] = int_num;
    i += 1; 
  } // end read student.dat
  inFile.close();
  cout << "student.dat loaded and stored on heap" << endl;
  } // end if inFile is open
  else{
    cout << "Could not open student.dat" << endl;
  }    
} // end loadData method

void Student::write_fullReport(){
  int i;

  // I/O Declartions
  ofstream outFile;

  outFile.open("fullReport.txt");

  if(outFile.is_open()){
    // write to fullReport.txt
    for( i = 0; i < 50 ; i++){
      outFile << "Full Name: " << GivenName[i] << " " << Surname[i] << endl;
      outFile << "StreetAddress: " << address[i].getAddress1() << endl;
      outFile << "Address2: " << address[i].getAddress2() << endl;
      outFile << "City: " << address[i].getCity() << endl;
      outFile << "State: " << address[i].getState() << endl;
      outFile << "ZipCode: " << address[i].getZipCode() << endl;
      outFile << "Date Of Birth: " << dob[i].getMonth() << "/"
      << dob[i].getDay() << "/" << dob[i].getYear() << endl;
      outFile << "Date Of Graduation: " << graduation[i].getMonth() << "/"
      << graduation[i].getDay() << "/" << graduation[i].getYear() << endl;
      outFile << "GPA: " << gpa[i] << endl;
      outFile << "Credit Hours Complete: " << creditHours[i] << endl;
      outFile << endl;
    } // end write to fullReport.txt
  outFile.close();
  cout << "fullReport.txt created" << endl;
  } // end if outFile is open
  else{
    cout << "Could not open fullReport.txt" << endl;
  }
  
} // end write_fullReport() method

void Student::write_shortReport(){
  
  int i;
  // I/O Declartions
  ofstream outFile;

  outFile.open("shortReport.txt");
  
  if(outFile.is_open()){
    // write to shortReport.txt
    for( i = 0; i < 50 ; i++){
      outFile << "Full Name: " << GivenName[i] << " "; 
      outFile << Surname[i] << endl;
      outFile << endl;
    } // end write to shortReport.txt
  outFile.close();
  cout << "shortReport.txt created" << endl; 
  } // end if outFile is open
  else{
    cout << "Could not open shortReport.txt" << endl;
  }
} // end write_shortReprot() method

void Student::write_alphaReport(){
  
  int i, j;
  int MAX = 50;

  // I/O Declartions
  ofstream outFile;

  outFile.open("alphaReport.txt");

  if(outFile.is_open()){
    // alphabetically sort heap of students (bubble sort)
    for (i = 0; i < MAX-1; i++){
      for (j = 0; j < MAX-1-i; j++){
        if((Surname[j].compare(Surname[j+1])) > 0){
          swap(j+1,j);
        }
      }
    } // end alphabetically sort heap of students
    
    // write to alphaReport.txt
    for( i = 0; i < 50 ; i++){
      outFile << "Full Name: " << GivenName[i] << " "; 
      outFile << Surname[i] << endl;
      outFile << endl;
    } // end write to alphaReport.txt
    outFile.close();
    cout << "alphaReport.txt created" << endl; 
  } // end if outFile is open
  else{
    cout << "Could not open alphaReport.txt" << endl;
  }  
  
} // end write_alphaReport() method

void Student::swap(int a, int b){

  // swap student data 
  string tempName1, tempName2;
  Address tempAddress;
  Date tempDOB, tempGrad;
  double tempGPA;
  int tempCredits;
  
  tempName1 = Surname[a];
  tempName2 = GivenName[a];
  tempAddress =  address[a];
  tempDOB = dob[a];
  tempGrad = graduation[a];
  tempGPA = gpa[a];
  tempCredits = creditHours[a];
  
  Surname[a] = Surname[b];
  GivenName[a] = GivenName[b];
  address[a] = address[b];
  dob[a] = dob[b];
  graduation[a] = graduation[b];
  gpa[a] = gpa[b];
  creditHours[a] = creditHours[b];
  
  Surname[b] = tempName1;
  GivenName[b] = tempName2;
  address[b] = tempAddress;
  dob[b] = tempDOB;
  graduation[b] = tempGrad;
  gpa[b] = tempGPA;
  creditHours[b] = tempCredits;
  
} // end swap() method
