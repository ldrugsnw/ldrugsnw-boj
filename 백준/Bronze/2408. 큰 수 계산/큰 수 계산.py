n = int(input())

expression = ""
for i in range(2 * n - 1):
    line = input().strip()
    if line == '/':
        line = '//'
    expression += line

result = int(eval(expression))
print(result)