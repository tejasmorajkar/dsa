#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int reverse(int A) {
    bool is_negative = false;
    if (A < 0)
    {
        is_negative = true;
        A = -A;
    }
 
    int prev_rev_num = 0, rev_num = 0;
    while (A != 0)
    {
        // int curr_digit = A % 10;
        
        int curr_digit = A - ((A / 10) * 10); 
 
        rev_num = (rev_num * 10) + curr_digit;

        if ((rev_num - curr_digit) / 10 != prev_rev_num)
        {
            return 0;
        }
 
        prev_rev_num = rev_num;
        A = A / 10;
    }
 
    return (is_negative == true) ? -rev_num : rev_num;
}

int main()
{
    int A = -1146467285;
    int result = reverse(A);
    cout << result << endl;
	return 0;
}