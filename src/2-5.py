def generate_filtered_tuple(n, m):
    # 使用生成器推导式生成包含 n 个整数元素的元组，过滤掉偶数
    result_tuple = tuple(x for x in range(1, m + 1) if x % 2 != 0)[:n]
    return result_tuple

# 示例调用
n = 10  # 元素个数
m = 20  # 元素最大值
filtered_tuple = generate_filtered_tuple(n, m)

print("生成的元组:", filtered_tuple)