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

    //Дебажная отрисовка сферы
    DrawDebugSphere(GetWorld(), GetActorLocation(),
        Radius, 24, SphereColor);

    //Нанесение урона
    //1. указатель на мир
    //2. наносимый урон
    //3. центр нанесения урона
    //4. радиус урона
    //5. тип наносимого урона (пока не используем)
    //6. массив акторов которые будут игнорировать урон
    //7. актор, который наносит ущерб
    //8. контроллер актора наносящего урон
    //9. наносить ли полный урон
    //true - вне зависимости от точки сферы нанесётся полный урон
    //false - полный урон только в центре сферы, далее вычисляется.
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