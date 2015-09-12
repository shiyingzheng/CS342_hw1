// url is a null terminated string that represents anything that the lab can throw at us
// returns 0 if url is valid, otherwise -1
// host, path, and file should be character arrays of length 100
// parse will overwrite host with the host, path with the path, and file with the file
extern int parse(char* url, char* host, char* path, char* file);
