#include <iostream>
#include <stdlib.h>
#include "simpleCharManager.h"
using namespace std;

int main(int argc, char *argv[])
{
  simpleCharManager simplest_mem_manager;

  /*write driver code as described in the assignment to replace this */
  // std::cout << "Hello world!\n" ;

  char* m1 = simplest_mem_manager.alloc_chars(13); // how many char we need

  m1 [0] = 'H';
  m1 [1] = 'e';
  m1 [2] = 'l';
  m1 [3] = 'l';
  m1 [4] = 'o';
  m1 [5] = ' ';
  m1 [6] = 'w';
  m1 [7] = 'o';
  m1 [8] = 'r';
  m1 [9] = 'l';
  m1 [10] = 'd';
  m1 [11] = '!';
  m1 [12] = '\n';

  cout << m1 ; // print out "Hello World!" 

  simplest_mem_manager.free_chars(m1+6);

  
  return 0;
}

