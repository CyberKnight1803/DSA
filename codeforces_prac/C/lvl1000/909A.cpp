#include<iostream>
#include<string>
using namespace std;

int main() 
{
	char first[10], last[10];
	cin >> first;
	cin >> last;
	
	string pre1, pre2, temp, result;
	pre1 = "";
	pre1 += first[0];
	pre2 = "";
	pre2 += last[0];
	result = pre1 + pre2;
	
	for (int i = 1; first[i]; i++) 
	{
		pre1 += first[i];
		temp = pre1 + pre2;
	
		if (temp < result)
		{
			result = temp;
		}
	}
	
	cout << result;
}

