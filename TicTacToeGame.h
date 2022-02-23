#pragma once

#include <afxwin.h>

enum class SqState {
	E = -1, X, O
};

class TicTacToeGame {
public:
	SqState field[9] = { SqState::E, SqState::E, SqState::E, SqState::E, SqState::E, SqState::E, SqState::E, SqState::E, SqState::E };
	SqState player = SqState::X;
	BOOL ended = FALSE;

	void playerMove(UINT coord);
	UINT findComputerMove();

	INT minimax(UINT depth, SqState player);
	INT checkWin(SqState player);
	BOOL checkDraw();
	SqState getEnemy(SqState player);
};
