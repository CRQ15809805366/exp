def find_overlap_and_merge(s1, s2):
    # 查找首尾交叉的最大子串长度
    find_overlap = lambda x, y: max([i for i in range(len(x) + 1) if x[-i:] == y[:i]] or [0])
    
    overlap_length = find_overlap(s1, s2)
    
    # 合并两个字符串，首尾交叉部分只保留一份
    merge_strings = lambda x, y, overlap: x + y[overlap:]
    merged_string = merge_strings(s1, s2, overlap_length)
    
    return overlap_length, merged_string

# 示例调用
s1 = "1234"
s2 = "2347"
overlap_length, merged_string = find_overlap_and_merge(s1, s2)
print(f"首尾交叉的最大子串长度: {overlap_length}")
print(f"合并后的字符串: {merged_string}")