//This is a small but dangerous program entirely focusing on how dangerous accessing of fork() syscall is this essentially can hang up any cpu in the world.

#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	for (int i =0;i!=10000;i++)
	{
		fork();
		printf("%d ",i);
	}
	return 0;
}
