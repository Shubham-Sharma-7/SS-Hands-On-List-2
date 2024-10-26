/*
============================================================================
Name : 8c.c
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
    printf("SIGFPE caught\n");
    _exit(0);
}

int main()
{
    if (signal(SIGFPE, print) == SIG_ERR)
    {
        perror("Error while assigning signal handler!");
        return 1;
    }

    // Trigger SIGFPE by dividing by zero
    int x = 1;
    int y = 0;
    int result = x / y; // This will cause SIGFPE (division by zero)

    (void)result; // Avoid unused variable warning
    print();
    return 0;
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc -o 8c.c 8c
(base) mohitsharma@MacBook-Pro hands on list 2 % ./8c
SIGFPE caught

============================================================================
*/