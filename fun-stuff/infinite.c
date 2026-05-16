#include<unistd.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
	pid_t pid;
	pid =fork();
	if(pid==0)
	{
		execv("./infinite",NULL);
	}
	else
	{
		execv("./infinite",NULL);		
	}
	return 0;
}
