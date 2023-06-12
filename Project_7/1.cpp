#include <iostream>
using namespace std;

int **m;         //put your variable here
void ourTest(int **x) {
  m = x;     // OK
  m[0][1] = 2; // error
  m[0] = new int [10]; //error
  m ++;   // OK
}

int main() {
  int **a = new int *[10];
  for(int i = 0; i < 10; i ++) {
    a[i] = new int[20];
  }
  ourTest(a);
}