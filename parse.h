#ifndef PARSE_H_
#define PARSE_H_

// Ths will initialize the private parse.c buffer with the string passed
// in the parameter inputLine
void initBuffer(char *inputLine);

// This function returns a 1 if there are still more tokens in the string, otherwise it
// returns 0. 
int hasNextToken();

// This function removes the first token from the ubffer. The buffer is reduced in size
// since the token was removed. The removed token is returned to the caller. If the buffer is empty
// then this function returns NULL.
char *nextToken();

// This function reinitializes the private buffer with the string originally provided by the initBuffer() function call.
// This will effectively restart the token extraction processs from the beginning.
void rewind();
#endif //PARSE_H_
