// Shoot Them Up Game

#include "Components/STUHealthComponent.h"
#include "GameFramework/Actor.h"

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
    
    ChangeHealth(Health - Damage);

    if (IsDead())
        OnDeath.Broadcast();
}

void USTUHealthComponent::ChangeHealth(float Value)
{
    Health = FMath::Clamp(Value, 0.f, MaxHealth);
    OnHealthChanged.Broadcast(Health);
}
