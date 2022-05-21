#include "Menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <conio.h>

int menu(char _indicator, int _count, ...)
{
	int i, selected = 0, key = 0x0;
	va_list args;
	
	while (key != 0x71)
	{
		if (key == 0x50)
		{
			if (selected == _count - 1) selected = 0;
			else selected++;
		}
		else if (key == 0x48)
		{
			if (selected == 0) selected = _count - 1;
			else selected--;
		}
		else if (key == 0xD)
		{
			return selected;
		}

		#if defined(_WIN32)
			system("cls");
		#elif defined(__linux__)
			system("clear");
		#endif

		va_start(args, _count);
		for (i = 0; i < _count; i++)
		{
			if (selected == i) printf("%c ", _indicator);
			printf("%s\n", va_arg(args, char*));
		}
		va_end(args);

		key = _getch();
	}

	return NULL;
}