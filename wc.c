#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>


void print_tool(int bytes)
{
	char bytes_t[10];
	int i =0;
	int count = 0;
	while(bytes>0)
	{
		int bytes_r=bytes%10;
		bytes = bytes/10;
		char a = '0'+bytes_r;
		bytes_t[i]=a;
		i++;
		count++;
	}

	for(int i =count-1;i>=0;i--)
	{
		write(1,&bytes_t[i],1);
	}
	write(1,"\n",1);
}

int main(int argc, char *argv[])
{
	if(argc<2)
	{
		write(2,"Not enough files supplied!!",28);
		exit(0);
	}
	int fd = open(argv[1],O_RDONLY);
	int words=1;
	int lines=0;
	int bytes=0;
	
	char buffer[1024];
	ssize_t bytes_read;
	while((bytes_read=read(fd,buffer,sizeof(buffer)))>0)
	{
		bytes +=bytes_read;
		for(int i =0;i<bytes;i++)
		{	
			if(buffer[i]=='\n')
				lines++;
		}
	}

	write(1,"Lines: ",7);	
	print_tool(lines);

	write(1,"Bytes: ",7);
	print_tool(bytes);


	close(fd);
	return 0;
}
