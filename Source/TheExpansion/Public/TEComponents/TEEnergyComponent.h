// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"

#include "TEEnergyComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THEEXPANSION_API UTEEnergyComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTEEnergyComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
		float GetEnergy() { return Energy; } ;
    float GetMaxEnergy() { return MaxEnergy; };

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement",
              meta = (ClampMin = "0.0", ClampMax = "1000.0"))
    float MaxEnergy= 100.0f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement",
              meta = (ClampMin = "0.0", ClampMax = "1000.0"))
    float Energy = 100.0f;

private:
    UFUNCTION()
  void OnTakeAnyDamage( AActor * DamagedActor, float Damage,
                       const class UDamageType * DamageType, class AController* InstigatedBy, AActor*
                       DamageCauser);

		
};
