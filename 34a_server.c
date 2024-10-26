/*
============================================================================
Name : 34a.c
Author : Shubham Sharma
Description : Write a program to create a concurrent server.
    a.use fork
    b.use pthread_create
============================================================================
*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

int main() {
    int socktd = socket(AF_INET, SOCK_STREAM, 0);
    if (socktd == -1) {
        perror("Error when creating socket");
        return -1;
    }
    printf("Server socket created\n");

    // Server info
    struct sockaddr_in server, client;
    server.sin_addr.s_addr = htonl(INADDR_ANY); // Host to network long
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);  // Port 8080

    // Bind the socket
    int bindS = bind(socktd, (struct sockaddr *)&server, sizeof(server));
    if (bindS == -1) {
        perror("Error while binding name to socket");
        return -1;
    }
    printf("Binding to server socket was successful!\n");

    // Listen for connections
    int listenS = listen(socktd, 3);
    if (listenS == -1) {
        perror("Error while trying to listen for connections");
        return -1;
    }
    printf("Listening for connections...\n");

    while (1) {
        socklen_t client_size = sizeof(client);
        int connectionfd = accept(socktd, (struct sockaddr *)&client, &client_size);
        if (connectionfd == -1) {
            perror("Error while accepting connection");
            return -1;
        }
        printf("Connection accepted from client\n");

        if (fork() == 0) {
            // In child process
            char buf[100];
            printf("Write message from server to client: ");
            fgets(buf, sizeof(buf), stdin);

            // Write message from server to connection fd
            write(connectionfd, buf, strlen(buf));

            // Clear the buffer
            memset(buf, 0, sizeof(buf));

            // Read message from client
            read(connectionfd, buf, sizeof(buf));
            printf("Data from client: %s\n", buf);

            // Close the connection in the child process
            close(connectionfd);
            _exit(0);
        } else {
            // In parent process, close the connection fd
            close(connectionfd);
        }
    }

    // Closing socket
    close(socktd);
    return 0;
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc -o 34a_server 34a_server.c
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc -o 34a_client 34a_client.c
(base) mohitsharma@MacBook-Pro hands on list 2 % ./34a_server
Server socket created
Binding to server socket was successful!
Listening for connections...
Connection accepted from client
Write message from server to client: hello client
Data from client: hello server
^Z
zsh: suspended  ./34a_server
============================================================================
*/