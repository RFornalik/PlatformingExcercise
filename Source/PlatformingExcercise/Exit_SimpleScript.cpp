// Fill out your copyright notice in the Description page of Project Settings.


#include "Exit_SimpleScript.h"
#include "Kismet/KismetSystemLibrary.h"

void UExit_SimpleScript::Execute()
{
	UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, false);
}