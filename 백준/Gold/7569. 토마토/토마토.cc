#include "iostream"
#include "vector"
#include "queue"

#define ABS(X) ((X) >= 0 ? (X) : -(X))

using namespace std;

vector<vector<int> > P;
vector<int> days;
int N,M,H,front;
int v[101][101][101];

queue<int> bfs;

int Hash(int i,int j,int k){
    return (i-1)*M*N + (j-1)*N + k;
}

void Connect(int i1,int j1,int k1,int i2,int j2,int k2){
    if(i1 <= 0 || i2 <= 0 || j1 <= 0 || j2 <= 0 || k1 <= 0 || k2 <= 0 || i1 > H || i2 > H || j1 > M || j2 > M || k1 > N || k2 > N) return;
    if(v[i1][j1][k1] == -1 || v[i2][j2][k2] == -1) return;
    
    int h1 = Hash(i1,j1,k1),h2 = Hash(i2,j2,k2);
    // std::cout << "connect: " << h1 << " " << h2 << "\n";
    P[h1].emplace_back(h2);
}

void ConnectNeighbor(int i,int j,int k){
    for(int dx = -1;dx <= 1;++dx){
        for(int dy = -1;dy <= 1;++dy){
            for(int dz = -1;dz <= 1;++dz){
                if(ABS(dx) + ABS(dy) + ABS(dz) == 1){
                    Connect(i,j,k,i+dz,j+dy,k+dx);
                }
            }
        }
    }
}

int m = -1;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  
    cin >> N >> M >> H;
    P.resize(N*M*H+1);
    days.resize(N*M*H+1);
    for(int i=1;i<=H;++i){
        for(int j=1;j<=M;++j){
            for(int k=1;k<=N;++k){
                cin >> v[i][j][k];
            }
        }
    }

    // std::cout << "board\n";
    // for (int i = 1; i <= H; i++) {
    //     for (int j = 1; j <= M; j++) {
    //         for (int k = 1; k <= N; k++) {
    //             std::cout << v[i][j][k] << " ";
    //         }
    //         std::cout << "\n";
    //     }
    //     std::cout << "\n";
    // }

    for(int i=1;i<=H;++i){
        for(int j=1;j<=M;++j){
            for(int k=1;k<=N;++k){
                ConnectNeighbor(i,j,k);
                if(v[i][j][k] == 1){
                    bfs.push(Hash(i,j,k));
                    days[Hash(i,j,k)] = 0;
                }
                else if(!v[i][j][k]) days[Hash(i,j,k)] = -1;
                else days[Hash(i,j,k)] = -2;
            }
        }
    }
    while(!bfs.empty()){
        front = bfs.front();
        // std::cout << "bfs node: " << front << "\n";
        bfs.pop();
        for(int _v : P[front]){
            // std::cout << "nxt: " << _v << "\n";
            if(days[_v] == -1) {
                days[_v] = days[front] + 1;
                bfs.push(_v);
            }
        }
    }
    for(int i=1;i<=N*M*H;++i){
        if(days[i] != -2){
            if(days[i] == -1){
                m = -1;
                break;
            }
            m = max<int>(m,days[i]);
        }
    }
    cout << m;
}