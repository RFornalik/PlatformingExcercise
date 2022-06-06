// Fill out your copyright notice in the Description page of Project Settings.


#include "IfTrophy1_InteractableActor.h"
#include "PickUp_Interactor.h"
#include "PlatformerSaveGameInstance.h"
#include "Kismet/GameplayStatics.h"

void AIfTrophy1_InteractableActor::OnInteract_Implementation(AActor* fromActor)
{
	APickUp_Interactor* trophy = GetWorld()->SpawnActor<APickUp_Interactor>(trophyToSpawn.Get(), GetActorTransform());
	trophy->bCanInteract = false;
}
void AIfTrophy2_InteractableActor::OnInteract_Implementation(AActor* fromActor)
{
	APickUp_Interactor* trophy = GetWorld()->SpawnActor<APickUp_Interactor>(trophyToSpawn.Get(), GetActorTransform());
	trophy->bCanInteract = false;
}
void AIfTrophy3_InteractableActor::OnInteract_Implementation(AActor* fromActor)
{
	APickUp_Interactor* trophy = GetWorld()->SpawnActor<APickUp_Interactor>(trophyToSpawn.Get(), GetActorTransform());
	trophy->bCanInteract = false;
}


AIfTrophy1_InteractableActor::AIfTrophy1_InteractableActor()
{
	root = CreateAbstractDefaultSubobject<USceneComponent>("root");
	SetRootComponent(root);
}
AIfTrophy2_InteractableActor::AIfTrophy2_InteractableActor()
{
	root = CreateAbstractDefaultSubobject<USceneComponent>("root");
	SetRootComponent(root);
}
AIfTrophy3_InteractableActor::AIfTrophy3_InteractableActor()
{
	root = CreateAbstractDefaultSubobject<USceneComponent>("root");
	SetRootComponent(root);
}
void AIfTrophy1_InteractableActor::BeginPlay()
{
	UPlatformerSaveGameInstance* inst = Cast<UPlatformerSaveGameInstance>(UGameplayStatics::GetGameInstance(this));
	if(inst->IsValidLowLevel())
	{
		if (inst->data.bHasEarnedTrophy1)Execute_OnInteract(this,this);
	}
}
void AIfTrophy2_InteractableActor::BeginPlay()
{
	UPlatformerSaveGameInstance* inst = Cast<UPlatformerSaveGameInstance>(UGameplayStatics::GetGameInstance(this));
	if (inst->IsValidLowLevel())
	{
		if (inst->data.bHasEarnedTrophy2)Execute_OnInteract(this,this);
	}
}
void AIfTrophy3_InteractableActor::BeginPlay()
{
	UPlatformerSaveGameInstance* inst = Cast<UPlatformerSaveGameInstance>(UGameplayStatics::GetGameInstance(this));
	if (inst->IsValidLowLevel())
	{
		if (inst->data.bHasEarnedTrophy3)Execute_OnInteract(this,this);
	}
}