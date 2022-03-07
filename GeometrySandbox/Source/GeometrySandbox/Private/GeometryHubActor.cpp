#include "GeometryHubActor.h"
//Нужен для работы с указателем на мир
#include "Engine/World.h"

AGeometryHubActor::AGeometryHubActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AGeometryHubActor::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnTenActors();
	SpawnFromEditorSettings();
}

void AGeometryHubActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGeometryHubActor::SpawnTenActors()
{
	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}

	for (int32 i = 0; i < 10; i++)
	{
		const FTransform InstanceTransform = FTransform(FRotator::ZeroRotator, FVector(0.0f, 300.0f * i, 250.0f));
		ABaseGeometryActor* Instance = World->SpawnActorDeferred<ABaseGeometryActor>(GeometryActor, InstanceTransform);

		//Объект может и не создасться, например если закончилась память
		if (!Instance) 
		{
			continue;
		}

		FGeometryData MovementData;
		MovementData.MoveType = FMath::RandBool() ? EMovementType::Sin : EMovementType::Static;

		FMaterialData MaterialData;
		MaterialData.TimerFrequency = FMath::RandBool() ? 2.0f : 1.0f;
		MaterialData.Color = FLinearColor::MakeRandomColor();

		Instance->SetMovementData(MovementData);
		Instance->SetMaterialData(MaterialData);

		Instance->FinishSpawning(InstanceTransform);
	}
}

void AGeometryHubActor::SpawnFromEditorSettings()
{
	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}

	for (const FGeometrySpawnData SpawnData : SpawnDatas)
	{
		ABaseGeometryActor* Instance = World->SpawnActorDeferred<ABaseGeometryActor>(SpawnData.GeometryActor, SpawnData.InitialTransform);

		if (!Instance)
		{
			continue;
		}

		Instance->SetMovementData(SpawnData.InitialMovementData);
		Instance->SetMaterialData(SpawnData.InitialMaterialData);

		Instance->FinishSpawning(SpawnData.InitialTransform);
	}
}

