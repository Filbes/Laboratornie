def proverka(s):
    for c in s:
        if c != '0' and c != '1':
            return False
    return True

def privesti_k_8_bitam(s):
    if len(s) > 8:
        return ""

    while len(s) < 8:
        s = "0" + s

    return s

def kon(a, b):
    result = ""

    for i in range(8):
        if a[i] == '1' and b[i] == '1':
            result += '1'
        else:
            result += '0'

    return result

print("Выберите режим работы:")
print("1 - читать строки из файлов")
print("2 - ввод строк с клавиатуры")
print("3 - ввести строки и записать их в файлы")

choice = input("Ваш выбор: ")

if choice == "1":

    try:
        with open("input1.txt", "r") as f1:
            a = f1.read().strip()

        with open("input2.txt", "r") as f2:
            b = f2.read().strip()

        print("Данные прочитаны из файлов")

    except FileNotFoundError:
        print("Ошибка: файл не найден")
        exit()

elif choice == "2":

    a = input("Введите первую битовую строку: ")
    b = input("Введите вторую битовую строку: ")

elif choice == "3":

    a = input("Введите строку для input1.txt: ")
    b = input("Введите строку для input2.txt: ")

    with open("input1.txt", "w") as f1:
        f1.write(a)

    with open("input2.txt", "w") as f2:
        f2.write(b)

    print("Файлы успешно заполнены")

else:
    print("Неверный выбор")
    exit()

if not proverka(a) or not proverka(b):
    print("Ошибка: строки должны содержать только 0 и 1")
    exit()

a = privesti_k_8_bitam(a)
b = privesti_k_8_bitam(b)

if a == "" or b == "":
    print("Ошибка: длина строки больше 8 бит")
    exit()


print("Строка 1:", a)
print("Строка 2:", b)

result = kon(a, b)

print("Результат AND:", result)

with open("output.txt", "w") as fout:
    fout.write("Результат AND: " + result)

print("Результат записан в файл output.txt")