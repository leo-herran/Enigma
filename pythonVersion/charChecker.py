# !, ', (, ), (comma), *, :, ;, ?	
okayCharacters = [33, 39, 40, 41, 42, 44, 45,  46, 58, 59, 63];

	
def checkCharAcceptable(c):
    cOrd = ord(c);
    return cOrd in okayCharacters;

