// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "WorldStreamer_InteractableActor.generated.h"

/**
Simple random level loader
  */
UCLASS()
class PLATFORMINGEXCERCISE_API AWorldStreamer_InteractableActor : public AInteractableActor
{
	GENERATED_BODY()
public:
	virtual void OnInteract_Implementation(AActor* fromActor) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FName> levelsToLoad;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 amount;
	UFUNCTION()
	void Iteration();
};
