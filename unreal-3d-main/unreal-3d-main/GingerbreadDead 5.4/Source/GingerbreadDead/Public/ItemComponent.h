// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "ItemComponent.generated.h"

/**
 * 
 */
class AGingerbreadDeadCharacter;

UCLASS()
class GINGERBREADDEAD_API UItemComponent : public USkeletalMeshComponent
{
	GENERATED_BODY()
	
public:

	AGingerbreadDeadCharacter* Player;

	UFUNCTION()
		virtual void Attach(AGingerbreadDeadCharacter* AttachPlayer);
	UFUNCTION()
		virtual void Detach();
	UFUNCTION()
		virtual void Use();
};
