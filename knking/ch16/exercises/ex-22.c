
enum chess_pieces {KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN};
// a)
/**
int piece_value[6] = {
   200, 9, 5, 3, 3, 1
};
*/
// b)
int piece_value[6] = {
   [KING] = 200,
   [QUEEN] = 9,
   [ROOK] = 5,
   [BISHOP] = 3,
   [KNIGHT] = 3,
   [PAWN] = 1
};