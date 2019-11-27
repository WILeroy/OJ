/*
Problem Description:
    There is a server which has the disk space of M and the memory of
	N. Given some tasks, the i-th task needs the disk space of Xi and
	the memory of Yi, and it can serve Ui users. Design an algorithm
	and implement it to find out the maximum number of users that this
	server can serve simultaneously.

Input:
    The first line of input contains three integers M, N and K, which
	denote the total disk space, the total memory and the number of
	tasks. The next K lines are the disk space need, the memory need
	and the number of users served of tasks. (1≤M, N≤1000, K≤1000, and
	Ui≤100000).

Output:
    Line1: Maximum number of users.
*/

#include <stdio.h>
#include <stdlib.h>

int M, N, K;
int task[3];
int *last_map = (int *)malloc(1001 * 1001 * sizeof(int));
int *map = (int *)malloc(1001 * 1001 * sizeof(int));
int result;

int main()
{	
	scanf("%d%d%d", &M, &N, &K);
	for (int k=0; k<K; k++) {
		scanf("%d%d%d", task, task+1, task+2);
		for (int i=1; i<=M; i++) {
			for (int j=1; j<=N; j++) {
				if (task[0] > i || task[1] > j) {
					map[i*1001+j] = last_map[i*1001+j];
				}
				else {
					if (last_map[i*1001+j] > last_map[(i-task[0])*1001+(j-task[1])] + task[2]) {
						map[i*1001+j] = last_map[i*1001+j];
					} 
					else {
						map[i*1001+j] = last_map[(i-task[0])*1001+(j-task[1])] + task[2];
					}
				}
			}
		}
		
		result = map[M*1001+N];
		int *t = last_map;
		last_map = map;
		map = t; 
	}
	
	printf("%d", result);
	
	return 0;
}
