/*
============================================================================
Name : 8g.c
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
    printf("SIGPROF caught\n");
    exit(0); // Exit the program after handling the signal
}

int main()
{
    struct itimerval timer;

    // Configure the timer
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;
    timer.it_value.tv_sec = 0;
    timer.it_value.tv_usec = 2;

    // Set the timer
    if (setitimer(ITIMER_PROF, &timer, NULL) == -1)
    {
        perror("Error while setting an interval timer!");
        return 1;
    }

    // Set up the signal handler
    if (signal(SIGPROF, print) == SIG_ERR)
    {
        perror("Error while assigning signal handler!");
        return 1;
    }

    // Wait for the signal to be caught
    pause(); // Suspend the process until a signal is caught

    // The program should exit in the signal handler
    return 0;
}

/*
============================================================================
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc -o 8g.c 8g
(base) mohitsharma@MacBook-Pro hands on list 2 % ./8g
SIGPROF caught
============================================================================
*/