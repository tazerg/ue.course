// Shoot Them Up Game

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "STUCharacterMovementComponent.generated.h"

UCLASS()
class SHOOTTHEMUP_API USTUCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
	
public:
    //meta - ���� ���������� ������� �������� ������� �������� ��������� ��������.
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Movement", meta = (ClampMin = "1.5", ClampMax = "3.0"))
    float RunModifier = 2.f;

    //�������������� ������� ������������ ������������ ��������
    virtual float GetMaxSpeed() const override;
};
