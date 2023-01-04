#include <iostream>
#include <string>
#include <thread>
using namespace std;
// input thread
void input_thread(string& input_string) {
  // get input from user
  getline(cin, input_string);
}

// reverse thread
void reverse_thread(const string& input_string) {
  // reverse the string
  string reversed_string(input_string.rbegin(), input_string.rend());
  cout << reversed_string << endl;
}

// capital thread
void capital_thread(const string& input_string) {
  // capitalize the characters of the string
  string capitalized_string;
  for (char c : input_string) {
    capitalized_string += toupper(c);
  }
  cout << capitalized_string << endl;
}

// shift thread
void shift_thread(const string& input_string) {
  // shift each character of the string two times
  string shifted_string;
  for (char c : input_string) {
    shifted_string += char(int(c) + 2);
  }
  cout << shifted_string << endl;
}

int main() {
  string input_string;
  // create the threads
  thread input_t(input_thread, ref(input_string));
  // start the input thread
  input_t.join();
  
  thread reverse_t(reverse_thread, cref(input_string));
  thread capital_t(capital_thread, cref(input_string));
  thread shift_t(shift_thread, cref(input_string));

  // start the other threads
  reverse_t.join();
  capital_t.join();
  shift_t.join();
  
  if (input_t.joinable()) 
  {
  cout << "Input thread is still running" << endl;
  } 
  else 
  {
  cout << "Input thread has finished" << endl;
  }
  
  if (input_t.joinable()) 
  {
  cout << "Input thread is still running" << endl;
  } 
  else 
  {
  cout << "Input thread has finished" << endl;
  }
  return 0;
}

