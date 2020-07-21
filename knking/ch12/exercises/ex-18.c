// @comment: value of K and k not provided

int evaluate_position(char board[8][8])
{
   int white_sum = 0;
   int black_sum = 0;

   for (char *i = &board[0][0], *end = &board[0][0] + (8 * 8); i < end; i++) {
      switch(*i) {
         // case 'K': white_sum +=
         case 'Q': white_sum += 9; break;
         case 'R': white_sum += 5; break;
         case 'B': white_sum += 3; break;
         case 'N': white_sum += 3; break;
         case 'P': white_sum += 1; break;
         // case 'k': black_sum += 
         case 'q': black_sum += 9; break;
         case 'r': black_sum += 5; break;
         case 'b': black_sum += 3; break;
         case 'n': black_sum += 3; break;
         case 'p': black_sum += 1; break;
      }
   }
   return white_sum > black_sum ? (white_sum - black_sum) : (white_sum - black_sum);
}