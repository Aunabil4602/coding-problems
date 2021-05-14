#include <bits/stdc++.h>
#define LL long long
#define N 100005
#define MOD 1000000007
#define PP pair<int, int>

using namespace std;

string s;
int n, p;
pair<int, int> degXor[N];
set<pair<int, int>> degPos;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> degXor[i].first >> degXor[i].second;

        degPos.insert(make_pair(degXor[i].first, i));
    }

    vector<pair<int, int>> edges;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> p = *(degPos.begin());
        degPos.erase(degPos.begin());

        int curNode = p.second;

        if (degXor[curNode].first > 0)
        {
            degXor[curNode].first--;

            int adjNode = degXor[curNode].second;
            degPos.erase(make_pair(degXor[adjNode].first, adjNode));
            degXor[adjNode].first--;
            degPos.insert(make_pair(degXor[adjNode].first, adjNode));

            degXor[adjNode].second ^= curNode;

            edges.push_back(make_pair(curNode, adjNode));
        }
    }

    cout << edges.size() << "\n";
    for (auto edge : edges)
    {
        cout << edge.first << " " << edge.second << "\n";
    }
}
