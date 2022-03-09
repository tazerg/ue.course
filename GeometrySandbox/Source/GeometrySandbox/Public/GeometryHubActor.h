#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//����������� ��������� ������� ����� ��������
#include "BaseGeometryActor.h"
#include "GeometryHubActor.generated.h"

USTRUCT(BlueprintType)
struct FGeometrySpawnData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "SpawnData")
	TSubclassOf<ABaseGeometryActor> GeometryActor;

	UPROPERTY(EditAnywhere, Category = "SpawnData")
	FGeometryData InitialMovementData;

	UPROPERTY(EditAnywhere, Category = "SpawnData")
	FMaterialData InitialMaterialData;

	UPROPERTY(EditAnywhere, Category = "SpawnData")
	FTransform InitialTransform;
};

UCLASS()
class GEOMETRYSANDBOX_API AGeometryHubActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AGeometryHubActor();

protected:
	virtual void BeginPlay() override;

	//TSubclassOf - ������-��������� �� ����� ��� ��� �������
	UPROPERTY(EditAnywhere, Category = "Spawner")
	TSubclassOf<ABaseGeometryActor> GeometryActor;

	//��������� ������� ����� ����� 
	//(������������ ���������� �� �����)
	UPROPERTY(EditAnywhere, Category = "Spawner")
	UClass* Class;

	//��������� �������� ��������� �� ������������ ������ �� �����
	//(������������ ���������� �� �����)
	UPROPERTY(EditAnywhere, Category = "Spawner")
	ABaseGeometryActor* GeometryObject;

	UPROPERTY(EditAnywhere, Category = "SpawnEditorData")
	TArray<FGeometrySpawnData> SpawnDatas;

public:	
	virtual void Tick(float DeltaTime) override;

private:
	void SpawnTenActors();
	void SpawnFromEditorSettings();

	UFUNCTION()
	void OnColorChanged(const FLinearColor& Color, const FString& Name);
	void OnTimerFinished(AActor* Actor);

};
