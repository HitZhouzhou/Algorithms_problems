def KingGame():
    n = int(input())
    king = list(map(int,input().split()))[0]
    troops = []
    for item in range(n):
        troop = list(map(int,input().split()))
        troops.append(troop)
    # troops[1:] = sorted(troops[1:])
    troops.sort(key=lambda x: x[0]*x[1])  # 按照左右手乘积 升序排列
    count = king
    maxResult = count // troops[0][1] # 计算第一个大臣可以得到的金币
    for item in range(1, n):
        count *= troops[item-1][0]
        result = count // troops[item][1]
        if result > maxResult:
            maxResult = result
    print(maxResult)
KingGame()
