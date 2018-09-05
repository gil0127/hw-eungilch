#include <iostream>
#include <stdlib.h>
#include "flexCharManager.h"
using namespace std;

int main()
{
   flexCharManager manager;


    char * ptr = manager.alloc_chars(30);
    ptr[0] = 'H';
    ptr[1] = 'e';
    ptr[2] = 'l';
    ptr[3] = 'l';
    ptr[4] = 'o';
    ptr[5] = ' ';
    ptr[6] = 'w';
    ptr[7] = 'o';
    ptr[8] = 'r';
    ptr[9] = 'l';
    ptr[10] = 'd';
    ptr[11] = '!';
    ptr[12] = '\n';

    ptr[13] = 'H';
    ptr[14] = 'e';
    ptr[15] = 'l';
    ptr[16] = 'l';
    ptr[17] = 'o';
    ptr[18] = ' ';
    ptr[19] = 'm';
    ptr[20] = 'o';
    ptr[21] = 'o';
    ptr[22] = 'n';
    ptr[23] = '!';
    ptr[24] = ' ';
    ptr[25] = 'B';
    ptr[26] = 'y';
    ptr[27] = 'e';
    ptr[28] = '.';
    ptr[29] = '\n';

    cout << ptr;
    manager.free_chars(ptr);

    return 0;
}

