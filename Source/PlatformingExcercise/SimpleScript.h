// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SimpleScript.generated.h"

/**
 Simple scripts to Call after certain interactions, That Have Arguments
 */
USTRUCT(BlueprintType)
struct FScriptArguments
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<USimpleScript> script;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<int32> intArguments;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<bool> boolArguments;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FName> nameArguments;
};

UCLASS()
class PLATFORMINGEXCERCISE_API USimpleScript : public UObject
{
	GENERATED_BODY()
public:
	USimpleScript();	
	UFUNCTION(BlueprintCallable)
		virtual void Execute();

	static USimpleScript* CreateFromArgs(FScriptArguments _args,UObject* outer);
protected:
	FScriptArguments args;
};

