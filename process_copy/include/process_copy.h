#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>

int check_pram(int argc,const char*src,int pronum);
int blocksize_cur(const char* src,int pronum);
int process_create(const char*src,const char* dest,int pronum,int blocksize);
int process_wait();
