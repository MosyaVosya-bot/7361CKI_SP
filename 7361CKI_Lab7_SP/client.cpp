#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include<ctype.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
   
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    server = gethostbyname(argv[1]);
    
 
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr));
  
  
    int num1;
    int num2;
    int ans;
    
    
    
    while(true)
    {
    
    memset(buffer,0,256*sizeof(int));						
    n = read(sockfd,buffer,255);				

    printf("Server talking  - %s\n",buffer);
    scanf("%d" , &num1);						
    write(sockfd, &num1, sizeof(int));     		
	
	
	
    memset(buffer,0,256*sizeof(int));;						
    n = read(sockfd,buffer,255);				

    printf("Server talking - %s\n",buffer);
    scanf("%d" , &num2);						
    write(sockfd, &num2, sizeof(int));     			
	    			


    read(sockfd , &ans , sizeof(int));				
    printf("Server: Your random nuber is : %d\n" , ans);
    
	
    }
    close(sockfd);
    return 0;
}
