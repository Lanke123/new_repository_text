#include <process_copy.h>

//wait函数
int process_wait()
{
	pid_t zpid;
	while((zpid = waitpid(-1,NULL,WNOHANG)) != -1)
	{
		if(zpid > 0)
		{
			printf("parent wait success! the child zpid = %d\n",zpid);
		}
		else
		{
			sleep(1);
		}
	}

	return 0;
}
