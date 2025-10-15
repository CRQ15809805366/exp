def count_word_frequency(input_string):
    # 将字符串按空格分割成单词列表
    words = input_string.split()
    
    # 使用字典统计每个单词出现的次数
    word_count = {}
    for word in words:
        word = word.strip()  # 去除单词前后可能的空格
        word_count[word] = word_count.get(word, 0) + 1
    
    return word_count

# 示例调用
input_string = "I love China I love programming"
word_count = count_word_frequency(input_string)

# 输出结果
print("单词出现次数统计：")
for word, count in word_count.items():
    print(f"{word}: {count}")