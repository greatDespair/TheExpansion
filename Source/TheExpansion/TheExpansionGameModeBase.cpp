// Copyright Epic Games, Inc. All Rights Reserved.


#include "TheExpansionGameModeBase.h"
#include "Public/Player/TEBaseRobot.h"
#include "Public/Player/TEPlayerController.h"

ATheExpansionGameModeBase::ATheExpansionGameModeBase()
{

	DefaultPawnClass = ATEBaseRobot::StaticClass();
    PlayerControllerClass = ATEPlayerController::StaticClass();


}