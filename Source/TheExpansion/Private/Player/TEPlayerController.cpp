// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/TEPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "TEBaseRobot.h"

void ATEPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    InputComponent->BindAction("ChangePlayer", IE_Pressed, this, &ATEPlayerController::ChangePlayer);

}

void ATEPlayerController::ChangePlayer()
{
    CurrentRobot = (CurrentRobot + 1) % TEBaseRobots.Num();
    Possess( Cast<APawn>(TEBaseRobots[CurrentRobot]) );

}

void ATEPlayerController::BeginPlay()
{
    Super::BeginPlay();
    
    UGameplayStatics::GetAllActorsOfClass(GetWorld(),ATEBaseRobot::StaticClass(),TEBaseRobots);


}

