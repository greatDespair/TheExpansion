// Fill out your copyright notice in the Description page of Project Settings.


#include "TEComponents/TEEnergyComponent.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UTEEnergyComponent::UTEEnergyComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UTEEnergyComponent::BeginPlay()
{
	Super::BeginPlay();
	
	if (GetOwner())
    {
        GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UTEEnergyComponent::OnTakeAnyDamage);
	
	}
	
	
}

void UTEEnergyComponent::OnTakeAnyDamage(AActor *DamagedActor, float Damage, const UDamageType *DamageType,
                                         AController *InstigatedBy, AActor *DamageCauser)
{
    Energy -= Damage;
}


// Called every frame


