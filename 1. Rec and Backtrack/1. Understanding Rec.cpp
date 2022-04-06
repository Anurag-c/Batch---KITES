#include<bits/stdc++.h>
using namespace std;

// 5 => 5 4 3 2 1
void printDec(int n)
{
	if(n == 0) return;

	cout<<n<<" ";
	printDec(n - 1);
}

// 5 => 1 2 3 4 5
void printInc(int n)
{
	if(n == 0) return;

	printInc(n - 1);
	cout<<n<<" ";
}

void printInc2(int start, int end)
{
	if(start > end) return;

	cout<<start<<" ";
	printInc2(start + 1, end);
}

// 3 => 3 2 1 1 2 3
// 5 => 5 4 3 2 1 1 2 3 4 5
void printDecInc(int n)
{
	printDec(n);
	printInc(n);
}

void printDecInc2(int n)
{
	if(n == 0) return;

	cout<<n<<" ";
	printDecInc2(n - 1);
	cout<<n<<" ";
}

// n = 3
void printZigZag(int n)
{
	if(n == 0) return;

	cout<<n<<" pre\n";
	printZigZag(n - 1);
	cout<<n<<" In\n";
	printZigZag(n - 1);
	cout<<n<<" post\n";
}

int power(int a, int b)
{
	if(b == 0) return 1;
	return a * power(a, b - 1);
}

int powerOptimal(int a, int b)
{
	if(b == 1) return a;

	int halfPow = powerOptimal(a, b / 2);
	int ans = halfPow * halfPow;

	return (b % 2) ? ans * a : ans;
}

// 4, A, B, C
int toh(int disks, char src, char help, char dest)
{
	if(disks == 0) return 0;

	int moves = 0;
	
	moves += toh(disks - 1, src, dest, help); // 3, A, C, B
	
	moves++;
	cout<<"Move "<<src<<" to "<<dest<<"\n"; // last disk from A to C
	
	moves += toh(disks - 1, help, src, dest); // 3, B, A, C

	return moves;
}

void toh2(int disks, char src, char help, char dest, int& moves)
{
	if(disks == 0) return;

	toh2(disks - 1, src, dest, help, moves); // 3, A, C, B
	
	moves++;
	cout<<"Move "<<src<<" to "<<dest<<"\n"; // last disk from A to C
	
	toh2(disks - 1, help, src, dest, moves); // 3, B, A, C
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	printInc(5);
	cout<<"\n";

	printDec(5);
	cout<<"\n";
	
	printDecInc(3);
	cout<<"\n";

	printZigZag(3);

	cout<<power(4, 12)<<"\n";
	cout<<powerOptimal(4, 12)<<"\n";

	cout<<toh(3, 'A', 'B', 'C')<<"\n";
	
	int moves = 0;
	toh2(3, 'A', 'B', 'C', moves);
	cout<<moves;
}