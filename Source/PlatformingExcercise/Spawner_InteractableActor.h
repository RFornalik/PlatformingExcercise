// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "Spawner_InteractableActor.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMINGEXCERCISE_API ASpawner_InteractableActor : public AInteractableActor
{
	GENERATED_BODY()
public:
	ASpawner_InteractableActor();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<AActor> actorToSpawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USceneComponent* root;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bUseOnce;
	virtual void OnInteract_Implementation(AActor* fromActor) override;
	virtual void OnReset_Implementation(AActor* fromActor) override;
private:
		bool bUsed;
};
