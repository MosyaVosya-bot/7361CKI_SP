#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <ctype.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
     int sockfd, newsockfd, portno;
     int num1 , num2 , ans , choice;
     socklen_t clilen;
     char buffer[256];
     struct sockaddr_in serv_addr, cli_addr;
     int n;

     sockfd = socket(AF_INET, SOCK_STREAM, 0);
   
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)); 
         
     listen(sockfd,5);
     clilen = sizeof(cli_addr);
     newsockfd = accept(sockfd, 
                 (struct sockaddr *) &cli_addr, 
                 &clilen);
   
       
     while(true)
     {
     n = write(newsockfd,"Enter Number 1 : ",strlen("Enter Number 1"));           
     read(newsockfd, &num1, sizeof(int));					
     printf("Client Entered - Number 1 is : %d\n" , num1);
          
     n = write(newsockfd,"Enter Number 2 : ",strlen("Enter Number 2"));              
     read(newsockfd, &num2, sizeof(int));					
     printf("Client Entered - Number 2 is : %d\n" , num2);
   
     ans=num1+rand()%num2;
     write(newsockfd , &ans , sizeof(int));
     }
     close(newsockfd);
     close(sockfd);
     return 0; 
}
