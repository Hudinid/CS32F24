#include "Roster.h"

#include <cstdlib>
#include <fstream>
#include <cassert>

Roster::Roster() {
  // initialize to empty array

  this->numStudents = 0;
  for (int i=0; i<ROSTER_MAX; i++) {
    this->students[i] = NULL;
  }

}

void Roster::resetRoster() {
 // To avoid memory leaks:
  //  Recycle memory for all allocated students on roster
  
  while (this->numStudents > 0) {
    delete this->students[this->numStudents - 1];
    this->numStudents --;
  }

}

void Roster::addStudentsFromFile(std::string filename) {
  std::ifstream ifs; // the stream we will use for the input file
  ifs.open(filename);
  
  if (ifs.fail()) {
    std::cerr << "Could not open input file: "
	      << filename << std::endl;
    exit(2); 
  }

  // ifs is an instance of ifstream
  // ifstream inherits from istream, 
  //   i.e. ifs is-a istream

  this->addStudentsFromStream(ifs);

}

void Roster::addStudentsFromStream(std::istream &is) {

  this->resetRoster();

  std::string thisLine;
  // Try to read past the header line.
  getline(is,thisLine);
  if ( is.eof() || is.fail() ) {
    std::cerr << "Unable to read first line of input stream" << std::endl;
    exit(3);
  }

  getline(is,thisLine);
  while (  !is.eof() && !is.fail() ) {
    // If we get here, it means the most recent attempt to read succeeded!
    // So do something with thisLine
    
    Student *sPtr = new Student(thisLine);
    this->students[this->numStudents] = sPtr;
    this->numStudents++;
    
    // try to read another line
    getline(is,thisLine);
  } // end while

}

int Roster::getNumStudents() const { 
  return this->numStudents; // stub
}

Student Roster::getStudentAt(int index) const { 
  int p = this->students[index]->getPerm();
  std::string lastName = this->students[index]->getLastName();
  std::string firstMidName = this->students[index]->getFirstAndMiddleNames();

  Student ret(p, lastName, firstMidName);
  return ret;
}

std::string Roster::toString() const {
  std::string result = "{\n";
  // std::cout << this->students[0]->toString() << std::endl;   // @@@ RESTORE THIS 
  for (int i = 0; i < this->numStudents-1; i ++) {
    result += this->students[i]->toString() + ",\n";
  }
  result += this->students[this->numStudents-1]->toString() + "\n";
  result += "}\n";
  return result;

}

void Roster::sortByPerm() {
  // SELECTION SORT
  for(int i = this->numStudents; i > 0; i --) {
    sortByPermHelper(i);
  }

}

int Roster::indexOfMaxPermAmongFirstKStudents(int k) const {
  // std::cout << k << std::endl;
  int max = this->students[k-1]->getPerm();
  int ret = k-1;
  for(int i = 0; i < k; i ++) {
    if(this->students[i]->getPerm() > max) {
      max = this->students[i]->getPerm();
      ret = i;
      // std::cout << i << std::endl;
    }
  }

  return ret; // STUB
}

void Roster::sortByPermHelper(int k) {
  // swaps max perm from [0..k-1] with elem [k-1]
  
  // std::cout << std::to_string(k) << " " << this->toString() << std::endl;
  int im = indexOfMaxPermAmongFirstKStudents(k);

  // std::cout <<"hit" << " " << std::to_string(im) << std::endl;
  // now swap the pointers between index im and index k-1
  Student* temp = this->students[im];

  // std::cout << temp->toString() << std::endl;
  // std::cout << this->students[k-1]->toString() << std::endl;

  this->students[im] = this->students[k-1];
  
  // std::cout << this->students[im]->toString() << std::endl;

  this->students[k-1] = temp;

  // std::cout << this->students[k-1]->toString() << std::endl;


  // delete temp;
  // THIS IS STILL A STUB !!!
  
}
