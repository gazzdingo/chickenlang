
#include <stdlib.h>
#include "syntax.h"

struct expr_t* build_expr_t(int type ,char* identifier, void* value, void* next){


	struct expr_t* result = malloc(sizeof(struct expr_t));
	result->type = type;
    result->identifier = identifier;
	result->input = input;
	result->next = next;
	return result;
}

struct x_y_pos* build_x_y_pos(int x,int y){

    struct x_y_pos* result =malloc(sizeof(struct expr_t));
    result.x = x;
    result.y = y;
    return result;
}
