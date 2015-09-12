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
 * 6 Creating socket failed
 * 7 Error connecting
 * 8 or greater got error code errcode
 */
void print_error(int errcode) {
    switch(errcode) {
        case 1:
            printf("usage hw1 <URL>\n");
            break;
        case 2:
            printf("Error: malformed URL\n");
            break;
        case 3:
            printf("Error: no such host\n");
            break;
        case 4:
            printf("receiving request failed\n");
            break;
        case 5:
            printf("Could not find headers; quitting\n");
            break;
        case 6:
            printf("Failed to create socket\n");            
        default:
            printf("Got error code %d\n", errcode);
            break;
    }
}

int main(int argc, char** argv){
    if (argc < 2) {
        print_error(1);
        exit(1);
    }
    char host[MAX_URL_LENGTH];
    char path[MAX_URL_LENGTH];
    char file[MAX_URL_LENGTH];     
    int status = parse(argv[1], host, path, file);
    if (status) {
        print_error(2);
        exit(1);
    }
    printf("%s\n", host);
    printf("%s\n", path);
    printf("%s\n", file);
    
    struct hostent* result = gethostbyname(host);
    if (result) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if(sock < 0) {
            print_error(7);
            exit(1);
        }
        struct sockaddr_in addr; 
        addr.sin_family = AF_INET;
        addr.sin_port = htons(80);    
        addr.sin_addr.s_addr = inet_addr(net_ntoa(*((struct in_addr*)result->h_addr_list[0])));
    }
    else {
        print_error(3);
    }
    
}
