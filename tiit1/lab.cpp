#include <iostream>
#include <math.h>
#include <ctime>

float f(float x){
    return x/sqrt(1 + x);
}

int main(){
    float x, y, n=0, S, x0=0, x1=3.1415, y0=0, y1= 1.55, s0=2.88653 , N=10000;

    for(int i = 0; i < N; i++){
        x = rand() % 31415;
        x /= 10000;
        y = rand() % 155;
        y /= 100;
        if (y<=f(x)) n++;
    }

    S = (x1 - x0) * (y1 - y0) * n / N;   
    std::cout << S << "    " << abs((s0-S)/x1*100)<<"%" << std::endl;

    return 0;
}