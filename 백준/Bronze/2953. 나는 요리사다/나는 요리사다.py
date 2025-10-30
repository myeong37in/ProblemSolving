import sys

def main():
    li = [0] * 6
    for i in range(1, 6):
        li[i] = sum(map(int, sys.stdin.readline().split()))

    max_idx = 0
    max_val = 0
    for i in range(1, 6):
        if li[i] > max_val:
            max_val = li[i]
            max_idx = i

    print(max_idx, max_val)

if __name__ == "__main__":
    main()