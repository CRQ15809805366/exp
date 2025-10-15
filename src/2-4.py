def list_and_slicing_operations():
    # 生成一个整型列表
    original_list = [i for i in range(1, 11)]  # 示例列表 [1, 2, ..., 10]
    
    # 包含原列表中所有元素的新列表
    new_list = original_list[:]
    
    # 包含原列表中所有元素的逆序列表
    reversed_list = original_list[::-1]
    
    # 具有偶数位置的元素列表（索引从0开始）
    even_position_list = original_list[1::2]
    
    return new_list, reversed_list, even_position_list

# 示例调用
new_list, reversed_list, even_position_list = list_and_slicing_operations()

print("原列表的所有元素的新列表:", new_list)
print("原列表的逆序列表:", reversed_list)
print("原列表中偶数位置的元素列表:", even_position_list)