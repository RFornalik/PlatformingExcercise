// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SimpleScript.h"
#include "SetInstanceData_SimpleScript.generated.h"

/**
Simple Function that changes Property values in PlatformerSaveGameInstance
TODO: Use Name Arguments as property names
 */
UCLASS()
class PLATFORMINGEXCERCISE_API USetInstanceData_SimpleScript : public USimpleScript
{
	GENERATED_BODY()
public:
	virtual void Execute() override;
	
};
