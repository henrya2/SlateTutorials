#include "SlateTutorials.h"

#include "TutorialGameHUD.h"
#include "TutorialGameHUDUI.h"

#include "GlobalMenuStyle.h"
#include "MenuStyles.h"
#include "TutGameMode.h"
#include "TutorialCharacter.h"

void STutorialGameHUDUI::Construct(const FArguments& args)
{
	Score.Bind(this, &STutorialGameHUDUI::GetScore);
	Health.Bind(this, &STutorialGameHUDUI::GetHealth);

	OwnerHUD = args._OwnerHUD;

	HUDStyle = &FMenuStyles::Get()->GetWidgetStyle<FGlobalStyle>("Global");

	ChildSlot
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			.HAlign(HAlign_Right)
			.VAlign(VAlign_Top)
			[
				SNew(STextBlock)
				.TextStyle(&HUDStyle->MenuTitleStyle)
				.Text(Score)
			]
			+ SOverlay::Slot()
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Top)
			[
				SNew(STextBlock)
				.TextStyle(&HUDStyle->MenuTitleStyle)
				.Text(Health)
			]
		];
}

FText STutorialGameHUDUI::GetScore() const
{
	// NOTE: THIS IS A TERRIBLE WAY TO DO THIS. DO NOT DO IT. IT ONLY WORKS ON SERVERS. USE GAME STATES INSTEAD!
	ATutGameMode* GameMode = Cast<ATutGameMode>(OwnerHUD->GetWorldSettings()->GetWorld()->GetAuthGameMode());

	if (GameMode == nullptr)
		return FText::FromString(TEXT("SCORE: --"));

	FString score = TEXT("SCORE: ");
	score.AppendInt(GameMode->GetScore());

	return FText::FromString(score);
}

FText STutorialGameHUDUI::GetHealth() const
{
	ATutorialCharacter* Character = Cast<ATutorialCharacter>(OwnerHUD->PlayerOwner->GetCharacter());

	if (Character == nullptr)
		return FText::FromString(TEXT("HEALTH: --"));

	FString health = TEXT("HEALTH: ");
	health.AppendInt(Character->Health);

	return FText::FromString(health);
}
