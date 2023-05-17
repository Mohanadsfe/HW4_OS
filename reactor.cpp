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
    reactor->handler.handlers_func[fd]=handler; // key= fd ,value = handler

}


void WaitFor(reactor *reactor){

    pthread_join(reactor->thread_id,NULL);

}


void handle_newConn(){

//       addrlen = sizeof remoteaddr; newfd = accept(listener,
//                (struct sockaddr *)&remoteaddr,&addrlen);

//           if (newfd == -1)
//                     {
//                         perror("accept");
//                     }
//                     else
//                     {

//     add_to_pfds(&pfds, newfd, &fd_count, &fd_size);

//     printf("pollserver: new connection from %s on " "socket %d\n",
//        inet_ntop(remoteaddr.ss_family,
//       get_in_addr((struct sockaddr *)&remoteaddr),
//        remoteIP, INET6_ADDRSTRLEN), newfd);
    

// }

}

void recv_print(){



     // // If not the listener, we're just a regular client
     // int nbytes = recv(pfds[i].fd, buff, sizeof buff, 0);

    // int sender_fd = pfds[i].fd;

       // if (nbytes <= 0)

          // {
          //     // Got error or connection closed by client
         //     if (nbytes == 0)
           //     {
           //         // Connection closed
          //         printf("pollserver: socket %d hung up\n", sender_fd);
          //     }

          //     else
             //     {
          //         perror("recv");
             //     }

            //     close(pfds[i].fd); // Bye!

            //     del_from_pfds(pfds, i, &fd_count);
             // }

         // else
            // {
             //     // We got some good data from a client  

             // }


}

}


