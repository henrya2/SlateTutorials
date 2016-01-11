#pragma once

#include "GameFramework/GameMode.h"
#include "TutGameMode.generated.h"

/**
* A simple game mode providing a means of retrieving and adjusting a single Score value.
**/
UCLASS()
class ATutGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ATutGameMode();
	/**
	* Retrieves the current Score from the game mode.
	**/
	UFUNCTION(BlueprintPure, BlueprintCallable, Category = "Score")
	int32 GetScore();

	/**
	* Adds to the game score.
	**/
	UFUNCTION(BlueprintCallable, Category = "Score")
	void AddPoints(int32 value);

	/**
	* Removes from the game score.
	**/
	UFUNCTION(BlueprintCallable, Category = "Score")
	void DeductPoints(int32 value);

private:
	/**
	* Stores the current score.
	**/
	int32 CurrentScore;
};
