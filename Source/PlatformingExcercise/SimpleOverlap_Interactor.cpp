// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleOverlap_Interactor.h"
#include "Components/BoxComponent.h"
#include "DoubleJumpCharacter.h"

ASimpleOverlap_Interactor::ASimpleOverlap_Interactor()
{
	box = CreateDefaultSubobject<UBoxComponent>("Extent");
	SetRootComponent(box);
	box->OnComponentBeginOverlap.AddDynamic(this, &ASimpleOverlap_Interactor::OnOverlapBegin);
}
void ASimpleOverlap_Interactor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ADoubleJumpCharacter* c = Cast<ADoubleJumpCharacter>(OtherActor);

	//Checks if it was the charactor who picked it
	if (c->IsValidLowLevel())
	{
		Interact();
	}

}