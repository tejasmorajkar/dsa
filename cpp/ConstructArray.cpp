#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

void print_array(vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

vector<int> get_factors(int n)
{
    vector<int> factors;
    factors.push_back(1);
    int root_n = sqrt(n);

    for (int i = 2; i <= root_n; i++)
    {
        if (n % i == 0)
        {
            factors.push_back(i);
            if (i != n / i)
            {
                factors.push_back(n / i);
            }
        }
    }

    factors.push_back(n);
    return factors;
}

vector<int> solve(const int A, const int B, const int C)
{
    vector<int> result;

    if (A == 2)
    {
        result.push_back(B);
        result.push_back(C);
        return result;
    }

    int max_diff = C - B;
    vector<int> factors = get_factors(max_diff);
    sort(factors.begin(), factors.end());

    int min_first_element = INT32_MAX;
    int min_last_element = INT32_MAX;

    for (int factor : factors)
    {
        int total_elements = (max_diff / factor) + 1;
        if (total_elements <= A)
        {
            vector<int> possible_result;
            possible_result.push_back(B);
            int diff = factor;
            int next_element = B + diff;

            while (next_element <= C)
            {
                possible_result.push_back(next_element);
                next_element += diff;
            }

            if (possible_result.size() == A)
            {
                return possible_result;
            }
            else
            {
                // Check if we can add elements at start of result
                int prev_element = B - diff;
                if (prev_element >= 1)
                {
                    while (possible_result.size() != A)
                    {
                        possible_result.insert(possible_result.begin(), prev_element);
                        prev_element -= diff;
                        if (prev_element < 1)
                        {
                            break;
                        }
                    }
                }

                // if size still not equal lets add elements at end
                if (possible_result.size() != A)
                {
                    next_element = possible_result[possible_result.size() - 1] + diff;
                    while (possible_result.size() != A)
                    {
                        possible_result.push_back(next_element);
                        next_element += diff;
                    }
                }
            }

            if (possible_result.size() == A)
            {
                if (possible_result[A - 1] <= min_last_element &&
                    possible_result[0] <= min_first_element)
                {
                    result = possible_result;
                    min_first_element = possible_result[0];
                    min_last_element = possible_result[A - 1];
                }
            }
        }
    }
    return result;
}

vector<int> solve2(const int A, const int B, const int C) {
    vector<int> ans(A, INT_MAX);
    
    for (int a = 1; a <= 50; a++)
    {
        for (int d = 1; d <= 50; d++){
            vector<int> temp(A);
            for (int i = 0; i < A;i++){
                temp[i] = a + i * d;
            }

            bool fB = false;
            bool fC = false;
            for (int i = 0; i < A;i++){
                if(temp[i] == B)
                    fB = true;
                else if (temp[i] == C)
                    fC = true;
            }

            if(fB == true && fC == true && temp[A - 1] < ans[A - 1]){
                for (int i = 0; i < A;i++){
                    ans[i] = temp[i];
                }
            }
        }
    }
    return ans;
}

int main()
{
    int A = 7, B = 39, C = 41;
    vector<int> result = solve2(A, B, C);
    print_array(result);
    return 0;
}