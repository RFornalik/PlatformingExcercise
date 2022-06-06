// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "IfTrophy1_InteractableActor.generated.h"

/**
As this project is small, I made 3 Actors that Spawn Trophies if Instance has met the conditions.
I would do this more professionally this if project was bigger
 */
UCLASS()
class PLATFORMINGEXCERCISE_API AIfTrophy1_InteractableActor : public AInteractableActor
{
	GENERATED_BODY()
public:
	AIfTrophy1_InteractableActor();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USceneComponent* root;
	virtual void OnInteract_Implementation(AActor* fromActor) override;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		TSubclassOf<class APickUp_Interactor> trophyToSpawn;
protected:
	virtual void BeginPlay() override;
	
};
UCLASS()
class PLATFORMINGEXCERCISE_API AIfTrophy2_InteractableActor : public AInteractableActor
{
	GENERATED_BODY()
public:
	AIfTrophy2_InteractableActor();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USceneComponent* root;
	virtual void OnInteract_Implementation(AActor* fromActor) override;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		TSubclassOf<class APickUp_Interactor> trophyToSpawn;
protected:
	virtual void BeginPlay() override;

};
UCLASS()
class PLATFORMINGEXCERCISE_API AIfTrophy3_InteractableActor : public AInteractableActor
{
	GENERATED_BODY()
public:
	AIfTrophy3_InteractableActor();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USceneComponent* root;
	virtual void OnInteract_Implementation(AActor* fromActor) override;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		TSubclassOf<class APickUp_Interactor> trophyToSpawn;
protected:
	virtual void BeginPlay() override;

};
