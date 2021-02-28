// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/TEBaseRobot.h"
#include"Camera\CameraComponent.h"
#include"Components/InputComponent.h"
#include"GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TEComponents/TECharacterMovementComponent.h"

DEFINE_LOG_CATEGORY_STATIC(Character, All, All)

// Sets default values

ATEBaseRobot::ATEBaseRobot(const FObjectInitializer &ObjInit): 
    Super(ObjInit.SetDefaultSubobjectClass<UTECharacterMovementComponent>
        (ACharacter::CharacterMovementComponentName))
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
   
    SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
    SpringArm->SetupAttachment(GetRootComponent());
    SpringArm->bUsePawnControlRotation = true;

    CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComponent->SetupAttachment(SpringArm);
    
   
}

// Called when the game starts or when spawned
void ATEBaseRobot::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATEBaseRobot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    

}

// Called to bind functionality to input
void ATEBaseRobot::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ATEBaseRobot::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ATEBaseRobot::MoveRight);
    PlayerInputComponent->BindAxis("LookUp", this, &ATEBaseRobot::AddControllerPitchInput);
    PlayerInputComponent->BindAxis("LookRight", this, &ATEBaseRobot::AddControllerYawInput);
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ATEBaseRobot::Jump);
  
    PlayerInputComponent->BindAction("SpeedUp", IE_Pressed, this, &ATEBaseRobot::SpeedUp);
    PlayerInputComponent->BindAction("SpeedUp", IE_Released, this, &ATEBaseRobot::SpeedDown);
}

void ATEBaseRobot::MoveForward(float Amount)
{
    AddMovementInput(GetActorForwardVector(), Amount);

}

void ATEBaseRobot::MoveRight(float Amount)
{
    AddMovementInput(GetActorRightVector(), Amount);
}

void ATEBaseRobot::SpeedUp()
{
    
    GetCharacterMovement()->MaxWalkSpeed = RunSpeed ;
    WantsToRun = true;
}

void ATEBaseRobot::SpeedDown()
{

    GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
    WantsToRun = false;
}

bool ATEBaseRobot::IsRunning()
{
    
    return WantsToRun && (GetVelocity().Size() > RunSpeed * 0.8);
   
}
