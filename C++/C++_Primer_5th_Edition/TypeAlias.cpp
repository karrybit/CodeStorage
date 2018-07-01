#include <iostream>

int main() {
    typedef char *pstring;
    const pstring cstr = 0;     // cstr は char への定数ポインタ
    const pstring *ps;          // ps は char への定数ポインタへのポインタ

    /*
     * const pstring cstr は const char *cstr ではない
     * （つまり、const char へのポインタではない）
     * const が修飾するのは、char * 型に対してなので、
     * char *const cstr という型になる
    */
    return 0;
}
