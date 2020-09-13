#include <stdio.h>
#include <string.h>

void new_cmd() { printf("new_cmd\n"); }
void open_cmd() { printf("open_cmd\n"); }
void close_cmd() { printf("close cmd\n"); }
void close_all_cmd() { printf("close all cmd\n"); }
void save_cmd() { printf("save cmd\n"); }
void save_as_cmd() { printf("save as cmd\n"); }
void save_all_cmd() { printf("save all cmd\n"); }
void print_cmd() { printf("print cmd\n"); }
void exit_cmd() { printf("exit cmd\n"); }

struct {
   char *cmd_name;
   void (*cmd_pointer)(void);
} file_cmd[] = {
   {"new", new_cmd},
   {"open", open_cmd},
   {"close", close_cmd},
   {"close all", close_all_cmd},
   {"save", save_cmd},
   {"save as", save_as_cmd},
   {"save all", save_all_cmd},
   {"print", print_cmd},
   {"exit", exit_cmd}
};

void call_cmd(char cmd[])
{
   for (int i = 0, end = sizeof(file_cmd)/sizeof(file_cmd[0]); i < end; i++) {
      if (strcmp(file_cmd[i].cmd_name, cmd) == 0) {
         file_cmd[i].cmd_pointer();
         break;
      }
   }
}

int main(void)
{  
   call_cmd("close");
   return 0;
}