#ifndef DELIMITERS_H
#define DELIMITERS_H

#include <iostream>
#include <fstream>
using namespace std;

class Delimiters{
  public:
    Delimiters(); //default constructor
    ~Delimiters(); //destructor
    int countDelimiters(string fileName); //syntax checker if there is an error with syntax or not

  private:
};

#endif
