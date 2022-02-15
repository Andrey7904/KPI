def input_text():
    text = []
    print("Enter your text: (press CTRL + X or empty line to stop)")
    flag = True
    exit_line = "\u0018"
    while(flag):
        line = str(input())
        if ((line == exit_line) | (line == "")):
            flag = False
        else:
            text.append(line)
    return text

def create_file(path, text):
    flag = True
    while (flag):
        choice = input("You want to add text or rewrite file? (Enter 'a' if you want to add text; 'r' if you want to rewrite text): ")
        if (choice == 'a'):
            new_file = open(path, 'at')
            new_file.write('\n' + text[0])
            flag = False
        if (choice == 'r'):
            new_file = open(path, 'wt')
            new_file.write(text[0])
            flag = False
        else:
            print('Wrong symbol. Try again')

    for i in range(1, len(text)):
        new_file.write('\n' + text[i])
    new_file.close()
    

def display_file(path):
    file = open(path,'rt')
    for string in file:
        print(string,end='')
    print('\n')
    file.close()

def read_text(path):
    file = open(path, "rt")
    text = file.readlines()
    file.close()
    return text

def change_text(text):
    edited_text = []
    for line in text:
        sentences_list = line.split('. ')
        for sentence in sentences_list:
            sentence = sentence.strip()
            result = sentence
            sentence = sentence.replace(";" , " ")
            sentence = sentence.replace("," , " ")
            words_list = sentence.split(" ")
            min_length = len(words_list[0])
            min_word = words_list[0]
            for word in words_list:
                if ((len(word) < min_length) & (word != "")):
                    min_length = len(word)
                    min_word = word
            if (result == ""):
                continue
            result += "--"+ str(min_length) + "--" + '"' + min_word + '"' + '--'
            edited_text.append(result)
    return edited_text


file_path = "filePy.txt"
new_file_path = "newFilePy.txt"

text = input_text()
create_file(file_path, text)

print("Original file is: ")
display_file(file_path)

new_text = read_text(file_path)
changed_text = change_text(new_text)
create_file(new_file_path, changed_text)

print("New file is: ")
display_file(new_file_path)
