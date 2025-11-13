import sys

def main():
    A = int(sys.stdin.readline().strip())
    op = sys.stdin.readline().strip()
    B = int(sys.stdin.readline().strip())
    
    if op == '+':
        print(A + B)
    else:
        print(A * B)
        
if __name__ == "__main__":
    main()