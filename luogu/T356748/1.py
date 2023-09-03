def construct_tree(n, d, k):
    if n == 1:
        if d == 0:
            return [1], True
        else:
            return [], False
    if n < k or (n - 1) * (k - 1) < d:
        return [], False

    tree = [1]
    remaining_nodes = n - 1
    remaining_distance = d

    for i in range(1, n):
        max_depth = min(i, remaining_nodes - 1)
        max_dist = remaining_distance - max_depth

        # 如果k=1，或者达到了叶子节点的条件，则将其作为叶子节点
        if k == 1 or remaining_nodes == max_dist:
            tree.append(i + 1)
            remaining_nodes -= 1
            remaining_distance -= i
        else:
            # 否则，将其添加为当前节点的儿子节点
            tree.extend([i + 1] * min(k - 1, remaining_nodes - 1))
            remaining_nodes -= min(k - 1, remaining_nodes - 1)
            remaining_distance -= min(k - 1, remaining_nodes - 1) * i

    if remaining_nodes == 0 and remaining_distance == 0:
        return tree, True
    else:
        return [], False


# 处理多组数据
T = int(input())
for _ in range(T):
    n, d, k = map(int, input().split())
    tree, possible = construct_tree(n, d, k)
    if possible:
        print("YES")
        print(" ".join(map(str, tree)))
    else:
        print("NO")
