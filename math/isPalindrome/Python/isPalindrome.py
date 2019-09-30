import string

def prepare_string(input):
    # Remove all punctuation
    translator = str.maketrans('', '', string.punctuation)
    text = input.translate(translator)

    # Remove all whitespaces
    text = text.strip().replace(' ', '')

    # Set characters to lovercase
    text = text.lower()

    return text

def check_if_palindrome(input):
    text = str(input)
    text = prepare_string(text)
    if len(text) % 2 == 0:
        if text[::-1] == text:
            return True
        else:
            return False
