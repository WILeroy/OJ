/* 
    问题描述 : 
        Ackermann函数A(m,n)定义如下：
	    A(m,n) = {
                        n+1,                m=0;
                        A(m-1, 1)           m>0, n=0;
                        A(m-1, A(m, n-1))   m>0, n>0;
                     } 
        设计并完成A(m, n)的算法实现。 
*/ 

#include <iostream>

/* 
   递归方法实现 
*/
int A_Recursive(int m, int n)
{
	if (m == 0)
	{
		return (n+1);
	}
	
	if (n == 0)
	{
		return A_Recursive(m-1, 1);
	}
	
	if (m>0 && n>0)
	{
		int temp = A_Recursive(m, n-1);
		return A_Recursive(m-1, temp);
	}	
}

/*
   动态规划方法-备忘录方法实现 
*/ 
int Memo[5][100000] = {0};
int A_Memo(int m, int n)
{
	if (Memo[m][n] != 0)
	{
		return Memo[m][n];
	}
	
	if (m == 0)
	{
		Memo[m][n] = n+1;
		return Memo[m][n];
	}
	
	if (n == 0)
	{
		Memo[m][n] = A_Memo(m-1, 1);
		return Memo[m][n];
	}
	else
	{
		Memo[m][n] = A_Memo(m-1, A_Memo(m, n-1));
		return Memo[m][n];
	}
}

/*
   动态规划方法-实现 
*/ 
int val[6];
int ind[6];

int A_Dynamic(int m, int n)
{
	if (m == 0)
	{
		return n+1;
	}	
	for (int i=0; i<=m; i++)
	{
		val[i] = -1;
		ind[i] = -2;
	}
	val[0] = 1;
	ind[0] = 0;
	while (ind[m] < n)
	{
		val[0]++;
		ind[0]++;
		for (int i=0; i<m; i++)
		{
			if (ind[i]==1 && ind[i+1]<0)
			{
				val[i+1] = val[0];
				ind[i+1] = 0;
			}
			if (val[i+1] == ind[i])
			{
				val[i+1] = val[0];
				ind[i+1]++;
			}
		}
	}
	return val[m];
}

#include <ctime>
int main(int argc, char** argv) 
{
	clock_t start, finish;
	double total_time;
	
	/* 简单递归方法 */	
	start = clock();
	std::cout << A_Recursive(3, 11);
	finish = clock();
	total_time = (double)(finish-start) / CLOCKS_PER_SEC;
	std::cout << " --- " << total_time << "s" << std::endl;
	
	/* 备忘录方法 */ 
	start = clock();
	std::cout << A_Memo(3, 11);
	finish = clock();
	total_time = (double)(finish-start) / CLOCKS_PER_SEC;
	std::cout << " --- " << total_time << "s" << std::endl;
	
	/* 动态规划方法 */ 
	start = clock();
	std::cout << A_Dynamic(3, 11);
	finish = clock();
	total_time = (double)(finish-start) / CLOCKS_PER_SEC;
	std::cout << " --- " << total_time << "s" << std::endl;
	
	return 0;
}
