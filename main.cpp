#include <iostream>
#include <vector>

using namespace std;

int A1(int m, int n)
{
	if (m == 0)
	{
		return n+1;
	}
	
	if (n == 0)
	{
		return A1(m-1, 1);
	}
	else
	{
		return A1(m-1, A1(m, n-1));
	}
}

vector< vector<int> > A2_result;

int A2(int m, int n)
{
	/* Init array size to m x n */
	A2_result.resize(m+1);
	for (int i=0; i!=A2_result.size(); i++)
	{
		A2_result[i].resize(n+1);
	}
	
	/* Init array 0 row */
	for (int i=0; i!=A2_result[0].size(); i++)
	{
		A2_result[0][i] = i + 1;
	}
	
	/* calculate other value */
	/*
	for (int i=1; i!=A2_result.size(); i++)
	{
		for (int j=0; j!=A2_result[i].size(); j++)
		{
			if (j == 0)
			{
				A2_result[i][j] = A2_result[i-1][1];
			}
			else
			{
				A2_result[i][j] = A2_result[i-1][A2_result[i][j-1]];
			}
		}
	}
	*/
	return A2_result[m][n];
}

int main(int argc, char** argv) 
{
	//cout << A1(3, 12) << endl;
	
	cout << A2(3, 12) << endl;
	
	return 0;
}
