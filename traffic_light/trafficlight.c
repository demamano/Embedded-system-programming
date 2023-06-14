#include <reg51.h>

sbit red = P1^0;
sbit yellow = P1^1;
sbit green = P1^2;

void main() {
    unsigned int i;
    red = yellow = green = 0;

    while (1) {
        red = 1;

        for (i = 0; i < 60000; i++);  // Faster delay

        red = 0;
        yellow = 1;

        for (i = 0; i < 40000; i++);  // Faster delay

        yellow = 0;
        green = 1;

        for (i = 0; i < 60000; i++);  // Faster delay

        green = 0;

        for (i = 0; i < 60000; i++);  // Faster delay
    }
}
