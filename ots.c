#include <stdio.h>
#include <string.h>

void push(char *stack, char string, int *top) {
  (*top)++;
  stack[(*top)] = string;
}

char pop(char *stack, int *top) {
  char value = stack[(*top)];
  (*top)--;
  return value;
}

int checkChar(char char1, char char2) {
  if (char1 == '(' && char2 == ')') {
    return 1;
  } else if (char1 == '[' && char2 == ']') {
    return 1;
  } else if (char1 == '{' && char2 == '}') {
    return 1;
  }
  
  return 0;
}

char * isBalanced(char *string) {
  int length = strlen(string);
  int top = -1;
  char stack[length];

  for (int i = 0; i < length; i++) {
    if (string[i] == '(' || string[i] == '[' || string[i] == '{') {
      push(stack, string[i], &top);
    } else {
      if (top == -1 || !checkChar(pop(stack, &top), string[i])) {
        return "NO";
      }
    }
  }

  if (top == -1) {
    return "YES";
  } else {
    return "NO";
  }
}

int main(int argc, char const *argv[]) {
  char string[10];
  scanf("%s", &string);

  char *result = isBalanced(string);

  printf("%s", result);
  
  return 0;
}