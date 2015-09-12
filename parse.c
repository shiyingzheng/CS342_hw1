#include "parse.h"
#include <stdio.h>
#include <regex.h>
#include <string.h>

int parse(char* url, char* host, char* path, char* file)
{
    // check if the URL starts with http:// or https://
    if(memcmp(url,"http://",4)==0 || memcmp(url,"https://",4)==0)
    {   return -1;   }

    // go through the url and get the start and end bytes of the hostname
    int hostname_start_flag = -1;
    int hostname_end_flag = -1;
    int last_slash_flag = -1;
    int i;
    for(i=0;i<strlen(url);i++)
    {
        if(url[i]=='/')
        {   last_slash_flag = i;   }
        if(i>0 && url[i]=='/' && url[i-1]=='/')
        {   hostname_start_flag = i+1;   }
        else if(hostname_start_flag!=-1 && hostname_end_flag==-1 && url[i]=='/')
        {   hostname_end_flag = i-1;   }
    }

    // copy the hostname from the url to the host variable
    for(i=hostname_start_flag;i<hostname_end_flag;i++)
    {   host[i-hostname_start_flag] = url[i];   }
    host[i] = 0;

    // copy the path from the url to the path variable
    for(i=hostname_end_flag;i<strlen(url);i++)
    {   path[i-hostname_end_flag] = url[i];   }
    path[i] = 0;

    // copy the filename from the url to the file variable
    for(i=last_slash_flag;i<strlen(url);i++)
    {   file[i-last_slash_flag] = url[i];   }
    file[i] = 0;

    return 0;
}

int main()
{
    char* url = "http://lolwebiste.gov/get/this/file.jpeg";
    char* host = malloc(101);
    char* path = malloc(101);
    char* file = malloc(101);
    int out = parse(&url, &host, &path, &file);
    if(out!=0)
    {   printf("Meow...");   }
    else
    {   printf("\n%s\n\n%s\n\n%s\n",host,path,file);   }
}
