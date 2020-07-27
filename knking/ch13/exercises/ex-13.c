void build_index_url(const char* domain, char *index_url)
{
   strcpy(index_url, "http://www.");
   strcat(index_url, domain);
   strcat(index_url, "/index.html");
}

int main(void)
{
   char index[50];
   build_index_url("knking.com", index);
   printf("index url = %s\n", index);

   return 0;
}