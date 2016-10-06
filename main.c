#include <errno.h> 
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <pthread.h>

#ifndef   NI_MAXHOST
#define   NI_MAXHOST 1025
#endif

void* main2(void* p);

int main(void)
{
	//nacl_io_init();
	pthread_t main2_thread;
	if(pthread_create(&main2_thread, NULL, main2, NULL)) {
		fprintf(stderr, "Error creating thread\n");
		return 1;
	}
	fprintf(stdout,"Could create thread\n");
	if(pthread_join(main2_thread, NULL)) {

		fprintf(stderr, "Error joining thread\n");
		return 2;
	}
	fprintf(stdout,"Could join thread\n");
	return 0;


}

void* main2(void* p)
{
    fprintf(stdout,"entered thread\n");
    struct addrinfo* result;
    struct addrinfo* res;
    int error;
    /* resolve the domain name into a list of addresses */
    error = getaddrinfo("www.google.com", NULL, NULL, &result);
    if (error != 0 ) {   
        if (error == EAI_SYSTEM) {
            //fprintf(stdout,"getaddrinfo error EAI_SYSTEM in syscall %s\n", strerror(errno));
        } else {
            fprintf(stderr, "error in getaddrinfo: %s\n", gai_strerror(error));
        }   
        exit(EXIT_FAILURE);
    }   
    fprintf(stdout,"was able to go through syscall");
    /* loop over all returned results and do inverse lookup */
    for (res = result; res != NULL; res = res->ai_next) {   
        char hostname[NI_MAXHOST];
        error = getnameinfo(res->ai_addr, res->ai_addrlen, hostname, NI_MAXHOST, NULL, 0, 0); 
        if (error != 0) {
            fprintf(stderr, "error in getnameinfo: %s\n", gai_strerror(error));
            continue;
        }
        if (*hostname != '\0')
            fprintf(stdout,"hostname: %s\n", hostname);
    }   
    freeaddrinfo(result);
    return 0;
}
