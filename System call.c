#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
printf("\n I am a process and my pid=%d",(int)getpid());
pid_t pid=fork();
printf("\n fork returned=%d",(int)pid);
if(pid==0)
{
printf("\n I am a child process and my pid is=%d",(int)getpid());
printf("\n My parent's pid=%d",(int)getppid());
printf("\n Child exiting");
}
if(pid>0)
{
printf("\n I am parent and my pid=%d",(int)getpid());
wait(NULL);
printf("\n Parent exiting");
}
if(pid<0)
{
perror("\n Fork failed\n");
}
return 0;
}

/*
OUTPUT-
[student@PC-7 ~]$ gedit
[student@PC-7 ~]$ gcc shruti.c
[student@PC-7 ~]$ cd Documents
[student@PC-7 Documents]$ gcc shruti.c
[student@PC-7 Documents]$ gedit shruti.c
[student@PC-7 Documents]$ gcc shruti.c
[student@PC-7 Documents]$ ./a.out

I am a process and my pid=3025
 fork returned=3026
 I am a process and my pid=3025
 fork returned=0
 I am a child process and my pid is=3026
 My parent's pid=3025
 Child exiting I am parent and my pid=3025
 Parent exiting[student@PC-7 Documents]$ 

*/