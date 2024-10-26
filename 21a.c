/*
============================================================================
Name : 21a.c
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
    char *fifo1 = "./fifo1"; // FIFO for sending
    char *fifo2 = "./fifo2"; // FIFO for receiving

    mkfifo(fifo1, S_IRWXU);
    mkfifo(fifo2, S_IRWXU);

    while (1)
    {
        // Writing to FIFO1
        fd1 = open(fifo1, O_WRONLY);
        if (fd1 == -1) {
            perror("Error opening fifo1 for writing");
            exit(1);
        } else {
            printf("Enter message: ");
            int l = getline(&s, &size, stdin);
            write(fd1, s, l);
            close(fd1);
            printf("message completed\n");
        }

        // Reading from FIFO2
        fd2 = open(fifo2, O_RDONLY);
        if (fd2 == -1) {
            perror("Error opening fifo2 for reading");
            exit(1);
        } else {
            char buf;
            printf("Received: ");
            while (read(fd2, &buf, 1) > 0)
                write(1, &buf, 1);
            write(1, "\n", 1);
            close(fd2);
            printf("message completed\n");
        }
    }

    return 0;
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc 21a.c -o 21a
(base) mohitsharma@MacBook-Pro hands on list 2 % ./21a
Enter message: Shubham
message completed
Sharma

Received: message completed
Enter message: sending to 21b
message completed
sending to 21a

Received: message completed
Enter message: ^Z
zsh: suspended  ./21a
============================================================================
*/