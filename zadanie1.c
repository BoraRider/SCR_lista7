#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS	10

int PrintHello(long t)
{
   printf("Hello SCR. Written by thread ID #%ld!\n", t);
   pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
   pthread_t threads[NUM_THREADS];

   int error_wiadomosc;
   
   for(long t=0;t<NUM_THREADS;t++)
   {

     printf("In main: creating thread %ld\n", t);

     error_wiadomosc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);

     if (error_wiadomosc)
        {
       printf("ERROR; return code from pthread_create() is %d\n", error_wiadomosc);
       exit(-1);
       }

     }

   pthread_exit(NULL);
}
