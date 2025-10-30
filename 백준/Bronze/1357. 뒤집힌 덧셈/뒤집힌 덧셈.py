import sys

def main():
    X, Y = map(str, sys.stdin.readline().split())
    
    rev_X = ''.join(reversed(X))
    rev_Y = ''.join(reversed(Y))

    rev_sum = int(rev_X) + int(rev_Y)
    ans = int(''.join(reversed(str(rev_sum))))
    print(ans)

if __name__ == "__main__":
    main()