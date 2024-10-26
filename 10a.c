/*
============================================================================
Name : 10a.c
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
void print(){
    printf("Caught SIGSEGV\n");
}
int main()
{
    int status;
    struct sigaction act;
    
    act.sa_handler=print;//function that replace default action of signal SIGSEGV
    act.sa_flags=0;
    status = sigaction(SIGSEGV,&act,NULL);
    if (status == -1)
    {
        perror("Error while assigning signal handler!");
    }
    else
    {
        raise(SIGSEGV);
    }
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc -o 10a.c 10a
(base) mohitsharma@MacBook-Pro hands on list 2 % ./10a
Caught SIGSEGV
============================================================================
*/