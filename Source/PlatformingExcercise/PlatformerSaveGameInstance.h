// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PlatformerSaveGameInstance.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FPlatformingInstanceData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		bool bHasEarnedTrophy1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bHasEarnedTrophy2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bHasEarnedTrophy3;

};
UCLASS()
class PLATFORMINGEXCERCISE_API UPlatformerSaveGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	FPlatformingInstanceData data;
};
