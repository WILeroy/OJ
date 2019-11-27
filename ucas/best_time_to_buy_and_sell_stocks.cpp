/*
Problem Description:
    Say you have an array for which the i-th element is the price of
	a given stock on day i. Design an algorithm to find the maximum
	profit. You may complete as many transactions as you like (i.e.,
	buy one and sell one share of the stock multiple times).

    For example, there is an array [7, 1, 5, 3, 6, 4] and its answer
	7. The element 7 in the array means the price of a given stock on
	day 0, and the element 4 means the price of the stock on day 5.
	The answer 7 means the maximum profit.

    Note: You may not engage in multiple transactions at the same time
	(i.e., you must sell the stock before you buy again).

Input:
    An array with int elements, separated by spaces.

Output:
    An integer.
*/

#include <stdio.h>

long long int price[1000000];
long long int n;

int main()
{
	long long int sum = 0;
	while (scanf("%lld", &price[n]) != EOF) {
		n++;
	}
	
	for (int i=1; i<n; i++) {
		if (price[i] > price[i-1]) {
			sum += (price[i]-price[i-1]);
		}
	}
	
	printf("%lld", sum);
	return 0;
}
