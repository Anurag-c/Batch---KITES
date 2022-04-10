#include<bits/stdc++.h>
using namespace std;

void display(vector<int>& arr, int idx)
{
	if(idx == arr.size()) return; // array is empty (reached end of array)
	
	cout<<arr[idx]<<" ";
	display(arr, idx + 1);
}

int maxElement(vector<int>& arr, int idx)
{
	// if(idx == arr.size()) return INT_MIN;
	if(idx == arr.size() - 1) return arr[idx]; // only one ele in array (last ele) 

	int smallAns = maxElement(arr, idx + 1);// [0]  small = [1, 2, 3, 4]
	return max(arr[idx], smallAns);
}

int minElement(vector<int>& arr, int idx)
{
	if(idx == arr.size() - 1) return arr[idx]; // only one ele in array (last ele) 

	int smallAns = minElement(arr, idx + 1);// [0]  small = [1, 2, 3, 4]
	return min(arr[idx], smallAns);
}

int find(vector<int>& arr, int ele, int idx)
{
	if(idx == arr.size()) return -1;

	int smallAns = find(arr, ele, idx + 1);
	if(smallAns != -1) return smallAns;

	return (arr[idx] == ele) ? idx : -1;
}

int firstIndex(vector<int>& arr, int ele, int idx)
{
	if(idx == arr.size()) return -1;

	if(arr[idx] == ele) return idx;
	return firstIndex(arr, ele, idx + 1);
}

int lastIndex(vector<int>& arr, int ele, int idx)
{
	if(idx == arr.size()) return -1;

	int smallAns = find(arr, ele, idx + 1);
	if(smallAns != -1) return smallAns;

	return (arr[idx] == ele) ? idx : -1;
}

vector<int> allIndex(vector<int>& arr, int ele, int idx)
{
	if(idx == arr.size()) return {};

	vector<int>smallAns = allIndex(arr, ele, idx + 1);
	if(arr[idx] == ele) smallAns.insert(smallAns.begin(), idx);

	return smallAns;
}


void allIndex2(vector<int>& arr, int ele, int idx, vector<int>& ans)
{
	if(idx == arr.size()) return;

	if(arr[idx] == ele) ans.push_back(idx);
	allIndex2(arr, ele, idx + 1, ans);
}
// ans => [3, 4, 5, 6, 9]

vector<string> getSubsequences(string& s, int idx)
{
	if(idx == s.length()) return {""};

	vector<string> smallAns = getSubsequences(s, idx + 1);
	int n = smallAns.size();
	for(int i = 0; i < n; i++)
	{
		smallAns.push_back(s[idx] + smallAns[i]);
		//smallAns.push_back(smallAns[i].push_front(s[idx]));
	}

	return smallAns;
}

void printSubsequence2N(string& s, int idx, string& currPath)
{
	if(idx == s.length())
	{
		cout<<currPath<<"\n";
		return;
	}

	//1) consider
	currPath.push_back(s[idx]);
	printSubsequence2N(s, idx + 1, currPath);
	currPath.pop_back(); // backtrack

	//2) not consider
	printSubsequence2N(s, idx + 1, currPath);
}

void printSubsequenceNC0(string& s, int idx, string& currPath)
{
	cout<<currPath<<"\n"; // print every level
	if(idx == s.length()) return; 
	// works same without the base case because for loops handles this, 
	// i.e; if idx > n the for loop will not execute hence directly returns.
	
	int n = s.length();
	for(int i = idx; i < n; i++) // Call on each character (Eg : starting with a and then b, ...)
	{
		currPath.push_back(s[i]);
		printSubsequenceNC0(s, i + 1, currPath); // idx + 1 (wrong)
		currPath.pop_back(); // backtrack
	}
}

vector<string> getPermutations(string& s)
{
	if(s.length() == 0) return {""};

	int n = s.length();
	vector<string>ans;
	for(int i = 0; i < n; i++)
	{
		string remaining = s.substr(0, i) + s.substr(i + 1);
		vector<string> smallAns = getPermutations(remaining);
		int m = smallAns.size();

		for(int j = 0; j < m; j++)
			ans.push_back(s[i] + smallAns[j]); // a + bc and a + cb
	}

	return ans;
}

