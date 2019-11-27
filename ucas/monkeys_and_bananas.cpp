/*
Problem Description:
    Given an array of size n that has the following speciﬁcations:
        Each element in the array contains either a monkey or a banana.
        Each monkey can eat only one banana.
        A monkey cannot eat a banana which is more than K units away from the monkey.
    We need to ﬁnd the maximum number of bananas that can be eaten by monkeys.
	
Input:
    Two lines.
    The first line contains an array of size n contain chars 'B'
	(represent Banana) or 'M' (represent Monkey). n >= 0. The second
	line contains a integer K, K >= 0.

Output:
    An integer, the maximum number of bananas can be eaten by monkeys. 
*/

#include <stdio.h>

char line[200001];
bool visited[200001];
int k, n;

int main()
{
	n = 0;
	scanf("%s", line);
	scanf("%d", &k);
	for (int i=0; line[i]=='B' || line[i]=='M'; i++) {
		if (line[i]=='M' && !visited[i]) {
			for (int j=i+1; j<=(i+k); j++) {
				if (line[j]!='B' && line[j]!='M') {
					break;
				}
				if (line[j]=='B' && !visited[j]) {
					visited[i] = true;
					visited[j] = true;
					n++;
					break;
				}
			}
		}

		if (line[i]=='B' && !visited[i]) {
			for (int j=i+1; j<=(i+k); j++){
				if (line[j]!='B' && line[j]!='M') {
					break;
				}
				if (line[j]=='M' && !visited[j]) {
					visited[i] = true;
					visited[j] = true;
					n++;
					break;
				}
			}
		}
	}
	
	printf("%d", n);
	return 0;
}