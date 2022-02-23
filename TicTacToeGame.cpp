#include "TicTacToeGame.h"

/**
 * @brief Sets field cell to current player
 * @param coord - Cell coordinate 
 */
void TicTacToeGame::playerMove(UINT coord)
{
	field[coord] = player;
}

/**
 * @brief Calculates best move for computer using minimax algorithm
 */
UINT TicTacToeGame::findComputerMove()
{
	INT bestScore = INT_MIN, score;
	UINT bestCell = -1;

	for (UINT i = 0; i < 9; i++)
		if (field[i] == SqState::E) {
			field[i] = SqState::O;

			score = minimax(0, SqState::O);

			if (score > bestScore) {
				bestScore = score;
				bestCell = i;
			}

			field[i] = SqState::E;
		}

	return bestCell;
}

/**
 * @brief Calculates score of current game board for player. If the game is ended, it returns its result minus depth of this state in game tree. Else, it returns 
 * @param depth - Number of steps made in game graph
 * @param player - Player for which we want to calculate current score
 */
INT TicTacToeGame::minimax(UINT depth, SqState player)
{
	if (player == SqState::E) throw "Called with Empty player";

	SqState enemy = getEnemy(player);

	INT winScore = checkWin(player);

	if (winScore) return winScore - depth;

	INT maxEnemyScore = INT_MIN;

	for (int i = 0; i < 9; i++)
		if (field[i] == SqState::E) {
			field[i] = enemy;
			INT score = minimax(depth + 1, enemy);

			if (score > maxEnemyScore)
				maxEnemyScore = score;

			field[i] = SqState::E;
		}

	if (maxEnemyScore == INT_MIN) return 0;

	return -maxEnemyScore;
}

/**
 * @brief Checks if current game state is wining for player or its enemy
 * @param player - Player for which we check
 * @returns 10 means win for player, -10 - for enemy, 0 - draw or unfinished
 */
INT TicTacToeGame::checkWin(SqState player)
{
	if (player == SqState::E) throw "Called with Empty player";

	SqState enemy = getEnemy(player);

	for (INT i = 0; i < 3; i++) {
		if ((field[i * 3] == field[1 + i * 3] && field[1 + i * 3] == field[2 + i * 3]) || // Row
			(field[i] == field[3 + i] && field[3 + i] == field[6 + i])) { // Column
			if (field[i * 4] == player)
				return 10;
			if (field[i * 4] == enemy)
				return -10;
		}
	}

	if ((field[0] == field[4] && field[4] == field[8]) || // first diagonal
		(field[2] == field[4] && field[4] == field[6])) { // second diagonal
		if (field[4] == player)
			return 10;
		if (field[4] == enemy)
			return -10;
	}

	return 0;
}

/**
 * @brief Checks if current game state is a draw
 */
BOOL TicTacToeGame::checkDraw()
{
	for (int i = 0; i < 9; i++)
		if (field[i] == SqState::E)
			return FALSE;

	ended = TRUE;
	return TRUE;
}

/**
 * @brief Utility for getting enemy of player
 */
SqState TicTacToeGame::getEnemy(SqState player)
{
	if (player == SqState::E) throw "Called with Empty player";

	if (player == SqState::X)
		return SqState::O;
	else
		return SqState::X;
}
