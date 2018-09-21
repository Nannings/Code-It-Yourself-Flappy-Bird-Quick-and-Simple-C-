#include <iostream>
#include <string>
using namespace std;

#include "olcConsoleGameEngine.h"

class FlappyBird : public olcConsoleGameEngine
{
public:

private:
	float fBirdPosition = 0.0f;
	float fBirdVelocity = 0.0f;
	float fBirdAcceleration = 0.0f;

	float fGravity = 100.0f;

protected:
	virtual bool OnUserCreate() {
		return true;
	}

	virtual bool OnUserUpdate(float fElapsedTime) {

		if (m_keys[VK_SPACE].bPressed)
		{
			fBirdAcceleration = 0.0f;
			fBirdVelocity = -fGravity / 4.0f;
		}
		else
		{
			fBirdAcceleration += fGravity * fElapsedTime;
		}

		if (fBirdAcceleration >= fGravity) {
			fBirdAcceleration = fGravity;
		}

		Fill(0, 0, ScreenWidth(), ScreenHeight(), L' ');

		fBirdVelocity += fBirdAcceleration * fElapsedTime;
		fBirdPosition += fBirdVelocity * fElapsedTime;

		int nBirdX = (int)(ScreenWidth() / 3.0f);

		if (fBirdVelocity > 0) {
			DrawString(nBirdX, fBirdPosition + 0, L"\\\\\\");
			DrawString(nBirdX, fBirdPosition + 1, L"<\\\\\\=Q");
		}
		else
		{
			DrawString(nBirdX, fBirdPosition + 0, L"<///=Q");
			DrawString(nBirdX, fBirdPosition + 1, L"///");
		}

		return true;
	}
};

int main() {
	FlappyBird game;
	game.ConstructConsole(80, 48, 16, 16);
	game.Start();

	return 0;
}