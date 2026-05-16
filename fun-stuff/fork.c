#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	for (int i =0;i!=1000;i++)
	{
		fork();
		printf("%d ",i);
	}
	return 0;
}
