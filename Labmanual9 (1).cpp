//demonstration of operator overloading of + operator
#include<iostream>
using namespace std;
class complex
{
	private : float r,i;
	public : complex()
	{

	};
	complex(float r1, float i1)
	{
		r =r1;
		i =i1;
	}
	complex operator + (complex c2)
	{
		complex c;
		c.r = r+c2.r;
		c.i =i+c2.i;
		return c;
	}
	void display()
	{
		cout<<r<<"+r"<<i;
	}
};
int main()
{
	complex c1(10,15) ,c2(15,20) ,c3;
	c3 =c1+c2;
	c3.display();
	return 0;
}