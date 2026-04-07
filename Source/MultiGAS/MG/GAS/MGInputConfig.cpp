// Fill out your copyright notice in the Description page of Project Settings.


#include "MG/GAS/MGInputConfig.h"

const UInputAction* UMGInputConfig::FindNativeInputActionByTag(const FGameplayTag& InputTag) const
{
	for (const FMGInputAction& Action : NativeInputActions)
	{
		if (Action.InputAction && Action.InputTag == InputTag)
		{
			return Action.InputAction;
		}
	}

	return nullptr;
}
