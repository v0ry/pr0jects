#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* routine(){
	printf("This should be pid id\n");
	sleep(3);
	printf("2\n");
}

int main(int agrc, char* argv[]) 
{ 
 	pthread_t t1;
	pthread_create(&t1, NULL, &routine, NULL);
	pthread_join(t1, NULL);
    return 0;
}