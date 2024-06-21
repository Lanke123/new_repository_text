#include <process_copy.h>

//任务量计算函数
int blocksize_cur(const char *src,int pronum)
{
	//打开文件
	int fd = open(src, O_RDWR);
	if(fd == -1)
	{
		printf("open file fail!\n");
		return -1;
	}

	//获取文件大小
	int size = lseek(fd,0,SEEK_END);
	if(size < 0)
	{
		printf("lseek file error\n");
		return -1;
	}
	
	//每一份进程要处理的大小
	int block_size = size / pronum;
	if(size % pronum != 0)
	{
		block_size+=1;
	}

	return block_size;
}
