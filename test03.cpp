//============================================================================
// Name        : test03.cpp
// Author      : Feri
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Caesar.h"

using namespace std;

int main(int argc, char *argv[]) {
  cout << argc << endl;
  if(argc == 4) {
    char* input = argv[1];
    int key = atoi(argv[3]);
    Caesar example(input,key);
  }

  else if(argc == 6) {
    if(argv[2][1] == 's') {
      char* input = argv[1];
      char* output = argv[5];
      int key = atoi(argv[3]);
      Caesar example2(input,key,output);
    }

    else if(argv[2][1] == 'o') {
      char* input = argv[1];
      char* output = argv[3];
      int key = atoi(argv[5]);
      Caesar example2(input,key,output);
    }

  }
  else {
    cout << "Not valid argument number";
  }
  return 0;
}
