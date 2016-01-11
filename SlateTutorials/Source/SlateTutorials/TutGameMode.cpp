#include "SlateTutorials.h"
#include "TutGameMode.h"
#include "TutorialGameHUD.h"
#include "TutorialCharacter.h"

ATutGameMode::ATutGameMode()
	: Super(FObjectInitializer::Get())
	, CurrentScore(0)
{
	HUDClass = ATutorialGameHUD::StaticClass();
	DefaultPawnClass = ATutorialCharacter::StaticClass();
}

int32 ATutGameMode::GetScore()
{
	return CurrentScore;
}

void ATutGameMode::AddPoints(int32 value)
{
	if (value > 0)
		CurrentScore += value;
}

void ATutGameMode::DeductPoints(int32 value)
{
	if (value > 0)
		CurrentScore = FMath::Max(CurrentScore - value, 0);
}
