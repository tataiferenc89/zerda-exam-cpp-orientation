#define CATCH_CONFIG_MAIN
#include "Caesar.h"
#include "Catch.h"

using namespace std;

void string_to_file(string character, string file_name);

TEST_CASE("Check if shift works") {
  Caesar caesar;
  string charater = "a";
  string file_name = "test_file_1.txt";
  string_to_file(charater,file_name);
  caesar.get_text_from_file(file_name);
  caesar.encryptr(1);
  REQUIRE(caesar.get_text()[0][0] == 'b');
}

TEST_CASE("Check if negative shift works") {
  Caesar caesar;
  string charater = "b";
  string file_name = "test_file_1.txt";
  string_to_file(charater,file_name);
  caesar.get_text_from_file(file_name);
  caesar.encryptr(-1);
  REQUIRE(caesar.get_text()[0][0] == 'a');
}

TEST_CASE("Check if shift above Z works") {
  Caesar caesar;
  string charater = "z";
  string file_name = "test_file_1.txt";
  string_to_file(charater,file_name);
  caesar.get_text_from_file(file_name);
  caesar.encryptr(1);
  REQUIRE(caesar.get_text()[0][0] == 'a');
}

TEST_CASE("Check if negative shift if character is a") {
  Caesar caesar;
  string charater = "a";
  string file_name = "test_file_1.txt";
  string_to_file(charater,file_name);
  caesar.get_text_from_file(file_name);
  caesar.encryptr(-1);
  REQUIRE(caesar.get_text()[0][0] == 'z');
}

TEST_CASE("Check if shift works for capitals") {
  Caesar caesar;
  string charater = "A";
  string file_name = "test_file_1.txt";
  string_to_file(charater,file_name);
  caesar.get_text_from_file(file_name);
  caesar.encryptr(1);
  REQUIRE(caesar.get_text()[0][0] == 'B');
}
void string_to_file(string character, string file_name) {
  ofstream my_text;
  if(!my_text.is_open()) {
    my_text.open(file_name);
  }
  my_text << character;
  my_text.close();
}
