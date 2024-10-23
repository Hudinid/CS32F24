#include "Student.h"
#include <sstream>

Student::Student(int perm, 
		 std::string lastName, 
		 std::string firstAndMiddleNames) {
      this->perm = perm;
      this->lastName = lastName;
      this->firstAndMiddleNames = firstAndMiddleNames;
}

int Student::getPerm() const { 
  return this->perm;
}

std::string Student::getLastName() const { 
  return this->lastName;
}

std::string Student::getFirstAndMiddleNames() const { 
  return this->firstAndMiddleNames;
}

std::string Student::getFullName() const { 
  return this->firstAndMiddleNames + " " + this->lastName;
}

std::string Student::toString() const { 
  std::string ret;
  ret = '['+ std::to_string(perm) + ',' + this->lastName + ',' + this->firstAndMiddleNames + ']';
  return ret;
  /*
  // e.g. [12345,Smith,Malory Logan]
  
  std::ostringstream oss;
  
  oss << "[" 
      << this->getPerm() << ","
      << this->getLastName() << ","
      << this->getFirstAndMiddleNames() << "]";
  return oss.str();
  */

} 

