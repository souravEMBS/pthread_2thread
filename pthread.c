#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>



void *myfunc(void *n){
	char* msg;
	msg = (char *)n;

	int i;

	for(i=0;i<10;i++)
	{
		printf("%s %d\n",msg,i);
		sleep(1);
	}
}


int main(int argc, char const *argv[])
{
	/* code */

	int pthread1,pthread2;
	pthread_t thread1,thread2;
	char* msg1 = "first thread";
	char* msg2 = "second thread";

	if((pthread1 = pthread_create(&thread1,NULL,myfunc,(void *)msg1)) != 0)
		perror("no thread with error no ");
	else
		perror("thread1: ");

	if((pthread2 = pthread_create(&thread2,NULL,myfunc,(void *)msg2)) != 0)
		perror("no thread with error no ");
	else
		perror("thread2: ");

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);

	printf("thread 1 return: %d\nthread2 return %d\n",pthread1,pthread2);
	return 0;
}

