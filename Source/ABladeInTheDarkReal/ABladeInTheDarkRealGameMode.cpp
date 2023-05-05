// Copyright Epic Games, Inc. All Rights Reserved.

#include "ABladeInTheDarkRealGameMode.h"
#include "ABladeInTheDarkRealCharacter.h"
#include "UObject/ConstructorHelpers.h"

AABladeInTheDarkRealGameMode::AABladeInTheDarkRealGameMode()
{	
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
