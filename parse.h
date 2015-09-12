#include <netdb.h>

// url is a null terminated string that represents anything that the lab can throw at us
// returns an ip address if the url is valid, otherwise NULL
// path and file should be character arrays of length 100
// parse will overwrite path with the path, and file with the file
extern struct hostent* parse(char* url, char* path, char* file);
