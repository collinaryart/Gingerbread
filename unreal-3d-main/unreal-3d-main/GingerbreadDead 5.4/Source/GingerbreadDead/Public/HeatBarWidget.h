// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "HeatBarWidget.generated.h"

class AGingerbreadDeadCharacter;
/**
 * 
 */
UCLASS()
class GINGERBREADDEAD_API UHeatBarWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	AGingerbreadDeadCharacter* Player;
	void NativeConstruct() override;
	//void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	UPROPERTY(EditAnywhere)
		float CurrentHeat = 100;

	void UpdateHeatBar(float heatValue);

	void UpdateHeatBarColour(FLinearColor Colour);

	UPROPERTY(meta = (BindWidget))
	class UProgressBar* HeatBar;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* HeatLabel;
	
	
};
