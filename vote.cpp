#include <iostream>
#include <stack>
#include <string>

struct candidates {
		string name;
		int votes;
};

bool sorting(candidates a, candidates b) {
	return a.votes<b.votes;
}

int main() {
	candidates candidate[5];
	int candidateCount;
	cin>>candidateCount;
	while(candidateCount > 4 || candidateCount < 2) {
		cin>>candidateCount;
	}
	for (int i = 1; i <= candidateCount; i++)
	{
		getline(cin,candidate[i].name);
		candidate[i].votes=0;
	}

	cout<<"Now VOTE! Current Candidates:"<<endl;
	for (int i = 1; i <= candidateCount; i++)
	{
		cout<<"Number "<<i<<": "<<candidate[i].name<<endl;
	}
	for (int i = 1; i <= 5; i++)
	{
		int voting;
		cout<<"Vote for: ";
		cin>>voting;
		while (voting>candidateCount || voting<1) {
			cout<<"Invalid Vote:";
			cin>>voting;
		}
		candidate[voting].votes++;
	}
	sort(candidate+1,candidate+candidateCount,sorting);
	for (int i = 1; i <= candidateCount; i++)
	{
		cout<<candidate[i].name<<" got "<<candidate[i].votes<<" votes"<<endl;
	}
	if (candidate[1].votes!=candidate[2].votes)
	{
		cout<<"NO OVERALL WINNER"<<endl;
		return 0;
	}
	cout<<"NEW CLASS CAPTAIN: "<<candidate[1].name<<"!!!!"<<endl;
	return 0;
}
