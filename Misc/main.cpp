#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {
  cout << "Hello World!\n";
  set<string> M = {"banana", "apple"};

  map<string, int> M2 = {{"banana", 1}, {"apple", 2}};

  for (auto i : M) {
    cout << i << endl;
  }

  for (auto i : M2) {
    cout << i.first << " " << i.second << endl;
  }

}