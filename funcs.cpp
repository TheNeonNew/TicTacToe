#include <iostream>

using namespace std;

int board[9];
bool SetX = true;

int gv(int index) {
	return board[index];
}

void sv(int index, int value) {
	if (index <= 8) board[index] = value;
}

void DrawField() {
	cout << "------------" << endl;
	cout << ' ';
	for (int i = 0; i < 9; i++) {
		switch(board[i]) {
			case 0: 
				cout << ' ';
				break;
			case 1:
				cout << 'X';
				break;
			case 2:
				cout << 'O';
				break;
		}
		cout << " | ";
		if (i == 2 || i == 5 || i == 8) cout << '\n' << "------------" << endl << ' ';
		
	}
}

bool Win() {
	bool diag = board[0] != 0 && board[4] != 0 && board[8] != 0;
	for (int i = 0; i < 3; ++i) {
        if ((board[i*3] != 0) && (board[i*3] == board[i*3+1]) 
                        && (board[i*3+1] == board[i*3+2])) {
            return true;
        }
        if ((board[i] != 0) && (board[i] == board[i+3]) 
                        && (board[i+3] == board[i+6])) {
            return true;
        }            
    }
    if ((board[4] != 0) && (board[0] == board[4]) 
                        && (board[4] == board[8])) {
        return true;
    }
    if ((board[4] != 0) && (board[2] == board[4]) 
                        && (board[4] == board[6])) {
        return true;
    }        
    return false;
}

void TurnExec() {
	int input;
	char sign = SetX ? 'X' : 'O';
	cout << "Insert number where you wanna put (from 0 to 8) " << sign << '\t';
	cin >> input;
	if (SetX) sv(input, 1);
	else sv(input, 2);
	SetX = !SetX;
}

int main() {
	while (!(Win())) {
		TurnExec();
		DrawField();
	}
	char sign = !SetX ? 'X' : 'O';
	cout << '\n' << sign << " Wins" << endl;
	
}
