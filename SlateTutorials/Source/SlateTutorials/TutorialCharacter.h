#pragma once

#include "GameFramework/Character.h"
#include "TutorialCharacter.generated.h"

/**
* A simple character providing a means of retrieving and manipulating health.
**/
UCLASS()
class ATutorialCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ATutorialCharacter();
	/**
	* Stores the character's current health.
	**/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	int32 Health;
};
