#pragma once

#include <iostream>
#include <pthread.h>
#include<map>
#include<vector>
#include<wait.h>
using namespace std;

typedef struct handler_t{
    
    map<int,handler_t> handlers_func; 
    
} handler_t;


typedef struct reactor
{
    vector<int> fds; // fd , function for fd
    pthread_t thread_id;
    handler_t handler;
} reactor;



void* createReactor(); 
void stopReacotr(void*);
void startReactor(void*);
void addFd(void*,int fd, handler_t handler);
void WaitFor(void*);

