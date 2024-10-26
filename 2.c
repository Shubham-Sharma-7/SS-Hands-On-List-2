/*
============================================================================
Name : 2.c
Author : Shubham Sharma
Description : Write a program to print the system resource limits. Use getrlimit system call.
Date: 12th Sep, 2024
============================================================================
*/
#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

void print(char *text, rlim_t soft, rlim_t hard, char *unit)
{
    printf("%s - \n", text);

    printf("\tSoft Limit: ");
    if (soft == RLIM_INFINITY)
        printf("Unlimited\n");
    else
        printf("%ld %s\n", soft, unit);

    printf("\tHard Limit: ");
    if (hard == RLIM_INFINITY)
        printf("Unlimited\n");
    else
        printf("%ld %s\n", hard, unit);
}

int main()
{
    int status;                   // Determines the success of the `getrlimit` call
    struct rlimit resourceLimits; // Holds the hard & soft limits for a resource

    // RLIMIT_AS -> Maximum size of the process's virtual memory (address space)
    status = getrlimit(RLIMIT_AS, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_AS!");
    else
        print("Max size of process's virtual memory", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");

    // RLIMIT_CORE -> Maximum size of core dump
    status = getrlimit(RLIMIT_CORE, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_CORE!");
    else
        print("Max size of core dump", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");

    // RLIMIT_CPU -> Maximum CPU time that the process can consume
    status = getrlimit(RLIMIT_CPU, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_CPU!");
    else
        print("Max CPU time the process can consume", resourceLimits.rlim_cur, resourceLimits.rlim_max, "seconds");

    // RLIMIT_DATA -> Maximum size of the process's data segment
    status = getrlimit(RLIMIT_DATA, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_DATA!");
    else
        print("Max size of process's data segment", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");

    // RLIMIT_FSIZE -> Maximum size of files the process may create
    status = getrlimit(RLIMIT_FSIZE, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_FSIZE!");
    else
        print("Max size of files the process may create", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");

    // RLIMIT_MEMLOCK -> Maximum number of bytes that can be locked into memory
    status = getrlimit(RLIMIT_MEMLOCK, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_MEMLOCK!");
    else
        print("Max number of bytes that can be locked into memory", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");

    // RLIMIT_NOFILE -> Maximum number of open files
    status = getrlimit(RLIMIT_NOFILE, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_NOFILE!");
    else
        print("Max number of open files", resourceLimits.rlim_cur, resourceLimits.rlim_max, "files");

    // RLIMIT_NPROC -> Maximum number of processes the user can create
    status = getrlimit(RLIMIT_NPROC, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_NPROC!");
    else
        print("Max number of processes the user can create", resourceLimits.rlim_cur, resourceLimits.rlim_max, "");

    // RLIMIT_RSS -> Maximum resident set size
    status = getrlimit(RLIMIT_RSS, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_RSS!");
    else
        print("Max resident set size (RSS)", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");

    // RLIMIT_STACK -> Maximum stack size
    status = getrlimit(RLIMIT_STACK, &resourceLimits);
    if (status == -1)
        perror("Error while getting RLIMIT_STACK!");
    else
        print("Max size of process stack", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");

    return 0;
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc -o 2 2.c
(base) mohitsharma@MacBook-Pro hands on list 2 % ./2
Max size of process's virtual memory - 
	Soft Limit: Unlimited
	Hard Limit: Unlimited
Max size of core dump - 
	Soft Limit: 0 bytes
	Hard Limit: Unlimited
Max CPU time the process can consume - 
	Soft Limit: Unlimited
	Hard Limit: Unlimited
Max size of process's data segment - 
	Soft Limit: Unlimited
	Hard Limit: Unlimited
Max size of files the process may create - 
	Soft Limit: Unlimited
	Hard Limit: Unlimited
Max number of bytes that can be locked into memory - 
	Soft Limit: Unlimited
	Hard Limit: Unlimited
Max number of open files - 
	Soft Limit: 256 files
	Hard Limit: Unlimited
Max number of processes the user can create - 
	Soft Limit: 1333 
	Hard Limit: 2000 
Max resident set size (RSS) - 
	Soft Limit: Unlimited
	Hard Limit: Unlimited
Max size of process stack - 
	Soft Limit: 8372224 bytes
	Hard Limit: 67092480 bytes
============================================================================
*/