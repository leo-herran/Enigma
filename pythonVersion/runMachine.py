import machine, rotor

# !, ', (, ), (comma), :, ;, ?	
okayCharacters = [33, 39, 40, 41, 44, 46, 58, 59, 63];

def encodeOrDecode():
	print("encode or decode? (e/d)");
	encode = input()[0];
	if(encode != 'e' and encode != 'd'): 
		print("Sorry?");
		return encodeOrDecode();
	else:
		if encode == 'e':
			return True;
		else:
			return False;

#change naughty characters to #
def censorWord(word):
	for i in range(0, len(word)):
		c = ord(word[i]);
		if c < 97 or c > 122:
			if not (c in okayCharacters):
				newWord = word[0:i] + "#" + word[(i+1):];
				word = newWord;
					
	return word;

def transformMessage(machine, message):
	for word in message:
		if word == "0":
			return;
		#else:
			

def runInputAndOutput(machine):
	e = encodeOrDecode();
	print("enter a message!");
	message = input().split();

	#convert to lower case. 
	for word in message:
		message[message.index(word)] = word.lower();
	
	#censor unwanted characters. 
	for word in message:
		if not word.isalpha():
			newWord = censorWord(word);
			message[message.index(word)] = newWord; 
	
	transformMessage(machine, message);
	message.append("0"); #end of sentence signal
	print(message);


def main():
	m = machine(false);
	answer = "y";
	while(answer == "y" or answer == "secret"): 
		if(answer == "secret"):
			m = machine(true);
		
		#runInputAndOutput(m);
		print("Use the enigma machine again? (y/n)");
		answer = input();
	
	print("later.");
	

if __name__ == "__main__":
	main();
