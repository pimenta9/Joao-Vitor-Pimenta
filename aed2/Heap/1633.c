#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int n, t, c;
    
    while (scanf("%d", &n) != EOF)
    {
        unsigned long long int nextFreeTime = 0, sum = 0;

        priority_queue < pair <int, int> > pq1;

        while (n--)
        {
            cin >> t;
            cin >> c;
            pq1.push (make_pair(-t, -c));
        }

        priority_queue < pair <int, int> > pq2;

        nextFreeTime += (-pq1.top().first) + (-pq1.top().second);
        pq1.pop();

        while (!pq1.empty() || !pq2.empty())
        {
            while (!pq1.empty() && -pq1.top().first<=nextFreeTime)
            {
                pq2.push (make_pair(pq1.top().second, pq1.top().first));
                pq1.pop();
            }
            if (pq2.empty())
            {
                nextFreeTime = (-pq1.top().first) + (-pq1.top().second);
                pq1.pop();
            }
            else
            {
                sum += nextFreeTime - (-pq2.top().second);
                nextFreeTime += (-pq2.top().first);
                pq2.pop();
            }
        }
        cout << sum << endl;
    }

    return 0;
}
