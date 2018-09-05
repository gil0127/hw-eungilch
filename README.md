# homework-resources

/*
**Assignment 1**

This assignment was composed of answering questions, understanding course policies,
using git commands, palindromes, streams, and memory



**Palindromes**
The most important part I changed is each sides of character are compared by 
if statement and stream.

**hw1q5**
Converting string 11 to actal integer. Then pass the number to helper function and count the number of word to print. The most challenge part was without "noskipws" the whitespaces are ignored.


** Memory **

**** Part 1)
A basic implementation sets a buffer array to the null '\0' character.  
The null character is also set when the memory is freed.  This 
basic implementation return a buffer that holds n characters.
The free_chars function will free from that pointer to end of the buffer.
The primary problem is that deleting one pointer will also delete the 
rest of that buffer, leading to memory leaks.

**** Part 2)
A better implementation implies using a memory block that stores the 
starting address.  This fixes the problem of the part 1 where you
delete the rest of the buffer, with the allocated size, you know
the address to delete at and how many bytes to free.  Since we 
are using the first fit approach, it is possible for fragmentation
to occur as there may be huge caps of memory that do not get filled
as earlier allocated memory gets freed.

*/