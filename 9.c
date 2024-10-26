/*
============================================================================
Name : 9.c
Author : Shubham Sharma
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal - 
Use signal system call. 
Date: 13th Sep, 2024
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handle_sigint(int sig) {
    printf("Caught SIGINT signal: %d\n", sig);
}

int main() {
    // Ignore the SIGINT signal for 5 seconds
    printf("Ignoring the SIGINT signal for 5 seconds\n");
    signal(SIGINT, SIG_IGN);
    sleep(5);

    // Reset the default action of the SIGINT signal
    printf("Resetting the default action of the SIGINT signal\n");
    signal(SIGINT, handle_sigint);
    sleep(5);

    printf("You can now send a SIGINT signal (Ctrl+C)\n");
    while (1) {
        // Infinite loop to keep the program running
    }

    return 0;
}

/*
============================================================================
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc -o 9.c 9
(base) mohitsharma@MacBook-Pro hands on list 2 % ./9
Ignoring the SIGINT signal for 5 seconds
Resetting the default action of the SIGINT signal
You can now send a SIGINT signal (Ctrl+C)
^CCaught SIGINT signal: 2
^CCaught SIGINT signal: 2
^CCaught SIGINT signal: 2
^Z
zsh: suspended
============================================================================
*/