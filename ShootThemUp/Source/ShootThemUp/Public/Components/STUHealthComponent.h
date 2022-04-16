// Shoot Them Up Game

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "STUHealthComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnDeath);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOOTTHEMUP_API USTUHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	USTUHealthComponent();

	float GetHealth() const { return Health; }
    UFUNCTION(BlueprintCallable)
    bool IsDead() const { return FMath::IsNearlyZero(Health); }

    FOnDeath OnDeath;
    FOnHealthChanged OnHealthChanged;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health", meta = (ClampMin = "10.0", ClampMax = "200.0"))
	float MaxHealth = 100.f;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AutoHeal")
    bool AutoHealEnabled = true;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Autoheal")
    float AutoHealDelaySec = 3.f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Autoheal")
    float AutoHealUpdateTime = 0.5f;
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AutoHeal")
    float AutoHealValue = 1.f;

private:
    float Health = 0.f;
    FTimerHandle AutoHealUpdateTimer;

    UFUNCTION()
    void OnTakeAnyDamage(
        AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);

    void ChangeHealth(float ValueInc);
    void UpdateAutoHealTimer();
    void OnAutoHealUpdateTimerFired();
};
