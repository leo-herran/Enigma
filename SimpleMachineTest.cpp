#include "Rotor.h"
#include "Machine.h"
#include "NewMachine.h"
#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;


bool promptTypeOfMachine() {
    cout << "Use new enigma machine? (y/n)" << "\n";
    string answer;
    getline(cin,answer);
    if(answer.empty()) {
        cout << "I know your keyboard isn't broken." << "\n";
        return promptTypeOfMachine();
    }
    return answer == "y";
}

bool promptEncodeOrDecode() {
    cout << "Encode or decode? (e/d)" << "\n";
    string answer;
    getline(cin,answer);
    if(answer.empty()) {
        cout << "I know your keyboard isn't broken." << "\n";
        return promptEncodeOrDecode();
    }
    return answer == "e";
}

vector<string> getInputWords() {
    cout << "What would you like to enter into the machine?" << "\n";
   
    string sentence;
    getline(cin, sentence);
    if(sentence.empty()) {
        cout << "I know your keyboard isn't broken." << "\n";
        return getInputWords();
    }
    string buf;
    stringstream wordstream(sentence);
    
    vector<string> words;
    
    while(wordstream >> buf) {
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
            result += c;
        } else if(c < 'a' || c > 'z'){
            return "~"; //bad character, return tilde
        } else {
            result += c;
        }  
    }
    return result;
}

vector<string> trimAndTransform(vector<string> sentence, Machine* m, bool encode) {
    vector<string> result;
    for(vector<string>::const_iterator i = sentence.begin(); i != sentence.end(); i++) {
        string word = *i;
        char punc = '~';
        char lastChar = word.at(word.size() - 1);
        if(lastChar == '.' || lastChar == ',') {
            word = word.substr(0, word.size() - 1);
            lastChar == '.' ? punc = '.' : punc = ',';
        } 
        
        if(word != "0") {
            word = convertToLowerCase(word);
        }
        if(word == "~") {
            result.push_back("~"); //bad character in input
            return result; 
        }
        
        string transformedWord;
        
        transformedWord = m->getTransformedString(word, encode);
       
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

void runInputOutput(Machine* m, bool newMachine) {
    bool encode = promptEncodeOrDecode();
    vector<string> sentence = getInputWords();
    
    if(newMachine) {
        sentence.push_back("0");
    }
   
    vector<string> transformedSentence = trimAndTransform(sentence, m, encode);
    while(transformedSentence.back() == "~") {
        cout << "Only letters, please." << "\n";
        sentence = getInputWords();
        transformedSentence = trimAndTransform(sentence, m, encode);
    }
    if(newMachine) {
        transformedSentence.pop_back();
    }
    printSentence(transformedSentence);
}

//void runInputOutputNewMachine(NewMachine* m) {
//    bool encode = promptEncodeOrDecode();
//    vector<string> sentence = getInputWords();
//    
//    vector<string> transformedSentence = trimAndTransform(sentence, m, encode);
//    while(transformedSentence.back() == "~") {
//        cout << "Only letters, please." << "\n";
//        sentence = getInputWords();
//        transformedSentence = trimAndTransform(sentence, m, encode);
//    }
//    
//    printSentence(transformedSentence);
//}

int main() {  
    bool newMachine = promptTypeOfMachine();
    Machine* m;
    if(newMachine) {
        m = new NewMachine();
    } else {
        m = new Machine();
    }
    string answer = "y";
    while(answer == "y") {
        runInputOutput(m, newMachine);
        cout << "Use machine again? (y/n)" << '\n';
        getline(cin,answer); 
    }
    cout << "later" << "\n";
}


 


