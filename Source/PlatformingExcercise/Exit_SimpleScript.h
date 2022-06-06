// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SimpleScript.h"
#include "Exit_SimpleScript.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMINGEXCERCISE_API UExit_SimpleScript : public USimpleScript
{
	GENERATED_BODY()
public:
	virtual void Execute() override;
};
