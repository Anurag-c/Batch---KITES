#include<bits/stdc++.h>
using namespace std;

int coinChangePermutationInfi(vector<int>& arr, int target, vector<int>& path)
{
	if(target == 0)
	{
		for(int num : path) cout<<num<<" ";
		cout<<"\n";
		return 1;
	}

	int n = arr.size();
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		if(target < arr[i]) continue;

		path.push_back(arr[i]);
		cnt += coinChangePermutationInfi(arr, target - arr[i], path);
		path.pop_back();
	}

	return cnt;
}

int coinChangeCombinationInfi1(vector<int>& arr, int target, int idx, vector<int>& path)
{
	if(target == 0)
	{
		for(int num : path) cout<<num<<" ";
		cout<<"\n";
		return 1;
	}

	int n = arr.size();
	int cnt = 0;

	for(int i = idx; i < n; i++)
	{
		if(target < arr[i]) continue;

		path.push_back(arr[i]);
		cnt += coinChangeCombinationInfi1(arr, target - arr[i], i, path);
		path.pop_back();
	}

	return cnt;
}

int coinChangeCombinationInfi2(vector<int>& arr, int target, int idx, vector<int>& path)
{
	if(target == 0)
	{
		for(int num : path) cout<<num<<" ";
		cout<<"\n";
		return 1;
	}

	int n = arr.size();
	if(idx == n) return 0;

	int cnt = 0;
	if(target >= arr[idx])
	{
		path.push_back(arr[idx]);
		cnt += coinChangeCombinationInfi2(arr, target - arr[idx], idx, path);
		path.pop_back();
	}

	cnt += coinChangeCombinationInfi2(arr, target, idx + 1, path);
	return cnt;
}

int coinChangePermutation(vector<int>& arr, int target, vector<int>& visited, vector<int>& currPath)
{
	if(target == 0)
	{
		for(int num : currPath) cout<<num<<" ";
		cout<<"\n";
		return 1;
	}

	int n = arr.size();
	int cnt = 0;

	for(int i = 0; i < n; i++)
	{
		if(target < arr[i]) continue;

		if(visited[i] == false)
		{
			visited[i] = true;
			currPath.push_back(arr[i]);
			
			cnt += coinChangePermutation(arr, target - arr[i], visited, currPath);
			
			visited[i] = false;
			currPath.pop_back();
		}
	}

	return cnt;
}

int coinChangeCombination1(vector<int>& arr, int target, int idx, vector<int>& path)
{
	if(target == 0)
	{
		for(int num : path) cout<<num<<" ";
		cout<<"\n";
		return 1;
	}

	int n = arr.size();
	int cnt = 0;

	for(int i = idx; i < n; i++)
	{
		if(target < arr[i]) continue;

		path.push_back(arr[i]);
		cnt += coinChangeCombination1(arr, target - arr[i], i + 1, path);
		path.pop_back();
	}

	return cnt;
}

int coinChangeCombination2(vector<int>& arr, int target, int idx, vector<int>& path)
{
	if(target == 0)
	{
		for(int num : path) cout<<num<<" ";
		cout<<"\n";
		return 1;
	}

	int n = arr.size();
	if(idx == n) return 0;

	int cnt = 0;
	if(target >= arr[idx])
	{
		path.push_back(arr[idx]);
		cnt += coinChangeCombination2(arr, target - arr[idx], idx + 1, path);
		path.pop_back();
	}

	cnt += coinChangeCombination2(arr, target, idx + 1, path);
	return cnt;
}

int queensPermutation1D(vector<int>& boxes, int queens, int queenNo)
{
	if(queenNo > queens)
	{
		for(int num : boxes) cout<<num<<" ";
		cout<<"\n";
		return 1;
	}

	int cnt = 0;
	int n = boxes.size();
	for(int i = 0; i < n; i++)
	{
		if(boxes[i] == -1)
		{
			boxes[i] = queenNo;
			cnt += queensPermutation1D(boxes, queens, queenNo + 1);
			boxes[i] = -1;
		}
	}

	return cnt;
}

int queensCombination1D(vector<int>& boxes, int idx, int queens, int queenNo)
{
	if(queenNo > queens)
	{
		for(int num : boxes) cout<<num<<" ";
		cout<<"\n";
		return 1;
	}

	if(idx == boxes.size()) return 0;
	int cnt = 0;

	boxes[idx] = queenNo;
	cnt += queensCombination1D(boxes, idx + 1, queens, queenNo + 1);
	boxes[idx] = -1;

	cnt += queensCombination1D(boxes, idx + 1, queens, queenNo);

	return cnt;
}

