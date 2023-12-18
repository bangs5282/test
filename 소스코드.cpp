#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> input;

class Position {

public:

    int x;
    int y;

    Position(int _x, int _y) : x(_x), y(_y) {}

    bool operator==(Position& pos) {
        if (pos.x == x && pos.y == y)
            return true;
        
        return false;
    }

    bool operator!=(Position& pos) {
        if (pos.x != x || pos.y != y)
            return true;

        return false;
    }

    bool isRight()
    {
        if (x < 0 || x > 4)
            return false;
        
        if (y < 0 || y > 4)
            return false;

        return true;
    }

    int getValue() {
        return input[y][x] - '0';
    }

};
Position startPosition = { 0, 4 };
Position endPosition = { 4, 0 };

int answer = -1;



void init()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    // 구역 정보 입력
    input.push_back({ '2', '0', '1', '1', 'F'});
    input.push_back({ '1', '2', '0', '2', '3'});
    input.push_back({ '2', '2', '0', '2', '1'});
    input.push_back({ '3', '1', '0', '2', '0'});
    input.push_back({ 'S', '0', '1', '3', '0'});
}



// nowPosition : 현재의 위치
// sum : 지금까지 줍게된 캔디

void algorithm(Position nowPosition, int sum)   
{

    // 위치가 구역의 크기보다 작거나 클때의 오류 예방
    if (!nowPosition.isRight())
        return;


    // 끝 구역에 도달할때
    if (nowPosition == endPosition) {

        answer = max(answer, sum);  // answer에 저장된 값과 주워온 사탕의 값중 더 큰값을 answer에 저장
        return;

    }
    


    // 지금의 위치가 시작지점이 아니라면 사탕을 줍는다
    if(nowPosition != startPosition)
        sum += input[nowPosition.y][nowPosition.x] - '0';



    // 오른쪽으로 이동
    algorithm({ nowPosition.x + 1, nowPosition.y }, sum);


    // 위로 이동
    algorithm({ nowPosition.x, nowPosition.y - 1 }, sum);
}



void print()
{
    // 정답 출력
    cout << answer << endl;
}



int main() {

    init();
    algorithm(startPosition, 0);
    print();

    return 0;
}
