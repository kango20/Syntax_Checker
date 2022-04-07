#include "Delimiters.h"

int main(int argc, char** argv){
  Delimiters d; //creates an instance of the Delimiters class

  try{
    if (argc != 2){ //checks if user enters correct number of arguments
      cout << "Incorrect number of command line arguments." << endl;
      return 1; //exit
    }
    d.countDelimiters(argv[1]); // checks the syntax of the file inputted in the command line
    int run = 1;
    char yn;
    string name;
    while(run == 1){ //checks if user wants to analyze other files
        cout << "Would you like to analyze another file? y/n" << endl;
        cin >> yn;
        if (yn == 'y'){
          cout << "Enter file name: ";
          cin >> name;
          d.countDelimiters(name); //checks the syntax of another file the user inputs
          run = 1;
        }
        else if (yn == 'n'){ //user does not want to analyze another file
          run = 0;
        }
        else{ //error handling
          cout << "Invalid input" << endl;
          cin >> yn;
          run = 1;
        }
    }
  }
  catch(runtime_error& excpt){ //catches runtime error
    cout << excpt.what() << endl;
  }
}
