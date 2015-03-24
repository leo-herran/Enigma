#include "Rotor.h"
#include "Machine.h"
#include<iostream>
#include<sstream>
#include<vector>

using namespace std;

vector<string> getInputWords() {
    cout << "What would you like to encode?" << "\n";
    string leo;
    getline(cin, leo);
    string buf;
    stringstream leostream(leo);
    
    vector<string> words;
    
    while(leostream >> buf) {
        words.push_back(buf);
    }
    
    return words;
}

vector<string> trimAndEncode(vector<string> sentence, Machine m) {
    vector<string> result;
    for(vector<string>::const_iterator i = sentence.begin(); i != sentence.end(); i++) {
        string word = *i;
        char lastChar = word.at(word.size() - 1);
        if(lastChar == '.' || lastChar == ',') {
            word = word.substr(0, word.size() - 1);
        } 
        result.push_back(m.getEncodedString(word));
    }
    return result;
}

vector<string> trimAndDecode(vector<string> sentence, Machine m) {
    vector<string> result;
    for(vector<string>::const_iterator i = sentence.begin(); i != sentence.end(); i++) {
        string word = *i;
        char lastChar = word.at(word.size() - 1);
        if(lastChar == '.' || lastChar == ',') {
            word = word.substr(0, word.size() - 1);
        } 
        result.push_back(m.getDecodedString(word));
    }
    return result;
}

void printSentence(vector<string> sentence) {
    for(vector<string>::const_iterator i = sentence.begin(); i != sentence.end(); i++) {
        cout << *i << " ";
    
    }
    cout << "\n";
}

int main() {
    
    //can't handle capital letters yet. Also removes commas and periods. 
    Machine m;
    vector<string> sentence = getInputWords();
    printSentence(sentence);
    vector<string> code = trimAndEncode(sentence, m);
    printSentence(code);
    vector<string> words = trimAndDecode(code, m);
    printSentence(words);
    
}


 


