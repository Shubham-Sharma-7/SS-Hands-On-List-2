/*
============================================================================
Name : 22b.c
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

int main() {
    const char *fifo_path = "./fifo_channel";
    mkfifo(fifo_path, 0666);  // Create the FIFO with read/write permissions

    // Wait for the reader to open the FIFO first
    int fd = open(fifo_path, O_WRONLY);  // Block until the reader opens FIFO
    if (fd == -1) {
        perror("Error opening FIFO for writing");
        return 1;
    }

    char buffer[100];
    printf("Enter a message to send: ");
    fgets(buffer, sizeof(buffer), stdin);

    write(fd, buffer, strlen(buffer));  // Write to the FIFO
    close(fd);  // Close the FIFO

    return 0;
}

/*
============================================================================
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc 22b.c -o 22b
(base) mohitsharma@MacBook-Pro hands on list 2 % ./22b
Enter a message to send: shubham
============================================================================
*/