# Enigma
A simplification of the enigma machine used in WWII. My implementation resembles the original machine in that it contains three 
"rotors" (substitution ciphers over the alphabet) and a reflector (symmetric substitution cipher over the alphabet) and encodes 
characters by sending them through the three rotors, through the reflector, and back through the rotors. It different from 
the original in its lack of a plugboard. Another difference is the ability of my machine to map a character to itself, 
which was a feature avoided in the orignal design (and turned out to be a critical design flaw, as evidenced by the result 
of the war). 

The enigma machine elevates its enciphering capability from a regular substitution cipher by mechanizing its inner rotors. 
As stringing together a few rotors is still a substitution cipher, the enigma machine rotates one of its rotors each time 
a character is encoded. Thus, if a letter appears more than once in a word then it will most likely be encoded to multiple different letters in that word. In the original machine, the first rotor would rotate once for each encoded character until it made a full rotaton, then the second rotor would rotate, then the third. In my implementation, after 78 encoded charcters (i.e. each rotor makes a full rotation) the rotors stop rotating, so the machine becomes a regular substitution cipher. 

One problem with the Enigma machine is the way it consistently encodes words to the same ciphertext. If the word "and" were to appear multiple times in a message it would be encoded to the same three-letter code. This means that applying frequency analysis to encoded messages could expose common words. Another problem with the Enigma machine is that the first letters in words are always encoded the same, which means encoding a phrase such as "apples are always appetizing" would be encoded as "jjuznx juf jmjilx jjucqwugoo." 

To remedy these problems I implemented a cousin to the enigma machine that increments its rotors after each character is encoded *and* after each word is encoded. The functionality of the machines is similar: 

![alt text](http://i.imgur.com/FOjpin2.jpg "Using both versions of the Enigma machine.")

However, the disparity between the two becomes evident when encoding a phrase with repeated words:

![alt text](http://i.imgur.com/UEh0UmP.jpg "Differences in encoding between the two machines.")
