#include "parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <regex.h>
#define MAX_URL_LENGTH 256
#define BUF_SIZE 1048576
extern int write_buffer(char* buf, FILE* fptr);
