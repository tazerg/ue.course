// Shoot Them Up Game

#include "Dev/STUDevDamageActor.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"

ASTUDevDamageActor::ASTUDevDamageActor()
{
	PrimaryActorTick.bCanEverTick = true;

    SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
    SetRootComponent(SceneComponent);
}

void ASTUDevDamageActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASTUDevDamageActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    //�������� ��������� �����
    DrawDebugSphere(GetWorld(), GetActorLocation(),
        Radius, 24, SphereColor);

    //��������� �����
    //1. ��������� �� ���
    //2. ��������� ����
    //3. ����� ��������� �����
    //4. ������ �����
    //5. ��� ���������� ����� (���� �� ����������)
    //6. ������ ������� ������� ����� ������������ ����
    //7. �����, ������� ������� �����
    //8. ���������� ������ ���������� ����
    //9. �������� �� ������ ����
    //true - ��� ����������� �� ����� ����� �������� ������ ����
    //false - ������ ���� ������ � ������ �����, ����� �����������.
    //
    UGameplayStatics::ApplyRadialDamage(
        GetWorld(),
        Damage,
        GetActorLocation(),
        Radius,
        nullptr,
        {},
        this,
        nullptr,
        DoFullDamage);
}