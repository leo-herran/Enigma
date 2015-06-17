import random

class Rotor:
	alphabet = "abcdefghijklmnopqrstuvwxyz";
	jumbledAlphabet = []; 

	def swap(self, first, second):
		temp = self.jumbledAlphabet[first];
		self.jumbledAlphabet[first] = self.jumbledAlphabet[second];
		self.jumbledAlphabet[second] = temp;

	def generateJumbledAlphabet(self):
		for i in range(0, 26):
			self.jumbledAlphabet.append(self.alphabet[i]);

		for i in range(25, 0, -1):
			choice = random.choice(range(0, i));
			self.swap(i, choice);
		
	def positiveMod(self, value, mod):
		return ((value % mod) + mod) % mod;

	def getEncodedChar(self, c, rotationDegree):
		index = self.positiveMod(self.alphabet.index(c) - rotationDegree, 26); 
		return self.jumbledAlphabet[index];		

	def getDecodedChar(self, c, rotationDegree):
		index = self.positiveMod(self.jumbledAlphabet.index(c) + rotationDegree, 26); 
		return self.alphabet[index];		


	def setSecretAlphabet(self, secret):
		for i in range(0, 26):
			self.jumbledAlphabet[i] = secret[i];

	def __init__(self):
		self.generateJumbledAlphabet();
	
