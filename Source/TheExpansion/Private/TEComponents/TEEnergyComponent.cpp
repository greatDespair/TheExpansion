// Fill out your copyright notice in the Description page of Project Settings.


#include "TEComponents/TEEnergyComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "TimerManager.h"

// Sets default values for this component's properties
UTEEnergyComponent::UTEEnergyComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
   
    
}


// Called when the game starts
void UTEEnergyComponent::BeginPlay()
{
	Super::BeginPlay();



	if (GetOwner())
    {

        GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UTEEnergyComponent::OnTakeAnyDamage);
	    
	} 
    SetEnergy(MaxEnergy);
    EnergyChanged.Broadcast(Energy);
	
}

bool UTEEnergyComponent::isDead()
{
    return FMath::IsNearlyZero(Energy);
}

void UTEEnergyComponent::OnTakeAnyDamage(AActor *DamagedActor, float Damage, const UDamageType *DamageType,
                                         AController *InstigatedBy, AActor *DamageCauser)
{
    if (Damage < 0.0f || isDead()) return;
    GetWorld()->GetTimerManager().ClearTimer(ChargeTimerHandle);
    
    SetEnergy(Energy - Damage);
	if (isDead())
    {
        OnDeath.Broadcast();
        OnDead = true;
    }
    else if (CanCharge)
    {
        GetWorld()->GetTimerManager().SetTimer(ChargeTimerHandle, this, &UTEEnergyComponent::ChargeUpdate,
                                               ChargeUpdateTime, true, ChargeDelay);
    }

    EnergyChanged.Broadcast(Energy);
}


// Called every frame

void UTEEnergyComponent::ChargeUpdate()
{
    
    SetEnergy(Energy + ChargeModify);
    EnergyChanged.Broadcast(Energy);

    if (FMath::IsNearlyEqual(Energy, MaxEnergy))
    {
        GetWorld()->GetTimerManager().ClearTimer(ChargeTimerHandle);
    }
}

void UTEEnergyComponent::SetEnergy(float NewEnergy)
{
    Energy = FMath::Clamp(NewEnergy, 0.0f, MaxEnergy);
}

void UTEEnergyComponent::ToCharge(float Power)
{
    if (Power <= 0 || isDead()) return;

    SetEnergy(Energy + Power);
    EnergyChanged.Broadcast(Energy);
}