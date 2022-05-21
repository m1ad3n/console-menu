#include <stdio.h>
#include "Menu.h"

int main()
{
	printf("\n%d", menu('*', 3, "Compile", "Compile & Run", "Debug"));
	return 0;
}