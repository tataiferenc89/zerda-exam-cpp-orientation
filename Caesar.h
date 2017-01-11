/*
 * Caesar.h
 *
 *  Created on: 2017 jan. 11
 *      Author: Feri
 */

#ifndef CAESAR_H_
#define CAESAR_H_
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Caesar {
private:
  vector<string> text;

public:
  Caesar();
  Caesar(string,int);
  Caesar(string,int,string);
  vector<string> get_text_from_file(string);
  vector<string> get_text();
  void print_out_text_vector();
  void print_out_file(string);
  void write_text_to_file(string);
  void encryptr(int);
  void decryptr(int);

};

#endif /* CAESAR_H_ */
