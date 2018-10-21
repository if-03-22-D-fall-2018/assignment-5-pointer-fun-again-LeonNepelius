#include <stdio.h>

struct PlayStruct
{
  int int_value;
  double double_value;
  char a_string[64];
};

void print_struct(struct PlayStruct,struct PlayStruct*);
void change_struct(struct PlayStruct,struct PlayStruct*);
void print_string(char string_to_print[]);
void change_string(char string1[], char* p_string[]);

int main(int argc, char const *argv[]) {
  struct PlayStruct play_struct = {0,0.0,"Hi"};
  struct PlayStruct* pps = &play_struct;
  char another_string[16] = "Hello";
  char* p_another_string = another_string;
  print_struct(play_struct,pps);
  change_struct(play_struct,pps);
  // The pointer to ps will change the values
  // and play_struct wont write it because the function will be teterminated before
  print_struct(play_struct,pps);
  print_string(play_struct.a_string);
  change_string(play_struct.a_string,&p_another_string);
  print_string(play_struct.a_string);
  print_string(p_another_string);
  return 0;
}

void print_struct(struct PlayStruct ps,struct PlayStruct* pps) {
  printf("Values of struct ps: %d, %f, %s\n",ps.int_value,ps.double_value,ps.a_string );
  printf("Values of struct ps: %d, %f, %s\n\n",pps->int_value,pps->double_value,pps->a_string );
}
void change_struct(struct PlayStruct ps,struct PlayStruct* pps)
{
  ps.int_value = 99;
  pps->int_value = 88;
}

void print_string(char string_to_print[])
{
  printf("string_to_print: %s\n",string_to_print );
}
void change_string(char string1[], char* p_string[])
{
  string1[2] = 0;
  p_string[1] = 0;
}
