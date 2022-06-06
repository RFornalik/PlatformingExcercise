// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractorBase.h"
#include "SimpleOverlap_Interactor.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMINGEXCERCISE_API ASimpleOverlap_Interactor : public AInteractorBase
{
	GENERATED_BODY()
public:
	ASimpleOverlap_Interactor();
	//Box, that triggers the pickup
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UBoxComponent* box;
	//Event triggered by overlapping box
	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
};
