#include <cstddef>
#include "simpleCharManager.h"



simpleCharManager::simpleCharManager()
{

	for(int i = 0; i<BUF_SIZE; i++)
	{
		buffer[i] = '\0'; // clean the buffer
		track[i] = 0;
	}

}

simpleCharManager::~simpleCharManager(){}
             
char* simpleCharManager::alloc_chars(int n){

	for(int i=0; i<BUF_SIZE-n+1; i++)
	{	
		bool free = true;
		for(int j=0; j<n; j++)
		{
			if(track[i+j] > 0)
			{
				free = false; // memory is not free
	
				break;
			}
		}
		if(free)
		{
			track [i] = n; // how many chars are allocated

			return &(buffer[i]);
		}
	}

        return NULL; // if I didn't allocate memory
}

void simpleCharManager::free_chars(char* p)
{
	int addr = p - (buffer); // memmory addr 

	track[addr] = 0;

	for(int i = addr; i<BUF_SIZE - addr; i++)
	{
		buffer[i] = '\0';
	}


}         




