#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Using pairs with arrival time and marker to denote arrival and departure
bool solve(vector<int> &arrive, vector<int> &depart, int K) {
    vector<pair<int,int>> log;
    int n = arrive.size();
    for (int i=0; i<n; i++)
    {
        log.push_back(make_pair(arrive[i], 1));
        log.push_back(make_pair(depart[i], 0));
    }
    sort(log.begin(), log.end());
    int active_count = 0, max_active = 0;
    for (int i=0; i<n; i++)
    {
        if (log[i].second==1)
        {
            active_count++;
            max_active = max(max_active, active_count);
        }
        else
            active_count--;
    }
    return max_active <= K;
}

// Checking 
bool is_hotel_booking_possible(vector<int> &arrive, vector<int> &depart, int K) {
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());
    int N=arrive.size();
    for (int i=0; i<N; i++)
    {
        if ((i+K)<N && arrive[i+K]<=depart[i])
            return false;
    }
    return true;
}

int main()
{
    vector<int> arrive {1, 2, 2, 3};
    vector<int> depart {2, 6, 4, 5};
    int K = 1;
    bool result = solve(arrive, depart, K);
    cout << result << endl;
    return 0;
}