// Shoot Them Up Game

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STUDevDamageActor.generated.h"

UCLASS()
class SHOOTTHEMUP_API ASTUDevDamageActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ASTUDevDamageActor();

    //Компонент для добавления трансформации и перемещения актора по сцене
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
    USceneComponent* SceneComponent;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Radius = 300.f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FColor SphereColor = FColor::Orange;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Damage = 1.f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool DoFullDamage = true;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSubclassOf<UDamageType> DamageType;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
};
