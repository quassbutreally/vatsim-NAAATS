#pragma once
#include "pch.h"
#include "EuroScopePlugIn.h"
#include <string>
#include <map>
#include <gdiplus.h>
#include "BaseWindow.h"

using namespace std;
using namespace Gdiplus;
using namespace EuroScopePlugIn;

class CFlightPlanWindow : public CBaseWindow
{
	public:
		// Inherited methods
		CFlightPlanWindow(POINT topLeft);
		virtual void MakeWindowItems();
		virtual void RenderWindow(CDC* dc, Graphics* g, CRadarScreen* screen);
		CRect RenderDataPanel(CDC* dc, Graphics* g, CRadarScreen* screen, POINT topLeft, bool isCopy);
		void RenderConflictWindow(CDC* dc, Graphics* g, CRadarScreen* screen, POINT topLeft);
		void RenderMessageWindow(CDC* dc, Graphics* g, CRadarScreen* screen, POINT bottomLeft);
		void RenderClearanceWindow(CDC* dc, Graphics* g, CRadarScreen* screen, POINT topLeft);
		void RenderManEntryWindow(CDC* dc, Graphics* g, CRadarScreen* screen, POINT topLeft);
		void RenderCoordModal(CDC* dc, Graphics* g, CRadarScreen* screen, POINT topLeft);
		void RenderHistoryModal(CDC* dc, Graphics* g, CRadarScreen* screen, POINT topLeft);
		void RenderATCRestrictModal(CDC* dc, Graphics* g, CRadarScreen* screen, POINT topLeft);
		void RenderTransferModal(CDC* dc, Graphics* g, CRadarScreen* screen, POINT topLeft);

		bool IsButtonPressed(int id);

		// Button clicks
		virtual void ButtonDown(int id);
		virtual void ButtonUp(int id);
		virtual void ButtonPress(int id);
		virtual void ButtonUnpress(int id);
		virtual void SetButtonState(int id, CInputState state);

		// Fill data
		void UpdateData(CRadarScreen* screen, CAcFPStatus status);
		void OnCloseFlightPlanWindow();
		int ChangeDataPoint(CRadarScreen* screen, int data, string str); // Master method to deal with all cases of text input

		// Panel states
		bool IsData = true;
		bool IsCopyMade = false;
		bool IsConflictWindow = false;
		bool IsClearanceOpen = false;
		bool IsManualEntryOpen = false;
		bool IsMessageOpen = false;
		bool IsCoordOpen = false;
		bool IsHistoryOpen = false;
		bool IsATCRestrictionsOpen = false;
		bool IsTransferOpen = false;

		// Button definitions
		static const int BTN_CLOSE;
		static const int BTN_COPY;
		static const int BTN_TRNSFR;
		static const int BTN_COORD;
		static const int BTN_MANENTRY;
		static const int BTN_PROBE;
		static const int BTN_DELETE;
		static const int BTN_ADS;
		static const int BTN_READBK;
		static const int BTN_MSG;
		static const int BTN_HIST;
		static const int BTN_SAVE;
		static const int BTN_ATCR;
		static const int BTN_ATCR_CPY;

		// Dropdown definitions
		static const int DRP_ATCR;
		static const int DRP_ATCR_CPY;

		// Text definitions
		static const int TXT_ACID;
		static const int TXT_TYPE;
		static const int TXT_DEPART;
		static const int TXT_ETD;
		static const int TXT_SELCAL;
		static const int TXT_DATALINK;
		static const int TXT_COMMS;
		static const int TXT_OWNERSHIP;
		static const int TXT_SPD;
		static const int TXT_LEVEL;
		static const int TXT_DEST;
		static const int TXT_TCK;
		static const int TXT_STATE;
		static const int TXT_SPD_CPY;
		static const int TXT_LEVEL_CPY;
		static const int TXT_DEST_CPY;
		static const int TXT_TCK_CPY;
		static const int TXT_STATE_CPY;
};

