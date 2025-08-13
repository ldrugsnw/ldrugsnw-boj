while True:
    S = input()
    res = 0
    if S == '#':
        break
    for i in range(len(S)):
        if S[i] == '~':
            res += 8 ** (len(S)-1-i) * 0
        elif S[i] == "\\":
            res += 8 ** (len(S) - 1 - i) * 1
        elif S[i] == "(":
            res += 8 ** (len(S) - 1 - i) * 2
        elif S[i] == "@":
            res += 8 ** (len(S) - 1 - i) * 3
        elif S[i] == "?":
            res += 8 ** (len(S) - 1 - i) * 4
        elif S[i] == ">":
            res += 8 ** (len(S) - 1 - i) * 5
        elif S[i] == "&":
            res += 8 ** (len(S) - 1 - i) * 6
        elif S[i] == "%":
            res += 8 ** (len(S) - 1 - i) * 7
        elif S[i] == "/":
            res += 8 ** (len(S) - 1 - i) * -1
    print(res)