struct pinball_machine
{
   char name[40];
   int year;
   enum type { EM, SS};
   int players;
};