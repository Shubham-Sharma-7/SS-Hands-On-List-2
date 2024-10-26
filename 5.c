/*
============================================================================
Name : 5.c
Author : Shubham Sharma
Description : Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.
Date: 12th Sep, 2024
============================================================================
*/
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main() {
    long val;

    // _SC_ARG_MAX - Maximum length of the arguments to the exec family of functions.
    errno = 0;  // Reset errno before calling sysconf()
    val = sysconf(_SC_ARG_MAX);
    if (val == -1) {
        if (errno != 0) {
            perror("sysconf(_SC_ARG_MAX) failed");
        } else {
            printf("_SC_ARG_MAX is undefined.\n");
        }
    } else {
        printf("Maximum length of the arguments to the exec family of functions: %ld\n", val);
    }

    // _SC_CHILD_MAX - Maximum number of simultaneous processes per user ID.
    errno = 0;
    val = sysconf(_SC_CHILD_MAX);
    if (val == -1) {
        if (errno != 0) {
            perror("sysconf(_SC_CHILD_MAX) failed");
        } else {
            printf("_SC_CHILD_MAX is undefined.\n");
        }
    } else {
        printf("Maximum number of simultaneous processes per user ID: %ld\n", val);
    }

    // _SC_CLK_TCK - Number of clock ticks (jiffy) per second.
    errno = 0;
    val = sysconf(_SC_CLK_TCK);
    if (val == -1) {
        if (errno != 0) {
            perror("sysconf(_SC_CLK_TCK) failed");
        } else {
            printf("_SC_CLK_TCK is undefined.\n");
        }
    } else {
        printf("Number of clock ticks (jiffy) per second: %ld\n", val);
    }

    // _SC_OPEN_MAX - Maximum number of open files.
    errno = 0;
    val = sysconf(_SC_OPEN_MAX);
    if (val == -1) {
        if (errno != 0) {
            perror("sysconf(_SC_OPEN_MAX) failed");
        } else {
            printf("_SC_OPEN_MAX is undefined.\n");
        }
    } else {
        printf("Maximum number of open files: %ld\n", val);
    }

    // _SC_PAGESIZE - Size of a page.
    errno = 0;
    val = sysconf(_SC_PAGESIZE);
    if (val == -1) {
        if (errno != 0) {
            perror("sysconf(_SC_PAGESIZE) failed");
        } else {
            printf("_SC_PAGESIZE is undefined.\n");
        }
    } else {
        printf("Size of a page: %ld bytes\n", val);
    }
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc -o 5.c 5
(base) mohitsharma@MacBook-Pro hands on list 2 % ./5
Maximum length of the arguments to the exec family of functions: 1048576
Maximum number of simultaneous processes per user ID: 1333
Number of clock ticks (jiffy) per second: 100
Maximum number of open files: 256
Size of a page: 16384 bytes
============================================================================
*/