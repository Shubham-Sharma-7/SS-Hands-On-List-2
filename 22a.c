/*
============================================================================
Name : 22a.c
Author : Shubham Sharma
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date: 17th Sep, 2024
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/select.h>

int main() {
    const char *fifo_path = "./fifo_channel";
    mkfifo(fifo_path, 0666);  // Create the FIFO with read/write permissions

    int fd = open(fifo_path, O_RDONLY | O_NONBLOCK);  // Non-blocking read
    if (fd == -1) {
        perror("Error opening FIFO for reading");
        return 1;
    }

    fd_set readfds;
    struct timeval timeout;
    char buffer[100];

    FD_ZERO(&readfds);  // Clear the set
    FD_SET(fd, &readfds);  // Add the FIFO descriptor to the set

    timeout.tv_sec = 10;  // Wait up to 10 seconds
    timeout.tv_usec = 0;

    int result = select(fd + 1, &readfds, NULL, NULL, &timeout);

    if (result == -1) {
        perror("Select error");
    } else if (result == 0) {
        printf("No data received in 10 seconds.\n");
    } else {
        if (FD_ISSET(fd, &readfds)) {
            int len = read(fd, buffer, sizeof(buffer) - 1);
            if (len > 0) {
                buffer[len] = '\0';
                printf("Received message: %s\n", buffer);
            }
        }
    }

    close(fd);  // Close the FIFO
    unlink(fifo_path);  // Unlink the FIFO
    return 0;
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc 22a.c -o 22a
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc 22b.c -o 22b
(base) mohitsharma@MacBook-Pro hands on list 2 % ./22a
Received message: shubham
============================================================================
*/