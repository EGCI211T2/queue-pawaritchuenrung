#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Queue.h"

using namespace std;

int main(int argc, char **argv) {
    Queue q;
    int i;

    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "x") == 0) {
            int price = q.dequeue();
            if (price != -1) {
                cout << "You have to pay " << price << " Baht" << endl;
                
                if (price > 0) {
                    int cash;
                    do {
                        cout << "Cash: ";
                        cin >> cash;
                    } while (cash < price); // Keep asking until enough cash is given
                    
                    if (cash > price) {
                        cout << "Change: " << cash - price << " Baht" << endl;
                    }
                }
                cout << "================" << endl;
            } else {
                cout << "Queue is empty. No customer to pay." << endl;
            }
        } 
        else {
            // Since enqueue needs 2 values (order and qty)
            // We take argv[i] as order and argv[i+1] as qty
            if (i + 1 < argc && strcmp(argv[i+1], "x") != 0) {
                int order = atoi(argv[i]);
                int qty = atoi(argv[i+1]);
                q.enqueue(order, qty);
                i++; // Skip the next index since we used it for qty
            }
        }
    }
    return 0;
}