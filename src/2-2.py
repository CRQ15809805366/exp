# 方法 1：使用系统内置集合类
def system_set_operations(setA, setB):
    # 交集
    intersection = setA & setB
    # 差集
    difference = setA - setB
    # 并集
    union = setA | setB

    return intersection, difference, union

# 示例调用
setA = {1, 2, 3, 4}
setB = {3, 4, 5, 6}
intersection, difference, union = system_set_operations(setA, setB)

print("系统集合类实现：")
print(f"交集: {intersection}")
print(f"差集: {difference}")
print(f"并集: {union}")

# 方法 2：自定义集合类
class CustomSet:
    def __init__(self, elements):
        self.elements = set(elements)

    def intersection(self, other):
        # 交集
        return CustomSet([x for x in self.elements if x in other.elements])

    def difference(self, other):
        # 差集
        return CustomSet([x for x in self.elements if x not in other.elements])

    def union(self, other):
        # 并集
        return CustomSet(list(self.elements) + [x for x in other.elements if x not in self.elements])

    def __str__(self):
        return str(self.elements)

# 示例调用
setA = CustomSet([1, 2, 3, 4])
setB = CustomSet([3, 4, 5, 6])

intersection = setA.intersection(setB)
difference = setA.difference(setB)
union = setA.union(setB)

print("\n自定义集合类实现：")
print(f"交集: {intersection}")
print(f"差集: {difference}")
print(f"并集: {union}")