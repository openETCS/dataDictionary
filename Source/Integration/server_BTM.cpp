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
#include <cassert>

#include "EurobaliseTelegram.h"
#include "Bitstream_Init.h"
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
    signal(sig, SIG_IGN);
    std::cout << "Do you really want to quit? [y/n] ";

    char  c = getchar();

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

    unsigned char buffer[2048];
    unsigned char targetbuffer[2048];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        error("ERROR opening socket\n");
    }

    struct sockaddr_in serv_addr;

    bzero(&serv_addr, sizeof(serv_addr));

    const int portno = 15010;

    //portno = atoi(argv[1]);
    // setting fixed port number

    serv_addr.sin_family = AF_INET;

    serv_addr.sin_addr.s_addr = INADDR_ANY;

    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        error("ERROR on binding\n");
    }

    listen(sockfd, 5);

    struct sockaddr_in cli_addr;
    socklen_t clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

    if (newsockfd < 0)
    {
        error("ERROR on accept\n");
    }

    bzero(buffer, 256);

    std::cout << "BTM Server listening to port " << portno << " started.\n";

    while (1)
    {
        int n = read(newsockfd, buffer, 2048);

        if (n < 0)
        {
            error("ERROR reading from socket");
        }

        std::cout << "Here is the message: " << buffer << std::endl;
        //unsigned char *pos = targetbuffer;
        std::cout << "Target buffer: length: " << n;

        for (int i = 1; i <= n / 2 - 1; i++)
        {
            std::cout << " (" <<  buffer[2 * i - 1] << "," <<  buffer[2 * i] << ")";

            int tmp = buffer[2 * i - 1] - 48;

            if (tmp > 9)
            {
                tmp -= 7;
            }

            int tmp2 = buffer[2 * i] - 48;

            if (tmp2 > 9)
            {
                tmp2 -= 7;
            }

            targetbuffer[i - 1] = tmp * 16 + tmp2;

            std::cout << "  " << targetbuffer[i - 1] << " ";

            //sscanf(pos, "%2hhx", &buffer[i]);
            //pos += 2* sizeof(char);
            //targetbuffer[i] << std::hex << buffer[i];
        }

        std::cout << std::endl;
        int m = (n - 2) * 4;

        std::cout << m << std::endl;

        Bitstream stream;
        Bitstream_Init(&stream, targetbuffer, 2048, 0);
        print(stream, 0, m);
        std::cout << std::endl;

        std::cout << " Decoding Eurobalise Telegram." << std::endl;

        EurobaliseTelegram telegram;
        telegram.decode(stream);

        std::cout << " Decoder Output: " << telegram << std::endl;

        for (int i = 0; i < n; i++)
        {
            buffer[i] = 0;
        }

        n = write(newsockfd, "I got your message", 18);

        if (n < 0)
        {
            error("ERROR writing to socket");
        }

    }

    close(newsockfd);
    close(sockfd);

    return EXIT_SUCCESS;
}

