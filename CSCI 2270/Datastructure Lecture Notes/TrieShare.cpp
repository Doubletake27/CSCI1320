// code adapted from https://www.geeksforgeeks.org/trie-insert-and-search/

#include <iostream>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode{
	TrieNode *children[ALPHABET_SIZE];

	bool isEndOfWord;
};

TrieNode *makeNode(){
	// allocate space for a new node
		TrieNode *newNode = new TrieNode;
		newNode-> isEndOfWord = false;
		// init all children to NULL
		for(int i = 0; i <ALPHABET_SIZE;i++){
			newNode -> children[i] = nullptr;
		}
		return newNode;
}

void insert(TrieNode *root,string key){
	TrieNode *newCrawl = root;
	for(int i = 0; i< key.length();i++){
		//Shift the index so it starts at 0
		int index = key[i] - 'a';

		// check if null pointer has been reached
		// if so, add a new node
		if(!newCrawl->children[index]){
			newCrawl->children[index] = makeNode();
		}

		newCrawl = newCrawl->children[index];
	}

	newCrawl-> isEndOfWord = true;
}

// search return bool true if key exists in structure
bool search(TrieNode *root, string key){
	TrieNode *newCrawl = root;
	for(int i = 0; i< key.length(); i++){
		int index = key[i] - 'a';
		if(!newCrawl->children[index]){
				return false;
		}
		newCrawl = newCrawl->children[index];
	}
	// NewCrawl != Null therefore the last chaacter exists
	// NewCrawl -> isEnd of WOrd = the last character is end of word;
	return(newCrawl !=NULL && newCrawl -> isEndOfWord);
}

int main(){

	// Test keys. Using only ASCII characters a through z
	string keys[] = {"the","a","there","answer","any","by","bye","their"};
	int n = 8;

	TrieNode * root = makeNode();
	// The first node gets created here
	// TrieNode *root = makeNode();

	for(int i = 0; i<n; i++)
		insert(root,keys[i]);
	// //
	string searchString;

	while(searchString!="exit"){
		cout << "Input a search string to see if it's in the dictonary: ";
		cin >> searchString;
		cout << "\"" << searchString;
		bool inDictonary =  search(root,searchString);
		if(inDictonary)
			cout << "\" found in dictionary" << endl;
		else
			cout << " not found in dictionary" << endl;
	}

	return 0;
}
