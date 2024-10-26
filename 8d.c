/*
============================================================================
Name : 8d.c
Author : Shubham Sharma
Description : Write a separate program using signal system call to catch the following signals.
    a.SIGSEGV
    b.SIGINT
    c.SIGFPE
    d.SIGALRM(use alarm system call)
    e.SIGALRM(use setitimer system call)
    f.SIGVTALRM(use setitimer system call)
    g.SIGPROF(use setitimer system call)
Date: 13th Sep, 2024
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void print(int signum)
{
    printf("SIGALRM caught\n");
    exit(0);
}

int main()
{
    struct sigaction sa;
    sa.sa_handler = print; // Set the handler
    sigemptyset(&sa.sa_mask); // No additional signals to block
    sa.sa_flags = 0; // No special flags

    // Set up the signal handler for SIGALRM
    if (sigaction(SIGALRM, &sa, NULL) == -1)
    {
        perror("Error while assigning signal handler");
        return 1;
    }

    alarm(2); // Set an alarm for 2 seconds

    // Efficiently wait for the signal
    while (1)
    {
        pause(); // Wait for signals
    }

    return 0; // This will never be reached
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc -o 8d.c 8d
(base) mohitsharma@MacBook-Pro hands on list 2 % ./8d
SIGALRM caught
============================================================================
*/