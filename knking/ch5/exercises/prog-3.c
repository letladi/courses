#include <stdio.h>

int main(void)
{
   float commission, value, price, units;

   printf("Enter the number of shares: ");
   scanf("%f", &units);
   printf("Enter the price per share: ");
   scanf("%f", &price);
   
   value = units * price;

   if (value < 2500.0f) 
      commission = 30.00f + 0.17f * value;
   else if (value < 6250.00f)
      commission = 56.00f + 0.0066f * value;
   else if (value < 20000.00f)
      commission = 76.00f + 0.0034f * value;
   else if (value < 50000.00f)
      commission = 100.00f + 0.0022f * value;
   else if (value < 500000.00f)
      commission = 155.00f + 0.0011f * value;
   else  
      commission = 255.00f + 0.0009f * value;

   if (commission < 39.00f)   
      commission = 39.00f;

   float rival_commission;

   if (units < 2000.00f) rival_commission = 33 + 0.03 * units;
   else rival_commission = 33 + 0.02 * units;

   printf("Commission: $%.2f\n", commission);
   printf("[rival commission is: $%.2f]\n", rival_commission);
   
   return 0;
}