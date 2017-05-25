# heap-students

## Develop Process Documentation

Three classes Address, Date, and Student are use to create a student record
system. Below are the details of the class data structure.

Student
  First name
  Last name
  Address(object)
  Date(object)
  Date(object)
  gpa
  credit hours completed

Address
  address line 1
  address line 2
  city
  state
  zip code

Date
  month
  day
  year

The Student data will be a large array stored on the heap. This means that
for all the private properties declared in the Student interface should be
declared as a pointer to an array as descrbed as below.
```cpp
string *Surname;
Address *address;
double *gpa;
```
Initially I started will the following:
```cpp
string Surname;
Address address;
double gpa;
```
This makes things difficult because the student object in main needs a method
to list all the student data stored on the heap. Using an array of student
properties instead of array of student objects instantiated in main allows the
class to have a better suited structure for accessing data of several students.

The Address and Date interfaces however do not need its properties to be arrays.
The Student class will not need to declare additional Address or Date properties
for any element of the Student class property arrays. This assumes that each
student should have an identical amount of properties and the number of
elements created in the arrray of each property should be the same and
represent the number of students stored on the heap. The index should coincide
with a single student.  

The confusion comes from the student class not being plural. While the main
propram will only need to instantiate a single student object. The student
class has the functionality to store data for more than just one student, and
will be demostrating that in this assignment.

The null pararamter constructor for Student should define the arrays for 50
elements to be stored on the heap like so.
```cpp
Student::Student(){
  Surname = new string[50];
  address = new Address[50];
  gpa = new double[50]; 
}
```
For blackbelt options, It might be useful to implement a feature that will
determine the amount of elements needed by using the dat file as a parameter.
The basic version will assume 50 elements, with default definitions, use a 
method to read .dat file and copy data over to corresponding elements.

Below are some method brainstorming for listing names and copying .dat file

```cpp
Student::listNames(){
  till x<50
  print givenName[x]
}  
```

```cpp
Student::loadData(){
  inFile.open("student.dat");
  for(i = 0; i < 50; i++){
    while(getline(inFile,currentLine)){
      current.str(currentLine);
      while(getline(current,subLine, ',')){
        givenName[i] = subline;
        or
        converter.str(subline);
        converter >> gpa[i];
      }
    }
  }
}
```

# Version 1 Post-Completion thoughts (10/28/2016)
Some of the functionality of methods might have been easier to implement
if an additional class maybe called Class or School was made. This School
object then could be instantiated in main and contain an array of Student
objects instead of the Student class containing an array of Student data.
This was apparent during the making of the alpahaReport method. Swaping data
between students seemed to be more work than should have necessary. The better
solution might look something like this.

```cpp
void School::swap(int a, int b){
   temp Student = Student[a];
   Student[a] = Student[b];
   Student[b] =  temp;
}
```

Other than that, program seems to work properly and without memory leaks. If my
understanding of how valgrind works, the still reachable memory is a side effect
of valgrind being compiled with the program. The memory location of the reachable
block was associated with a file within the valgrind directory.
