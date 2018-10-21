#### Python 3.5+ required ####
from sys import argv, exit

def print_usage():
    print(f'USAGE: python {argv[0]} <file>')

def get_word(line: str) -> str:
    ''' Gets first word before comma of a line '''
    idx = line.find(',')
    return line if idx == -1 else line[:idx]

def count_before_comma(file_name: str) -> dict:
    ''' Count the Words before Each comma ',' 
        with new lines as seperators '''
    word_count = {}
    with open(file_name) as f:
        for line in f:
            word = get_word(line)
            word_count[word] = word_count.setdefault(word, 0) + 1
    return word_count

def pretty_print_answer(answer: dict):
    ''' Prints the answer of the problem. '''
    for word, count in answer.items():
        print(word, count)

if __name__ == '__main__':
    if len(argv) != 2:
        print_usage()
        exit(1)

    pretty_print_answer(count_before_comma(argv[1]))