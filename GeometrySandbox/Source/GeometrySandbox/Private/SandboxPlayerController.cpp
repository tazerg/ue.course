// Fill out your copyright notice in the Description page of Project Settings.


#include "SandboxPlayerController.h"
#include "Components/InputComponent.h"
//Нужен для получения всех акторов нужного типа
#include "Kismet/GameplayStatics.h"
#include "SandboxPawn.h"

DEFINE_LOG_CATEGORY_STATIC(LogSandboxPlayerController, All, All);

void ASandboxPlayerController::SetupInputComponent() 
{
	Super::SetupInputComponent();

	InputComponent->BindAction("ChangePawn", IE_Pressed, this, &ASandboxPlayerController::ChangePawn);
}

void ASandboxPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//Получение всех акторов нужного типа
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASandboxPawn::StaticClass(), Pawns);
}

void ASandboxPlayerController::ChangePawn()
{
	if (Pawns.Num() <= 1) 
	{
		return;
	}

	ASandboxPawn* CurrentPawn = Cast<ASandboxPawn>(Pawns[CurrentPawnIndex]);
	CurrentPawnIndex = (CurrentPawnIndex + 1) % Pawns.Num();

	if (!CurrentPawn) 
	{
		return;
	}

	UE_LOG(LogSandboxPlayerController, Display, TEXT("Change pawn"));

	//Установка контроля над Пауном
	Possess(CurrentPawn);
}