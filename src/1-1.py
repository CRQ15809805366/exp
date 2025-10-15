import random

def guess_number_game():
    # 系统生成一个随机数字，范围为1到100
    number_to_guess = random.randint(1, 100)
    max_attempts = 5  # 最大尝试次数
    print("欢迎来到猜数字小游戏! 系统已经生成了一个1到100之间的随机数字。")
    print(f"你有 {max_attempts} 次机会来猜测正确的数字。")

    for attempt in range(1, max_attempts + 1):
        try:
            user_guess = int(input(f"第 {attempt} 次猜测，请输入你的数字："))
        except ValueError:
            print("请输入一个有效的整数！")
            continue

        if user_guess == number_to_guess:
            print("恭喜你，猜对了！游戏结束。")
            return
        elif user_guess > number_to_guess:
            print("太大了！")
        else:
            print("太小了！")

    print(f"很遗憾，你没有猜对。正确答案是 {number_to_guess}。游戏结束。")

# 运行游戏
if __name__ == "__main__":
    guess_number_game()