// Fill out your copyright notice in the Description page of Project Settings.


#include "SetInstanceData_SimpleScript.h"
#include "PlatformerSaveGameInstance.h"
#include "Kismet/GameplayStatics.h"
void USetInstanceData_SimpleScript::Execute()
{
	if(args.intArguments.Num()>0 && args.boolArguments.Num() > 0)
	{
		UPlatformerSaveGameInstance* inst = Cast<UPlatformerSaveGameInstance>(UGameplayStatics::GetGameInstance(GetOuter()));
		if(inst->IsValidLowLevel())
		{
		switch(args.intArguments[0])
		{
		case 0:
		{
			inst->data.bHasEarnedTrophy1 = args.boolArguments[0];
			break;
		
		}
		case 1:
		{
			inst->data.bHasEarnedTrophy2 = args.boolArguments[0];
			break;

		}
		case 2:
		{
			inst->data.bHasEarnedTrophy3 = args.boolArguments[0];
			break;

		}
		default:
		{
			break;
		}
		}
		}
	}




}
