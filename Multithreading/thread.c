#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2

typedef struct _tdata {
	int id;
	int total;
} tdata; 

pthread_mutex_t lock;

// The function to be executed by all threads
void *myThreadFun(void *vargp)
{
	// Store the value argument passed to this thread
	int i, lock_status;
	tdata *input = (tdata *)vargp;

	lock_status = pthread_mutex_lock(&lock);
	if ( lock_status == 0 ) {
		printf("I'm thread %d and total print is %d\n",input->id,input->total);
		for ( i=input->id;i<input->total;i+=2 ) {
			printf("<%d>\t%d\n",input->id,i);	
		}
		pthread_mutex_unlock(&lock);
		pthread_exit(NULL);
	} else {
		printf("Couldn't acquire lock: Status %d", lock_status);
	}

} 
int main(int argc, char **argv)
{
	int i,rc;
	tdata input[2];
	pthread_t tid;

	pthread_mutex_init(&lock, NULL);
	
	printf("%d, %s\n",argc,argv[1]);
	
	// Let us create three threads
	for (i = 0; i < NUM_THREADS; i++) {
		input[i].id = i;
		input[i].total = atoi(argv[1]);
		printf("Thread %d is starting..\n",input[i].id);
		if (rc = pthread_create(&tid, NULL, myThreadFun, &input[i])) {
			printf("Error: pthread_create, rc: %d\n", rc);
			return EXIT_FAILURE;
		}
	}

	/* block until all threads complete */
	for (i = 0; i < NUM_THREADS; i++) {
//		pthread_join(input[i].id, NULL);
	}
	return 0; 
}
