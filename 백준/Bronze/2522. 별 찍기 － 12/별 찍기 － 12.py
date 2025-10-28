import sys

def main():
    N = int(sys.stdin.readline().strip())
    
    lines = []
    for i in range(1, N + 1):
        lines.append(' ' * (N - i) + '*' * i)
        
    for i in range(N - 1, 0, -1):
        lines.append(' ' * (N - i) + '*' * i)

    for line in lines:
        print(line)

if __name__ == "__main__":
    main()