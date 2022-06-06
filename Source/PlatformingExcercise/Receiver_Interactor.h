// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractorBase.h"
#include "Receiver_Interactor.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMINGEXCERCISE_API AReceiver_Interactor : public AInteractorBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interactors")
		TArray<AInteractorBase*> interactorsToReceive;
	//If we want the interactions to be recieved in certain order and reset if player fails to do that
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Properties")
		bool bOrdered;
private:
	//Tracks the amount of interactions
	int32 intIndex;
protected:
	virtual void OnReset() override;
	virtual void BeginPlay() override;
	UFUNCTION()
	void OnReceive(AInteractorBase* interactor);

};
