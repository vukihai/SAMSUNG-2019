#include<iostream>
using namespace std;

struct robot{
	int x, y, d;
	robot(int _x, int _y, int _d) {
		x = _x;
		y = _y;
		d = _d;
		neighbours[1][1] = 9;
	}
	int neighbours[3][3];
	int dTox[8] = {1, 0, 0, 0, 1, 2, 2, 2};
	int dToy[8] = {2, 2, 1, 0, 0, 0, 1, 2};
};
int main() {
	int rx, ry, rd;
	while(1) {
		cin >> rx;
		if(rx == -1) break;
		cin >> ry >> rd;
		robot b(rx, ry, rd);
		for(int i=0; i<8; i++) {
			int nx, ny, ns;
			cin >> nx >> ny >> ns;
			b.neighbours[nx-b.x+1][ny-b.y+1] = ns;
		}
		
		b.d -= 2; if(b.d <0) b.d += 8;
		while(!b.neighbours[b.dTox[b.d]][b.dToy[b.d]]) {
	//		cout <<b.d <<" -----------" <<endl;
			b.d++; if(b.d >7) b.d -= 8;
		}
		cout <<b.d <<endl;
//		cout << b.neighbours[b.dTox[1]][b.dToy[1]];
//		for(int i=2; i>=0; i--) {
//			for(int j=2; j>=0; j--) {
//				cout <<b.neighbours[j][i] << ' ';
//			}
//			cout <<endl;
//		}
	}
	
	return 0;
}