vector<string> getPermutationsStar(string& s)
{
	int n = s.length();
	vector<string>ans;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '*') continue;

		char temp = s[i];
		s[i] = '*';
		vector<string> smallAns = getPermutationsStar(s);
		s[i] = temp;

		int m = smallAns.size();
		for(int j = 0; j < m; j++)
			ans.push_back(s[i] + smallAns[j]); // a + bc and a + cb
	}

	if(ans.size() == 0) return {""};
	return ans;
}

void printPermutations(string& s, string& currPath)
{
	int n = s.length();
	
	if(currPath.length() == n)
	{
		cout<<currPath<<"\n";
		return;
	}
	
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '*') continue;

		currPath.push_back(s[i]);
		char temp = s[i];
		s[i] = '*';
		
		printPermutations(s, currPath);
		
		s[i] = temp;
		currPath.pop_back();
	}
}

vector<vector<string>> getPartitions(string& s, int idx)
{
	if(idx == s.length()) return {{}};

	int n = s.length()
	vector<vector<string>>ans;
	for(int cut = idx; cut < n; cut++) // cut = 0 (wrong)
	{
		if(!isPalindrome(s, idx, cut)) continue;

		vector<vector<string>>smallAns = getPartitions(s, cut + 1) // (idx + 1 wrong)
		int m = smallAns.size();
		for(int i = 0; i < m; i++)
		{
			smallAns[i].insert(smallAns[i].begin(), s.substr(idx, cut - idx + 1));
			ans.push_back(smallAns[i]);
		}
	}

	return ans;
}

// cut strategy
class Solution 
{
    vector<vector<string>>ans;
    
    bool isPalindrome(string& s, int start, int end)
    {
        while(start < end)
        {
            if(s[start] != s[end])
                return false;
            
            start++;
            end--;
        }
        
        return true;
    }
    
    void storePartitions(string& s, int idx, vector<string>& currPath)
    {
        int n = s.length();
        
        if(idx == n)
        {
            ans.push_back(currPath);
            return;
        }
        
        for(int cut = idx; cut < n; cut++)
        {
            if(!isPalindrome(s, idx, cut)) continue;
            
            currPath.push_back(s.substr(idx, cut - idx + 1));
            storePartitions(s, cut + 1, currPath);
            currPath.pop_back();
        }
    }
    
public:
    
    vector<vector<string>> partition(string s) 
    {
        vector<string>currPath;
        storePartitions(s, 0, currPath);
        return ans;
    }
};

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	
	vector<int>arr({1, 2, 3, 5, 5, 5, 6, 7, 5});
	
	//1) display
	display(arr, 0);
	cout<<"\n";

	//2) Max and Min Ele
	cout<<maxElement(arr, 0)<<"\n";
	cout<<minElement(arr, 0)<<"\n";

	//3) firstIndex and LastIndex
	cout<<firstIndex(arr, 5, 0)<<"\n";
	cout<<lastIndex(arr, 5, 0)<<"\n";
	
	//4) AllIndices
	vector<int>allIndices;
	allIndex2(arr, 5, 0, allIndices);
	for(int i : allIndices) cout<<i<<" ";
	cout<<"\n";
	
	allIndices = allIndex(arr, 5, 0);
	for(int i : allIndices) cout<<i<<" ";
	cout<<"\n";
	
	//5) getSubsequences
	string s = "abc";
	vector<string> subs = getSubsequences(s, 0);
	for(string s : subs) cout<<s<<"\n";
	cout<<"\n";

	//6) 2^N method
	string currPath;
	printSubsequence2N(s, 0, currPath);

	//7) Nc0 + Nc1 + ...
	printSubsequenceNC0(s, 0, currPath);
	cout<<"\n";
	
	//8) getPermutations
	vector<string>permut = getPermutations(s);
	for(string s : permut) cout<<s<<"\n";
	cout<<"\n";

	permut = getPermutationsStar(s);
	for(string s : permut) cout<<s<<"\n";
	cout<<"\n";
	
	//9) printPermutations
	printPermutations(s, currPath);
}