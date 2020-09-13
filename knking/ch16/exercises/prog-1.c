#include <stdio.h>
#include <string.h>

struct dialing_code {
   char *country;
   int code;
};


const struct dialing_code country_code[] = {
   {"Argentina",           54}, {"Bangladesh",        880},
   {"Brazil",              55}, {"Burma (Myanmar)",   95},
   {"China",               86}, {"Colombia",          57},
   {"Congo, Dem. Rep. of", 243},{"Egypt",             20},
   {"Ethiopia",            251},{"France",            33},
   {"Germany",             49},{"India",              91},
   {"Indonesia",           62},{"Iran",               98},
   {"Italy",               39},{"Japan",              81},
   {"Mexico",              52},{"Nigeria",            234},
   {"Pakistan",            92},{"Philippines",        63},
   {"Poland",              48},{"Russian",            7},
   {"South African",       27},{"South Korea",        82},
   {"Spain",               34},{"Sudan",              249},
   {"Thailand",            66},{"Turkey",             90},
   {"Ukraine",             380},{"United Kingdom",    44},
   {"United States",       1},{"Vietnam",             84}
};

int main(void)
{
   int code;
   printf("Enter a country code: ");
   scanf(" %d", &code);

   int index = -1;
   for (int i = 0, len = (sizeof(country_code) / sizeof(country_code[0])); i < len; i++) {
      if (code == country_code[i].code) {
         index = i;
         break;
      }
   }

   if (index >= 0) {
      printf("Code %d is for %s\n", code, country_code[index].country);
   } else {
      printf("Code %d does not belong to any country\n", code);
   }

   return 0;
}