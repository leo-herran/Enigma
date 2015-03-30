# Enigma
A simplification of the enigma machine used in WWII. My implementation resembles the original machine in that it contains three 
"rotors" (substitution ciphers over the alphabet) and a reflector (symmetric substitution cipher over the alphabet) and encodes 
characters by sending them through the three rotors, through the reflector, and back through the rotors. It is different from 
the original in its lack of a plugboard. 

The enigma machine elevated its enciphering capability from a regular substitution cipher by mechanizing its inner rotors. 
As stringing together a few rotors is still a substitution cipher, the enigma machine rotates one of its rotors each time 
a character is encoded. Thus, if a letter appears more than once in a word then it will most likely be encoded to multiple different letters in that word. In the original machine, the first rotor would rotate once for each encoded character until it made a full rotaton, then the second rotor would rotate once, then the third would rotate once when the second rotor made a full rotation. This means that each encoded character is given a unique substitution cipher and messages up to 26^3 characters in length can be encoded. A feature avoided in the orignal design was the ability of the machine to map characters to themselves (which was a result of the reflector). This turned out to be a critical design flaw, as evidenced by the result 
of the war. 

An example of the machine's behavior and enciphering capability is given below.

![alt text](http://i.imgur.com/PXY7Ncy.jpg "Enigma machine in action!")
