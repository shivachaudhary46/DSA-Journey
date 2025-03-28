#include<iostream>
using namespace std;
class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    /*insertion to the dictionary */
    void recursiveWord(TrieNode* root, string word){

        //base case
        if(word.length() == 0){
            root->isTerminal =  true;
            return;
        }
    
        TrieNode* child;
        int index = word[0] - 'A';
        //if present 
        if(root->children[index] != NULL){
            child = root->children[index];
        }
    
        //if absent 
        else{
            child = new TrieNode(word[index]);
            root->children[index] = child;
        }
    
        //recursion calls 
        recursiveWord  (root, word.substr(1));
    }

    void insertWord(string word){
        recursiveWord(root, word);
    }

    /*searching in the dictionary*/
    bool utilSearch(TrieNode* root, string word){

        //base case 
        if(word.length() == 0){
            return root->isTerminal;
        }

        int index = word[0] - 'A';

        TrieNode* child;
        //if character is present 
        if(root -> children[index] != NULL){
            child = root->children[index];
        }else{
            return false;
        }

        //make recursive falls
        return utilSearch(root, word.substr(1));
    
    }

    bool searchWord(string word){
        return utilSearch(root, word);
    }

    void printSuggestions(trieNode* curr, vector<string> temp, string path){

        if(curr -> isterminal){
            temp.push_back(path);
            return;
        }

        for(char ch='A'; ch<='Z'; ch++){
            TrieNode* next = curr->children[ch-'A'];
            printSuggestions(next, temp, path);
            path.pop_back();
        }
    }

    void phoneDirectory(trieNode* root, string str){
        TrieNode* prev = root;
        vector<vector<string> > output;
        string path = "";

        for(int i=0; i<str.length(); i++){
            char lastCh = str[i];
            path.push_back(lastCh);

            TrieNode* curr = prev->children[lastCh-'A'];
            vector<string> temp;
            printSuggestions(curr, temp, path);

            if(curr == NULL){
                break;
            }

            output.push_back(temp);
            temp.clear();
        }


    } 
};
int main(){
    Trie t;
    t.insertWord("ARMED");
    t.insertWord("DUCK");
    t.insertWord("DO");
    t.insertWord("DAMP");
    t.insertWord("DAM");

    if(t.searchWord("ARM")){
        cout<<"character is present"<<endl;
    }else{
        cout<<"character is absent"<<endl;
    }

    cout<<"character word DAMP "<<t.searchWord("DAMP")<<endl;

}