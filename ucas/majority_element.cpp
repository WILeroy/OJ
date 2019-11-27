/*
Problem description:
    Given an array of size n, find the majority element. The majority
	element is the element that appears more than n/2 times. You may
	assume that the array is non-empty and the majority element always
	exist in the array.

    The range of length of array is n (1≤n≤5000000) and the element in
	array is no bigger than 1000000000.

Input:
    Line 1: the length of array.
	Line 2: the all elements in array and split by spaces.

Output:
    Line 1: A single integer that is the majority element.
*/

#include <stdio.h>

long long int n;

int main()
{
	scanf("%lld", &n);
	long long int t, l;
	long long int num = 1;
	scanf("%lld", &l);

	for (long long int i=1; i<n; i++) {
    	scanf("%lld", &t);
    	if (num == 0) {
			l = t;
			num++;
			continue;
		}
    	if (l == t) num++;
    	else num--;
	}
	
	printf("%lld", l);
	return 0;
}

