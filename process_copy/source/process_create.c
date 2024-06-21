#include <process_copy.h>

//进程创建函数
int process_create(const char* src,const char* dest,int pronum,int blocksize)
{
	pid_t pid;
	int i;
		
	//按照进程数量创建子进程
	for(i = 0;i < pronum;i++)
	{
		pid = fork();
		if(pid == 0)
		{
			break;
		}
	}
	if(pid > 0)
	{
		process_wait();
	}
	else if(pid == 0)
	{
		//偏移量
		int offset = blocksize*i;
		char offset_str[10];
		char block_str[10];
		bzero(offset_str,sizeof(offset_str));
		bzero(block_str,sizeof(block_str));
		//转换为字符串
		sprintf(offset_str,"%d",offset);
		sprintf(block_str,"%d",blocksize);

		//重载
		execl("/home/colin/20230912/process_copy/Mod/copy","copy",src,dest,offset_str,block_str,NULL);

	}
	else
	{
		perror("fork fail!");
		return -1;
	}

	return 0;
}

