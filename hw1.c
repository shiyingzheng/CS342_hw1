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
void print_error(int errcode) {
    switch(errcode) {
        case 1:
            printf("usage hw1 <URL>");
            break;
        case 2:
            printf("Error: malformed URL");
            break;
        case 3:
            printf("Error: no such host");
            break;
        case 4:
            printf("receiving request failed");
            break;
        case 5:
            printf("Could not find headers; quitting");
            break;
        default:
            printf("Got error code %d", errcode);
            break;
    }
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
