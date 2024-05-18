# c-stuff: the repo where I throw my c junk.
I'd like to get back into writing C, so I'm just throwing some basic stuff together to warm up to it.

## What's in here
So far:
### csar.c (Caesar Cypher)
A super basic project that encrypts with the [Caesar Cipher](https://en.wikipedia.org/wiki/Caesar_cipher) I'm using a right-shift of three (the one Julius Caesar used). Lowercase letters get shifted into lowercase, same with uppercase. Non-letter characters ignored! Csar reads a message.txt file and prints the encrypted text.

### vigenere.c Vignère
The [Vignère Cipher] (https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher) is a variation on the Caesar cipher. Instead of hacing a constant offset, each character's offset is determined by a corresponding letter of a key. So, a key "foo" would offset by 6, then 14, then 14, then back to 6, until the original text has been enciphered.
