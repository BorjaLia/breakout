#pragma once
#include <string>
#include "Utils_Borja.h"
#include "Globals.h"
#include "Levels.h"

// Credits Menu Buttons
enum class CButtons
{
	EXIT,
	AMOUNT
};

void InitCreditsContext(btn::Container& container, btn::Button buttons[]);
void CreditsUpdate(btn::Button creditsButtons[], SubMenus& subMenu);
void CreditsDraw(btn::Container creditsContainer, btn::Button creditsButtons[]);
