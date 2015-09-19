#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string longestCommonPrefix_v1(vector<string>& strs) {
		if (strs.size() == 0)
			return "";
		if (strs.size() == 1)
			return strs[0];

		int M = strs[0].size();
		int len = 0, minLen = INT_MAX;
		int sNum = 0, cNum = 0;
		for (sNum = 0; sNum <= strs.size()-2; sNum++){
			//compare adjacent two string
			len = 0;
			for (cNum = 0; cNum < strs[sNum].size() && cNum < strs[sNum + 1].size(); cNum++){
				if (strs[sNum][cNum] == strs[sNum + 1][cNum])
					len++;
				else
					break;
			}
			//here, easy to mistake. set initial val as INT_MAX
			minLen = min(minLen,len);
		}
		return strs[0].substr(0, minLen);
	}

	//Method 2: compare in parellel.

	//Method 3: Use Trie.
	typedef struct node {
		char ch;
		int branch; //记录分支树，方便最后查询
		int times;
		node* child[26];
	}node, *Trie;

	Trie init_Trie()
	{
		Trie root = (node*)malloc(sizeof(node)); //Trie树的根节点不存储数据
		root->branch = 0;
		root->times = 0;
		for (int i = 0; i<26; i++)
			root->child[i] = NULL;
		return root;
	}

	void insert_Trie(Trie root, const string str)
	{
		int n = str.length();
		if (n == 0)
		{
			root->times++;
			return;
		}
		int i = 0;
		int idx;
		node *p = root;
		root->times++;
		while (i<n)
		{
			idx = str[i] - 'a';
			if (p->child[idx] != NULL)
			{
				p = p->child[idx];
				p->times++;
				i++;
			}
			else
			{
				node* tmp = (node*)malloc(sizeof(node));
				tmp->ch = str[i];
				tmp->branch = 0;
				tmp->times = 1;
				for (int j = 0; j<26; j++)
					tmp->child[j] = NULL;

				p->branch++;
				p->child[idx] = tmp;
				p = tmp;
				i++;
			}
		}
	}

	string longestCommonPrefix(vector<string> &strs)
	{
		int n = strs.size();
		if (n == 0)
			return "";

		int i;
		Trie root = init_Trie();
		for (i = 0; i<n; i++)
			insert_Trie(root, strs[i]);

		i = 0;
		node* p = root;
		while (i<strs[0].length() && p->branch == 1 && p->times == n)
		{
			p = p->child[strs[0][i] - 'a'];
			i++;
		}
		if (p->times < n)
			i--;
		return strs[0].substr(0, i);
	}

};


int main()
{
	vector<string> strs;
	strs.push_back("abc");
	strs.push_back("abcdefghi");
	strs.push_back("abclkfjdlgk");
	strs.push_back("abcooijgf");
	strs.push_back("abcrhkjef");
	strs.push_back("abccc");

	Solution so;
	cout << so.longestCommonPrefix(strs) << endl;
	return 1;
}