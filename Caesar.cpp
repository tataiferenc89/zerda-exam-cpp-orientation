/*
 * Caesar.cpp
 *
 *  Created on: 2017 jan. 11
 *      Author: Feri
 */

#include "Caesar.h"

Caesar::Caesar() {

}

Caesar::Caesar(string input_file,int key) {
  get_text_from_file(input_file);
  encryptr(key);
  print_out_text_vector();
}

Caesar::Caesar(string input_file,int key,string output_file) {
  get_text_from_file(input_file);
  encryptr(key);
  write_text_to_file(output_file);
}

vector<string> Caesar::get_text() {
  return text;
}

void Caesar::print_out_text_vector() {
  for(unsigned int i = 0; i < text.size(); i++) {
    std::cout << text[i] << std::endl;
  }
}

void Caesar::print_out_file(string output) {
  ifstream output_text;
  string line;
  if(!output_text.is_open()) {
    output_text.open(output);
  }
  while(getline(output_text,line)) {
     cout << line << endl;
  }
  output_text.close();
}

vector<string> Caesar::get_text_from_file(string input_file) {
  string line;
  ifstream input_text;
  if(!input_text.is_open()) {
    input_text.open(input_file);
  }
  while(getline(input_text,line)) {
    text.push_back(line);
  }
  input_text.close();
  return text;
}

void Caesar::write_text_to_file(string output) {
  ofstream output_text;
  if(!output_text.is_open()) {
    output_text.open(output);
  }
  for(unsigned int i = 0; i < text.size(); i++) {
    output_text << text[i] << endl;
  }
  output_text.close();
}

void Caesar::encryptr(int key) {
  if (key > 26) {
    key %= 26;
  }
  for(unsigned int i = 0; i < text.size(); i++) {
    for(unsigned int j = 0; j < text[i].length(); j++) {
      if(text[i][j] > 64 && text[i][j] < 91) {
        text[i][j] += key;
        if(text[i][j] < 65) {
          text[i][j] += 26;
        }
        else if(text[i][j] > 90) {
          text[i][j] -= 26;
        }
      }
      else if(text[i][j] > 96 && text[i][j] < 123) {
        text[i][j] += key;
        if(text[i][j] < 97) {
          text[i][j] += 26;
        }
        else if(text[i][j] > 122) {
          text[i][j] -= 26;
        }
      }
    }
  }
}

void Caesar::decryptr(int key) {
  key *= (-1);
  encryptr(key);
}
