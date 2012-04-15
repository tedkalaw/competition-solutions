/*
 * Problem Set Volume 1, Problem 100
 * "The 3n + 1 problem"
 * 
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=3&page=show_problem&problem=36
 *
 */

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

int cycle_length(int start){
  int len = 1;
  while(start > 1){
    if(start % 2 == 1){
      start = (3*start) + 1;
      ++len;
    }
    else{
      start = start / 2;
      ++len;
    }
  }

  return len;
}

int main(){
  deque<string> to_process;
  string input;
  int i,j;
  istringstream is("");

  getline(cin, input);
  while(!input.empty()){
    to_process.push_front(input);
    getline(cin, input);
  }

  int max_cycle;
  while(!to_process.empty()){
    max_cycle = 1;
    is.clear();
    is.str(to_process.back());
    to_process.pop_back();
    is >> i >> j;
    for(int k=i; k<=j; k++){
      max_cycle = max(max_cycle, cycle_length(k));
    }
    cout << i << " " << j << " " << max_cycle << endl;
  }

}
