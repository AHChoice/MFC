// Dump.cpp : �������̨Ӧ�ó������ڵ㡣
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

