// Fill out your copyright notice in the Description page of Project Settings.


#include "ChangeLevel_SimpleScript.h"
#include "Kismet/GameplayStatics.h"

void UChangeLevel_SimpleScript::Execute()
{
	if(args.nameArguments.Num() > 0)
	{
		UGameplayStatics::OpenLevel(this, args.nameArguments[0]);
	}
	


}