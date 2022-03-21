#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> slidingMaximum(const vector<int> &A, int B) {
    vector<int> result;
    deque<int> deque;
    int n = A.size();

    for (int i = 0; i < n; i++)
    {
        while(!deque.empty() && A[deque.back()] <= A[i])
        {
            deque.pop_back();
        }
        deque.push_back(i);
        if (i >= B - 1)
        {
            result.push_back(A[deque.front()]);
        }
        if (deque.front() == (i - B + 1))
        {
            deque.pop_front();
        }
    }
    return result;
}

int main()
{
    vector<int> A {1, 2, 3, 4, 2, 7, 1, 3, 6};
    int B = 6;
    vector<int> result = slidingMaximum(A,B);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
	return 0;
}