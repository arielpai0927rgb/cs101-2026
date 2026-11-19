#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generate_set(int arr[7]) {
    int pool[69];
    for (int i = 0; i < 69; i++) {
        pool[i] = i + 1;
    }

    for (int i = 68; i > 0; i--) {
        int j = rand() % (i + 1);
        int tmp = pool[i];
        pool[i] = pool[j];
        pool[j] = tmp;
    }

    for (int i = 0; i < 7; i++) {
        arr[i] = pool[i];
    }

    for (int i = 0; i < 6 - 1; i++) {
        for (int j = 0; j < 6 - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int main(void) {
    int n;

    printf("歡迎光臨長庚樂透彩購買機台\n");
    do {
        printf("請問您要買幾組樂透彩：");
        if (scanf("%d", &n) != 1) {
            return 1;
        }
        if (n < 1 || n > 5) {
            printf("請輸入 1 到 5 之間的整數！\n");
        }
    } while (n < 1 || n > 5);

    srand((unsigned int)time(NULL));

    FILE *fp = fopen("lotto.txt", "w");
    if (fp == NULL) {
        printf("無法開啟 lotto.txt 進行寫入！\n");
        return 1;
    }

    time_t now = time(NULL);
    char *time_str = ctime(&now);
    // 移除 ctime 字串結尾的 '\n'，方便對齊排版
    if (time_str != NULL) {
        size_t len = strlen(time_str);
        if (len > 0 && time_str[len - 1] == '\n') {
            time_str[len - 1] = '\0';
        }
    }

    fprintf(fp, "========= lotto649 =========\n");
    fprintf(fp, "= %s =\n", time_str ? time_str : "Unknown Time");

    for (int i = 1; i <= 5; i++) {
        fprintf(fp, "[%d]: ", i);
        if (i <= n) {
            int nums[7];
            generate_set(nums);
            for (int k = 0; k < 7; k++) {
                fprintf(fp, "%02d", nums[k]);
                if (k < 6) {
                    fprintf(fp, " ");
                }
            }
        } else {
            for (int k = 0; k < 7; k++) {
                fprintf(fp, "--");
                if (k < 6) {
                    fprintf(fp, " ");
                }
            }
        }
        fprintf(fp, "\n");
    }

    fprintf(fp, "========= csie@CGU =========\n");
    fclose(fp);

    printf("以為您購買的 %d 組樂透組合輸出至 lotto.txt\n", n);

    return 0;
}
