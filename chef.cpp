#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
queue<int> q;
int visited[100010];
int d[100010];
queue<int> v[10];
 
int main()
{
	ios_base::sync_with_stdio(0);
	string str;
	cin >> str;
	int len = str.size();
 
	for(int i=0;i<len;i++){
		int n = str[i]-48;
		v[n].push(i);
	}
 
	memset(visited,0,sizeof(visited));
 
	d[0] = 0;
	visited[0] = 1;
	q.push(0);
 
	while(!q.empty()){
 
		int first = q.front();
		if(first == len-1)
			break;
		q.pop();
		int num = str[first]-48;
 
		if(first-1 >=0 && visited[first-1]==0){
			visited[first-1] = 1;
			q.push(first-1);
			d[first-1] = d[first] + 1;
		}
 
		if(first+1<len && visited[first+1]==0){
			visited[first+1] = 1;
			q.push(first+1);
			d[first+1] = d[first]+1;
		}
 
 		while(!v[num].empty()){
			int num1 = v[num].front();
 			v[num].pop();
 
			if(visited[num1]==0){
				visited[num1] = 1;
				q.push(num1);
				d[num1] = d[first]+1;
			}
		}
	}
	cout << d[len-1] << endl;
	return 0;
} 
