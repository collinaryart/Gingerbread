// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "GingerbreadDeadGameState.generated.h"

/**
 * 
 */
UCLASS()
class GINGERBREADDEAD_API AGingerbreadDeadGameState : public AGameState
{
	GENERATED_BODY()
	float GetMultiplier(APlayerState* PlayerState); // Get score's multiplier, so that when it increases, flame particle effect changes dynamically
	
};
