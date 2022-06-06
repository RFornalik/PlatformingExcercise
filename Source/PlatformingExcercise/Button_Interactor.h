// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractorBase.h"
#include "Button_Interactor.generated.h"

/**
 * 
 */
UCLASS()
class PLATFORMINGEXCERCISE_API AButton_Interactor : public AInteractorBase
{
	GENERATED_BODY()
public:
	AButton_Interactor();
	//Box, that triggers the press
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UBoxComponent* box;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USceneComponent* releasedPos;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USceneComponent* pressedPos;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* buttonMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Defaults")
		bool bPressed;

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
protected:
	virtual void OnReset() override;
	virtual void OnPreInteract_Implementation() override;
	virtual void OnPreReset_Implementation() override;
	int32 charactersOverlapping;
	bool bPendingReset;
}; 
