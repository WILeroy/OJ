/*
Problem Description:
    Recall the problem of finding the number of inversions. As in the
    course, we are given a sequence of n numbers a1, a2, ⋯, an, and
    we define an inversion to be a pair i<j such that ai>aj.

    We motivated the problem of counting inversions as a good measure
    of how different two orderings are. However, one might feel that
    this measure is too sensitive. Let's call a pair a significant
    inversion if i<j and ai>3aj. Give an O(nlogn) algorithm to count
    the number of significant inversions between two orderings.

    The array contains N elements (1<=N<=100000). All elements are in
    the range from 1 to 1000000000.

Input:
    The first line contains one integer N, indicating the size of the
    array. The second line contains N elements in the array. (50%
    test cases guarantee that N<1000.)

Output:
    Output a single integer which is the number of pairs of significant
    inversions. 
*/

#include <stdio.h>

int n;
long long int a[100001];
long long int a3[100001];
long long int a_[100001];
long long int a3_[100001];
int num;

void merge(int l, int mid, int r)
{
    int i = l;
    int j = mid + 1;

    int k1 = l;
    int k2 = mid+1;

    while (k1<=mid && k2<=r) {
        if (a[k1] > a3[k2]) {
            num += (r-k2+1);
            k1++;        
        }
        else {
            k2++;
        }
    }

    for (int k = l; k <= r; k++) {
        if (i > mid) {
        	a_[k] = a[j];
            a3_[k] = a3[j++];
        }
        else if (j > r) {
            a_[k] = a[i];
            a3_[k] = a3[i++];
        }
        else if (a[i] > a[j]) {
            a_[k] = a[i];
            a3_[k] = a3[i++];
        }
        else {
            a_[k] = a[j];
            a3_[k] = a3[j++];
        }
    }
    //copy sorted array.
    for (int k = l; k <= r; k++) {
        a[k] = a_[k];
        a3[k] = a3_[k];
    }
}

void mergesort(int l, int r) 
{
    if (l < r) {
        int mid = (l+r)/2;
        mergesort(l, mid);
        mergesort(mid+1, r);
        merge(l, mid, r);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        scanf("%lld", &a[i]);
        a3[i] = 3 * a[i];
    }
    
    mergesort(0, n-1);

    printf("%d", num);
    
    return 0;
}