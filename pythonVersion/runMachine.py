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

#change numbers to #
def censorNumbers(word):
	for i in range(0, len(word)):
		c = ord(word[i]);
		if c >= 48 and c <= 57:
			newWord = word[0:i] + "#" + word[(i+1):];
			word = newWord;
					
	return word;

def transformMessage(machine, message, encode):
	for i in range(0, len(message)):
		word = message[i];
		transformedWord = machine.getTransformedString(word, encode);
		message[i] = transformedWord;

	return message;			

def runInputAndOutput(machine):
	encode = encodeOrDecode();
	print("enter a message!");
	message = input().split();

	#convert to lower case. 
	for word in message:
		message[message.index(word)] = word.lower();
	
	#for now we can just censor numbers. 
	for i in range(1, len(message)):
		word = message[i];
		if not word.isalpha():
			newWord = censorNumbers(word);
			message[i] = newWord; 
	
	message = transformMessage(machine, message, encode);
	printMessage(message);


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
