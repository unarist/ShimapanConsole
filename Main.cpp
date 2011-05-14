#include <Windows.h>

int main()
{
	WORD attr[2]={
		BACKGROUND_BLUE|BACKGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED,
		BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|FOREGROUND_BLUE|FOREGROUND_INTENSITY
	};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	DWORD written;
	GetConsoleScreenBufferInfo(hOut, &info);
	for(int y=0;y<info.dwSize.Y;++y)
	{
		if(4*y>info.dwSize.X) break;
		COORD pos={2*y,y};
		FillConsoleOutputAttribute(hOut, attr[y/2%2], info.dwSize.X-4*y, pos, &written);
	}
	return 0;
}