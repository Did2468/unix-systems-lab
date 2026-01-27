//This is a custom implementation of cp command u find in linux or unix based terminals executed purely through system calls(not optimized).

#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	if(argc<3)
	{
		write(2,"use as follows ./cp <file1> <file2>",37);
		exit(0);
	}
	int fd = open(argv[1],O_RDONLY);
	int fd1 = open(argv[2], O_CREAT | O_WRONLY,0644);
	char buffer[1024];
	ssize_t bytes_read;
	while((bytes_read=read(fd,buffer,sizeof(buffer)))>0)
	{
		write(fd1,buffer,bytes_read);
	}
	close(fd);
	close(fd1);
	return 0;
}
