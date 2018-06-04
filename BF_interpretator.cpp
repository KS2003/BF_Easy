#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
using namespace std;

vector<int> a(30000, 0);
int it = 0;

void bf(string s){
	for(int i = 0; i<s.size(); i++){
		if(s[i]=='+')
			a[it]++;
		if(s[i]=='-')
			a[it]--;
		if(s[i]=='>')
			it++;
		if(s[i]=='<')
			it--;
		if(s[i]=='.')
			cout << a[it];
		if(s[i]==',')
			cin >> a[it];
		if(s[i]=='['){
			string s1 = "";
			int c = 1;
			for(i = i+1; i<s.size(); i++){
				if(s[i]=='[')
					c++;
				if(s[i]==']')
					c--;
				if(c==0)
					break;
				s1 = s1+s[i];
			}
			while(a[it]){
				bf(s1);
			}
		}
	}
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    bf(s);

    return 0;
}