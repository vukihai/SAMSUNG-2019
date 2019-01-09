#include<iostream>
#include<vector>
using namespace std;
const char DIRECTION[] = "NESW";
int FORWARD[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int board[51][51] = {0};
int xMax, yMax;
struct Bot {
	int x, y;
	int direction;
	bool lost = false;
	Bot(int _x, int _y, char _d) {
		x = _x;
		y = _y;
		direction = _d;
	}
	bool go(char _action) {
	//	cout << "--test: " << _action << direction << x << y <<endl;
		if(_action == 'F') {
			int newx = x + FORWARD[direction][0];
			int newy = y + FORWARD[direction][1];
			if(isLost(newx, newy)) {
				if(board[x][y] == 0){
					board[x][y] =1;
					lost = true;
					return false;
				}
				else return true;
			} else {
				x = newx;
				y = newy;
			}
		}
		if(_action == 'R') direction++; if(direction ==4) direction = 0;
		if(_action == 'L') direction--; if(direction ==-1) direction = 3;
		return true;
	}
	bool isLost(int _x, int _y) {
		if(_x > xMax || _x < 0 ) return true;
		if(_y > yMax || _y < 0 ) return true;
		return false;
	}
};
int main() {
	cin >> xMax >> yMax;
	int xbot, ybot;
	char dbot;
	string s;
	while(cin >> xbot) {
		cin >> ybot >> dbot;
		int dbot1;
		if(dbot=='N') dbot1 = 0;
		if(dbot=='E') dbot1 = 1;
		if(dbot=='S') dbot1 = 2;
		if(dbot=='W') dbot1 = 3;
		Bot b(xbot, ybot, dbot1);
		cin >> s;
		for(int i=0; i<s.length(); i++) {
			if(!b.go(s[i])) break;
		}
		cout << b.x <<' ' << b.y << ' ' << DIRECTION[b.direction];
		if(b.lost) cout <<" LOST";
		cout <<endl;
	}
	return 0;
}
