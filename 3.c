/*
============================================================================
Name : 3.c
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

    printf("Before updating limits\n");
    
    // RLIMIT_STACK -> Maximum size of the process stack
    status = getrlimit(RLIMIT_STACK, &resourceLimits);
    if (status == -1)
    {
        perror("Error while getting RLIMIT_STACK!");
    }
    else
    {
        print("Maximum size of the process stack", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");
    }

    printf("Choosing new resource limits\n");
    struct rlimit newresourceLimits; // Holds the new hard & soft limits for a resource
    newresourceLimits.rlim_cur = 16 * 1024 * 1024; // Set soft limit to 16MB
    newresourceLimits.rlim_max = 32 * 1024 * 1024; // Set hard limit to 32MB
    status = setrlimit(RLIMIT_STACK, &newresourceLimits);
    if (status == -1)
    {
        perror("Error while setting new RLIMIT_STACK!");
    }

    printf("After updating limits\n");

    // RLIMIT_STACK -> Maximum size of the process stack
    status = getrlimit(RLIMIT_STACK, &resourceLimits);
    if (status == -1)
    {
        perror("Error while getting RLIMIT_STACK!");
    }
    else
    {
        print("Maximum size of the process stack", resourceLimits.rlim_cur, resourceLimits.rlim_max, "bytes");
    }

    return 0;
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands on list 2 % gcc -o 3 3.c
(base) mohitsharma@MacBook-Pro hands on list 2 % ./3
Before updating limits
Maximum size of the process stack - 
	Soft Limit: 8372224 bytes
	Hard Limit: 67092480 bytes
Choosing new resource limits
After updating limits
Maximum size of the process stack - 
	Soft Limit: 16777216 bytes
	Hard Limit: 33554432 bytes
============================================================================
*/