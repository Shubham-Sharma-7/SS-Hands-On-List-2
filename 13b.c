/*
============================================================================
Name : 13b.c
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
#include <sys/types.h>
int main()
{
    pid_t pid;
    printf("Enter process id\n");
    scanf("%d",&pid);
    int status = kill(pid, SIGSTOP);
    if (status == -1)
    {
        perror("Error while sending kill signal!");
    }
}
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