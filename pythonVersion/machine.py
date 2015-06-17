import rotor

class Machine():

	r1 = rotor.__init__();
	r2;
	r3;
	r1degree;
	r2degree;
	r3degree;
	reflector;
	
	def resetRotorDegrees(self):
		self.r1degree = 0;
		self.r2degree = 0;
		self.r3degree = 0;


	def incrementRotorDegrees(self):
		if(self.r1degree == 26):
			if(self.r2degree == 26):
				if(self.r3degree == 26):
					self.resetRotorDegrees();
				else:
					self.r3degree = self.r3degree + 1;
					self.r2degree = 1;
			else:
				self.r2degree = self.r2degree + 1;
				self.r1degree = 1;
		else:
			self.r1degree = self.r1degree + 1;			
	

	def transformCharacter(self, c, encode):
		r1c = self.r1.getEncodedChar(c, r1degree);
		r2c = self.r2.getEncodedChar(r1c, r2degree);
		r3c = self.r3.getEncodedChar(r2c, r3degree);
		reflectorC;

		if(encode):
			reflectorC = self.reflector.getEncodedChar(r3c, 0);
		else:
			reflectorC = self.reflector.getDecodedChar(r3c, 0);

		r3dc = self.r3.getDecodedChar(reflectorC, r3degree);
		r2dc = self.r2.getDecodedChar(r3dc, r2degree);
		r1dc = self.r1.getDecodedChar(r2dc, r1degree);
		return r1dc;


	def getTransformedString(self, word, encode):
		return "yo";	

		
	def __init__(self, secretModeFlag):
		if(secretModeFlag):
			self.r1.setSecretAlphabet();	
			self.r2.setSecretAlphabet();	
			self.r3.setSecretAlphabet();	
			self.reflector.setSecretAlphabet();	
		
		else:
			self.r1 = rotor();	
			self.r2 = rotor();	
			self.r3 = rotor();	
	
		rotorOneDegree = 0;
		rotorTwoDegree = 0;
		rotorThreeDegree = 0;




