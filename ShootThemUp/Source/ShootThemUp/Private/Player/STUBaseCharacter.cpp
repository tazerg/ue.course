// Shoot Them Up Game

#include "Player/STUBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/STUCharacterMovementComponent.h"
#include "Components/STUHealthComponent.h"
#include "Components/TextRenderComponent.h"

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

    HealthComponent = CreateDefaultSubobject<USTUHealthComponent>("HealthComponent");

    HealthTextComponent = CreateDefaultSubobject<UTextRenderComponent>("HealthTextComponent");
    HealthTextComponent->SetupAttachment(GetRootComponent());
}

void ASTUBaseCharacter::BeginPlay()
{
    Super::BeginPlay();

    //Макросы которые кидают ассерты если в переменной null
    check(HealthComponent);
    check(HealthTextComponent);
}

void ASTUBaseCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    const auto Health = HealthComponent->GetHealth();
    HealthTextComponent->SetText(
        FText::FromString(FString::Printf(TEXT("%.0f"), Health)));

    //Тестовое нанесение урона самому себе
    TakeDamage(0.1f, FDamageEvent{}, Controller, this);
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
    if (Amount == 0)
    {
        return;
    }
    AddMovementInput(GetActorForwardVector(), Amount);
}

void ASTUBaseCharacter::MoveRight(float Amount)
{
    if (Amount == 0)
    {
        return;
    }

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

float ASTUBaseCharacter::GetMovementDirection() const
{
    if (GetVelocity().IsZero())
    {
        return 0.f;
    }
    const auto NormalizedVelocity = GetVelocity().GetSafeNormal();
    const auto AngleBetween = FMath::Acos(
        FVector::DotProduct(GetActorForwardVector(),
        NormalizedVelocity));
    const auto CrossProduct = FVector::CrossProduct(
        GetActorForwardVector(), 
        NormalizedVelocity);
    const auto Degrees = FMath::RadiansToDegrees(AngleBetween);
    return CrossProduct.IsZero() ? Degrees : Degrees * FMath::Sign(CrossProduct.Z);
}