#include <iostream>

int main() {
    const double pi1 = 3.14;         // pi は const であり、その値は変更できない
    double *ptr = &pi1;              // エラー：ptr はポインタ
    const double *cptr = &pi1;       // OK：cptr は const double へのポインタ
    *cptr = 42;                     // エラー：*cptr には代入できない

    int errNumb = 0;
    int *const curErr = &errNumb;   // curErr は常に errNumb を指す
    const double pi2  =3.14159;
    const double *const pip = &pi2; // pip は const オブジェクトへの const ポインタ
    return 0;
}
