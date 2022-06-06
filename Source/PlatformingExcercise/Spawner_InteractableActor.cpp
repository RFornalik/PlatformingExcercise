// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawner_InteractableActor.h"
ASpawner_InteractableActor::ASpawner_InteractableActor()
{
	root = CreateDefaultSubobject<USceneComponent>("root");
	SetRootComponent(root);
}
void ASpawner_InteractableActor::OnInteract_Implementation(AActor* fromActor)
{
	if(!bUsed || bUseOnce)
	{
		bUsed = true;
		GetWorld()->SpawnActor<AActor>(actorToSpawn.Get(), GetActorTransform());
	}
}
void ASpawner_InteractableActor::OnReset_Implementation(AActor* fromActor)
{
	bUsed = false;
}