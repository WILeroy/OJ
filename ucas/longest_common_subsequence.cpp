/*
Problem Description:
    Given two sequences, find the length of the longest common
	subsequence (LCS). A subsequence is different from a substring,
	for the former need NOT be consecutive of the original sequence.
	For example, for “ABCD" and “AEFC", the longest common subsequence
	is “AC", and the length of it is 2.

Input:
    The first line of input is an integer N representing the pair
	number of sequences in this group test cases. (0<N<=100). For
	each test case, it contains two lines. The first line contains
	two integer L1 and L2, which represent the lengths of two
	sequences (0<L1, L2<=1000). The second line consists of two
	sequences separated by a space. Each sequence consists of uppercase
	English characters only.

Output:
    Output file must contain N integers - each integer represents the
	length of the longest common subsequence of the given sequences.
*/

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

short n;
short L1, L2;
string str1, str2;
short map[1001][1001];
short result[100];

int main()
{
	scanf("%hd", &n);
	
	for (int k=0; k<n; k++) {
		scanf("%hd%hd", &L1, &L2);
		cin >> str1 >> str2;
		for (int i=1; i<=L1; i++) {
			for (int j=1; j<=L2; j++) {
				if (str1[i-1] == str2[j-1]) {
					map[i][j] = map[i-1][j-1]+1;
				} else {
					if (map[i-1][j] > map[i][j-1]) map[i][j] = map[i-1][j];
					else map[i][j] = map[i][j-1];
				}
			}
		}
		result[k] = map[L1][L2];
	}
	
	cout << result[0];
	for (int i=1; i<n; i++) {
		cout << endl << result[i];
	}
	
	return 0;
} 
