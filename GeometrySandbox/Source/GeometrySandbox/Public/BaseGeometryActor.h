// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "BaseGeometryActor.generated.h"

UENUM(BlueprintType)
enum class EMovementType : uint8
{
	Sin,
	Static
};

USTRUCT(BlueprintType)
struct FGeometryData 
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "Movement")
	float Amplitude = 50.0f;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float Frequency = 2.0f;
	UPROPERTY(EditAnywhere, Category = "Movement")
	EMovementType MoveType = EMovementType::Static;
};

USTRUCT(BlueprintType)
struct FMaterialData 
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "Material")
	FLinearColor Color = FLinearColor::Black;

	UPROPERTY(EditAnywhere, Category = "Material")
	float TimerFrequency = 3.0f;
};

UCLASS()
class GEOMETRYSANDBOX_API ABaseGeometryActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseGeometryActor();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseMeshComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "GeometryData")
	FGeometryData MovementData;

	UPROPERTY(EditAnywhere, Category = "MaterialData")
	FMaterialData MaterialData;

	UPROPERTY(EditAnywhere, Category = "Weapon")
	int32 WeaponsNum = 4;
	UPROPERTY(EditDefaultsOnly, Category = "Stat")
	int32 KillsNum = 7;
	UPROPERTY(EditInstanceOnly, Category = "Stat")
	float Health = 43.58999f;
	UPROPERTY(EditAnywhere, Category = "Stat")
	bool IsDead = false;
	UPROPERTY(VisibleAnywhere, Category = "Weapon")
	bool HasWeapon = true;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FVector InitialLocation;
	FTimerHandle TimerHandle;

	const int32 TimerMaxCount = 5;
	int32 TimerCount = 0;

	void PrintTypes();
	void PrintStringTypes();
	void PrintTransform();
	void HandleMovement();
	void SetMaterialColor(const FLinearColor& NewColor);

	void OnTimerFired();
};
