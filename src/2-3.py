import random
import string

def generate_nested_list(n, m):
    # 生成嵌套列表，每个子列表包含随机长度的字符串
    nested_list = [
        [''.join(random.choices(string.ascii_letters + string.digits, k=random.randint(1, m))) for _ in range(random.randint(1, m))]
        for _ in range(n)
    ]
    
    # 按照字符串长度降序排序每个子列表
    sorted_nested_list = [sorted(sublist, key=len, reverse=True) for sublist in nested_list]
    
    return sorted_nested_list

# 示例调用
n = 5  # 嵌套列表的元素个数
m = 4  # 每个字符串的最大长度
result = generate_nested_list(n, m)

# 输出结果
print("生成的嵌套列表：")
for sublist in result:
    print(sublist)