#include <iostream>

//- Point 구조체 2개를 메모리 할당하여 생성하세요.
//- 임의의 값 x, y를 채우고, addPoint함수를 호출하여 두 Point 덧셈을 하세요.
//- addPoint 함수 안에서는 새로운 Point 구조체를 메모리 할당해야 하고 이를 반환해야 합니다.
//- 생성한 포인트 구조체를 출력하고 덧셈 결과도 출력하세요.
//- 생성한 구조체를 메모리 해제하세요.


using namespace std;

Point& addPoint(const Point& p1, const Point& p2);

typedef struct _Point {
    int x;
    int y;
}Point;


int main() {

    Point *a;

    a = new Point[3];

    a[0] = { 20, 30 };
    a[1] = { 30, 40 };

   a[3] =  addPoint(a[0],a[1]);

   cout << a[3].x << endl;
   cout << a[3].y << endl;

   delete a;

    return 0;
}

Point& addPoint(const Point& p1, const Point& p2) {
    Point& temp;

    temp.x = p1.x + p2.x;
    p1.y + p2.y;

    
}
