#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    char lines[N][25];   // not 2D result array, just input storage
    int final_len[N];    // final lengths after fixing a-count

    int maxlen = 0;

    // Read and process each line
    for (int i = 0; i < N; i++) {
        scanf("%s", lines[i]);

        int len = strlen(lines[i]);
        int cnt = len - 1;   // number of 'a'

        // Fix odd count
        if (cnt % 2 == 1) {
            cnt--;
            if (cnt == 0) cnt = 2;
        }

        final_len[i] = cnt + 1; // length = b + a's

        if (final_len[i] > maxlen)
            maxlen = final_len[i];
    }

    // Print final centered lines
    for (int i = 0; i < N; i++) {

        int spaces = (maxlen - final_len[i]) / 2;

        // print leading spaces
        for (int s = 0; s < spaces; s++)
            printf(" ");

        // print result string
        printf("b");
        for (int j = 0; j < final_len[i] - 1; j++)
            printf("a");

        printf("\n");
    }

    return 0;
}
