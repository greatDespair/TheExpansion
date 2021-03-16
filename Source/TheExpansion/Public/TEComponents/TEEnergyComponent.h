// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"


#include "TEEnergyComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnDeath)
DECLARE_MULTICAST_DELEGATE_OneParam(FOnEnergyChanged, float)




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
    UFUNCTION()
	float GetEnergy() const{ return Energy; } ;
    UFUNCTION()
    float GetMaxEnergy() const { return MaxEnergy; };

    UFUNCTION(BlueprintCallable)
    void ToCharge(float Power);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "EnergyStats",
              meta = (ClampMin = "0.0", ClampMax = "1000.0"))
    float MaxEnergy= 100.0f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "EnergyStats",
              meta = (ClampMin = "0.0", ClampMax = "1000.0"))
    float Energy = 1.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Charge")
    bool CanCharge = false;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Charge")
    float ChargeUpdateTime = 1.0f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Charge")
    float ChargeDelay = 3.0f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Charge")
    float ChargeModify = 1.0f;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "EnergyStats")
    bool OnDead=false;

    bool isDead();

    FOnDeath OnDeath;
    FOnEnergyChanged EnergyChanged;

private:
    UFUNCTION()
      void OnTakeAnyDamage( AActor * DamagedActor, float Damage,
                           const class UDamageType * DamageType, class AController* InstigatedBy, AActor*
                       DamageCauser);

    FTimerHandle ChargeTimerHandle;
    void ChargeUpdate();
    void SetEnergy(float NewEnergy);
    

};
