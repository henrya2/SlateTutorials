#pragma once

#include "SlateBasics.h"

class SLATETUTORIALS_API SMainMenuUI : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMainMenuUI)
	{}
	SLATE_ARGUMENT(TWeakObjectPtr<class AMainMenuHUD>, MainMenuHUD)
	SLATE_END_ARGS()

	// Constructs and lays out the Main Menu UI Widget
	// args Arguments structure that contains widget-specific setup information.
	void Construct(const FArguments& InArgs);

	// Click handler for the Play Game! button ¨C Calls MenuHUD¡¯s PlayGameClicked() event.
	FReply PlayGameClicked();

	// Click handler for the Quit Game button ¨C Calls MenuHUD¡¯s QuitGameClicked() event.
	FReply QuitGameClicked();

	// Stores a weak reference to the HUD controlling this class.
	TWeakObjectPtr<class AMainMenuHUD> MainMenuHUD;

	const struct FGlobalStyle* MenuStyle;
};
