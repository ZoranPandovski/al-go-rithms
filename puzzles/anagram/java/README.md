# Java Anagram Checker

An anagram is a form of word play, where you take a word (or set of words) and form a different word (or different set of words) that use the same letters, just rearranged. All words must be valid spelling, and shuffling words around doesn't count.

Some serious word play aficionados find that some anagrams can contain meaning, like "Clint Eastwood" and "Old West Action", or "silent" and "listen".
Someone once said, "All the life's wisdom can be found in anagrams. Anagrams never lie." How they don't lie is beyond me, but there you go.

You can enter two words separated by a question mark. The output will be the information about the validity of the anagram.

**Example:**
~~~ text
"Clint Eastwood" ? "Old West Action"
"Clint Eastwood" is an anagram of "Old West Action"

"parliament" ? "partial man"
"parliament" is NOT an anagram of "partial man"
~~~

**Some sample inputs:**
~~~ text
"wisdom" ? "mid sow"
"Seth Rogan" ? "Gathers No"
"Reddit" ? "Eat Dirt"
"Schoolmaster" ? "The classroom"
"Astronomers" ? "Moon starer"
"Vacation Times" ? "I'm Not as Active"
"Dormitory" ? "Dirty Rooms"
~~~

---

### How to run the Java

(For anyone who want's to test this outside of an IDE)

Compile:
~~~ bash
javac AnagramDetector.java
~~~

Run:
~~~ bash
java AnargamDetector
~~~
