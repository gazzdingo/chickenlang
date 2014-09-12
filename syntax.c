
#include <stdlib.h>
#include "syntax.h"

struct chickenVals* inputValue(int x, int y){
    struct chickenVals* values;
    values.x = x; //position of the x value of the chicken
    values.y = y; //position of the y value of the chicken
    return values;
};//two int values for the x and the y of the chicken (top left);
