#include "SlateTutorials.h"
#include "WidgetGameMode.h"
#include "MainMenuHUD.h"

AWidgetGameMode::AWidgetGameMode()
	: Super(FObjectInitializer::Get())
{
	HUDClass = AMainMenuHUD::StaticClass();
}

