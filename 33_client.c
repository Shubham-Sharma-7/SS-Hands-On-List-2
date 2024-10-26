/*
============================================================================
Name : 33.c
Author : Shubham Sharma
Description : Write a program to communicate between two machines using socket.
============================================================================
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\nSocket creation error\n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 address from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported\n");
        return -1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed\n");
        return -1;
    }

    // Send message to the server
    char *message = "Hello from the client";
    send(sock, message, strlen(message), 0);
    printf("Message sent to server\n");

    // Receive response from the server
    read(sock, buffer, BUFFER_SIZE);
    printf("Response from server: %s\n", buffer);

    // Close the socket
    close(sock);

    return 0;
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc -o 33_server 33_server.c
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc -o 33_client 33_client.c
(base) mohitsharma@MacBook-Pro hands on list 2 % ./33_client
Message sent to server
Response from server: Hello from the server
============================================================================
*/