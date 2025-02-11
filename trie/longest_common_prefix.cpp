#include<iostream>
using namespace std;
class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char data){
        this -> data = data;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};
class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode* root, string word){

        //base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        TrieNode* child;
        int index = word[0] - 'a';

        //if present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        //if absent 
        else{
            child = new TrieNode(word[index]);
            root->children[index] = child;
            root->childCount++;
        }

        //recursive function 
        insertUtil(root, word.substr(1));
    }
    void insertWord(string word){
        insertUtil(root, word);
    }

    void lcp(string word, string &ans){

        for(int i=0; i<word.length(); i++){
            
            char ch = word[i];
            if(root->childCount == 1){
                ans.push_back(ch);

                int index = ch - 'a';
                root = root -> children[index];
            }else{
                break;
            }

            if(root->isTerminal){
                break;
            }
        }
    }
};
string longestCommonPrefix(vector<string> &arr){
    Trie* root = new Trie();
    int n = arr.size();

    for(int i=0; i<n; i++){
        root->insertWord(arr[i]);
    }

    string first = arr[0];
    string ans = " ";

    root->lcp(first, ans);

    return ans;
}
int main(){
    vector<string> arr;
    arr.push_back("shiva");
    arr.push_back("shireecha");
    arr.push_back("shita");
    arr.push_back("shiristhi");

    string ans = longestCommonPrefix(arr);
    cout<<"longest common prefix of given array "<<ans<<endl;
}