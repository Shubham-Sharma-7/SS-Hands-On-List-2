/*
============================================================================
Name : 20b.c
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

    char buffer[100];
    int fd;

    while (1)
    {
        fd = open(file, O_RDONLY); // Open FIFO in read-only mode
        if (fd == -1)
        {
            perror("Error opening FIFO for reading");
            exit(EXIT_FAILURE);
        }

        read(fd, buffer, sizeof(buffer)); // Read message from FIFO
        printf("Received: %s", buffer);   // Print received message

        close(fd); // Close FIFO after reading
    }

    return 0;
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc 20b.c -o 20b
(base) mohitsharma@MacBook-Pro hands on list 2 % ./20b
Received: Shubham writing to the other program
Received: okay now closing the communication 
^Z
zsh: suspended  ./20b
============================================================================
*/