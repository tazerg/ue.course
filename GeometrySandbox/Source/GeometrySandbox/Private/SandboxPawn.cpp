#include "SandboxPawn.h"
#include "Components/InputComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogSandboxPawn, All, All);

ASandboxPawn::ASandboxPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	SetRootComponent(SceneComponent);
}

void ASandboxPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASandboxPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (VelocityVector.IsZero()) 
	{
		return;
	}

	const FVector NewLocation = GetActorLocation() + Velocity * DeltaTime * VelocityVector;
	SetActorLocation(NewLocation);
}

void ASandboxPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASandboxPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASandboxPawn::MoveRight);
}

void ASandboxPawn::MoveForward(float Amount)
{
	UE_LOG(LogSandboxPawn, Display, TEXT("MoveForvard. Amount: %f"), Amount);

	VelocityVector.X = Amount;
}

void ASandboxPawn::MoveRight(float Amount)
{
	UE_LOG(LogSandboxPawn, Display, TEXT("MoveRight. Amount: %f"), Amount);

	VelocityVector.Y = Amount;
}