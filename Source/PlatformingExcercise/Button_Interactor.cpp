// Fill out your copyright notice in the Description page of Project Settings.


#include "Button_Interactor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"
#include "DoubleJumpCharacter.h"
AButton_Interactor::AButton_Interactor()
{
	
	box = CreateDefaultSubobject<UBoxComponent>("Extent");
	SetRootComponent(box);
	box->OnComponentBeginOverlap.AddDynamic(this, &AButton_Interactor::OnOverlapBegin);
	box->OnComponentEndOverlap.AddDynamic(this, &AButton_Interactor::OnOverlapEnd);
	releasedPos = CreateDefaultSubobject<USceneComponent>("releasedPos");
	pressedPos = CreateDefaultSubobject<USceneComponent>("pressedPos");
	buttonMesh = CreateDefaultSubobject<UStaticMeshComponent>("buttonMesh");
	pressedPos->SetupAttachment(GetRootComponent());
	releasedPos->SetupAttachment(GetRootComponent());
	buttonMesh->SetupAttachment(releasedPos);
}


void AButton_Interactor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	ADoubleJumpCharacter* test = Cast<ADoubleJumpCharacter>(OtherActor);
	if(test->IsValidLowLevel())
	{
		charactersOverlapping++;
		if(!bPressed)
		{
			Interact();
			bPressed = true;
		}

	}
}
void AButton_Interactor::OnReset()
{
	bPressed = false;
	bPendingReset = false;
}
void AButton_Interactor::OnPreInteract_Implementation()
{	
		buttonMesh->SetWorldLocation(pressedPos->GetComponentLocation());
		OnInteract();
}
void AButton_Interactor::OnPreReset_Implementation()
{
	if (charactersOverlapping == 0)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("RESET"));
		buttonMesh->SetWorldLocation(releasedPos->GetComponentLocation());
		OnReset();

	}
	else bPendingReset = true;
}
void AButton_Interactor::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	ADoubleJumpCharacter* test = Cast<ADoubleJumpCharacter>(OtherActor);
	if (test->IsValidLowLevel())
	{
		charactersOverlapping--;
		if (bPendingReset) Reset();
	}
}
