#include <cstdio>
#include "getSource.h"

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
