import random

class Rotor:

    def swap(self, first, second):
        temp = self.jumbledAlphabet[first];
        self.jumbledAlphabet[first] = self.jumbledAlphabet[second];
        self.jumbledAlphabet[second] = temp;

    def generateJumbledAlphabet(self):
        self.jumbledAlphabet = [];

        for i in range(0, self.alphLength):
            self.jumbledAlphabet.append(self.alphabet[i]);

        for i in range(self.alphLength - 1, 0, -1):
            choice = random.choice(range(0, i));
            self.swap(i, choice);
            
    def positiveMod(self, value, mod):
        return ((value % mod) + mod) % mod;

    def getEncodedChar(self, c, rotationDegree):
        index = self.positiveMod(self.alphabet.index(c) - rotationDegree, self.alphLength); 
        return self.jumbledAlphabet[index];		

    def getDecodedChar(self, c, rotationDegree):
        index = self.positiveMod(self.jumbledAlphabet.index(c) + rotationDegree, self.alphLength); 
        return self.alphabet[index];		


    def setSecretAlphabet(self, secret):
        for i in range(0, self.alphLength):
            self.jumbledAlphabet[i] = secret[i];

    def __init__(self, alphabet):
        self.alphabet = alphabet;
        self.alphLength = len(self.alphabet);
        self.generateJumbledAlphabet();
	
