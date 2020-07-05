#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include <iostream>

using namespace std;

class game_of_life : public olc::PixelGameEngine
{
public:
	game_of_life()
	{
		sAppName = "game-of-life";
	}

private:
	int *current_state;
	int *screen_state;

protected:
	bool OnUserCreate() override{

		current_state = new int[ScreenWidth() * ScreenHeight()];
		screen_state = new int[ScreenWidth() * ScreenHeight()];

		memset(current_state, 0, ScreenWidth() * ScreenHeight() * sizeof(int));
		memset(screen_state, 0, ScreenWidth() * ScreenHeight() * sizeof(int));

		for (int i = 0; i < ScreenWidth() * ScreenHeight(); i++) {
			current_state[i] = (short int)(rand() % 2);
		}

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override{

		this_thread::sleep_for(10ms);

		if (!GetKey(olc::Key::LEFT).bHeld) return true;

		auto square = [&](int x, int y) {
			return screen_state[y * ScreenWidth() + x];
		};

		for (int i = 0; i < ScreenWidth() * ScreenHeight(); i++) {
			screen_state[i] = current_state[i];
		}

		for (int x = 1; x < ScreenWidth() - 1; x++) {
			for (int y = 1; y < ScreenHeight() - 1; y++) {

				int neighbours = square(x - 1, y - 1) + square(x, y - 1) + square(x + 1, y - 1) +
					square(x - 1, y) +							0		 + square(x + 1, y) +
					square(x - 1, y + 1) + square(x, y + 1) + square(x + 1, y + 1);

				if (square(x, y) == 1) {
					if (neighbours == 2 || neighbours == 3) {
						current_state[y * ScreenWidth() + x] = 1;
					}
					else {
						current_state[y * ScreenWidth() + x] = 0;
					}
				}
				else {
					if (neighbours == 3) {
						current_state[y * ScreenWidth() + x] = 1;
					}
					else {
						current_state[y * ScreenWidth() + x] = 0;
					}
				}

				if (square(x, y) == 1) {
					Draw(x, y, olc::Pixel(255, 255, 255));
				}
				else Draw(x, y, olc::Pixel(0, 0, 0));
			}
		}

		return true;
	}
};


int main()
{
	game_of_life demo;
	demo.Construct(100, 100, 8, 8);
	demo.Start();

	return 0;
}