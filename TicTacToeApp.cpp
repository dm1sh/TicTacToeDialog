#include "TicTacToeApp.h"

#include "TicTacToeDlg.h"

CTicTacToeApp app;

BOOL CTicTacToeApp::InitInstance()
{
	CTicTacToeDlg* dlg = new CTicTacToeDlg();

	dlg->DoModal();

	return TRUE;
}
