a = input("Введите первую битовую строку: ")
b = input("Введите вторую битовую строку: ")

lenA = 0
for _ in a:
    lenA += 1

lenB = 0
for _ in b:
    lenB += 1

if lenA > 8 or lenB > 8:
    print("Ошибка, длина строки больше 8 бит.")
    exit()

for ch in a:
    if ch != '0' and ch != '1':
        print("Ошибка, первая строка введена некорректно.")
        exit()

for ch in b:
    if ch != '0' and ch != '1':
        print("Ошибка, вторая строка введена некорректно.")
        exit()

old_a = a

a8 = ['0'] * 8
k = lenA - 1
for i in range(7, -1, -1):
    if k >= 0:
        a8[i] = a[k]
        k -= 1

a = ''.join(a8)

if a != old_a:
    print("Измененная 1 строка:", a)

old_b = b

b8 = ['0'] * 8
k = lenB - 1
for i in range(7, -1, -1):
    if k >= 0:
        b8[i] = b[k]
        k -= 1

b = ''.join(b8)

if b != old_b:
    print("Измененная 2 строка:", b)

result = []
for i in range(8):
    if a[i] == '1' and b[i] == '1':
        result.append('1')
    else:
        result.append('0')

print("Результат AND:", ''.join(result))