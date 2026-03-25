#ifndef node_h
#define node_h
#include <iostream>
#include <string>
using namespace std;

/* Menu and Price Lists */
const string menu[] = {"Ramen", "Somtum", "Fried Chicken"};
const int price_list[] = {100, 20, 50};

class NODE {
    int ord, qty;
    NODE *nextPtr;

public:
    NODE(int, int); // Updated to take 2 values
    ~NODE();
    void set_next(NODE*);
    NODE* get_next();
    int get_price(); 
};

typedef NODE* NodePtr;

NODE::NODE(int x, int y) {
    ord = x;
    qty = y;
    nextPtr = NULL;
}

NODE* NODE::get_next() {
    return nextPtr;
}

int NODE::get_price() {
    int menuSize = sizeof(price_list) / sizeof(int);
    if (ord >= 1 && ord <= menuSize) {
        cout << menu[ord - 1] << " x" << qty << endl;
        return price_list[ord - 1] * qty;
    } else {
        cout << "No Food (Invalid Order)" << endl;
        return 0;
    }
}

void NODE::set_next(NODE *t) {
    nextPtr = t;
}

NODE::~NODE() {
    // Destructor shows what is being cleared
}

#endif