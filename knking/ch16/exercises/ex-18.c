
// a)
enum Color { BLACK, WHITE};
enum Piece { EMPTY, BISHOP, PAWN, KNIGHT, ROOK, QUEEN, KING };
// b)
typedef struct {
   enum Color color;
   enum Piece piece;
} Square;
// c)
Square board[8][8] = {
   [0] = { {BLACK, ROOK}, {BLACK, KNIGHT}, {BLACK, BISHOP}, {BLACK, QUEEN}, {BLACK, KING}, {BLACK, BISHOP}, {BLACK, KNIGHT}, {BLACK, ROOK} },
   [1] = { {BLACK, PAWN}, {BLACK, PAWN}, {BLACK, PAWN}, {BLACK, PAWN}, {BLACK, PAWN}, {BLACK, PAWN}, {BLACK, PAWN}, {BLACK, PAWN} },
   [6] = { {WHITE, PAWN}, {WHITE, PAWN}, {WHITE, PAWN}, {WHITE, PAWN}, {WHITE, PAWN}, {WHITE, PAWN}, {WHITE, PAWN}, {WHITE, PAWN} },
   [7] = { {WHITE, ROOK}, {WHITE, KNIGHT}, {WHITE, BISHOP}, {WHITE, QUEEN}, {WHITE, KING}, {WHITE, BISHOP}, {WHITE, KNIGHT}, {WHITE, ROOK} }
};
// d)

int main(void) 
{
   Square empty_square = { BLACK, EMPTY };
   for (int i = 2; i <= 5; i++) {
      for (int j = 0; j < 8; j++) {
         board[i][j] = empty_square;
      }
   }

   return 0;
}
