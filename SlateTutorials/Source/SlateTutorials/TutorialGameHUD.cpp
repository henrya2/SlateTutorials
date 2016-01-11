#include "SlateTutorials.h"

#include "TutorialGameHUD.h"
#include "TutorialGameHUDUI.h"

ATutorialGameHUD::ATutorialGameHUD()
	: Super(FObjectInitializer::Get())
{
}

void ATutorialGameHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (GEngine && GEngine->GameViewport)
	{
		UGameViewportClient* Viewport = GEngine->GameViewport;

		SAssignNew(GameHUD, STutorialGameHUDUI)
			.OwnerHUD(TWeakObjectPtr<ATutorialGameHUD>(this));

		Viewport->AddViewportWidgetContent(
			SNew(SWeakWidget).PossiblyNullContent(GameHUD.ToSharedRef())
			);
	}
}
