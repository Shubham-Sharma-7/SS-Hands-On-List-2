/*
============================================================================
Name : 10b.c
Author : Shubham Sharma
Description : Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
Date: 13th Sep, 2024
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
void print()
{
    printf("Caught SIGINT\n");
}
int main()
{
    int status;
    struct sigaction act;

    act.sa_handler = print; // function that replace default action of signal SIGSEGV
    act.sa_flags = 0;
    status = sigaction(SIGINT, &act, NULL);
    if (status == -1)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        raise(SIGINT);
    }
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc 10b.c -o 10b
(base) mohitsharma@MacBook-Pro hands on list 2 % ./10b
Caught SIGINT
============================================================================
*/