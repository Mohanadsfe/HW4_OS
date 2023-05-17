#include "reactor.hpp"


void *createReactor(){
reactor * reac = (reactor *)(malloc(sizeof(reactor)));
return reac;
}


void stopReacotr(reactor *reactor){

    pthread_exit(&reactor->thread_id);

}


void startReactor(reactor * reactor){

    while(1){
        wait(0); // wait until the thread-reactor die, actullay it will work inf.
    pthread_create(&reactor->thread_id, NULL, reactor->handler, &reactor->fds);

    }


}


void addFd(reactor * reactor,int fd, handler_t handler){
  
    reactor->fds.emplace_back(fd);


}


void WaitFor(reactor *reactor){

    pthread_join(reactor->thread_id,NULL);

}


