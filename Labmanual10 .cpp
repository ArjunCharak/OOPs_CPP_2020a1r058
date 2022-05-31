//program to demonstrate relational operator overloading
#include<iostream>
using namespace std;
class sample
{
	private : float a;
	public : sample(float a1)
	{
	  a =a1;
	}
	bool operator > (sample s)
	{
		if(a>s.a)
		return true;
		else
		return false;
	}
};
int main()
{
	sample s1(10),s2(20);
	if(s1>s2)
	cout<<"s1 bigger";
	else
	cout<<"s2 bigger";
	return 0;
}
