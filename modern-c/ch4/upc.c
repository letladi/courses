#include <stdio.h>

int main(void)
{
  int first_num, first_sum, second_sum, total, remainder, check_num;
  int manufacId[5] = {0};
  int productId[5] = {0};

  printf("Enter the first (single) digit: ");
  scanf("%1d", &first_num);

  printf("Enter the first group of five digits: ");
  scanf("%1d%1d%1d%1d%1d", &manufacId[0], &manufacId[1], &manufacId[2], &manufacId[3], &manufacId[4]);

  printf("Enter second group of five digits: ");
  scanf("%1d%1d%1d%1d%1d", &productId[0], &productId[1], &productId[2], &productId[3], &productId[4]);

  first_num = first_num + manufacId[1] + manufacId[3] + productId[0] + productId[2] + productId[4];
  second_sum = manufacId[0] + manufacId[2] + manufacId[4] + productId[1] + productId[3];
  total = ((first_num * 3) + second_sum) - 1;
  check_num = 9 - (total % 10);

  printf("Check digit: %d\n", check_num);
}
