# 方法 1
import random
import string
from collections import Counter

# 生成包含1000个随机字符的字符串
random_string = ''.join(random.choices(string.ascii_letters + string.digits, k=1000))

# 使用 Counter 统计每个字符出现的次数
char_count = Counter(random_string)

# 输出结果
print(char_count)
print("-----------------------")

# 方法 2
import random
import string

# 生成包含1000个随机字符的字符串
random_string = ''.join(random.choices(string.ascii_letters + string.digits, k=1000))

# 使用字典统计每个字符出现的次数
char_count = {char: random_string.count(char) for char in set(random_string)}

# 输出结果
print(char_count)