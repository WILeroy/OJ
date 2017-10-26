#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k = 0;
int n[101] = {0};

vector<int> a;
vector<int> b;

void fun(int _n)
{
    /* 判断是否为非关键数 */
    for (int i=b.size()-1; i!=-1; i--)
    {
        /* 如果为非关键数 */
        if (_n == b[i])
        {
            return;
        }
    }

    /* 如果不为非关键数 */
    /* 判断子数是否为已存在关键数 */
    int n_ = _n;
    a.push_back(n_);

    for (int i=a.size()-2; i!=-1; i--)
    {
        if (n_ == a[i])
        {
            int temp = a[a.size()-1];
            a[a.size()-1] = a[i];
            a[i] = temp;
            a.pop_back();
            return;
        }
    }

    if (_n%2 == 0) n_ = _n / 2;
    else n_ = (3 * _n + 1) / 2;

    while (n_ != 1)
    {
        for (int i=a.size()-2; i!=-1; i--)
        {
            if (n_ == a[i])
            {
                int temp = a[a.size()-1];
                a[a.size()-1] = a[i];
                a[i] = temp;
                a.pop_back();
                return;
            }
        }

        b.push_back(n_);

        if (n_%2 == 0) n_ = n_ / 2;
        else n_ = (3 * n_ + 1) / 2;
    }
}

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    while (cin >> k)
    {
        for (int i=0; i<k; i++)
            cin >> n[i];

        for (int i=0; i<k; i++)
        {
            fun(n[i]);
        }

        sort(a.begin(), a.end(), cmp);

        cout << a[0];
        for (int i=1; i!=a.size(); i++)
            cout << " " << a[i];


        a.clear();
        b.clear();
    }

    return 0;
}

