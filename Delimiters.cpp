#include "GenStack.h"
#include "Delimiters.h"

Delimiters::Delimiters(){} //default constructor

Delimiters::~Delimiters(){} //destructor

int Delimiters::countDelimiters(string fileName){ //function to find the syntax checker for delimiters
  ifstream inFS; // input file stream
  string line;
  GenStack<char> delimiter; // creates an instance of delimiter with type char

  //opens the input file and output file
  inFS.open(fileName);

  // throws an error if file does not open
  if(!inFS.is_open()){
    throw runtime_error("Could not open file");
  }

  int lineNum = 0;

  while(getline(inFS, line)){ //read from file
    ++lineNum;
    for(int i = 0; i < line.size(); ++i){ //checks for each character in the file
      switch(line[i]){ //checks for opening delimiter
        case '{':
        case '[':
        case '(':
          delimiter.push(line[i]); //adds the opening delimiter onto the stack
          break;
        default:
          break;
      }

      if(delimiter.isEmpty() && (line[i] == '}' || line[i] == ']' || line[i] == ')')){ // informs user of a hanging closing delimiter
        char expected;
        //finds the corresponding opening delimiter that is missing
        if(line[i] == '}'){
          expected = '{';
        }
        else if(line[i] == ')'){
          expected = '(';
        }
        else if(line[i] == '['){
          expected = ']';
        }
        cout << "Line " << lineNum << ": found '" << line[i] << "'"<< "expected opening '" << expected << "'" << endl;
        return 1;
      }

      if((line[i] == '}' && delimiter.peek() == '{') || (line[i] == ']' && delimiter.peek() == '[') || (line[i] == ')' && delimiter.peek() == '(')){ //if matching delimiter found, remove delimiter from stack
        delimiter.pop(); //removes from stack
      }
      else if((line[i] == '}' && delimiter.peek() != '{') || (line[i] == ']' && delimiter.peek() != '[') || (line[i] == ')' && delimiter.peek() != '(')){ //if no matching delimiter found, inform the user
        char expected;

        //finds the corresponding closing delimiter that is missing
        if(delimiter.peek() == '{'){
          expected = '}';
        }
        else if(delimiter.peek() == '('){
          expected = ')';
        }
        else if(delimiter.peek() == '['){
          expected = ']';
        }
        cout << "Line " << lineNum << ": expected '" << expected << "'"<< "found " << line[i] << endl;
        return 1;
      }
    }
  }


  if(!delimiter.isEmpty()){ // informs user if there are is a missing a closing delimeter once the file is all read
    char expected;
    //finds the corresponding closing delimiter that is missing
    if(delimiter.peek() == '{'){
      expected = '}';
    }
    else if(delimiter.peek() == '('){
      expected = ')';
    }
    else if(delimiter.peek() == '['){
      expected = ']';
    }
    cout << "Reached end of file, missing '" << expected << "'" << endl;
    return 1;
  }



  if(delimiter.isEmpty()){ //informs the user, there is no syntax error
    cout << "delimiter syntax is correct" << endl;
  }
  //Done with file, so close it
  inFS.close();
  return 0;
}
