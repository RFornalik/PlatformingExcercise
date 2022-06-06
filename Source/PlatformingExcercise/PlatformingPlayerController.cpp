// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformingPlayerController.h"

void APlatformingPlayerController::BeginPlay()
{
	SetInputMode(FInputModeGameOnly());
	SetShowMouseCursor(false);
}