/*
============================================================================
Name : 13a.c
Author : Shubham Sharma
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 15th Sep, 2024
============================================================================
*/
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void print() {
    printf("Received SIGSTOP\n");
}

int main() {
    // Attempt to set a signal handler for SIGSTOP
    struct sigaction sa;
    sa.sa_handler = print;
    sa.sa_flags = 0; // No special flags
    sigemptyset(&sa.sa_mask); // No additional signals blocked

    if (sigaction(SIGSTOP, &sa, NULL) == -1) {
        perror("Error while assigning signal handler for SIGSTOP");
    }

    printf("Sleeping for 15 seconds. Try sending SIGSTOP (Ctrl+Z).\n");
    sleep(15);

    return 0;
}

/*
    A program cannot catch a SIGSTOP signal. We can conclude this by observing that the customHandler function is never executed and instead the program is terminated!
    Two signals that cannot be caught or ignored:
    SIGSTOP
    SIGKILL
*/

/*
============================================================================
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc 13a.c -o 13a
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc 13b.c -o 13b
(base) mohitsharma@MacBook-Pro hands on list 2 % ./13a &
[2] 19548
(base) mohitsharma@MacBook-Pro hands on list 2 % Error while assigning signal handler for SIGSTOP: Invalid argument
Sleeping for 15 seconds. Try sending SIGSTOP (Ctrl+Z).
./13b
Enter process id
[2]  - done       ./13a
19548
Error while sending kill signal!: No such process
============================================================================
*/