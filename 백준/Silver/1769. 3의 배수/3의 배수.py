import sys

def main():
    s = sys.stdin.readline().strip()
    cnt = 0
    while len(s) > 1:
        s = str(sum(int(ch) for ch in s))
        cnt += 1
        
    print(cnt)
    if int(s) % 3 == 0:
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    main()