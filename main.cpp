/* 
 * File:   main.cpp
 * Author: radigue
 *
 * Created on 17 septembre 2012, 11:20
 */

#include <cstdlib>
#include <pthread.h>
#include <iostream>
using namespace std;

/*
 * 
 */
//V1
pthread_mutex_t acces = PTHREAD_MUTEX_INITIALIZER;

void* Pair(void* pData) {
    
    
        pthread_mutex_lock(&acces);
        cout << "Pair : " << i << endl;
        pthread_mutex_unlock(&acces);
        usleep(0);
    }
    pthread_exit(EXIT_SUCCESS);
}

void* Impair(void* pData) {
    for (int i = 1; i <= 100; i += 2) {
        pthread_mutex_lock(&acces);
        cout << "Impair : " << i << endl;
        pthread_mutex_unlock(&acces);
        usleep(0);
    }
    pthread_exit(EXIT_SUCCESS);
}

int main(int argc, char** argv) {
    void* retour;
    void* retour1;
    pthread_t th;
    pthread_t th1;
    for (int i = 0; i <= 100; i++) {
        if(i % 2 == 0)
            pthread_create(&th, NULL, Pair, NULL);
        else
                pthread_create(&th1, NULL, Impair, NULL);
    }
    if (retour != PTHREAD_CANCELED && retour1 != PTHREAD_CANCELED)
        cout << "Thread terminés" << endl;
        return 0;
}

