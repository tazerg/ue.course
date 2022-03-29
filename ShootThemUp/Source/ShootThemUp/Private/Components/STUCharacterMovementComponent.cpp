// Shoot Them Up Game


#include "Components/STUCharacterMovementComponent.h"
#include "Player/STUBaseCharacter.h"

float USTUCharacterMovementComponent::GetMaxSpeed() const
{
    const float MaxSpeed = Super::GetMaxSpeed();
    //GetPawnOwner - возвращает указатель на пауна владельца этого компонента
    //т.к. возвращаемый тип - APawn нам нужно скастить его к нашему кокнертному типу
    const ASTUBaseCharacter* Player = Cast<ASTUBaseCharacter>(GetPawnOwner());
    return Player && Player->IsRunning() ? MaxSpeed * RunModifier : MaxSpeed;
}