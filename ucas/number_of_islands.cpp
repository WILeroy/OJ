/*
Problem description:
    Given a 2d m*n grid map of '1's (land) and '0's (water), count
	the number of islands. An island is surrounded by water and is
	formed by connecting adjacent lands horizontally or vertically.
	You may assume all four edges of the grid are all surrounded by
	water. (1≤m≤1000, 1≤n≤1000).

Input:
    Line 1: m and n.
    Line 2: '1' or '0' in grid and split by spaces.

Output:
    Line 1: number of islands.
*/

#include <stdio.h>
#include <queue>

using namespace std;

int m, n;
bool map[1002][1002];
bool v[1002][1002];

queue<short> xq;
queue<short> yq;

void search(short x, short y)
{
	xq.push(x);
	yq.push(y);
	v[x][y] = true;	
	
	while (xq.size()) {
		x = xq.front();
		y = yq.front();
		xq.pop();
		yq.pop();
		
		if (map[x-1][y]) {
			if (!v[x-1][y]) {
				xq.push(x-1);
				yq.push(y);
				v[x-1][y] = true;
			}
		}
		if (map[x+1][y]) {
			if (!v[x+1][y]) {
				xq.push(x+1);
				yq.push(y);
				v[x+1][y] = true;				
			}
		}
		if (map[x][y-1]) {
			if (!v[x][y-1]) {
				xq.push(x);
				yq.push(y-1);
				v[x][y-1] = true;
			}
		}
		if (map[x][y+1]) {
			if (!v[x][y+1]) {
				xq.push(x);
				yq.push(y+1);
				v[x][y+1] = true;
			}
		}
	}
}

int main()
{
    int t;
	scanf("%d%d", &m, &n);

	for (int i=1; i<=m; i++) {
		for (int j=1; j<=n; j++) {
			scanf("%d", &t);
            if (t) map[i][j] = true;
		}
	}
	
	int num = 0;
	for (int i=1; i<=m; i++) {
		for (int j=1; j<=n; j++) {
			if (v[i][j]) continue;
			if (map[i][j]) {
				search(i, j);
				num++;
			}
		}
	}
	
	printf("%d", num);
	return 0;
}
