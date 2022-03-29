#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

string tournamentWinner(vector<vector<string>> competitions, vector<int> results) {
	string currentBestTeam  = "";
	unordered_map<string,int> scores = {{currentBestTeam,0}};

	// loop through competitions
	string winningTeam;
	for(int idx=0;idx<competitions.size();idx++){
		int result = results[idx];
		if(result==1)
			winningTeam = competitions[idx][0];
		else
			winningTeam = competitions[idx][1];

		if(scores.find(winningTeam)==scores.end())
			scores[winningTeam]=0;

		scores[winningTeam]+=3;
		if(scores[winningTeam]>scores[currentBestTeam])
			currentBestTeam=winningTeam;
	}

	return currentBestTeam;
}


int main(){
	vector<vector<string>> competitions = {
		{"HTML","C#"},
		{"C#","Python"},
		{"Python","HTML"}
	};
	vector<int> results = {0,0,1};

	string result = tournamentWinner(competitions,results);
	cout<<result<<endl;
	

	return 0;
}
