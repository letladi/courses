#include <stdio.h>

// a)
enum {NUL, SOH, STX, ETX}; // NUL = 0, SOH = 1, STX = 2, ETX = 3
// b)
enum {VT = 11, FF, CR}; // VT = 11, FF = 12, CR = 13
// c)
enum {SO = 14, SI, DLE, CAN =  24, EM}; // SO = 14, SI = 15, DLE = 16, CAN = 24, EM = 25
// d)
enum {ENQ = 45, ACK, BEL, LF = 37, ETB, ESC}; // ENQ = 45, ACK = 46, BEL = 47, LF = 37, ETB = 38, ESC = 39

int main(void)
{
   printf("NUL = %d, SOH = %d, STX = %d, ETX = %d\n", NUL, SOH, STX, ETX);
   printf("VT = %d, FF = %d, CR = %d\n", VT, FF, CR);
   printf("SO = %d, SI = %d, DLE = %d, CAN = %d, EM = %d\n", SO, SI, DLE, CAN, EM);
   printf("ENQ = %d, ACK = %d, BEL = %d, LF = %d, ETB = %d, ESC = %d\n", ENQ, ACK, BEL, LF, ETB, ESC);

   return 0;
}