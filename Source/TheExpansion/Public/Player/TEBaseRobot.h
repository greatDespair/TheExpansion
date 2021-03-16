// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"	
#include "TEComponents/TEEnergyComponent.h"
#include "TEBaseRobot.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UTextRenderComponent;

UCLASS()
class THEEXPANSION_API ATEBaseRobot : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	

protected:
    ATEBaseRobot(const FObjectInitializer &ObjInit);
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnyWhere,BlueprintReadWrite, Category="Components")
    UCameraComponent* CameraComponent;

    UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Components")
    UTEEnergyComponent *TEEnergyComponent;
    

    UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = "Components")
    USpringArmComponent *SpringArm;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Movement")
    int32 MaxArmLength=900;

    UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Movement" )
    int32 MinArmLength=250;
    

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement", 
			  meta=(ClampMin="0.1", ClampMax="1000.0"))
    float WalkSpeed = 300.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement",
              meta = (ClampMin = "0.1", ClampMax = "1000.0"))
    float RunSpeed=600.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Display")
    UTextRenderComponent *EnergyTextComponent;

	UFUNCTION(BlueprintCallable)
    bool IsRunning();

	bool WantsToRun=false;
    int32 ArmLength = 900.0f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void Death();
    void OnEnergyChanged(float Energy);
	

private:
    void MoveForward(float Amount);
    void MoveRight(float Amount);
    void SpeedUp();
    void SpeedDown();
    void ScrollUp();
    void ScrollDown();
    
};
