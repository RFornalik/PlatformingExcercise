// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUp_Interactor.h"
#include "Components/BoxComponent.h"
#include "DoubleJumpCharacter.h"

APickUp_Interactor::APickUp_Interactor()
{
	box = CreateDefaultSubobject<UBoxComponent>("Extent");
	SetRootComponent(box);
	box->OnComponentBeginOverlap.AddDynamic(this, &APickUp_Interactor::OnOverlapBegin);
	PrimaryActorTick.bCanEverTick = true;
	rotationSpeed = 200.f;
}
void APickUp_Interactor::Tick(float DeltaSeconds)
{

	AddActorWorldRotation(FRotator(0.f,DeltaSeconds * rotationSpeed,0.f));
}
void APickUp_Interactor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ADoubleJumpCharacter* c = Cast<ADoubleJumpCharacter>(OtherActor);

	//Checks if it was the charactor who picked it
	if(c->IsValidLowLevel())
	{
		Interact();
		if(bCanInteract)OnPrePickup();
	}

}
//Visual stuff

void APickUp_Interactor::OnPrePickup_Implementation()
{
	PickUp();
}

//Usually destruction event
void APickUp_Interactor::PickUp()
{
	this->Destroy();
}