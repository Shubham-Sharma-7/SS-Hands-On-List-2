/*
============================================================================
Name : 8a.c
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

void print(int sig)
{
    printf("SIGSEGV caught\n");
    _exit(0);
}

int main()
{
    // Assigning signal handler for SIGSEGV
    if (signal(SIGSEGV, print) == SIG_ERR)
    {
        perror("Error while assigning signal handler!");
        exit(EXIT_FAILURE);
    }

    // Send segmentation fault signal
    raise(SIGSEGV);

    return 0;
}

/*
============================================================================
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc -o 8a.c 8a
(base) mohitsharma@MacBook-Pro hands on list 2 % ./8a
SIGSEGV caught
============================================================================
*/