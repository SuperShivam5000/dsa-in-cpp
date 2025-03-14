#include <iostream>
using namespace std;
 
 
int main(){
  int a = 1; // stored in stack

  int* p = new int(); // allocate memory in heap
  *p = 1;  // 'p' is a pointer that is stored in stack but the value is stored in heap 
  delete(p); // deallocate memory in heap but 'p' still uses  bytes in stack

  p = new int[4]; // 'p' can be reused
  delete[] p; //delete array
  
  p = NULL; // delete pointer value

  return 0;
}