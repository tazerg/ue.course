// Shoot Them Up Game

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "STUBaseCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class USTUHealthComponent;
class UTextRenderComponent;

UCLASS()
class SHOOTTHEMUP_API ASTUBaseCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    //конструктор с параметром в котором передаётся объект инициализации
    ASTUBaseCharacter(const FObjectInitializer& ObjInit);

protected:
    //Необходим для связывания вращения вокруг компонента персонажа а не вокруг точки камеры
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USpringArmComponent* SpringArmComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UCameraComponent* CameraComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    USTUHealthComponent* HealthComponent;

    //Необходим для визуализации текста в мире
    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
    UTextRenderComponent* HealthTextComponent;

    //Анимация смерти
    UPROPERTY(EditDefaultsOnly, Category = "Animation")
    UAnimMontage* DeathAnimMontage;

    UPROPERTY(EditDefaultsOnly, Category = "Movement")
    FVector2D LandedDamageVelocity = FVector2D(900.f, 1300.f);
    UPROPERTY(EditDefaultsOnly, Category = "Movement")
    FVector2D LandedDamage = FVector2D(10.f, 80.f);
    
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    UFUNCTION(BlueprintCallable, Category = "Movement")
    bool IsRunning() const;

    UFUNCTION(BlueprintCallable, Category = "Movement")
    float GetMovementDirection() const;

private:
    bool WantsToRun = false;
    bool IsMovingForward = false;

    void MoveFroward(float Amount);
    void MoveRight(float Amount);
    void EnableAcceleration();
    void DisableAcceleration();
    void OnDeath();
    void OnHealthChanged(float HealthValue) const;

    UFUNCTION()
    void OnGroundLanded(const FHitResult& HitResult);
};
