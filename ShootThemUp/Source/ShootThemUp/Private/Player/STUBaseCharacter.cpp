// Shoot Them Up Game

#include "Player/STUBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/STUCharacterMovementComponent.h"

ASTUBaseCharacter::ASTUBaseCharacter(const FObjectInitializer& ObjInit) 
    : Super(
        ObjInit.SetDefaultSubobjectClass<USTUCharacterMovementComponent>(
            ACharacter::CharacterMovementComponentName))
{
    PrimaryActorTick.bCanEverTick = true;

    //Для связывания костей
    SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
    SpringArmComponent->SetupAttachment(GetRootComponent());
    SpringArmComponent->bUsePawnControlRotation = true;

    CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
    CameraComponent->SetupAttachment(SpringArmComponent);
}

void ASTUBaseCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void ASTUBaseCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ASTUBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    //Перемещение
    PlayerInputComponent->BindAxis("MoveForward", this, &ASTUBaseCharacter::MoveFroward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ASTUBaseCharacter::MoveRight);

    //Вращение
    PlayerInputComponent->BindAxis("LookUp", this, &ASTUBaseCharacter::AddControllerPitchInput);
    PlayerInputComponent->BindAxis("TurnAround", this, &ASTUBaseCharacter::AddControllerYawInput);

    //Экшн действия
    //Метод Jump уже реализован в базовом классе пауна
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ASTUBaseCharacter::Jump);

    //Ускорение
    PlayerInputComponent->BindAction("Run", IE_Pressed, this, &ASTUBaseCharacter::EnableAcceleration);
    PlayerInputComponent->BindAction("Run", IE_Released, this, &ASTUBaseCharacter::DisableAcceleration);
}

bool ASTUBaseCharacter::IsRunning() const
{
    return WantsToRun && IsMovingForward && !GetVelocity().IsZero();
}

void ASTUBaseCharacter::MoveFroward(float Amount)
{
    IsMovingForward = Amount > 0;
    AddMovementInput(GetActorForwardVector(), Amount);
}

void ASTUBaseCharacter::MoveRight(float Amount)
{
    AddMovementInput(GetActorRightVector(), Amount);
}

void ASTUBaseCharacter::EnableAcceleration()
{
    WantsToRun = true;
}

void ASTUBaseCharacter::DisableAcceleration()
{
    WantsToRun = false;
}