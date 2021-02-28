// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "TEPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class THEEXPANSION_API ATEPlayerController : public APlayerController
{
	GENERATED_BODY()
	
	protected:
		virtual void BeginPlay() override;
        virtual void SetupInputComponent() override;

		UPROPERTY()
		TArray<AActor *> TEBaseRobots;
        int32 CurrentRobot = 0;

		UFUNCTION()
        void ChangePlayer();

};
