#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char** argv)
{
	//合法性检测
	if(argc < 5)
	{
		printf("parameter error!\n");
		return -1;
	}
	//打开并创建文件
	int fd_src = open(argv[1],O_RDWR);
	if(fd_src == -1)
	{
		printf("src file open fail\n");
		return -1;
	}
	int fd_dest = open(argv[2],O_RDWR | O_CREAT,0664);
	if(fd_dest == -1)
	{
		printf("dest file create fail\n");
		return -1;
	}
	//找到位置，利用lseek函数
	lseek(fd_src,atoi(argv[3]),SEEK_SET);
	lseek(fd_dest,atoi(argv[3]),SEEK_SET);

	//初始化缓冲区
	int blocksize = atoi(argv[4]);
	char buffer[blocksize];
	bzero(buffer,sizeof(buffer));

	int size = read(fd_src,buffer,sizeof(buffer));
	if(size < 0)
	{
		printf("read file fail\n");
		return -1;
	}

	//写入
	write(fd_dest,buffer,sizeof(buffer));
	//关闭文件
	close(fd_src);
	close(fd_dest);

	return 0;

}
