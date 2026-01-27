//This is my attempt to create what happends underneath a shell when we enter a command,though basic will improve it in next versions

#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>

int main()
{
	write(1,"$ ",2);
	char buffer[1024];
	char *cmd[30];
	char words[20][50];
	
	ssize_t bytes_read = read(0,buffer,sizeof(buffer));
	
	int i=0,w=0,c=0;
	while(i<bytes_read)
	{
		if(buffer[i]==' ' || buffer[i]=='\n')
		{	
			if(c>0)
			{	
				words[w][c]='\0';
				cmd[w]=words[w];
				w++;
				c=0;
			}
		}
		else
		{
			words[w][c++]=buffer[i];
		}
		i++;
	}
	cmd[w]=NULL;
	
	pid_t pid=fork();


	if(pid==0)
	{
		execvp(cmd[0],cmd);
	}
	else
	{
		wait(NULL);
	}
	return 0;
}
