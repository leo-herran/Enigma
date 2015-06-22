# !, ', (, ), (comma), :, ;, ?	
okayCharacters = [33, 39, 40, 41, 44, 45,  46, 58, 59, 63];

	
def checkCharAcceptable(c):
	cOrd = ord(c);
	return cOrd in okayCharacters;

def checkIsLetter(c):
	cOrd = ord(c);
	return cOrd in range(97, 123);
