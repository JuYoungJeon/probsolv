#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;
int visited[100][100];

//returns size of the area
int dfs(int m, int n, int y, int x, vector<vector<int>> picture){
    if(visited[y][x]) return 0;
    int dir[4][2]={{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    visited[y][x]=true;
    int size=1;
    for(int i=0; i<4; i++){
        int ny=y+dir[i][0];
        int nx=x+dir[i][1];
        if(ny<m && nx<n &&ny>=0 && nx>=0&&picture[ny][nx]==picture[y][x]){
            size+=dfs(m, n, ny, nx, picture);
        }
    }
    return size;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int numArea=0;
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    memset(visited, 0, sizeof(visited));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(picture[i][j]!=0) {
                if(!visited[i][j])number_of_area+=1;
                max_size_of_one_area =max(max_size_of_one_area, dfs(m, n, i, j, picture));
                
            }
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
