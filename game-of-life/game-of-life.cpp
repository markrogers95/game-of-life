#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class Example : public olc::PixelGameEngine
{
public:
	Example()
	{
		sAppName = "game-of-life";
	}

public:
	bool OnUserCreate() override
	{
		for (int x = 0; x < ScreenWidth(); x++) {
			for (int y = 0; y < ScreenHeight(); y++) {
				
				if ((rand() % 100 + 1) == 1) {
					Draw(x, y, olc::Pixel(255, 255, 255));
				}
				else Draw(x, y, olc::Pixel(0, 0, 0));
			}
		}
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// called once per frame
		for (int x = 0; x < ScreenWidth(); x++)
			for (int y = 0; y < ScreenHeight(); y++)
				;
		return true;
	}
};


int main()
{
	Example demo;
	if (demo.Construct(960, 960, 1, 1))
		demo.Start();

	return 0;
}