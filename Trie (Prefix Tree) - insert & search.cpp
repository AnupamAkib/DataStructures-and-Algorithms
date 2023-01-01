#include <bits/stdc++.h>

using namespace std;
#define print(xz) cout << #xz << " = " << xz << endl;


class TrieNode{ //this is a Trie Node. A trie node contains a map that points all the child of this node. We can use 26 size array also if string only contains a-z or A-Z
public:
	unordered_map<char, TrieNode*> child;
	bool endOfWord; //this variable indicate if this node is the end of a word or not. true = word end, false = word not end
};

class Trie{
private:
	//getTrieNode is responsible for allocating a TrieNode and return it's pointer
	TrieNode* getTrieNode(){
		TrieNode* node = new TrieNode(); 
		node -> endOfWord = false; //as this is just an initial node, so endOfWord flag is set to false
		return node;
	}
	TrieNode* root = nullptr; //for the first time root node contains nullptr (null pointer value)

public:
	void Insert(string str){ //Time Complexity = O(l*m) where l=average length of words and n=number of words
		if(root == nullptr){ //if root is nullptr then allocate a TrieNode on it
			root = getTrieNode(); //It fires only once at first insertion
		}
		TrieNode* temp = root; //we will traverse the tree from root and don't wanna loose the root. So, assign root to 'temp' pointer and use it
		for(auto c : str){ //iterate over all the characters of string that we gonna insert
			if(temp->child.find(c) == temp->child.end()){ //if a character is not found as a child then make a new TrieNode and connect it with current TrieNode's character
				temp -> child[c] = getTrieNode(); //connect the newly created TrieNode with current char
			}
			temp = temp -> child[c]; //traverse the child of current char
		}
		temp -> endOfWord = true; //after the last character mark endOfWord = true in the the next empty TrieNode. So that we can understand a word ended here
		cout << "String '" << str << "' inserted!!" << endl;
	}

	//this function is used for searching if there is at least 1 word that starts with given prefix 'str'
	bool prefixSearch(string str){ //Time Complexity = O(n) where n = length of word to be searched
		TrieNode* temp = root; //get the root
		if(root == nullptr){ //if root is nullptr that means trie is empty right now
			cout << "Trie is Empty!" << endl;
			return false;
		}
		for(auto c : str){ //iterate over all the characters in prefix
			if(temp -> child.find(c) == temp -> child.end()){ //if no child found for a character then there is no such word that starts with given prefix. So, return false
				return false;
			}
			temp = temp -> child[c]; //go to child node of character c
		}
		//if child found for every characters of prefix that means there is at least one word that starts with given prefix
		return true; //return true as prefix found in trie
	}

	//this function is used to search a whole word in the trie. It will say if the full word exist in the trie or not
	bool wordSearch(string str){ //Time Complexity = O(n) where n = length of word to be searched
		TrieNode* temp = root; //get the root
		if(root == nullptr){ //if root is nullptr then trie is empty
			cout << "Trie is Empty!" << endl;
			return false;
		}
		for(auto c : str){ //iterate over all the characters in search key
			if(temp -> child.find(c) == temp -> child.end()){ //if no child found for a character then there is no such word as like the key. So, return false
				return false;
			}
			temp = temp -> child[c]; //go to child node of character c
		}
		if(temp -> endOfWord) return true; //endOfWord is 'true' means there is a word that ends in this position. that means the given word exist in trie. So, return true
		else return false; //otherwise return false as given word not found
	}
};

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	Trie trie; //declare a Trie

	//insert into the Trie
	trie.Insert("abc");
	trie.Insert("abgl");
	trie.Insert("cdf");
	trie.Insert("abcd");
	trie.Insert("lmn");

	//search a word in Trie
	string key = "abc";
	if(trie.wordSearch(key)){
		cout << "'" << key << "' found!" << endl;
	}
	else{
		cout << "'" << key << "' not found!" << endl;
	}

	//search a prefix in Trie
	key = "cd";
	if(trie.prefixSearch(key)){
		cout << "prefix '" << key << "' found!" << endl;
	}
	else{
		cout << "prefix '" << key << "' not found!" << endl;
	}

	return 0;
}
