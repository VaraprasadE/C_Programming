#include<stdio.h>
typedef enum Color{
    RED,
    GREEN,
    BLUE
} Color;

int main() {
    Color selectedColor = RED;
    switch(selectedColor) {
        case RED:
            printf("Selected Color: RED\n");
            break;
        case GREEN:
            printf("Selected Color: GREEN\n");
            break;
        case BLUE:
            printf("Selected Color: BLUE\n");
            break;
        default:
            printf("Unknown Color\n");
    }

    return 0;
}