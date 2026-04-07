// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "MG/GAS/MGInputConfig.h"
#include "MGInputComponent.generated.h"

/**
 * 
 */
UCLASS()
class MULTIGAS_API UMGInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	template <class UserObject, typename CallbackFunc>
	void BindNativeinputAction(
		const UMGInputConfig* InInputConfig, // Input Action 정의가 담긴 DataAsset
		const FGameplayTag& InInputTag, // 바인딩할 Action을 찾기 위한 Tag
		ETriggerEvent TriggerEvent, // Pressed, Released 등 언제 바인딩 함수가 호출될지
		UserObject* ContextObject, // 함수가 실행될 객체
		CallbackFunc Func); // 바인딩할 동작 함수
};

template <class UserObject, class CallbackFunc>
inline void UMGInputComponent::BindNativeinputAction(
	const UMGInputConfig* InInputConfig,
	const FGameplayTag& InInputTag,
	ETriggerEvent TriggerEvent,
	UserObject* ContextObject,
	CallbackFunc Func)
{
	checkf(InInputConfig, TEXT("MGInputComponent: Input config data asset is null, can not proceed with binding"));
	if (const UInputAction* FoundAction = InInputConfig->FindNativeInputActionByTag(InInputTag))
	{
		BindAction(FoundAction, TriggerEvent, ContextObject, Func);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to find Input Action for Tag: [%s] in Config: [%s]"),
		       *InInputTag.ToString(), *InInputConfig->GetName());
	}
}
