#include <parse.h>
#include <stdio.h>
#include <regex.h>


int parse(char* url, char* host, char* path)
{
    url = argv[0];

    // check if the URL starts with http:// or https://
    if(memcmp(url,"http:\/\/",4)==0 || memcmp(url,"https:\/\/",4)==0)
    {
        //TODO: handle case if they just forgot protocol
        return -1;
    }

    // go through the url and get the start and end bytes of the hostname
    int hostname_start_flag = -1;
    int hostname_end_flag = -1;
    for(int i=0;i<strlen(url);i++)
    {
        if(i>0 && memcmp(url[i],"\/",1)==0 && memcmp(url[i-1],"\/",1)==0)
        {
            hostname_start_flag = i+1;
        }
        else if(hostname_start_flag!=-1 && hostname_end_flag==-1 &&
           memcmp(url[i],"\/",1)==0)
        {
            hostname_end_flag = i-1;
        }
    }

    // copy the hostname from the url to the host variable
    for(i=hostname_start_flag;i<hostname_end_flag;i++)
    {
        host[i-hostname_start_flag] = url[i];
    }
    host[i] = 0;

    // copy the path from the url to the path variable
    for(i=hostname_end_flag;i<strlen(url);i++)
    {
        path[i-hostname_end_flag] = url[i];
    }
    path[i] = 0;

    return 0;
}
