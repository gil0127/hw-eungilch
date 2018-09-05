#include "flexCharManager.h"

flexCharManager::flexCharManager(){
	memSize = 2;
    takenSize = 0;
    used_memory = new Mem_Block *[memSize];
    for (int i = 0; i < memSize; ++i) {
        used_memory[i] = NULL;
    }
}

flexCharManager::~flexCharManager(){

	for (int i = 0; i < memSize; ++i) {
        if (used_memory[i] != NULL)
        {
            delete used_memory[i];
        }
    }
    delete [] used_memory;
}
             

char* flexCharManager::alloc_chars(int n){

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
			for (int j = 0; j < n; ++j) {
                track[i+j] = 1;
            }
            updatedMemBlock(n , &buffer[i]);
            return &(buffer[i]);
		}
	}

       return NULL;
}
   
   
void flexCharManager::updatedMemBlock(int size, char * address) {
    for(int i= 0; i < memSize; i++)
    {
     	if( used_memory[i] == NULL)
        {
           used_memory[i] = new  Mem_Block(size, address);
           takenSize++;
           return;
        }
    }
  allocateMemBlock(memSize, memSize*2);
}

void flexCharManager::allocateMemBlock(int oldSize,int newSize) 
{

 Mem_Block ** memories = new Mem_Block *[newSize];

    for (int j = 0; j < newSize; ++j) {
        memories[j] = NULL;
    }

    for(int i = 0; i < oldSize;i++)
    {
        memories[i] = used_memory[i];
    }

    delete [] used_memory;

    used_memory = memories;

    memSize *=2;
  
}

 void flexCharManager::free_chars(char * addr)
    {
      for(int i = 0; i < memSize; i++)
    	{
       	 if(used_memory[i] != NULL && used_memory[i]->physical_location == addr)
       	  {
            for(int j = 0; j < used_memory[i]->size; j++)
            {
                // deallocate memory

                char * ptr = used_memory[i]->physical_location;
                *(ptr + j) = '\0';
                int index = used_memory[i]->physical_location - buffer;
                for (int k = 0; k < used_memory[i]->size; ++k) {
                    track[index+k] = 0;
                }
            }
            delete used_memory[i];
            used_memory[i] = NULL;
            takenSize--;
            deallocateMemBlock();
            return;
        }
        // did not find, do nothing
      }
    }

void flexCharManager::deallocateMemBlock() {
    if(memSize/2 >= takenSize && memSize > 2)
    {
        Mem_Block ** memories = new Mem_Block *[memSize/2];

        for (int j = 0; j < memSize/2; ++j) {
            memories[j] = NULL;
        }
        int count = 0;
        for(int i = 0; i < memSize;i++)
        {
            if(used_memory[i] != NULL) {
                memories[count++] = used_memory[i];
            }
        }

        delete [] used_memory;

        used_memory = memories;

        memSize /=2;
    }
}
