'''
픽의 정리
넓이 = (변 위의 점의 개수)/2 + (내부의 점의 개수) - 1

다각형의 넓이: 신발끈 공식
1/2 * |(x1y2 - x2y1) + (x2y3 - x3y2) + (x3y4 - x4y3) + ... (xny1 - x1yn)|

선분 위의 좌표가 정수인 점의 개수: GCD
gcd(dx, dy) + 1 (양끝점 포함)

하나라도 모르면 굉장히 골치아플 것 같다
'''

import sys
import math

def main():
    N = int(sys.stdin.readline().strip())
    
    on_segment_points = 0
    area = 0
    li = []
    for _ in range(N):
        x, y = map(int, sys.stdin.readline().split())
        li.append((x, y))

    px, py = li[0]
    for i in range(1, N):
        cx, cy = li[i]
        area += (px * cy - cx * py)
        on_segment_points += math.gcd(cx - px, cy - py)

        px, py = cx, cy

    # n번째 점과 첫 번째 점 연결
    area += (px * li[0][1] - li[0][0] * py)
    on_segment_points += math.gcd(li[0][0] - px, li[0][1] - py)
    
    area = abs(area)
    
    ans = (area - on_segment_points + 2) / 2
    print(int(ans))

if __name__ == "__main__":
    main()