#include<bits/stdc++.h>
using namespace std;

int printPaths(int r, int c, int n, int m, string currPath)
{	
	if(r == n - 1 && c == m - 1)
	{
		cout<<currPath<<"\n";
		return 1;
	}

	int cnt = 0;
	if(c + 1 < m)
		cnt += printPaths(r, c + 1, n, m, currPath + 'R');

	if(r + 1 < n)
		cnt += printPaths(r + 1, c, n, m, currPath + 'D');

	if(r + 1 < n && c + 1 < m)
		cnt += printPaths(r + 1, c + 1, n, m, currPath + 'A');

	return cnt;
}

int printPathsWithJumps(int r, int c, int n, int m, string currPath)
{	
	if(r == n - 1 && c == m - 1)
	{
		cout<<currPath<<"\n";
		return 1;
	}

	int cnt = 0;
	
	for(int jump = 1; c + jump < m; jump++)
		cnt += printPathsWithJumps(r, c + jump, n, m, currPath + "R" + to_string(jump));

	for(int jump = 1; r + jump < n; jump++)
		cnt += printPathsWithJumps(r + jump, c, n, m, currPath + "D" + to_string(jump));

	for(int jump = 1; r + jump < n && c + jump < m; jump++)
		cnt += printPathsWithJumps(r + jump, c + jump, n, m, currPath + "A" + to_string(jump));

	return cnt;
}


bool isSafe(int nrow, int ncol, vector<vector<bool>>& vis)
{
	int n = vis.size();
	int m = vis[0].size();

	return ((nrow < n) && (nrow >= 0) && (ncol >= 0) && (ncol < m) && (vis[nrow][ncol] == false));
}

vector<vector<int>>dirs = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
vector<char>mapping = {'U', 'E', 'R', 'S', 'D', 'W', 'L', 'N'};
int floodFill(int r, int c, int n, int m, vector<vector<bool>>& vis, string currPath)
{	
	if(r == n - 1 && c == m - 1)
	{
		cout<<currPath<<"\n";
		return 1;
	}

	int cnt = 0;
	// direct 8 calls U,E,R,S,D,W,L,N => WILL NOT WORK
	
	vis[r][c] = true; // mark the current cell and make calls
	
	for(int i = 0; i < 8; i++)
	{
		int nr = r + dirs[i][0];
		int nc = c + dirs[i][1];

		if(isSafe(nr, nc, vis))
			cnt += floodFill(nr, nc, n, m, vis, currPath + mapping[i]);
	}

	vis[r][c] = false; //unmark the current cell and backtrack

	return cnt;
}

bool isSafe4(int nrow, int ncol, vector<vector<int>>& matrix)
{
	int n = matrix.size();
	int m = matrix[0].size();

	return ((nrow < n) && (nrow >= 0) && (ncol >= 0) && (ncol < m) && (matrix[nrow][ncol] == 0));
}

vector<char>mapping4 = {'U', 'R', 'D','L'};
vector<vector<int>>dirs4 = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int withObstacle(int r, int c, int n, int m, vector<vector<int>>& matrix, string currPath)
{	
	if(r == n - 1 && c == m - 1)
	{
		cout<<currPath<<"\n";
		return 1;
	}

	int cnt = 0;
	matrix[r][c] = -1;
	
	for(int i = 0; i < 4; i++)
	{
		int nr = r + dirs4[i][0];
		int nc = c + dirs4[i][1];

		if(isSafe4(nr, nc, matrix))
			cnt += withObstacle(nr, nc, n, m, matrix, currPath + mapping4[i]);
	}

	matrix[r][c] = 0;
	return cnt;
}

void decode(string s, int idx, string currPath)
{
	int n = s.length();

	if(idx == n)
	{
		cout<<currPath<<"\n";
		return;
	}

	if(s[idx] == '0') return;

	int num = s[idx] - '0';
	decode(s, idx + 1, currPath + char(num - 1 + 'A'));
	if(idx + 1 < n)
	{
		num = (s[idx] - '0') * 10 + (s[idx] - '0');
		if(num <= 26)
			decode(s, idx + 2, currPath + char(num - 1 + 'A'));
	}

}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	cout<<printPaths(0, 0, 2, 2, "")<<"\n";
	cout<<printPathsWithJumps(0, 0, 3, 3, "")<<"\n";

	vector<vector<bool>>visited(3, vector<bool>(3, false));
	cout<<floodFill(0, 0, 3, 3, visited, "")<<"\n";

	vector<vector<int>>matrix = { 
								  {0, -1, -1, -1},
  								  {0, 0, -1, 1}, 
         						  {0, 0, -1, -1},
         						  {-1, 0, 0, 0}
         						};

    cout<<withObstacle(0, 0, 4, 4, matrix, "")<<"\n";
	return 0;
}