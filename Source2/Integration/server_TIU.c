/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>

int sockfd, newsockfd;

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

void  INThandler(int sig)
{
    char  c;
    signal(sig, SIG_IGN);
    printf("Do you really want to quit? [y/n] ");

    c = getchar();

    if (c == 'y' || c == 'Y')
    {
        close(newsockfd);
        close(sockfd);
        exit(0);
    }
    else
    {
        signal(SIGINT, INThandler);
    }
}

int main(int argc, char *argv[])
{
    signal(SIGINT, INThandler);

    int portno;
    socklen_t clilen;
    char buffer[256];
    char in;
    struct sockaddr_in serv_addr, cli_addr;
    int n;


    printf("BTM Server Starting.. \n");
    //if (argc < 2) {
    //    fprintf(stderr,"ERROR, no port provided\n");
    //    exit(1);
    //}


    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        error("ERROR opening socket\n");
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    //portno = atoi(argv[1]);
    // setting fixed port number
    portno = 15002;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0)
    {
        error("ERROR on binding\n");
    }

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd,
                       (struct sockaddr *) &cli_addr,
                       &clilen);

    if (newsockfd < 0)
    {
        error("ERROR on accept\n");
    }

    bzero(buffer, 256);

    printf("BTM Server listening to port %d started.\n", portno);

    while (1)
    {
        n = read(newsockfd, buffer, 255);

        if (n < 0)
        {
            error("ERROR reading from socket");
        }

        printf("Here is the message: %s\n", buffer);
        n = write(newsockfd, "I got your message", 18);

        if (n < 0)
        {
            error("ERROR writing to socket");
        }
    }

    close(newsockfd);
    close(sockfd);
    return 0;
}
