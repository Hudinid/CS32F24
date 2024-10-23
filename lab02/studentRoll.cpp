#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  // STUB
  
  Node* n = new Node();

  n->s = new Student(s);
  n->next = nullptr;
  

  if(!head) {
    n->next = this->tail;
    this->head = n;
  }
  else if(!tail) {
    this->tail = n;
    this->head->next = tail;
  }
  else {
    this->tail->next = n;
    this->tail = this->tail->next;
  }
}

std::string StudentRoll::toString() const {
  Node* n = this->head;
  std::string ret;
  ret += "[";
  if(!n) {
    ret += "]";
    return ret;
  }
  while(n->next) {
    ret += n->s->toString() + ",";
    n = n->next; 
  }
  ret += n->s->toString();
  ret += "]";
  return ret;
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  // STUB
  head = tail = NULL;
  
  Node* temp = orig.head;  

  if(!temp) { 
    return;
  }

  head = new Node();
  head->s = new Student(temp->s->getName(),temp->s->getPerm());
  
  head->next = nullptr;  

  Node* n = head;

  temp = temp->next;
  // std::cout<<head->s->toString() << std::endl;

  while(temp) {

    // std::cout<< "here! " << std::endl;
    Node* newNode = new Node();
    newNode->s = new Student(temp->s->getName(),temp->s->getPerm());
    newNode->next = nullptr;
    // std::cout<<newNode->s->toString() << std::endl;


    n->next = newNode;

    n = n->next;

    temp = temp->next;
  }

  tail = n;
}

StudentRoll::~StudentRoll() {
  // STUB
  Node* n = this->head;
  Node* temp;
  while(n) {
    temp = n->next;
    delete n->s;
    delete(n);
    n = temp;
  }
  
  // delete head;
  this->head = nullptr;
  this->tail = nullptr;
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)
  
  // head = tail = nullptr;

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...

  Node* n1 = this->head;
  Node* temp1;
  while(n1) {
    temp1 = n1->next;
    delete n1->s;
    delete(n1);
    n1 = temp1;
  }
  
  this->head = nullptr;
  this->tail = nullptr;


  Node* temp = right.head;  
  if(!temp) {
    return *this;
  }

  head = new Node();
  head->s = new Student(temp->s->getName(),temp->s->getPerm());
  head->next = nullptr;  

  Node* n = head;
  temp = temp->next;

  while(temp) {
    

    Node* newNode = new Node();
    newNode->s = new Student(temp->s->getName(),temp->s->getPerm());
    newNode->next = nullptr;
    n->next = newNode;
    n = n->next;
    temp = temp->next;
  }

  tail = n;

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}





