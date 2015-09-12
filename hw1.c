#include "hw1.h"

int write_buffer(char* buf, FILE* fptr) {
}

/*
 * error codes:
 * 1 omitted url
 * 2 malformed url
 * 3 unknown host
 * 4 server did not respond
 * 5 server did not respond with a header
 * 6 or greater got error code errcode
 */
int print_error(int errcode) {
    
}

int main(int argc, char** argv){
    if (argc < 2) {
        print_error(1);
        exit(0);
    }
    char host[100];
    char path[100];
    char file[100];     
    int status = parse(argv[1], host, path, file);
    if (status) {
        print_error(2);
        exit(0);
    }
    printf("%s\n", host);
    printf("%s\n", path);
    printf("%s\n", file);
}
