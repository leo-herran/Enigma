from rotor import Rotor
import charChecker

class Machine():

    alphabet = "abcdefghijklmnopqrstuvwxyz";
    digits = "0123456789";

    #not very secure, I know...
    secretR1 = "dgnotpubfkacivhlsmrjwyxzeq";
    secretR2 = "lompwdzfsravkejnixtgchyqbu";
    secretR3 = "qkgslyfbphotwuraemnczdijvx";
    secretReflector = "lrufxmntzevkphiqodaywbjgsc";

    secretD1 = "3852069147"
    secretD2 = "0678124359"
    secretD3 = "7348910625"
    secretDReflector = "4689517320"

    #r1 = Rotor();
    #r2 = Rotor();
    #r3 = Rotor();
    #reflector = Rotor();

    r1degree = 0;
    r2degree = 0;
    r3degree = 0;
    
    def resetRotorDegrees(self):
        self.r1degree = 0;
        self.r2degree = 0;
        self.r3degree = 0;


    def incrementRotorDegrees(self):
        if(self.r1degree == self.alphLength):
            if(self.r2degree == self.alphLength):
                if(self.r3degree == self.alphLength):
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

        if (self.digitEncoding and not c in self.digits) or (not self.digitEncoding and not c in self.alphabet):
            if charChecker.checkCharAcceptable(c):
                return c;
            else:
                return "#";
 
        r1c = self.r1.getEncodedChar(c, self.r1degree);
        r2c = self.r2.getEncodedChar(r1c, self.r2degree);
        r3c = self.r3.getEncodedChar(r2c, self.r3degree);

        if(encode):
            reflectorC = self.reflector.getEncodedChar(r3c, 0);
        else:
            reflectorC = self.reflector.getDecodedChar(r3c, 0);

        r3dc = self.r3.getDecodedChar(reflectorC, self.r3degree);
        r2dc = self.r2.getDecodedChar(r3dc, self.r2degree);
        r1dc = self.r1.getDecodedChar(r2dc, self.r1degree);
        return r1dc;


    def getTransformedString(self, word, encode):
        if word == "<>":
            self.resetRotorDegrees();
            return "<>";

        newWord = "";
        for char in word:	
            newWord = newWord + self.transformCharacter(char, encode);	
            self.incrementRotorDegrees();
    
        return newWord;
        
    def __init__(self, letterFlag, secretModeFlag):
        self.digitEncoding = not letterFlag;
        if letterFlag:
            self.alphLength = len(self.alphabet);
        else:
            self.alphLength = len(self.digits);

        if(letterFlag):
            self.r1 = Rotor(self.alphabet);
            self.r2 = Rotor(self.alphabet);
            self.r3 = Rotor(self.alphabet);
            self.reflector = Rotor(self.alphabet);
        else:
            self.r1 = Rotor(self.digits);
            self.r2 = Rotor(self.digits);
            self.r3 = Rotor(self.digits);
            self.reflector = Rotor(self.digits);

        if(secretModeFlag):
            if(letterFlag):
                self.r1.setSecretAlphabet(self.secretR1);	
                self.r2.setSecretAlphabet(self.secretR2);	
                self.r3.setSecretAlphabet(self.secretR3);	
                self.reflector.setSecretAlphabet(self.secretReflector);	
            else:
                self.r1.setSecretAlphabet(self.secretD1);	
                self.r2.setSecretAlphabet(self.secretD2);	
                self.r3.setSecretAlphabet(self.secretD3);	
                self.reflector.setSecretAlphabet(self.secretDReflector);	

                
