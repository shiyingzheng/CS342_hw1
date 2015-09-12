#include "parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>
int main()
{
    char* url = "http://lolwebiste.gov/ayy/lmao.flac";
    char* url1 = "http://lolwebiste.gov/ayy/stuff/notherfolder/weeeeeeeee/lmao.flac";
    char* host = malloc(101);
    char* path = malloc(101);
    char* file = malloc(101);
    int out = parse(url1, host, path, file);
    if(out!=0)
    {   printf("Meow...");   }
    else
    {   printf("\nhost:%s\n\npath:%s\n\nfile:%s\n",host,path,file);   }
}
