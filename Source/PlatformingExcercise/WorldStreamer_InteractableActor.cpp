// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldStreamer_InteractableActor.h"
#include "Kismet/GameplayStatics.h"
#include "Math.h"

void AWorldStreamer_InteractableActor::Iteration()
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Iteration"));
	if(levelsToLoad.Num()>0 && amount > 0)
	{
		amount--;
		//As level streaming can't stream multiple levels at once, we need to iterate asynchronously
		FLatentActionInfo info;
		info.CallbackTarget = this;
		info.ExecutionFunction = FName("Iteration");
		info.Linkage = 0;
		info.UUID = 0;
		int32 index = FMath::RandRange(0, levelsToLoad.Num() - 1);
		UGameplayStatics::LoadStreamLevel(this, levelsToLoad[index], true, false, info);
		levelsToLoad.RemoveAt(index);
	}

}
void AWorldStreamer_InteractableActor::OnInteract_Implementation(AActor* fromActor)
{
	Iteration();
}
