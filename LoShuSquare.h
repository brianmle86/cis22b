
#ifndef LoShuSquare_h
#define LoShuSquare_h

using namespace std;

class LoShuSquare {
    private:
        int number;
        int grid[3][3];
    public:
        LoShuSquare();
        ~LoShuSqaure();
        void fill(int row, int col, int num);
        bool checkRow();
        bool checkCol();
        bool checkDiag();
        void printGrid();
};

LoShuSquare::LoShuSquare() {
    grid = { {0, 0, 0},
             {0, 0, 0},
             {0, 0, 0} };
              
}

LoShuSquare::void fill(int row, int col, int num) {
    grid[row - 1][col - 1] = num;
}

LoShuSquare:: void printGrid(int array[][]) {
    cout << "==================================";
    for(int i = 0; i < 3; i++) {
        cout << endl;
        for(int j = 0; i < 3; i++) {
            cout << array[i][j] << " ";
        }
    }
    cout << endl
         << "==================================";
}
#endif
