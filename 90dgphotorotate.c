#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//sto programma paragontai treis pinakes twn red, green, blue xrwmatwn kai ystera peristrefontai 90 moires dhladh grammes se sthles 

#define ROWS 3
#define COLS 5

struct pixel {
    unsigned char red;//value range [0,255]
    unsigned char green;
    unsigned char blue;
};

//prwta allazeis sthles se grammes h to antitheto analogws thn periptwsh
void rotate_right_90(struct pixel img[][COLS], struct pixel tmp[][ROWS]);

int main() {
    int i, j;
    struct pixel img[ROWS][COLS], tmp[COLS][ROWS];//img og image kai tmp 90 degree image
    srand(time(NULL));
    //dhmiourgei tyxaia xrwmata
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            img[i][j].red = rand() % 256;//[0,255]
            img[i][j].green = rand() % 256;
            img[i][j].blue = rand() % 256;
        }
    }
    printf("*** OG IMAGE ***\n\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("(%3d,%3d,%3d)    ", img[i][j].red, img[i][j].green, img[i][j].blue);
        }
        printf("\n");
    }
    rotate_right_90(img, tmp);
    printf("\n*** rotated img ***\n\n");
    for (i = 0; i < COLS; i++) {
        for (j = 0; j < ROWS; j++) {
            printf("(%3d,%3d,%3d)    ", tmp[i][j].red, tmp[i][j].green, tmp[i][j].blue);
        }
        printf("\n");
    }
    return 0;
}

void rotate_right_90(struct pixel img[][COLS], struct pixel tmp[][ROWS]) {
    int i, j, k = 0;
    for (i = 0; i < ROWS - 1; i++) {//efoson grammes 3, tis metaxeirizesai ws 0,1,2, eksou kai ROWS-1
        for (j = 0; j < COLS; j++) {
            tmp[j][i] = img[k][j];//to k einai o metrhths gia tis grammes toy img[ROWS][COLS]
        }
        k++;
    }
}
