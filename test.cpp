#include <iostream>

using namespace std;

int main() {
    int number = 10;
    int *int_ptr = &number;
    (*int_ptr)++;
    number++;
    cout << number;
}
