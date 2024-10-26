/*
============================================================================
Name : 21b.c
Author : Shubham Sharma
Description : Write two programs so that both can communicate by FIFO -Use two way communication.
Date: 17th Sep, 2024
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
    char *s=NULL;  // Data to be sent through the buffer
    int fd1, fd2;  // File descriptors for the FIFO files
    long int size = 100;
    char *fifo1 = "./fifo1"; // FIFO for receiving
    char *fifo2 = "./fifo2"; // FIFO for sending

    mkfifo(fifo1, S_IRWXU);
    mkfifo(fifo2, S_IRWXU);

    while (1)
    {
        // Reading from FIFO1
        fd1 = open(fifo1, O_RDONLY);
        if (fd1 == -1) {
            perror("Error opening fifo1 for reading");
            exit(1);
        } else {
            char buf;
            printf("Received: ");
            while (read(fd1, &buf, 1) > 0)
                write(1, &buf, 1);
            write(1, "\n", 1);
            close(fd1);
        }

        // Writing to FIFO2
        fd2 = open(fifo2, O_WRONLY);
        if (fd2 == -1) {
            perror("Error opening fifo2 for writing");
            exit(1);
        } else {
            printf("Enter message: ");
            int l = getline(&s, &size, stdin);
            write(fd2, s, l);
            close(fd2);
        }
    }

    return 0;
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc 21b.c -o 21b
(base) mohitsharma@MacBook-Pro hands on list 2 % ./21b
Shubham

Received: Enter message: Sharma
sending to 21b

Received: Enter message: sending to 21a
^Z
zsh: suspended  ./21b

============================================================================
*/