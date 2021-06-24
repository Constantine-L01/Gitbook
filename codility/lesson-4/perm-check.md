# Check whether array A is a permutation. 

A non-empty array A consisting of N integers is given.

A permutation is a sequence containing each element from 1 to N once, and only once.

For example, array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2

is a permutation, but array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3

is not a permutation, because value 2 is missing.

The goal is to check whether array A is a permutation.

Write a function:

    int solution(vector<int> &A);

that, given an array A, returns 1 if array A is a permutation and 0 if it is not.

For example, given array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2

the function should return 1.

Given array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3

the function should return 0.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [1..100,000];
        each element of array A is an integer within the range [1..1,000,000,000].

## Solution

### C++

1. Insert all the existing numbers into an unordered_set, then check whether there is missing number. 
```C++
// you can use includes, for example:
#include <algorithm>
#include <unordered_set>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    unordered_set<int> set;

    for(int i = 0; i < A.size(); i++){
        set.insert(A[i]);
    }

    for(int i = 1; i <= A.size(); i++){
        if(set.find(i) == set.end()){
            return 0;
        }
    }

    return 1;
}
```
