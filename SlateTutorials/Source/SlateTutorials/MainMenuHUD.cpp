#include "SlateTutorials.h"
#include "MainMenuHUD.h"
#include "MainMenuUI.h"

AMainMenuHUD::AMainMenuHUD()
	: Super(FObjectInitializer::Get())
{

}

void AMainMenuHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	SAssignNew(MainMenuUI, SMainMenuUI).MainMenuHUD(this);

	if (GetOwningPlayerController())
	{
		GetOwningPlayerController()->GetLocalPlayer()->ViewportClient->AddViewportWidgetContent(MainMenuUI->AsShared());
	}
}
