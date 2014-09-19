

#define CHICKEN 1
#define EGG 2
#define MOVE 3

struct expr_t {

	int type;

	char* identifier;

	void* input;

	void* next;
};

struct x_y_pos {

	int x;
	int y;
};



struct expr_t* build_expr_t(int type ,char* identifier, void* value, void* next);
struct x_y_pos* build_x_y_pos(int x,int y);
