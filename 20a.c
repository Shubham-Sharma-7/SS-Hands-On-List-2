/*
============================================================================
Name : 20a.c
Author : Shubham Sharma
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 16th Sep, 2024
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *file = "/tmp/my_fifo"; // Path for the FIFO file
    mkfifo(file, 0666); // Create FIFO file with read-write permissions

    char message[100];
    int fd;

    while (1)
    {
        fd = open(file, O_WRONLY); // Open FIFO in write-only mode
        if (fd == -1)
        {
            perror("Error opening FIFO for writing");
            exit(EXIT_FAILURE);
        }

        printf("Enter message to send: ");
        fgets(message, sizeof(message), stdin); // Read message from user input

        write(fd, message, sizeof(message)); // Write message to FIFO
        close(fd); // Close FIFO after writing
    }

    return 0;
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc 20a.c -o 20a
(base) mohitsharma@MacBook-Pro hands on list 2 % ./20a
Enter message to send: Shubham writing to the other program 
Enter message to send: okay now closing the communication 
Enter message to send: bye^Z
zsh: suspended  ./20a
============================================================================
*/