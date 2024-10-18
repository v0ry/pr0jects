#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* routine()
{
    printf("Hello from thread\n");
    sleep(3);
    printf("Thread is done\n");
}

/*
*/

int main(int agrc, char* argv[]) 
{ 
    pthread_t t1, t2;
    pthread_create(&t1, NULL, &routine, NULL);
    pthread_create(&t2, NULL, &routine, NULL);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
