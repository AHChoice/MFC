// Dump.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "DumpFile.h"

void print(int *p)
{
    p[0] = 0;
}

int main()
{
    DeclareDumpFile();
    print(NULL);
    return 0;
}

