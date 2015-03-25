#include "Rotor.h"
#include "Machine.h"
#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

bool promptEncodeOrDecode() {
    cout << "Encode or decode (e/d)?" << "\n";
    string answer;
    getline(cin,answer);
    if(answer == "e") {
        return true;
    } 
    return false;
}
vector<string> getInputWords() {
    cout << "What would you like to enter into the machine?" << "\n";
   
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

string convertToLowerCase(string word) {
    string result;
    for(string::iterator i = word.begin(); i != word.end(); i++) {
        char c = *i;
        if(c <= 'Z' && c >= 'A') {
            c = c - ('Z' - 'z');
            //result.append(&c);
            result += c;
        } else if(c < 'a' || c > 'z'){
            return "~"; //bad character, return tilde
        } else {
            result += c;
        }  
    }
    return result;
}

vector<string> trimAndTransform(vector<string> sentence, Machine m, bool encode) {
    vector<string> result;
    for(vector<string>::const_iterator i = sentence.begin(); i != sentence.end(); i++) {
        string word = *i;
        char punc = '~';
        char lastChar = word.at(word.size() - 1);
        if(lastChar == '.' || lastChar == ',') {
            word = word.substr(0, word.size() - 1);
            lastChar == '.' ? punc = '.' : punc = ',';
        } 
        
        word = convertToLowerCase(word);
        if(word == "~") {
            result.push_back("~"); //bad character in input
            return result; 
        }
        
        string transformedWord;
        if(encode) {
            transformedWord = m.getEncodedString(word);
        } else {
            transformedWord = m.getDecodedString(word);
        }
        if(punc != '~') {
            transformedWord += punc;
        }
        result.push_back(transformedWord);
    }
    return result;
}

void printSentence(vector<string> sentence) {
    for(vector<string>::const_iterator i = sentence.begin(); i != sentence.end(); i++) {
        cout << *i << " ";
    }
    cout << "\n";
}

void runInputOutput(Machine m) {
    bool encode = promptEncodeOrDecode();
    vector<string> sentence = getInputWords();
   
    vector<string> transformedSentence = trimAndTransform(sentence, m, encode);
    while(transformedSentence.back() == "~") {
        cout << "Only letters, please." << "\n";
        sentence = getInputWords();
        transformedSentence = trimAndTransform(sentence, m, encode);
    }
    printSentence(transformedSentence);
}
int main() {
  
    Machine m;
    string answer = "y";
    while(answer == "y") {
        runInputOutput(m);
        cout << "Use machine again? (y/n)" << '\n';
        getline(cin,answer); 
    }
    cout << "later" << "\n";
}


 


