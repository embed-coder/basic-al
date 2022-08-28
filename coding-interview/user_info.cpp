/*
Consider the struct UserInfo, which is used in a performance critical sub-system.

Currently, on a system:

    A long long takes 8 bytes
    A pointer, a float, and an int take 4 bytes each
    A short takes 2 bytes
    A char takes 1 byte

The struct takes 48 bytes of space. Rearrange the struct, without removing, renaming, or changing the type of the members, so that it uses less memory. The code uses pointers to struct members, so struct should be properly aligned.
*/
#include <stdio.h>

typedef struct UserInfo {
    long long credit_amount;
    float interest;
    int id;
    int account_number;
    int years_member;
    char* name;
    short account_type_code;
    char gender;
    char credit_rating;
} UserInfo;

#ifndef RunTests
int main() {
    printf("%d", sizeof(UserInfo));
}
#endif