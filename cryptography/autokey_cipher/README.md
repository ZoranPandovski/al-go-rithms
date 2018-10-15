##Autokey Cipher

####Introduction

The Autokey Cipher is a polyalphabetic substitution cipher. It is closely related to the Vigenere cipher, but uses a different method of generating the key. It was invented by Blaise de Vigenère in 1586, and is in general more secure than the Vigenere cipher.

####The Algorithm

The 'key' for the Autokey cipher is a key word. e.g. 'FORTIFICATION'

The Autokey cipher uses the following tableau (the 'tabula recta') to encipher the plaintext:

>     A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
>     ---------------------------------------------------
> A   A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
> B   B C D E F G H I J K L M N O P Q R S T U V W X Y Z A
> C   C D E F G H I J K L M N O P Q R S T U V W X Y Z A B
> D   D E F G H I J K L M N O P Q R S T U V W X Y Z A B C
> E   E F G H I J K L M N O P Q R S T U V W X Y Z A B C D
> F   F G H I J K L M N O P Q R S T U V W X Y Z A B C D E
> G   G H I J K L M N O P Q R S T U V W X Y Z A B C D E F
> H   H I J K L M N O P Q R S T U V W X Y Z A B C D E F G
> I   I J K L M N O P Q R S T U V W X Y Z A B C D E F G H
> J   J K L M N O P Q R S T U V W X Y Z A B C D E F G H I
> K   K L M N O P Q R S T U V W X Y Z A B C D E F G H I J
> L   L M N O P Q R S T U V W X Y Z A B C D E F G H I J K
> M   M N O P Q R S T U V W X Y Z A B C D E F G H I J K L
> N   N O P Q R S T U V W X Y Z A B C D E F G H I J K L M
> O   O P Q R S T U V W X Y Z A B C D E F G H I J K L M N
> P   P Q R S T U V W X Y Z A B C D E F G H I J K L M N O
> Q   Q R S T U V W X Y Z A B C D E F G H I J K L M N O P
> R   R S T U V W X Y Z A B C D E F G H I J K L M N O P Q
> S   S T U V W X Y Z A B C D E F G H I J K L M N O P Q R
> T   T U V W X Y Z A B C D E F G H I J K L M N O P Q R S
> U   U V W X Y Z A B C D E F G H I J K L M N O P Q R S T
> V   V W X Y Z A B C D E F G H I J K L M N O P Q R S T U
> W   W X Y Z A B C D E F G H I J K L M N O P Q R S T U V
> X   X Y Z A B C D E F G H I J K L M N O P Q R S T U V W
> Y   Y Z A B C D E F G H I J K L M N O P Q R S T U V W X
> Z   Z A B C D E F G H I J K L M N O P Q R S T U V W X Y

To encipher a message, place the keyword above the plaintext. Once all of the key characters have been written, start writing the plaintext as the key:

> FORTIFICATIONDEFENDTHEEASTWA
> DEFENDTHEEASTWALLOFTHECASTLE

Now we take the letter we will be encoding, 'D', and find it on the first column on the tableau. Then, we move along the 'D' row of the tableau until we come to the column with the 'F' at the top (The 'F' is the keyword letter for the first 'D'), the intersection is our ciphertext character, 'I'.

So, the ciphertext for the above plaintext is:

> FORTIFICATIONDEFENDTHEEASTWA
> DEFENDTHEEASTWALLOFTHECASTLE
> ISWXVIBJEXIGGZEQPBIMOIGAKMHE