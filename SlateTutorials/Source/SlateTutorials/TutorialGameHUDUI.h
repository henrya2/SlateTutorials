#pragma once

#include "SlateBasics.h"

// Lays out and controls the Tutorial HUD UI.

class STutorialGameHUDUI : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(STutorialGameHUDUI)
		: _OwnerHUD()
	{
	}

	SLATE_ARGUMENT(TWeakObjectPtr<class ATutorialGameHUD>, OwnerHUD);

	SLATE_END_ARGS()

public:
	/**
	* Constructs and lays out the Tutorial HUD UI Widget.
	*
	* \args Arguments structure that contains widget-specific setup information.
	**/
	void Construct(const FArguments& args);

private:
	/**
	* Stores a weak reference to the HUD owning this widget.
	**/
	TWeakObjectPtr<class ATutorialGameHUD> OwnerHUD;

	/**
	* A reference to the Slate Style used for this HUD's widgets.
	**/
	const struct FGlobalStyle* HUDStyle;

private:
	/**
	* Attribute storing the binding for the player's score.
	**/
	TAttribute<FText> Score;

	/**
	* Attribute storing the binding for the player's health.
	**/
	TAttribute<FText> Health;

	/**
	* Our Score will be bound to this function, which will retrieve the appropriate data and convert it into an FText.
	**/
	FText GetScore() const;

	/**
	* Our Health will be bound to this function, which will retrieve the appropriate data and convert it into an FText.
	**/
	FText GetHealth() const;
};
