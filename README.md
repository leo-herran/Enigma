# Enigma
A simplification of the enigma machine used in WWII. My implementation resembles the original machine in that it contains three 
"rotors" (substitution ciphers over the alphabet) and a reflector (symmetric substitution cipher over the alphabet) and encodes 
characters by sending them through the three rotors, through the reflector, and back through the rotors. It different from 
the original in its lack of a plugboard. Another difference is the ability of my machine to map a character to itself, 
which was a feature avoided in the orignal design (and turned out to be a critical design flaw, as evidenced by the result 
of the war). 

The enigma machine elevates its enciphering capability from a regular substitution cipher by mechanizing its inner rotors. 
As stringing together a few rotors is still a substitution cipher, the enigma machine rotates one of its rotors each time 
a character is encoded. Thus, if a letter appears more than once in a message then it will most likely be encoded to different
letters. In the original machine, the first rotor would rotate once for each encoded character until it made a full rotaton, then 
the second rotor would rotate, then the third. In my implementation, after 78 encoded charcters (i.e. each rotor makes a full
rotation) the rotors stop rotating, so the machine becomes a regular substitution cipher. 

Example:  
![alt text](http://i.imgur.com/i2WGd9x.png "Using the enigma machine")
