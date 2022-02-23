#include "TicTacToeDlg.h"

void CTicTacToeDlg::OnOK()
{
	if (player == SqState::O)
		MessageBox(L"Who are you trying to trick?", L"Game result");
	else
		CDialog::OnOK();
}

void CTicTacToeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	for (UINT i = 0; i < 9; i++)
		DDX_Control(pDX, IDC_BUTTON1 + i, buttons[i]);
}

BEGIN_MESSAGE_MAP(CTicTacToeDlg, CDialog)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BUTTON1, IDC_BUTTON9, CTicTacToeDlg::OnBnClickedSquare)
END_MESSAGE_MAP()

void CTicTacToeDlg::OnBnClickedSquare(UINT nID)
{
	if (ended) return;

	UINT btn_id = nID - IDC_BUTTON1;
	if (field[btn_id] == SqState::E) {
		CString msg;
		msg.Format(L"Pressed %u button", nID);
		TRACE(msg);

		player = SqState::X;
		playerMove(btn_id);
		buttons[btn_id].SetWindowTextW(L"X");

		if (checkWin(SqState::X)) {
			ended = TRUE;
			MessageBox(L"You have been able to do this! It's really cool, because my algorithm must be invincible.", L"Game result");
			return;
		}

		player = SqState::O;

		if (checkDraw()) {
			MessageBox(L"It's draw. You are still good enogh and didn't do mistakes during the game. This AI is powered by minimax algorithm, so it is invincible by design.", L"Game result");
			return;
		}

		UINT comp_id = findComputerMove();
		playerMove(comp_id);
		buttons[comp_id].SetWindowTextW(L"O");
		
		if (checkWin(SqState::O)) {
			ended = TRUE;
			MessageBox(L"Unfortunatly, you lost. If it'll make you feel any better, this AI is powered by minimax algorithm, so it is invincible by design.");
			return;
		}
	}
}
