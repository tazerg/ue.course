#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "BaseGeometryActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnColorChanged, const FLinearColor&, Color, const FString&, Name);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnTimerFinished, AActor*);

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float Amplitude = 50.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float Frequency = 2.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	EMovementType MoveType = EMovementType::Static;
};

USTRUCT(BlueprintType)
struct FMaterialData 
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Material")
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

	void SetMovementData(const FGeometryData& Data) 
	{
		MovementData = Data;
	}

	void SetMaterialData(const FMaterialData& Data) 
	{
		MaterialData = Data;
	}

	UFUNCTION(BlueprintCallable)
	FGeometryData GetMovementData() const 
	{
		return MovementData;
	}

	UFUNCTION(BlueprintCallable)
	FMaterialData GetMaterialData() const 
	{
		return MaterialData;
	}

	UPROPERTY(BlueprintAssignable)
	FOnColorChanged OnColorChanged;
	FOnTimerFinished OnTimerFinished;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GeometryData")
	FGeometryData MovementData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MaterialData")
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
