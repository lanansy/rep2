#include"pcpy.h"

int check_arg(const char * SFile, int arg_num,int pronum)
{
	//源文件是否存在
	if((access(SFile,F_Ok))!=0){
		perror("Check_arg error!\n");
		exit(-1);
	}
	//参数数量是否满足
	if(arg_num < 3){
		printf("Check_arg error:参数数量异常！\n");
		exit(-1);
	}
	//进程数量是否溢出
	if(pro_num <= 0||pronum >= 100){
		printf("Check_arg error:进程数量要大于0，小于100\n");
		exit(-1);
	}

	return 0;
}
