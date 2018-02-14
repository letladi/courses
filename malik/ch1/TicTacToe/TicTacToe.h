class TicTacToe {
public:
    void printBoard();
    TicTacToe();
    void play();
    void move(int point);
    bool isOver();
private:
    char board[3][3];
    char player1Symbol;
    char player2Symbol;
    int moveCount;
    static const int MAX_MOVES = 9;
    static const int INVALID_MOVE = 0;
    void getIndexes(int pointSelected, int& row, int& col);
    bool playerWon(const char playerToken) const;
    bool isDraw() const;
    void getMove(int& move) const;
};