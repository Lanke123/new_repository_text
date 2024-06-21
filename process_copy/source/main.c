#include <process_copy.h>

int main(int argc, char **argv)
{
	int pronum;
	//检测参数
	if(argv[3] == 0)
		pronum = 5;
	else
		pronum = atoi(argv[3]);
	char *src = argv[1];
	char *dest = argv[2];
	//检查参数合法性
	int err = check_pram(argc,src,pronum);
	if(err == -1)
	{
		printf("check parameter error\n");
		return -1;
	}

	//计算任务量
	int block_size = blocksize_cur(src, pronum);
	if(block_size == -1)
	{
		printf("block_size error\n");
		return -1;
	}
	
	//创建多进程
	err = process_create(src,dest,pronum,block_size);
	if(err == -1)
	{
		printf("create fail!\n");
		return -1;
	}

	return 0;
}
