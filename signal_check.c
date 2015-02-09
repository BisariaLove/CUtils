//
//  signal_check.c
//  
//
//  Created by Love Bisaria on 2/7/15.
//
//

#include <stdio.h>
#include <pthread.h>
#include <signal.h>

sigset_t set;
int sigint_signal = 0;
pthread_t monitor_thread, demo_thread;
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

void *monitor()
{
    
    while(1)
    {
        sigwait(&set, NULL);
        pthread_mutex_lock(&m);
        printf("__SIGINT received__\n");
        sigint_signal = 1;
        pthread_mutex_unlock(&m);
    }
    
}

void *demo_function(){
    while(sigint_signal == 0){
        pthread_mutex_lock(&m);
        fprintf(stdout, "__Value of SIGNAL FLAG %d:__\n",sigint_signal);
        pthread_mutex_unlock(&m);
    }
    return NULL;
}

int main(){
    
    sigemptyset(&set);
    sigaddset(&set,SIGINT);
    pthread_sigmask(SIG_BLOCK,&set,0);
    
    pthread_create(&monitor_thread, 0, monitor, NULL);
    pthread_create(&demo_thread, 0, demo_function, NULL);
    
    pthread_join(demo_thread, NULL);
    return 0;
}