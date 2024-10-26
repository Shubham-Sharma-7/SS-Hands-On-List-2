/*
============================================================================
Name : 8f.c
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
#include <sys/time.h>
#include <stdlib.h>

void print(int signum)
{
    printf("SIGVTALRM caught\n");
    exit(0);
}

int main()
{
    struct itimerval timer;

    // Configure the timer
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;
    timer.it_value.tv_sec = 2; // Set an alarm for 2 seconds
    timer.it_value.tv_usec = 0;

    // Set the timer
    if (setitimer(ITIMER_VIRTUAL, &timer, NULL) == -1)
    {
        perror("Error while setting an interval timer!");
        return 1;
    }

    // Set up the signal handler
    if (signal(SIGVTALRM, print) == SIG_ERR)
    {
        perror("Error while assigning signal handler!");
        return 1;
    }

    // Loop to wait for the alarm
    while (1)
    {
        pause(); //Wait for the signal to be caught
    }

    return 0; // This will never be reached
}

/*
============================================================================
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc -o 8f.c 8f
(base) mohitsharma@MacBook-Pro hands on list 2 % ./8f
SIGVTALARM caught
============================================================================
*/