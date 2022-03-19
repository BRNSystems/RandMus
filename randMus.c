#include <stdio.h> // putchar
#include <stdlib.h> // rand
#include <time.h> // time

const int num_samples = 6;
int main() {
    srand(time(NULL)); // seed random number generator
    int a[num_samples]; // array of random numbers
    int i; // loop counter
    int c; // out character
    int tmp; // temp character
    int x; // loop counter
    int y;  // loop counter
    while (1){
        for (x = 0; x < num_samples; x++) {
            a[x] = rand() % 20 + 1; // set a[x] to a random number between 1 and 50
        }
        for (i = 0;i<16000; i++) { // loop forever
            c = i >> a[0]; // shift right i by a[0]
            c = c | i >> a[1]; // or c by i shifted right by a[1]
            c = c * i; // multiply c by i
            c = c & a[2]; // and c by a[2]
            c = c | i >> a[3]; // or c by i shifted right by a[3]
            tmp = i & i >> a[4]; // and i by i shifted right by a[4]
            tmp = tmp | i >> a[5]; // or tmp by i shifted right by a[5]
            c = c ^ tmp; // xor c by tmp
            putchar(c); // print c
        }
    }
}
