#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

void tool(char *arg[],int i)
{
	int fd = open(arg[i],O_RDONLY);
	if(fd<0)
	{
		write(2,"Failed to open <file>\n",20);
		exit(1);
	}
	char buffer[1024];
	ssize_t bytes_read;
	while((bytes_read=read(fd,buffer,sizeof(buffer)))>0)
	{
		write(1,buffer,bytes_read);
	}
	close(fd);
}

int main(int argc, char *argv[])
{
	if(argc<2)
	{
		write(2,"Usage: mycat <file>\n",20);
		exit(1);
	}

	for(int i =1;i!=argc;i++)
	{
		tool(argv,i);	
	}	
	return 0;
}
