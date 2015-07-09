from machine import Machine

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
    numbers = [];
    for i in range(0, len(word)):
        c = ord(word[i]);
        if c >= 48 and c <= 57:
            numbers.append(word[i]);
            newWord = word[0:i] + "*" + word[(i+1):];
            word = newWord;
                                        
    return (newWord, numbers);

def containsNumbers(word):
    for i in range(0, 10):
        if str(i) in word:
            return True;

    return False;
    
def transformMessage(machine, message, encode):
    for i in range(0, len(message)):
        word = message[i];
        transformedWord = machine.getTransformedString(word, encode);
        message[i] = transformedWord;

    return message;			
	
def printMessage(message):
    for word in message:
        print(word + " ", end="");

    print("");

def runInputAndOutput(machine):
    encode = encodeOrDecode();
    print("Enter your message.");
    message = input().split();

    #convert to lower case. 
    for word in message:
        message[message.index(word)] = word.lower();
 
    #change numbers to special character (*) and encrypt them. 
    messageNumbers = []; 
    for i in range(len(message)):
        word = message[i];
        if containsNumbers(word): 
            wordData = censorNumbers(word); 
            newWord = wordData[0];
            message[i] = newWord; 
            messageNumbers.extend(wordData[1]);


    message.append("<>"); #end of message signal.	
    message = transformMessage(machine, message, encode);
    message.remove("<>");
    printMessage(message);
    print(messageNumbers);


def main():
    m = Machine(False);
    answer = "y";
    while(answer == "y" or answer == "secret"): 
        if(answer == "secret"):
            m = Machine(True);
        
        runInputAndOutput(m);
        print("Use the enigma machine again? (y/n)");
        answer = input();

    print("later.");
	

if __name__ == "__main__":
    main();
