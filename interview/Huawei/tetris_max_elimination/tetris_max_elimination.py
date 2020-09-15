frame, brick = input().split()
frame = [int(x) for x in frame]
brick = [int(x) for x in brick]

for pos_brick in range(len(frame) - len(brick) + 1):
    brick_frame_sum = [brick[i] + frame[pos_brick + i] for i in range(len(brick))]
    max_tmp = max(brick_frame_sum)
    for i, sum_tmp in enumerate(brick_frame_sum):
        # the brick and max_tmp are connected when sum_tmp == max_tmp
        if sum_tmp == max_tmp:
            frame[pos_brick + i] += 1

lines_eliminated = frame.count(min(frame))
print(lines_eliminated)
        