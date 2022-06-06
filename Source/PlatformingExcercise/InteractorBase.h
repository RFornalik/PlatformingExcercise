// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SimpleScript.h"
#include "InteractorBase.generated.h"

//INTERACTION EVENT, USEFUL FOR DOING MULTI-ACTOR INTERACTIONS
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteract, AInteractorBase*, Interactor);


UCLASS()
class PLATFORMINGEXCERCISE_API AInteractorBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractorBase();


	//Interaction event, useful for doing more complicated interactions
	UPROPERTY(BlueprintAssignable, Category = "Interactors")
		FOnInteract onInteractEvent;
	//Array of Actors that Should have Interactablility Interface, USEFUL FOR SINGLE ACTOR INTERACTIONS
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interactors")
		TArray<AActor*> actorsToInteract;
	//Simple scripts that we want to execute, persistent scripts are used to keep track of stuff
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interactors")
		TArray<FScriptArguments> persistentScriptsToExecute;
	//Non-persistent scripts that don't change overtime (their arguments might change though)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interactors")
		TArray<FScriptArguments> nonPersistentScriptsToExecute;

	//If we want to lock/unlock interactability, we should use this
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Defaults")
		bool bCanInteract;

	// Called to start interaction
	UFUNCTION(BlueprintCallable, Category = "Interaction")
		void Interact();
	//Resets the Interactor
	UFUNCTION(BlueprintCallable, Category = "Interaction")
		void Reset();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called on start of interaction, should do viual stuff(Timelines, etc.) before calling OnInteract.
	// 
	//As this function is used mostly for connectinng visual and gameplay behavior,
	//it can be overriden by blueprints AND c++.
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
		void OnPreInteract();



	// Called on start of Interaction reset, should do viual stuff(Timelines, etc.) before calling OnReset.
	// 
	//As this function is used mostly for connectinng visual and gameplay behavior,
	//it can be overriden by blueprints AND c++.
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
		void OnPreReset();



	// Main Body of the interaction, usually non-visual behavior
	UFUNCTION(BlueprintCallable, Category="Interaction")
		virtual void OnInteract();
	//Main Body of Interaction Reset, usually non-visual behavior
	UFUNCTION(BlueprintCallable, Category = "Interaction")
		virtual void OnReset();




	//Initialised Scripts
	TArray<class USimpleScript*> scripts;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
