/*
============================================================================
Name : 8b.c
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

void print()
{
    printf("SIGINT caught\n");
    _exit(0);
}

int main()
{
    if (signal(SIGINT, print) == SIG_ERR)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        raise(SIGINT); // SIGINT signal is sent to a process by its controlling terminal
    }
    
    return 0;
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc -o 8b.c 8b
(base) mohitsharma@MacBook-Pro hands on list 2 % ./8b
SIGINT caught
============================================================================
*/