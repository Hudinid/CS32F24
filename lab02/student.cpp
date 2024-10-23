#include "student.h"
#include <string>
#include <cstring>

Student::Student(const char * const name, int perm) {
  
  this->name = new char[strlen(name)+1];
  strcpy(this->name, name);

  this->perm = perm;
}

int Student::getPerm() const {
  return this->perm;
}

const char * const Student::getName() const {
  return this->name;
}

void Student::setPerm(const int permNumber) {
  this->perm = permNumber;
}

void Student::setName(const char * const name) {
  // if(strlen(this->name) > 1) {
  //   delete[] this->name;
  // }
  delete[] this->name;
  this->name = new char[strlen(name)+1];
  
  strcpy(this->name, name);
}


Student::Student(const Student &orig) {
  // this->setName(orig.getName());
  this->name = new char[strlen(orig.getName())+1];
  strcpy(this->name, orig.getName());
  this->setPerm(orig.getPerm());
}

Student::~Student() {
  delete[] this->name;
  // delete &perm;
}

Student & Student::operator=(const Student &right) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...
  delete[] this->name;
  
  this->name = new char[strlen(right.getName())+1];
  strcpy(this->name, right.getName());

  this->setPerm(right.getPerm());

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 

}

std::string Student::toString() const {
  std::string ret;

  ret += "[";
  ret += this->getName();
  ret += ',';
  ret += std::to_string(this->getPerm());
  ret += ']';

  return ret;
}

