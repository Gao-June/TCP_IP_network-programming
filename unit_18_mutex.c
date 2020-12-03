#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREAD 100

void *thread_inc( void *arg );
void *thread_des( void *arg );

long long num;
pthread_mutex_t mutex;

int main(int argc , char *argv[]){
	pthread_t thread_id[NUM_THREAD];		// 100 个线程
	int i=0;
	pthread_mutex_init( &mutex, NULL );		//创建互斥量
	
	for( i=0; i<NUM_THREAD; i++  ){
		if( i%2 ){
			pthread_create( &(thread_id[i]), NULL, thread_inc, NULL );
		}
		else{
			pthread_create( &(thread_id[i]), NULL, thread_des, NULL );
		}
	}
	
	for( i=0; i<NUM_THREAD; i++ ){
		pthread_join( thread_id[i], NULL );
	}
	
	printf( "result : %lld\n", num );
	pthread_mutex_destroy( &mutex );
	
	return 0;
}

void *thread_inc( void *arg ){
	int i=0;
	pthread_mutex_lock( &mutex );
	for( i=0; i<50000000; i++ ){
		num += 1;
	}
	pthread_mutex_unlock( &mutex );
	
	return NULL;
}

void *thread_des( void *arg ){
	int i=0;
	pthread_mutex_lock( &mutex );
	for( i=0; i<50000000; i++ ){
		num -= 1;
	}
	pthread_mutex_unlock( &mutex );
	
	return NULL;
}

