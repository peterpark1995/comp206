#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

int main(int argc, char *argv[])
{
  int b=1;
  char backup[100];
  char *source=getenv("BackupSource");
  char *destination=getenv("BackupDestination");
  char *btime=getenv("BackupTime");

  time_t getTime;
  struct tm *actualTime;

   while(b)
    {
       //in each loop you get the time so it can be compared with the env variable
       time(&getTime);
       actualTime=localtime(&getTime);
       strftime(backup, 100, "%H:%M", actualTime);

       //no need for a while loop in a while loop
       if(strcmp(backup,btime)==0)
       {
           system("cp -r $BackupSource $BackupDestination");
       }
       sleep(60);
    }

return 0;
}
