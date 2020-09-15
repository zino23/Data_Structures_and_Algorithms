try:
    m, n = [int(x) for x in input().split()]
    # m * n 
    res = [[0] * n for _ in range(m)]

    # delta x and delta y in terms of four directions
    # right: (0, 1)
    # left: (1, 0)
    # down: (0, -1)
    # up: (-1, 0)
    directions_x = [0, 1, 0, -1]
    directions_y = [1, 0, -1, 0]

    x = 0
    y = 0
    d = 0
    for i in range(1, m * n + 1):
        res[x][y] = i
        next_x = x + directions_x[d]
        next_y = y + directions_y[d]
        # if the next position exceeds bounds or is already taken, change direction
        if next_x < 0 or next_x >= m or next_y < 0 or next_y >= n or res[next_x][next_y] > 0:
            d = (d + 1) % 4
            next_x = x + directions_x[d]
            next_y = y + directions_y[d]
        x = next_x
        y = next_y

    for i in range(m):
        for j in range(n):
            print(res[i][j], end=' ')
        print()
    
    chosen = {}
    for i in range(m):
        for j in range(n):
            if res[i][j] % 10 == 7 and res[i][j] // 10 % 2 == 1:
                chosen[res[i][j]] = (i, j)

    final_res = [x[1] for x in sorted(chosen.items(), key=lambda x: x[0])]
    print(final_res)

except ValueError:
    print('[]')










