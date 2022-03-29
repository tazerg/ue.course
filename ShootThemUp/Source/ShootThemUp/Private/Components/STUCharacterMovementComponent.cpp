// Shoot Them Up Game


#include "Components/STUCharacterMovementComponent.h"
#include "Player/STUBaseCharacter.h"

float USTUCharacterMovementComponent::GetMaxSpeed() const
{
    const float MaxSpeed = Super::GetMaxSpeed();
    //GetPawnOwner - ���������� ��������� �� ����� ��������� ����� ����������
    //�.�. ������������ ��� - APawn ��� ����� �������� ��� � ������ ����������� ����
    const ASTUBaseCharacter* Player = Cast<ASTUBaseCharacter>(GetPawnOwner());
    return Player && Player->IsRunning() ? MaxSpeed * RunModifier : MaxSpeed;
}