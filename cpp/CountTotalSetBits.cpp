#include <iostream>
#include <cmath>

using namespace std;

// DP Solution using TC:O(N) SC:O(N)
int solve(int A)
{
    if (A == 0)
        return 0;
    if (A == 1)
        return 1;
    int count_setbits[A];
    count_setbits[0] = 0;
    count_setbits[1] = 1;
    int count = 1;
    int num;
    for (int i = 2; i <= A; i++)
    {
        if (i % 2 == 0)
            count_setbits[i] = count_setbits[i/2]%1000000007;
        else
            count_setbits[i] = (count_setbits[i/2]%1000000007 + 1)%1000000007;
        count += count_setbits[i]%1000000007;
    }
    return count%1000000007;
}

// Mathematical approach using TC:O(logN)
// x*2^(x-1) + N - (2^x - 1) + solve(N - 2^x)
// x is closest power of A
// x*2^(x-1) => counts of set bits of closest power of 2 minus 1
// N - (2^x - 1)=> for remaining numbers MSB is always set
// solve(N - 2^x) => for bits other thans MSB, repeat same logic
long long int calc_nearest_power(int num)
{
    long long int power = 0;
	while((1 << power) <= num)
		power++;
	return power - 1;
}

long long int power_of_2(int power)
{
    return 1 << power;
}

int count_set_bits(int A)
{
    if (A == 0 || A == 1) 
        return A;
    int x = calc_nearest_power(A);
    long long int first_exp = x * power_of_2(x-1);
    long long int second_exp = A - power_of_2(x) + 1;
    long long int third_exp = A - power_of_2(x);
    long long int ans = first_exp + second_exp + count_set_bits(third_exp);
    return (int)(ans%1000000007);
}

int solve2(int A)
{
    // Ignore 0 as all the bits are unset
    A++;

    // To store the powers of 2
    int powerOf2 = 2;

    // To store the result, it is initialized
    // with n/2 because the count of set
    // least significant bits in the integers
    // from 1 to n is n/2
    int cnt = A / 2;

    // Loop for every bit required to represent n
    while (powerOf2 <= A) {

        // Total count of pairs of 0s and 1s
        int totalPairs = A / powerOf2;

        // totalPairs/2 gives the complete
        // count of the pairs of 1s
        // Multiplying it with the current power
        // of 2 will give the count of
        // 1s in the current bit
        cnt += (totalPairs / 2) * powerOf2;
        cnt%=1000000007;

        // If the count of pairs was odd then
        // add the remaining 1s which could
        // not be groupped together
        cnt += (totalPairs & 1) ? (A % powerOf2) : 0;
        cnt%=1000000007;
        // Next power of 2
        powerOf2 <<= 1;
    }

    // Return the result
    return cnt;
}

int main()
{
    int A = 1000000007;
    int result = count_set_bits(A);
    cout << result << endl;
    return 0;
}