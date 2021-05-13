#include <bits/stdc++.h>
#define LL long long
#define N 100005
#define MOD 1000000007
#define PP pair<int, int>

using namespace std;

int n;
PP bombs[N];
vector<string> answers;

bool comparator(const PP &a, const PP &b)
{
    if (abs(a.first) < abs(b.first))
    {
        return true;
    }
    else if (abs(a.first) == abs(b.first))
    {
        return abs(a.second) < abs(b.second);
    }
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> bombs[i].second >> bombs[i].first;
    }

    sort(bombs, bombs + n, comparator);

    for (int i = 0; i < n; i++)
    {
        if (abs(bombs[i].first) > 0)
        {
            string s = "1 " + to_string(abs(bombs[i].first)) + " " + (bombs[i].first > 0 ? "U" : "D");
            answers.push_back(s);
        }
        if (abs(bombs[i].second) > 0)
        {
            string s = "1 " + to_string(abs(bombs[i].second)) + " " + (bombs[i].second > 0 ? "R" : "L");
            answers.push_back(s);
        }
        answers.push_back("2");
        if (abs(bombs[i].second) > 0)
        {
            string s = "1 " + to_string(abs(bombs[i].second)) + " " + (bombs[i].second > 0 ? "L" : "R");
            answers.push_back(s);
        }
        if (abs(bombs[i].first) > 0)
        {
            string s = "1 " + to_string(abs(bombs[i].first)) + " " + (bombs[i].first > 0 ? "D" : "U");
            answers.push_back(s);
        }
        answers.push_back("3");
    }
    cout << answers.size() << endl;
    for(int i=0;i<answers.size();i++){
        cout << answers[i]<<"\n";
    }
}
