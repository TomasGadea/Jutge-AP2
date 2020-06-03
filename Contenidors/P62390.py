# Simulant recursivitat (1)

from jutge import read


def escriu(n):
    s = [n]
    while len(s) > 0:
        print('', s[-1], end='')
        newtop = s[-1] - 1
        s.pop()
        if newtop >= 1:
            s.append(newtop)
            s.append(newtop)


def main():
    n = read(int)
    while n is not None:
        escriu(n)
        print()
        n = read(int)


main()
