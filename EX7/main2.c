#include <stdio.h>
#include <stdlib.h>

typedef struct Books {
    int id;
    int price;
    char title[100];
} book_t;

void total_price(const book_t books[], int count) {
    long long sum = 0;
    for (int i = 0; i < count; i++) {
        sum += books[i].price;
    }
    printf("\nTotal Price: %lld\n", sum);
}

void list_books(const book_t books[], int count) {
    printf("%-10s %-12s %-55s\n", "Id (int)", "Price (int)", "Title (string)");
    printf("-------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-12d %-55s\n", books[i].id, books[i].price, books[i].title);
    }
}

int main(void) {
    book_t books[6] = {
        {1, 1000, "All the Light We Cannot See"},
        {2, 300,  "The 38 Letters from J.D. Rockefeller to his son"},
        {3, 1000, "The Ballad of Songbirds and Snakes"},
        {4, 550,  "Killers of the Flower Moon"},
        {5, 870,  "Elon Musk"},
        {6, 1344, "Milk and Honey 12-Month 2024"}
    };

    int count = 6;

    list_books(books, count);
    total_price(books, count);

    FILE *fp = fopen("Book.bin", "wb");
    if (fp == NULL) {
        printf("Failed to open Book.bin for writing.\n");
        return 1;
    }

    size_t written = fwrite(books, sizeof(book_t), count, fp);
    fclose(fp);

    if (written != (size_t)count) {
        printf("Warning: only %zu of %d records written to Book.bin.\n", written, count);
        return 1;
    }

    printf("Saved %d books to Book.bin successfully.\n", count);

    return 0;
}
