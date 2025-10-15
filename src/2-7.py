import re

def find_three_letter_words(input_string):
    # 使用正则表达式查找长度为3的单词
    three_letter_words = re.findall(r'\b[a-zA-Z]{3}\b', input_string)
    return three_letter_words

# 示例调用
input_string = "The cat and dog are big fan of the zoo."
three_letter_words = find_three_letter_words(input_string)

# 输出结果
print("长度为3的单词：", three_letter_words)