#include <cstdio>
#include "compile.cpp"
#include "getSource.h"
#include "codegen.h"

int main() {
    char fileName[30];
    printf("enter source file name\n"); /* ソースプログラムファイルの名前 */
    scanf("%s", fileName);

    if (!openSource(fileName))
        return 1;

    if (compile())
        execute();

    closeSource();
}
