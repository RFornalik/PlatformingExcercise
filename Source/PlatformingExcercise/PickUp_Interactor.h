// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractorBase.h"
#include "PickUp_Interactor.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMINGEXCERCISE_API APickUp_Interactor : public AInteractorBase
{
	GENERATED_BODY()
public:
	APickUp_Interactor();
	//Box, that triggers the pickup
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UBoxComponent* box;
	//Rotation Speed, TODO: Separate Rotating Coins as subclasses
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float rotationSpeed;
	//Event triggered by overlapping box
	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	//Called after visual event
	UFUNCTION(BlueprintCallable, Category = "Events")
		virtual void PickUp();
	//Visual event
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Events")
		void OnPrePickup();

	virtual void Tick(float DeltaSeconds) override;

};
