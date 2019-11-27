/*
Problem description:
    Find the kth largest element in an unsorted array A. Note that it
    is the kth largest element in the sorted order, not the kth 
    distinct element. The range of length of A is N (1≤N≤5000000) and
    the element (integer) in A is no bigger than 1000000000. 

Input:
    Line 1: the length of the unsorted array A and the index k.
    Line 2: the all elements in array A and split by spaces.

Output:
    Line 1: A single integer that is the kth largest element in an
    unsorted array A.
*/

#include <stdio.h>

int N, K;
int A[5000001];

int Semi_Quick_Sort(int left, int right)
{
    int cur = left;
    while (left != right) {
        if (cur == left) {
            if (A[left] < A[right]) {
                int t = A[left];
                A[left] = A[right];
                A[right] = t;
                left++;
                cur = right;
            }
            else {
                right--;
            }
        }
        else {
            if (A[left] < A[right]) {
                int t = A[left];
                A[left] = A[right];
                A[right] = t;
                right--;
                cur = left;
            }
            else {
                left++;
            }
        }
    }
    return cur;
}

int main()
{
    scanf("%d%d", &N, &K);
    for (int i=0; i<N; ++i) {
        scanf("%d", &A[i]);
    }

    int left = 0;
    int right = N-1;
    K = K-1;
    int cur = Semi_Quick_Sort(left, right);
    while (cur != K) {
        if (cur < K) left = cur + 1;
        else right = cur - 1;
        cur = Semi_Quick_Sort(left, right);
    }
    
    printf("%d", A[cur]);
    return 0;
}
