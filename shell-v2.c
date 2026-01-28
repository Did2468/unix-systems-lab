#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<string.h>

char **parser()
{
	write(1,"$ ",2);

	char buffer[1024];
	ssize_t bytes_read = read(0,buffer,sizeof(buffer));

	char **cmd = malloc(30 * sizeof(char *)); 
	char temp[50];
	
	int i=0,w=0,c=0;
	while(i<bytes_read)
	{
		if(buffer[i]==' ' || buffer[i]=='\n')
		{	
			if(c>0)
			{	
				temp[c]='\0';
				cmd[w]=malloc(c+1);
				strcpy(cmd[w],temp);
				w++;
				c=0;
			}
		}
		else
		{
			temp[c++]=buffer[i];
		}
		i++;
	}
	cmd[w]=NULL;
	
	return cmd;
}

int main()
{
	
	while(1)
	{
		char **cmds=parser();	
		pid_t pid=fork();


		if(pid==0)
		{
			execvp(cmds[0],cmds);
		}
		else
		{	
			wait(NULL);
			//execv("./shellc",NULL);
		}
	}
	return 0;
}



