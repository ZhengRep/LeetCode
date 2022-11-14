#include<stdio.h>

#include "MovingAverageFromDataStream.h"

int main()
{
    MovingAverage* obj = new MovingAverage(3);
    double res;
    /*res = obj->next(1);
    res = obj->next(10);
    res = obj->next(3);
    res = obj->next(5);*/
    printf("%f\r\n", obj->next(1));
    printf("%f\r\n", obj->next(10));
    printf("%f\r\n", obj->next(3));
    printf("%f\r\n", obj->next(5));
    return 0;
}