#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
void main()
{
 int status,pid,child_pid;
 pid = fork();
 
 if(pid == -1){
 	printf("child process not created\n");
 	exit(0);
 	}
 else if(pid == 0){
 	printf("child process created with id :%d\n",getpid());
 	execlp("/bin/date","date",NULL);
 	exit(0);
 	}
 else {
 	child_pid = wait(&status);
 	printf("parent process created with id :%d\n",getpid());
 	printf("child process created successfully");
 	exit(0);
 	}
 }
