#include "SandboxPawn.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogSandboxPawn, All, All);

ASandboxPawn::ASandboxPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	SetRootComponent(SceneComponent);

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	//1.
	MeshComponent->SetupAttachment(GetRootComponent());

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraCOmponent");
	//2.
	CameraComponent->SetupAttachment(SceneComponent);

	//«аписи 1. и 2. идентичны, т.к. выше SceneComponent выставл€етс€ корневым.
}

//”становка контрол€ над пауном новым контроллером
void ASandboxPawn::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	UE_LOG(LogSandboxPawn, Display, TEXT("%s Possessed by %s"), *GetName(), *NewController->GetName());
}

//ѕотер€ контрол€ над пауном
void ASandboxPawn::UnPossessed()
{
	Super::UnPossessed();

	UE_LOG(LogSandboxPawn, Display, TEXT("%s Un possessed"), *GetName());
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
	VelocityVector = FVector::ZeroVector;
}

void ASandboxPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASandboxPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASandboxPawn::MoveRight);
}

void ASandboxPawn::MoveForward(float Amount)
{
	//UE_LOG(LogSandboxPawn, Display, TEXT("MoveForvard. Amount: %f"), Amount);

	VelocityVector.X = Amount;
}

void ASandboxPawn::MoveRight(float Amount)
{
	//UE_LOG(LogSandboxPawn, Display, TEXT("MoveRight. Amount: %f"), Amount);

	VelocityVector.Y = Amount;
}