//C++ program using structure to record the player's data and find out average and print out names of players having average more than 50.
#include<iostream>
using namespace std;
struct players
{
 char name[20];
 int runs;
 int innings;
 int notout;
};
int main()
{
	players p[30];
	float avg;
	cout<<"\t\t\t PLAYERS RECORD\n";
	cout<<"how many records do you want to enter?\n";
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"enter name,no of runs scored,no of innings,not out";
		cin>>p[i].name>>p[i].runs>>p[i].innings>>p[i].notout;
	}
	cout<<"players who have average more than 50 are----\n";
	for(int i=0;i<n;i++)
	{
		avg =p[i].runs/p[i].innings - p[i].notout;
		if (avg>50)
		{
			cout<<p[i].name<<endl;
		}
	}
	return 0;
}