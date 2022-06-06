// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractorBase.h"
#include "InteractableInterface.h"
#include "SimpleScript.h"

// Sets default values
AInteractorBase::AInteractorBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	bCanInteract = true;
}

// Called when the game starts or when spawned
void AInteractorBase::BeginPlay()
{
	Super::BeginPlay();

	//Initialize persistent scripts to execute
	for(FScriptArguments cl : persistentScriptsToExecute)
	{
		scripts.Add(USimpleScript::CreateFromArgs(cl,this));
	}
	
}

// Called every frame
void AInteractorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AInteractorBase::Interact()
{
	if (bCanInteract) OnPreInteract();
}
void AInteractorBase::Reset()
{
	if (bCanInteract) OnPreReset();
}

//Main Interaction body
void AInteractorBase::OnInteract()
{
	//Broadcast Interaction Event
	onInteractEvent.Broadcast(this);

	//Interact with every actor
	for(AActor* actor : actorsToInteract)
	{
		IInteractableInterface* test = Cast<IInteractableInterface>(actor);
		if(test)
		{
			IInteractableInterface::Execute_OnInteract(actor, this);
		}
	}
	//Execute Scripts
	for(USimpleScript* script : scripts)
	{
		script->Execute();
	}
	//Execute non-persistent scripts
	for (FScriptArguments cl : nonPersistentScriptsToExecute)
	{
		USimpleScript::CreateFromArgs(cl,this)->Execute();
	}

}
//Main Reset Body
void AInteractorBase::OnReset()
{

}


void AInteractorBase::OnPreInteract_Implementation()
{
	OnInteract();
}


void AInteractorBase::OnPreReset_Implementation()
{
	OnReset();

}


