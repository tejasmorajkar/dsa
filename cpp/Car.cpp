#include <bits/stdc++.h>
using namespace std;
class car
{
	int speed;
public : int* getSpeed()
	{
		return &speed;
	}
};

int main()
{
	car c;
	int *ptr = c.getSpeed();
	cout << ptr << endl;
	return 0;
}