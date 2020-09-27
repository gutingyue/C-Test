#include <iostream>
#include <vector>
using namespace std;

//蛇形方阵
vector<vector<int>> Snack(int n){
	vector<vector<int>> ret(n, vector<int>(n, 0));

	int flag = 1;//1顺时针  -1逆时针
	int N = n;

	int x = 0;
	int	y = 0;
	int count = 0;
	for (int i=1; i <= (n*n);){
		if (count==(N - 1) * 4){
			if (flag == 1)
				y++;
			else
				x++;
			flag *= -1;
			N -= 2;
			count = 0;
		}

		if (N == 1){
			ret[x][y] = n*n;
			break;
		}

		if (flag == 1){
			for (; y < ret.size() && ret[x][y] == 0; y++){
				ret[x][y] = i++;
				count++;
			}
			y--;
			x++;
			for (; x < ret.size() && ret[x][y] == 0; x++){
				ret[x][y] = i++;
				count++;
			}
			x--;
			y--;
			for (; y>=0 && ret[x][y] == 0; y--){
				ret[x][y] = i++;
				count++;
			}
			y++;
			x--;
			for (; x>0 && ret[x][y] == 0; x--){
				ret[x][y] = i++;
				count++;
			}
			x++;
		}
		else{
			for (; x < ret.size() && ret[x][y] == 0;x++){
				ret[x][y] = i++;
				count++;
			}
			x--;
			y++;
			for (; y < ret.size() && ret[x][y] == 0; y++){
				ret[x][y] = i++;
				count++;
			}
			y--;
			x--;
			for (; x>0 && ret[x][y] == 0; x--){
				ret[x][y] = i++;
				count++;
			}
			x++;
			y--;
			for (; y>0 && ret[x][y] == 0; y--){
				ret[x][y] = i++;
				count++;
			}
			y++;
		}
	}
	return ret;
}

int main(){
	int C;
	cin >> C;
	while (C){
		int N;
		cin >> N;
		vector<vector<int>> Table = Snack(N);

		int M;
		cin >> M;
		vector<int>out(M * 2, 0);
		for (int i = 0; i < out.size(); i++){
			cin >> out[i];
		}

		for (int i = 0; i < out.size();){
			cout << Table[out[i]][out[i+1]] << endl;
			i += 2;
		}
		C--;
	}
	


	return 0;
}