// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "ItemComponent.h"
#include "Components/SphereComponent.h"

#include "Collectable.generated.h"

UCLASS()
class GINGERBREADDEAD_API ACollectable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollectable();

	UPROPERTY(EditAnywhere)
		USphereComponent* Hitbox;
	UPROPERTY(EditAnywhere)
		UItemComponent* ItemComponent;

	//collision function
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent,AActor* OtherActor, UPrimitiveComponent* OtherComponent,int32 OtherBodyIndex, bool bFromSweep,const FHitResult& SweepResult);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