int queensCombination1DNc0(vector<int>& boxes, int idx, int queens, int queenNo)
{
	if(queenNo > queens)
	{
		for(int num : boxes) cout<<num<<" ";
		cout<<"\n";
		return 1;
	}

	int n = boxes.size();
	int cnt = 0;

	for(int i = idx; i < n; i++)
	{
		boxes[idx] = queenNo;
		cnt += queensCombination1DNc0(boxes, i + 1, queens, queenNo + 1);
		boxes[idx] = -1;
	}

	return cnt;
}

int queensPermutation2D(vector<vector<int>>& grid, int queens, int queenNo)
{
	if(queenNo > queens)
	{
		for(vector<int>& v: grid)
		{
			for(int num : v) cout<<num<<" ";
			cout<<"\n";
		}

		cout<<"\n";
		return 1;
	}

	int rows = grid.size();
	int cols = grid[0].size();
	int boxes = rows * cols;
	int cnt = 0;

	for(int i = 0; i < boxes; i++)
	{
		int r = i / cols;
		int c = i % cols;

		if(grid[r][c] == -1)
		{
			grid[r][c] = queenNo;
			cnt += queensPermutation2D(grid, queens, queenNo + 1);
			grid[r][c] = -1;
		}
	}

	return cnt;
}

int queensCombination2DNc0(vector<vector<int>>& grid, int idx, int queens, int queenNo)
{
	if(queenNo > queens)
	{
		for(vector<int>& v: grid)
		{
			for(int num : v) cout<<num<<" ";
			cout<<"\n";
		}

		cout<<"\n";
		return 1;
	}

	int rows = grid.size();
	int cols = grid[0].size();
	int boxes = rows * cols;
	int cnt = 0;

	for(int i = idx; i < boxes; i++)
	{
		int r = i / cols;
		int c = i % cols;

		grid[r][c] = queenNo;
		cnt += queensCombination2DNc0(grid, i + 1, queens, queenNo + 1);
		grid[r][c] = -1;
	}

	return cnt;
}

vector<vector<int>>dirs = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
bool isSafe(vector<vector<string>>& grid, int r, int c)
{
	int rows = grid.size();
	int cols = grid[0].size();

	for(int i = 0; i < 8; i++)
	{
		for(int rad = 1; rad < max(rows, cols); rad++)
		{
			int nr = r + (rad * dirs[i][0]);
			int nc = c + (rad * dirs[i][1]);
			
			if(nr < 0 || nr >= rows || nc < 0 || nc >= cols) break;

			if(grid[nr][nc] == "Q") return false;
		}
	}

	return true;
}

int nQueen(vector<vector<string>>& grid, int idx, int queens)
{
	if(queens == 0)
	{
		for(vector<string>& v: grid)
		{
			for(string s : v) cout<<s<<" ";
			cout<<"\n";
		}

		cout<<"\n";
		return 1;
	}

	int rows = grid.size();
	int cols = grid[0].size();
	int boxes = rows * cols;
	int cnt = 0;

	for(int i = idx; i < boxes; i++)
	{
		int r = i / cols;
		int c = i % cols;

		if(!isSafe(grid, r, c)) continue;

		grid[r][c] = 'Q';
		cnt += nQueen(grid, i + 1, queens - 1);
		grid[r][c] = '.';
	}

	return cnt;
}

vector<bool>visCol(4, false);
vector<bool>visDiag(7, false);
vector<bool>visAdiag(7, false);

bool isSafe2(vector<string>& grid, int row, int col)
{
	int m = grid[0].size();
	return (!visCol[col]) && (!visDiag[row - col + m - 1]) && (!visAdiag[row + col]); 
}

void toggle(vector<string>& grid, int row, int col)
{
	int m = grid.size();
	visCol[col] = !visCol[col];
	visDiag[row - col + m - 1] = !visDiag[row - col + m - 1];
	visAdiag[row + col] = !visAdiag[row + col];
	if(grid[row][col] == 'Q') grid[row][col] = '.';
	else grid[row][col] = 'Q';
}

int nQueenOpt(vector<string>& grid, int queens, int row)
{
	if(queens == 0)
	{
		for(string s: grid)
		{
			cout<<s;
			cout<<"\n";
		}

		cout<<"\n";
		return 1;
	}

	int cnt = 0;
	int m = grid[0].size();
	for(int col = 0; col < m; col++)
	{
		if(isSafe2(grid, row, col))
		{
			toggle(grid, row, col);
			cnt += nQueenOpt(grid, queens - 1, row + 1);
			toggle(grid, row, col);
		}
	}

	return cnt;
}


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	//vector<int>boxes(6, -1);
	vector<string>grid(4, "....");
	//cout<<queensPermutation1D(boxes, 3, 1)<<"\n";
	// cout<<queensCombination1DNc0(boxes, 0, 3, 1)<<"\n";
	//cout<<queensPermutation2D(grid, 2, 1);

	cout<<nQueenOpt(grid, 4, 0);
}