// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GingerbreadGameMode.generated.h"

/**
 * 
 */
UCLASS()
class GINGERBREADDEAD_API AGingerbreadGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	AGingerbreadGameMode();

	int heatLevel;

	virtual void Tick(float DeltaSeconds) override;
	
};
