/*
============================================================================
Name : 4.c
Author : Shubham Sharma
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 12th Sep, 2024
============================================================================
*/
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>

// Function to get the current time in nanoseconds
static inline uint64_t get_time_in_ns(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint64_t)ts.tv_sec * 1000000000ULL + ts.tv_nsec;
}

int main() {
    uint64_t start, end;
    pid_t pid;

    // Record the time before the system call
    start = get_time_in_ns();

    // Call getpid()
    pid = getpid();

    // Record the time after the system call
    end = get_time_in_ns();

    // Calculate the time taken in nanoseconds
    uint64_t time_taken_ns = end - start;

    printf("getpid() returned: %d\n", pid);
    printf("Time taken by getpid() in nanoseconds: %llu\n", time_taken_ns);

    return 0;
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc -o 4 4.c
(base) mohitsharma@MacBook-Pro hands on list 2 % ./4
getpid() returned: 12566
Time taken by getpid() in nanoseconds: 0
============================================================================
*/