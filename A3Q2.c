
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
int main()
{
 printf("start..\n");
 //getting stored environment
 char *BackupSource = getenv("BackupSource");
 char *BackupDestination = getenv("BackupDestination");
 char *BackupTime = getenv("BackupTime");
 char buffer[100];


 //declaring tm pointer
struct tm *time_structure;
//time_t epoch seems to be standard syntax
time_t epoch;


while(1)
{   
    //storing the localtime on the deference of *getTime
    time_structure = localtime(&epoch);
    //values of time in seconds
    time(&epoch);
    //storing the string of the time on hour and minute
    strftime(buffer, 100, "%H:%M", time_structure);
    while(strcmp(buffer,BackupTime)==0)
    {  
        system("cp -r $BackupSource $BackupDestination");
    }
    sleep(60);
}

 printf("Done.\n");
 return(0);

}























