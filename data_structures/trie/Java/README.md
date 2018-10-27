# Trees - Implementing a Trie

In the present repository I'm storing the codes created to implement a Trie.

<b>Lucas Gomes Dantas</b> (<dantaslucas@ufrn.edu.br>), student in the <b>Basic Data Structure II</b> class of <b>Prof. Dr. Jorge Estefano Santana de Souza</b> at <b>Federal University of Rio Grande do Norte</b>.

## Implemented functions

* <code>public void insert(String data)</code> - Receives one string with the word to be stored and saves it on the Trie;
* <code>public boolean search(String word)</code> - Searches if a given word exists on the Trie;
* <code>public void print()</code> - Prints all the words stored within the Trie;
* <code>public ArrayList<String> getWordsFromPrefix(String prefix)</code> - Receives a prefix (it does not matter if the prefix is a full word) and searchs for all words derived from this prefix.
* <code>public boolean delete(String word)</code> - Deletes a given word from within the Trie.

There are some private helper functions, you can find them by checking the <code>Trie.java</code> file.

Also, do not forget to check out <code>Node.java</code>, the Node structure was hidden from this README. 

## Compiling and running

The main focus was to provide the source code of the project. You can add them to Eclipse, IntelliJ or whatever option you prefer and compile/execute.

## License

    Copyright (C) 2018  Lucas Gomes Dantas
    Contact: <dantaslucas@ufrn.edu.br>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
