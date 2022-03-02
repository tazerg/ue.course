// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGeometryActor.h"
#include "Engine/Engine.h"

DEFINE_LOG_CATEGORY_STATIC(LogBaseGeometry, All, All);

// Sets default values
ABaseGeometryActor::ABaseGeometryActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	SetRootComponent(BaseMeshComponent);
}

// Called when the game starts or when spawned
void ABaseGeometryActor::BeginPlay()
{
	Super::BeginPlay();

	InitialLocation = GetActorLocation();

	PrintTypes();
	PrintStringTypes();
	PrintTransform();
}

// Called every frame
void ABaseGeometryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//z = z0 + amplitude * sin(freq * t)

	FVector CurrentLocation = GetActorLocation();
	//GetTimeSeconds - ���������� ���������� ������ ��������� � ������� ������ ����
	float time = GetWorld()->GetTimeSeconds();
	CurrentLocation.Z = InitialLocation.Z + Amplitude * FMath::Sin(Frequency * time);
	
	SetActorLocation(CurrentLocation);
}

void ABaseGeometryActor::PrintTypes()
{
	UE_LOG(LogTemp, Display, TEXT("Actor name: %s"), *GetName());
	UE_LOG(LogTemp, Display, TEXT("Weapons num: %d; Kills num: %i"), WeaponsNum, KillsNum);
	UE_LOG(LogTemp, Display, TEXT("Health: %f"), Health);
	UE_LOG(LogTemp, Display, TEXT("IsDead: %d"), IsDead);
	UE_LOG(LogTemp, Display, TEXT("HasWeapon: %d"), static_cast<int>(HasWeapon));
}

void ABaseGeometryActor::PrintStringTypes()
{
	FString Name = "Some Name";
	UE_LOG(LogBaseGeometry, Display, TEXT("Name: %s"), *Name);

	FString WeaponsNumStr = "Weapons num: " + FString::FromInt(WeaponsNum);
	FString HealthStr = "Health: " + FString::SanitizeFloat(Health, 2);//������ �������� �������� �� ���������� ����� ����� �������
	FString IsDeadStr = "IsDead: " + FString(IsDead ? "true" : "false");

	FString Stat = FString::Printf(TEXT("All:\n %s, %s, %s"), *WeaponsNumStr, *HealthStr, *IsDeadStr);
	UE_LOG(LogBaseGeometry, Display, TEXT("%s"), *Stat);

	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, Name);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, Stat, true, FVector2D(1.5f, 1.5f));
}

void ABaseGeometryActor::PrintTransform() 
{
	FTransform transform = GetActorTransform();

	FVector location = transform.GetLocation();
	FRotator rotation = transform.Rotator();
	FVector scale = transform.GetScale3D();

	UE_LOG(LogTemp, Display, TEXT("Actor name: %s"), *GetName());
	UE_LOG(LogTemp, Display, TEXT("Actor transform: %s"), *transform.ToString());
	UE_LOG(LogTemp, Display, TEXT("Actor location: %s"), *location.ToString());
	UE_LOG(LogTemp, Display, TEXT("Actor rotation: %s"), *rotation.ToString());
	UE_LOG(LogTemp, Display, TEXT("Actor scale: %s"), *scale.ToString());

	UE_LOG(LogTemp, Display, TEXT("Actor human readable transform: %s"), *transform.ToHumanReadableString());
}