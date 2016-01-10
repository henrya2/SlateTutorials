#pragma once

#include "GameFramework/HUD.h"
#include "MainMenuHUD.generated.h"

UCLASS(Blueprintable)
class SLATETUTORIALS_API AMainMenuHUD : public AHUD
{
	GENERATED_BODY()
public:
	AMainMenuHUD();
	// Initializes the Slate UI and adds it as widget content to the game viewport
	virtual void PostInitializeComponents() override;

	// Called by SMainMenu whenever the Play Game! button has been clicked.
	UFUNCTION(BlueprintImplementableEvent, Category = "Menus|Main Menu")
	void PlayGameClicked();

	// Called by SMainMenu whever the Quit Game! button has been clicked.
	UFUNCTION(BlueprintImplementableEvent, Category = "Menus|Main Menu")
	void QuitGameClicked();

	TSharedPtr<class SMainMenuUI> MainMenuUI;
};