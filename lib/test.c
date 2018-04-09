// Header libraries
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

// Custom
#include <custom.h>

void test_str_len() {
    char *quote = "andre";
    const int len = str_len(quote);
    assert(len == 5);
}


void test_str() {
    char *quote = "andre";
    char *result = str(quote);
    assert(quote == result);
}


void main(void){
    test_str_len();

    test_str();
}
