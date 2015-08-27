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
#include "Eurobalise_Telegram.h"
#include "Telegram_Header_Encoder.h"
#include "Packet_Header.h"
#include "Bitstream_Init.h"
#include <cassert>
#include "UpperBitsNotSet.h"
#include "print_bits.h"



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
          signal(SIGINT, INThandler);
}

int main(int argc, char *argv[])
{
     signal(SIGINT, INThandler);

     int portno;
     socklen_t clilen;
     unsigned char buffer[2048];
     unsigned char targetbuffer[2048];
     struct sockaddr_in serv_addr, cli_addr;
     int n;

     
    printf("BTM Server Starting.. \n");
     //if (argc < 2) {
     //    fprintf(stderr,"ERROR, no port provided\n");
     //    exit(1);
     //}
     

     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket\n");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     //portno = atoi(argv[1]);
     // setting fixed port number
     portno = 15010;
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding\n");
     listen(sockfd,5);
     clilen = sizeof(cli_addr);
     newsockfd = accept(sockfd, 
                 (struct sockaddr *) &cli_addr, 
                 &clilen);
     if (newsockfd < 0) 
          error("ERROR on accept\n");
     bzero(buffer,256);
     
     Bitstream stream;
     Bitstream_Init(&stream, targetbuffer, 2048, 0);

     printf("BTM Server listening to port %d started.\n",portno);
     while(1)
     {
        stream.bitpos = 0;
	n = read(newsockfd,buffer,2048);
	if (n < 0) error("ERROR reading from socket");
     	printf("Here is the message: %s\n",buffer);
	//unsigned char *pos = targetbuffer;
	printf ("Target buffer: Länge: %i ",n);
        for (int i=1;i<=n/2-1;i++){
		printf(" (%i %i) ", buffer[2*i-1], buffer[2*i]);		

		int tmp = buffer[2*i - 1];
		tmp -= 48;
		if (tmp > 9) tmp -= 7;

		int tmp2 = buffer[2*i];
		tmp2 -= 48;
		if (tmp2 > 9) tmp2 -= 7;

		targetbuffer[i-1] = tmp * 16 + tmp2;

		printf("  %i ",targetbuffer[i-1]);

		//sscanf(pos, "%2hhx", &buffer[i]);
		//pos += 2* sizeof(char);
		//targetbuffer[i] << std::hex << buffer[i];
	}
        printf("\n");
        int m = (n-2)*4;

        std::cout << m << std::endl;

        print(stream, 0, m);
        std::cout << std::endl;

        Eurobalise_Telegram telegram;

        std::cout << " Decoding Eurobalise Telegram." << std::endl;
        telegram.decode(stream);

        std::cout << " Decoder Output: " << telegram << std::endl;

	for (int i = 0; i < n; i++) buffer[i] = 0;

	n = write(newsockfd,"I got your message",18);
	if (n < 0) error("ERROR writing to socket");
	

     }

     close(newsockfd);
     close(sockfd);
     return 0; 
}
