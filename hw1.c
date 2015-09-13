#include "hw1.h"

int read_into_buffer(char* buf, int sock) {
    int pos = 0;
    int size;
    char* line_buf = (char*)malloc(sizeof(char) * BUF_SIZE);
    while ((size = read(sock, line_buf, BUF_SIZE)) > 0) {
        memcpy(buf + pos, line_buf, size);
        pos += size;
    }
    free(line_buf);
    return pos;
}

int write_buffer(char* buf, FILE* fptr, int size) {
    char* output = (char*)malloc(BUF_SIZE * sizeof(char));
    int i = 0;
    int pos = 0;
    int state = 0; //0, 1(\r), 2(\r\n), 3(\r\n\r), 4(\r\n\r\n)

    for (int i = 0; i < size; i++){
        if (state == 4){
            output[pos] = buf[i];
            pos++;
        }
        else if (buf[i] == '\r' && (state == 0 || state == 2)){
            state += 1;
        }
        else if (buf[i] == '\n' && state == 1){
            state += 1;
        }
        else if (buf[i] == '\n' && state == 3){
            state = 4;
        }
        else {
            state = 0;
        }
    }
    output[pos]=0;
    write(fileno(fptr), output, pos+1);
    free(output);
    return 0;
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
        case 7:
            printf("Error connecting\n");
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

    printf("Host: %s\nPath: %s\nFile: %s\n", host, path, file);
    struct hostent* result = gethostbyname(host);
    if (!result) {
        print_error(3);
        exit(1);
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0) {
        print_error(7);
        exit(1);
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);

    addr.sin_addr = *((struct in_addr*)result->h_addr_list[0]);

    char ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(addr.sin_addr), ip, INET_ADDRSTRLEN);

    printf("Connecting to host %s (%s) to retrieve document %s%s.\n", host, ip, path, file);

    int res = connect(sock, (struct sockaddr*)&addr, sizeof(addr));
    if(res < 0) {
        print_error(7);
        exit(1);
    }
    char request[MAX_URL_LENGTH + 10];
    sprintf(request, "GET %s%s HTTP/1.0\r\nHost: %s\r\n\r\n", path, file, host);
    printf("\nMaking Request:\n%s", request);
    write(sock, request, strlen(request));

    char* buffer = (char*)malloc(BUF_SIZE * sizeof(char));
    FILE* fptr = fopen(file, "w");
    if (!fptr) {
        printf("Could not open file: %s\n", file);
        exit(1);
    }

    int size = read_into_buffer(buffer, sock);
    if (size == -1){
        print_error(4);
        exit(1);
    }

    write_buffer(buffer, fptr, size);
    shutdown(sock,SHUT_RDWR);
    fclose(fptr);
    free(buffer);
}
