from string import ascii_lowercase, ascii_uppercase

while True: 
    try:
        s = input()
    except EOFError:
        break

    is_digit = False
    is_uppercase = False
    is_lowercase = False
    is_ascii = True
    size = len(s)
    
    if 6 <= size and size <= 32:
        for c in s:
            if c.isdigit():
                is_digit = True
            elif c in ascii_lowercase:
                is_uppercase = True
            elif c in ascii_uppercase:
                is_lowercase = True
            else:
                is_ascii = False
                break

    if is_ascii and is_digit and is_uppercase and is_lowercase:
        print("Senha valida.")
    else:
        print("Senha invalida.")
