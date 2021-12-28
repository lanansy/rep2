#include"pcpy.h"


int procreate(const char * SFile,const char *DFile,int pronum,int blocksize)
{
	int flag;
	pid_t pid;

	int pos;
	char cblock[10];
	char cpos[10];
	bzero(cblock,sizeof(cblock));
	bzero(cpos,sizeof(cpos));

	for(flag = 0;flag<pronum;flag++)
	{
		pid = fork();
		if(pid == 0)
			break;
	}
	if(pid > 0){
		printf("Parent pro pid [%d] 非阻塞回收...\n",getpid());
		pid_t zpid;
		while((zpid =waitpid(-1,NULL,WNOHANG))!=-1)
		{
			if(zpid > 0)
				printf("Parent wait sucess:zombie pid [%d]\n",zpid);
		}
	}else if(pid == 0){
		//偏移量计算
		pos =flag * blocksize;
		sprintf(cblock,"%d",blocksize);
		sprintf(cpos,"%d",pos);
		//重载
		execl("/c/Users/蓝桉/Desktop/rep/processcpy/Copy","./Copy",SFile,DFile,cblock,cpos,NULL);
	}else{
		perror("Fork CALL FAILED\n");
		exit(-1);
	}

	return 0;
}
