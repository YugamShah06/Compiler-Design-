#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 10

char grammar[MAX][MAX];
char leading[MAX][MAX], trailing[MAX][MAX];
int numRules;

void findLeading(char nt, char result[MAX]) {
    for (int i = 0; i < numRules; i++) {
        if (grammar[i][0] == nt) {
            for (int j = 2; grammar[i][j] != '\0'; j++) {
                if (!isupper(grammar[i][j])) {
                    if (!strchr(result, grammar[i][j])) {
                        strncat(result, &grammar[i][j], 1);
                    }
                    break;
                }
            }
        }
    }
}

void findTrailing(char nt, char result[MAX]) {
    for (int i = 0; i < numRules; i++) {
        if (grammar[i][0] == nt) {
            int len = strlen(grammar[i]);
            for (int j = len - 1; j >= 2; j--) {
                if (!isupper(grammar[i][j])) {
                    if (!strchr(result, grammar[i][j])) {
                        strncat(result, &grammar[i][j], 1);
                    }
                    break;
                }
            }
        }
    }
}

int main() {
    printf("Enter the number of grammar rules: ");
    scanf("%d", &numRules);
    getchar();

    printf("Enter the grammar rules (Format: A=xyz):\n");
    for (int i = 0; i < numRules; i++) {
        fgets(grammar[i], MAX, stdin);
        grammar[i][strcspn(grammar[i], "\n")] = 0;
    }

    for (int i = 0; i < numRules; i++) {
        char nt = grammar[i][0];
        char leadingSet[MAX] = "";
        char trailingSet[MAX] = "";
        findLeading(nt, leadingSet);
        findTrailing(nt, trailingSet);

        printf("LEADING(%c) = { %s }\n", nt, leadingSet);
        printf("TRAILING(%c) = { %s }\n", nt, trailingSet);
    }

    return 0;
}
