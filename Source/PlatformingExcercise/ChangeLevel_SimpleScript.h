// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SimpleScript.h"
#include "ChangeLevel_SimpleScript.generated.h"

/**
Open Level Script
 */
UCLASS()
class PLATFORMINGEXCERCISE_API UChangeLevel_SimpleScript : public USimpleScript
{
	GENERATED_BODY()
public:
	virtual void Execute() override;
	
};
