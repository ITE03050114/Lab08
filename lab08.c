#include<stdio.h>
#include<stdlib.h>

int main()
{
	int pid;
	int status = 0;
	int getsonpid,getparpid,i;
		
	for(i=0;i<3;i++)
	{
		pid=fork();
		if(pid != 0)
		{
			printf("parent: son_pid%d\n",pid);
			pid = wait(&status);
		}
		else
		{
			getparpid = getppid();
			getsonpid = getpid();
			printf("son   : parent_pid:%d	son_pid:%d\n",getparpid,getsonpid);
			exit(status);
		}
	}
	return 0;
}
