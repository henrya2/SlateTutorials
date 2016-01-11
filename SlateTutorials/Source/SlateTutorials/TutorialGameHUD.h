#pragma once

#include "GameFramework/HUD.h"

#include "TutorialGameHUD.generated.h"

/**
* Provides an implementation of the game's in-game HUD, which will display the player's current health and score.
**/
UCLASS()
class ATutorialGameHUD : public AHUD
{
	GENERATED_BODY()

public:
	ATutorialGameHUD();
	/**
	* Initializes the Slate UI and adds it as a widget to the game viewport.
	**/
	virtual void PostInitializeComponents() override;

private:
	/**
	* Reference to the Game HUD UI.
	**/
	TSharedPtr<class STutorialGameHUDUI> GameHUD;
};
