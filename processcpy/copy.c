#include "pcpy.h"

int main(int argc,char ** argv)
{
	//argv[1]=sfile argv[2]=dfile argv[3]=blocksize argv[4]=pos
	int pos = atoi(argv[4]);
	int blocksize = atoi(argv[3]);
	char buffer[blocksize];

	int sfd = open(argv[1],O_RDONLY);	
	int dfd = open(argv[2],O_WRONLY|O_CREAT,0664);
	lseek(sfd,pos,SEEK_SET);
	lseek(dfd,pos,SEEK_SET);

	int rsize;
	rsize = read(sfd,buffer,sizeof(buffer));
	write(dfd,buffer,rsize);


	return 0;
}

