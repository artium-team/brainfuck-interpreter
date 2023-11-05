#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMORY_SIZE 30000

char* readFile(char* filename) {
    FILE* file = fopen(filename,"r");
    if(file == NULL) {
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    long int size = ftell(file);
    rewind(file);
    char* content = calloc(size + 1, 1);
    fread(content,1,size,file);
    return content;
}

int main(int argc, char *argv[]) {
    char memory[MEMORY_SIZE] = {0};
    char *ptr = memory;

    if (argc != 2) {
        printf ("Wrong input!");
        return 0;
    }
    char *code = readFile(argv[1]);

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
