#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int N = 31 * 6;

struct Box
{
    int h, w, l;
    Box()
    {
        h = w = l = 0;
    }

    Box(int h, int w, int l)
    {
        this->h = h;
        this->w = w;
        this->l = l;
    }
};
int n;
int dp[N];

bool cmp(Box &a, Box &b)
{
    if (a.h > b.h && a.w > b.w)
        return true;
    if (a.h == b.h)
        return a.w > b.w;
    else
        return a.h > b.h;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[3];
    vector<Box> boxList;
    while (cin >> n && n > 0)
    {
        boxList.clear();

        for (int i = 0; i < n; i++)
        {
            cin >> arr[0] >> arr[1] >> arr[2];
            sort(arr, arr + 3);
            do
            {
                boxList.push_back(Box(arr[0], arr[1], arr[2]));
            } while (next_permutation(arr, arr + 3));
        }

        sort(boxList.begin(), boxList.end(), cmp);
        int answer = 0;
        for (int i = 0; i < boxList.size(); i++)
        {
            dp[i] = boxList[i].l;
            answer = max(answer, dp[i]);
            for (int j = 0; j < i; j++)
            {
                if (boxList[i].h < boxList[j].h && boxList[i].w < boxList[j].w)
                    dp[i] = max(dp[i], dp[j] + boxList[i].l);
                answer = max(answer, dp[i]);
            }
        }

        cout << answer << "\n";
    }

    return 0;
}
