#include <process_copy.h>

//参数检查函数
int check_pram(int argc,const char *src,int pronum)
{
	//检查数量
	if(argc < 3)
	{
		printf("parameter error\n");
		return -1;
	}
	//src文件是否存在
	if(0 != access(src,F_OK))
	{
		printf("src file is not exist\n");
		return -1;
	}
	//pronum是否合法
	if(pronum <= 0 || pronum > 100)
	{
		printf("pronum error\n");
		return -1;
	}

	//成功返回0
	return 0;
}


