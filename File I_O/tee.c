#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#ifndef BUFF_SIZE
#define BUFF_SIZE 1
#endif

int main(int argc, char *argv[])
{
	int opt,fd,flag;
	int flag2=O_WRONLY|O_CREAT;
	char str[BUFF_SIZE];
	char *filename=NULL;
	while ((opt = getopt(argc, argv, "a:")) != -1) {
		switch(opt){
			case 'a':
				filename=optarg;
				break;
			case '?':
				printf("Usage : %s -a filename",argv[0]);
				break;

		}
	}
	int remaining_args = argc - optind;
	if(remaining_args > 0){
		filename=argv[optind];
		flag2|=O_TRUNC;
	}
	else
		flag2|=O_APPEND;
	fd=open(filename,flag2,0644);
	if(fd==-1)
		printf("Open error\n");
	flag=0;
	while((flag=read(STDIN_FILENO,str,BUFF_SIZE))>0){
		write(fd,str,BUFF_SIZE);
		write(STDOUT_FILENO,str,BUFF_SIZE);
	}
	close(fd);
	exit(EXIT_SUCCESS);
}
