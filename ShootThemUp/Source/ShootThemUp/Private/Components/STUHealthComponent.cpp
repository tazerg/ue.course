// Shoot Them Up Game

#include "Components/STUHealthComponent.h"

#include "STUFireDamageType.h"
#include "STUIceDamageType.h"
#include "GameFramework/Actor.h"

DEFINE_LOG_CATEGORY_STATIC(LogHealthComponent, All, All);

USTUHealthComponent::USTUHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void USTUHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;
	
    //Получение актора владельца компонента
	AActor* Actor = GetOwner();
    if (Actor)
    {
        Actor->OnTakeAnyDamage.AddDynamic(this, &USTUHealthComponent::OnTakeAnyDamage); 
    }
}

void USTUHealthComponent::OnTakeAnyDamage(
    AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauesr)
{
    UE_LOG(LogHealthComponent, Display, TEXT("Damage taked: %f"), Damage);
    Health -= Damage;

    if (!DamageType)
        return;

    if (DamageType->IsA<USTUFireDamageType>())
    {
        UE_LOG(LogHealthComponent, Display, TEXT("This is FIRE damage"));
        return;
    }

    if (DamageType->IsA<USTUIceDamageType>())
    {
        UE_LOG(LogHealthComponent, Display, TEXT("This is ICE damage"));
        return;
    }
}
