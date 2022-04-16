// Shoot Them Up Game

#include "Components/STUHealthComponent.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"

DEFINE_LOG_CATEGORY_STATIC(LogHealthComponent, All, All);

USTUHealthComponent::USTUHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void USTUHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	ChangeHealth(MaxHealth);
	
    //Получение актора владельца компонента
	AActor* Actor = GetOwner();
    if (Actor)
    {
        Actor->OnTakeAnyDamage.AddDynamic(this, &USTUHealthComponent::OnTakeAnyDamage); 
    }
}

void USTUHealthComponent::OnTakeAnyDamage(
    AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
    if (Damage <= 0.f || IsDead())
        return;
    
    ChangeHealth(-Damage);
    UpdateAutoHealTimer();

    if (IsDead())
        OnDeath.Broadcast();
}

void USTUHealthComponent::ChangeHealth(float ValueInc)
{
    Health = FMath::Clamp(Health + ValueInc, 0.f, MaxHealth);
    OnHealthChanged.Broadcast(Health);
}

void USTUHealthComponent::UpdateAutoHealTimer()
{
    if (!AutoHealEnabled)
        return;
    
    GetOwner()->GetWorldTimerManager().ClearTimer(AutoHealUpdateTimer);

    if (IsDead())
        return;
    
    GetOwner()->GetWorldTimerManager().SetTimer(
        AutoHealUpdateTimer,
        this,
        &USTUHealthComponent::OnAutoHealUpdateTimerFired,
        AutoHealUpdateTime,
        true,
        AutoHealDelaySec);
}

void USTUHealthComponent::OnAutoHealUpdateTimerFired()
{
    ChangeHealth(AutoHealValue);

    if (!FMath::IsNearlyEqual(Health, MaxHealth))
        return;

    GetOwner()->GetWorldTimerManager().ClearTimer(AutoHealUpdateTimer);
}
