// Fill out your copyright notice in the Description page of Project Settings.


#include "HeatBarWidget.h"

#include "GingerbreadDead/GingerbreadDeadCharacter.h"

void UHeatBarWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Player = Cast<AGingerbreadDeadCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
	HeatBar->SetPercent(100);

	HeatBar->SetFillColorAndOpacity(FLinearColor(0.130f,0.08f,1.0f,1.0f));

}

/*void UHeatBarWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if(Player)
	{
		CurrentHeat = CurrentHeat - 1;
		HeatBar->SetPercent(CurrentHeat/100);
		
	}	
}*/

void UHeatBarWidget::UpdateHeatBar(float heatValue)
{
	//CurrentHeat = CurrentHeat - 5;
	CurrentHeat = heatValue;
	HeatBar->SetPercent(heatValue/100);
}


void UHeatBarWidget::UpdateHeatBarColour(FLinearColor Colour)
{
	HeatBar->SetFillColorAndOpacity(Colour);
	
}
