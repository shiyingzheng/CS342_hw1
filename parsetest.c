#include "parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>
int main()
{
    char* url = "http://lolwebiste.gov/ayy/lmao.flac";
    char* url1 = "http://www.google.com";
    char host[101];
    char path[101];
    char file[101];
    int out = parse(url1, host, path, file);
    if(out!=0)
    {   printf("Meow...");   }
    else
    {   printf("\nhost:%s\n\npath:%s\n\nfile:%s\n",host,path,file);   }
}
