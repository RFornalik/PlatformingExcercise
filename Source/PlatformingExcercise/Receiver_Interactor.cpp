// Fill out your copyright notice in the Description page of Project Settings.


#include "Receiver_Interactor.h"

void AReceiver_Interactor::BeginPlay()
{
for(AInteractorBase* actor : interactorsToReceive)
{
	actor->onInteractEvent.AddDynamic(this, &AReceiver_Interactor::OnReceive);
}

}
void AReceiver_Interactor::OnReset()
{
	intIndex = 0;
	//Be careful with actors that are possible to be destroyed
	for (AInteractorBase* actor : interactorsToReceive)
	{
		actor->Reset();
	}
}
void AReceiver_Interactor::OnReceive(AInteractorBase* interactor)
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Interaction Received 1!"));
	if (!bOrdered || interactorsToReceive.IndexOfByKey(interactor) == intIndex)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Good, Incrementing"));
		intIndex++;
		if (intIndex == interactorsToReceive.Num())Interact();
	}
	else Reset();
}