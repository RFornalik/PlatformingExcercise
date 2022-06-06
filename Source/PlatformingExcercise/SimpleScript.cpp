// Fill out your copyright notice in the Description page of Project Settings.


#include "SimpleScript.h"



USimpleScript::USimpleScript()
{
	//Initialised stuff
}
void USimpleScript::Execute()
{
	//Stuff like changing worlds
}
USimpleScript* USimpleScript::CreateFromArgs(FScriptArguments _args,UObject* outer)
{
	USimpleScript* newScript = NewObject<USimpleScript>(outer, _args.script.Get());
	newScript->args = _args;
	return newScript;
}