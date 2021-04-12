// Copyright Epic Games, Inc. All Rights Reserved.

#include "TS_GABRIEL_CABRERAGameMode.h"
#include "TS_GABRIEL_CABRERACharacter.h"
#include "UObject/ConstructorHelpers.h"

ATS_GABRIEL_CABRERAGameMode::ATS_GABRIEL_CABRERAGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/BP_Player"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
