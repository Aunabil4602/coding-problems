#include <bits/stdc++.h>
#define LL long long

using namespace std;

int arr[100005];
int n;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int i = -1, j = n;
    int suml = 0, sumr = 0;
    int cntl = 0, cntr = 0;
    while ((j - i) > 1)
    {
        if (suml == sumr)
        {
            i++;
            j--;
            suml += arr[i];
            sumr += arr[j];
            cntl++;
            cntr++;

            if (i == j)
            {
                cntr--;
                sumr -= arr[j];
                j++;
            }
        }
        else if (suml > sumr)
        {
            j--;
            sumr += arr[j];
            cntr++;
        }
        else
        {
            i++;
            suml += arr[i];
            cntl++;
        }
    }
    cout << cntl << " " << cntr << endl;
}
