#include <stdio.h>

#define MEMORY_SIZE 30000

int main() {
    char memory[MEMORY_SIZE] = {0};
    char *ptr = memory;
    char code[] = "++++++++++[>++++++++++<-]>.";

    for (int i = 0; code[i]; i++) {
        switch (code[i]) {
            case '>':
                ptr++;
                break;
            case '<':
                ptr--;
                break;
            case '+':
                (*ptr)++;
                break;
            case '-':
                (*ptr)--;
                break;
            case '.':
                putchar(*ptr);
                break;
            case ',':
                *ptr = getchar();
                break;
            case '[':
                if (*ptr == 0) {
                    i++;
                    while (code[i] != ']' || code[i - 1] == '[') {
                        if (code[i] == '[') {
                            i++;
                        } else if (code[i] == ']') {
                            i--;
                        }
                        i++;
                    }
                }
                break;
            case ']':
                if (*ptr != 0) {
                    i--;
                    while (code[i] != '[' || code[i - 1] == ']') {
                        if (code[i] == ']') {
                            i--;
                        } else if (code[i] == '[') {
                            i++;
                        }
                        i--;
                    }
                    i--;
                }
                break;
        }
    }

    return 0;
}
