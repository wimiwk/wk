n = int(input())
timestamps = []
for _ in range(n):
    s, t = map(int, input().split())
    timestamps.append((s, t))

record = {}
for s, t in timestamps:
    if s in record:
        record[s] += 1
    else:
        record[s] = 1
    if s + t in record:
        record[s + t] -= 1
    else:
        record[s + t] = -1

count = [0] * (n + 1)
current_count = 0
prev_time = 0
for time in sorted(record.keys()):
    count[current_count] += time - prev_time
    prev_time = time
    current_count += record[time]

output = ' '.join(str(c) for c in count[1:])
print(output)
